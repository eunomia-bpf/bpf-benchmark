#!/usr/bin/env python3
from __future__ import annotations

import argparse
import difflib
import hashlib
import json
import os
from pathlib import Path
import re
import shutil
import signal
import socket
import struct
import subprocess
import sys
import time


BPF_MAP_TYPES = {
    "unspec": 0,
    "hash": 1,
    "array": 2,
    "prog_array": 3,
    "perf_event_array": 4,
    "percpu_hash": 5,
    "percpu_array": 6,
    "stack_trace": 7,
    "cgroup_array": 8,
    "lru_hash": 9,
    "lru_percpu_hash": 10,
    "lpm_trie": 11,
    "array_of_maps": 12,
    "hash_of_maps": 13,
    "devmap": 14,
    "sockmap": 15,
    "cpumap": 16,
    "xskmap": 17,
    "sockhash": 18,
    "cgroup_storage": 19,
    "reuseport_sockarray": 20,
    "percpu_cgroup_storage": 21,
    "queue": 22,
    "stack": 23,
    "sk_storage": 24,
    "devmap_hash": 25,
    "struct_ops": 26,
    "ringbuf": 27,
    "inode_storage": 28,
    "task_storage": 29,
    "bloom_filter": 30,
    "user_ringbuf": 31,
}

PGM_INPUT_CONSTANT = 0
PGM_INPUT_PKT = 1
PGM_INPUT_PKT_PTRS = 2
PGM_INPUT_SKB = 3

K2_SUPPORTED_INPUT_TYPES = {PGM_INPUT_CONSTANT}

TEXT_INSN_RE = re.compile(
    r"\{\s*(-?\d+)\s*,\s*(-?\d+)\s*,\s*(-?\d+)\s*,\s*(-?\d+)\s*,\s*(-?\d+)\s*\}"
)

BPF_CLASS_MASK = 0x07
BPF_LD_CLASS = 0x00
BPF_LDX_CLASS = 0x01
BPF_ST_CLASS = 0x02
BPF_STX_CLASS = 0x03
BPF_JMP_CLASS = 0x05
BPF_JMP32_CLASS = 0x06
BPF_LDDW = 0x18
BPF_CALL = 0x85
BPF_EXIT = 0x95

BPF_ALU_OPS = {
    0x04,
    0x0C,
    0x14,
    0x1C,
    0x24,
    0x2C,
    0x34,
    0x3C,
    0x44,
    0x4C,
    0x54,
    0x5C,
    0x64,
    0x6C,
    0x74,
    0x7C,
    0x84,
    0x94,
    0xA4,
    0xAC,
    0xB4,
    0xBC,
    0xC4,
    0xCC,
    0xD4,
    0xDC,
    0x07,
    0x0F,
    0x17,
    0x1F,
    0x27,
    0x2F,
    0x37,
    0x3F,
    0x47,
    0x4F,
    0x57,
    0x5F,
    0x67,
    0x6F,
    0x77,
    0x7F,
    0x87,
    0x97,
    0xA7,
    0xAF,
    0xB7,
    0xBF,
    0xC7,
    0xCF,
    0xD7,
    0xDF,
}

STACK_STORE_OPS = {0x62, 0x63, 0x6A, 0x6B, 0x72, 0x73, 0x7A, 0x7B}

NO_ARG_HELPERS = {
    5,  # bpf_ktime_get_ns
    7,  # bpf_get_prandom_u32
    8,  # bpf_get_smp_processor_id
    14,  # bpf_get_current_pid_tgid
    15,  # bpf_get_current_uid_gid
    17,  # bpf_get_current_task
    37,  # bpf_get_current_cgroup_id on the kernels used by this suite
    80,  # bpf_get_current_cgroup_id on newer helper tables
}

HELPER_ARG_REGS = {1, 2, 3, 4, 5}


def sha256_file(path: Path) -> str:
    h = hashlib.sha256()
    with path.open("rb") as fh:
        for chunk in iter(lambda: fh.read(1024 * 1024), b""):
            h.update(chunk)
    return h.hexdigest()


def truncate_text(s: str, limit: int = 4000) -> str:
    if len(s) <= limit:
        return s
    return s[-limit:]


def parse_map_ids(value: str) -> list[int]:
    ids: list[int] = []
    for part in value.split(","):
        part = part.strip()
        if not part:
            continue
        try:
            ids.append(int(part, 10))
        except ValueError as exc:
            raise ValueError(f"invalid MAP_IDS entry {part!r}") from exc
    if ids == [0]:
        return []
    if any(map_id <= 0 for map_id in ids):
        raise ValueError(f"invalid MAP_IDS value {value!r}")
    return ids


def load_bpftool_map(path: Path) -> dict:
    with path.open() as fh:
        data = json.load(fh)
    if isinstance(data, list):
        if len(data) != 1:
            raise ValueError(f"{path} contains {len(data)} map entries, expected 1")
        data = data[0]
    if not isinstance(data, dict):
        raise ValueError(f"{path} is not a bpftool map JSON object")
    return data


def map_type_number(value: object) -> int:
    if isinstance(value, int):
        return value
    name = str(value).strip().lower()
    if name.startswith("bpf_map_type_"):
        name = name.removeprefix("bpf_map_type_")
    if name not in BPF_MAP_TYPES:
        raise ValueError(f"unsupported bpftool map type {value!r}")
    return BPF_MAP_TYPES[name]


def write_k2_maps(path: Path, map_ids: list[int], map_values_dir: Path) -> None:
    lines: list[str] = []
    for idx, map_id in enumerate(map_ids):
        show_path = map_values_dir / f"map-{map_id}.show.json"
        if not show_path.is_file():
            raise FileNotFoundError(f"missing map metadata for map id {map_id}: {show_path}")
        info = load_bpftool_map(show_path)
        key_size = int(info.get("bytes_key", info.get("key_size", 0)))
        value_size = int(info.get("bytes_value", info.get("value_size", 0)))
        max_entries = int(info.get("max_entries", 0))
        type_num = map_type_number(info.get("type", 0))
        if key_size <= 0 or value_size <= 0 or max_entries <= 0:
            raise ValueError(f"incomplete map metadata in {show_path}")
        lines.append(
            "{ "
            f"type = {type_num}, "
            f"key_size = {key_size}, "
            f"value_size = {value_size}, "
            f"max_entries = {max_entries}, "
            f"fd = {idx}, "
            "}"
        )
    path.write_text("\n".join(lines) + ("\n" if lines else ""))


def k2_input_type(prog_type: str) -> int:
    prog_type = prog_type.strip()
    if prog_type == "xdp":
        return PGM_INPUT_PKT_PTRS
    if prog_type in {"sched_cls", "sched_act", "cgroup_skb"}:
        return PGM_INPUT_SKB
    if prog_type == "socket_filter":
        return PGM_INPUT_PKT
    return PGM_INPUT_CONSTANT


def write_k2_desc(path: Path, prog_type: str) -> None:
    max_pkt = int(os.environ.get("BPFREJIT_K2_MAX_PKT_SZ", "256"))
    if max_pkt < 0:
        raise ValueError("BPFREJIT_K2_MAX_PKT_SZ must be non-negative")
    path.write_text(
        f"{{ pgm_input_type = {k2_input_type(prog_type)}, }}\n"
        f"{{ max_pkt_sz = {max_pkt}, }}\n"
    )


def k2_input_model_supported(prog_type: str) -> bool:
    return k2_input_type(prog_type) in K2_SUPPORTED_INPUT_TYPES


def choose_port() -> int:
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as sock:
        sock.bind(("127.0.0.1", 0))
        return int(sock.getsockname()[1])


def pack_text_bpf_insns(path: Path) -> bytes:
    out = bytearray()
    with path.open() as fh:
        for line_no, line in enumerate(fh, 1):
            stripped = line.strip()
            if not stripped:
                continue
            match = TEXT_INSN_RE.search(stripped)
            if match is None:
                raise ValueError(f"cannot parse K2 bpf_insns line {line_no}: {stripped!r}")
            opcode, dst, src, off, imm = (int(x) for x in match.groups())
            if not 0 <= opcode <= 255:
                raise ValueError(f"opcode out of range on line {line_no}: {opcode}")
            if not 0 <= dst <= 15 or not 0 <= src <= 15:
                raise ValueError(f"register out of range on line {line_no}: dst={dst} src={src}")
            if not -32768 <= off <= 32767:
                raise ValueError(f"offset out of range on line {line_no}: {off}")
            if 2**31 <= imm <= 2**32 - 1:
                imm -= 2**32
            if not -(2**31) <= imm <= 2**31 - 1:
                raise ValueError(f"imm out of range on line {line_no}: {imm}")
            out.extend(struct.pack("<BBhi", opcode, ((src & 0xF) << 4) | (dst & 0xF), off, imm))
    if not out:
        raise ValueError(f"K2 output contains no real BPF instructions: {path}")
    return bytes(out)


def unpack_bpf_insns(data: bytes) -> list[tuple[int, int, int, int, int]]:
    if len(data) % 8 != 0:
        raise ValueError(f"BPF bytecode length {len(data)} is not a multiple of 8")
    insns: list[tuple[int, int, int, int, int]] = []
    for off in range(0, len(data), 8):
        opcode, regs, insn_off, imm = struct.unpack_from("<BBhi", data, off)
        insns.append((opcode, regs & 0xF, (regs >> 4) & 0xF, insn_off, imm))
    return insns


def is_control_insn(opcode: int) -> bool:
    cls = opcode & BPF_CLASS_MASK
    return opcode in {BPF_CALL, BPF_EXIT} or cls in {BPF_JMP_CLASS, BPF_JMP32_CLASS}


def is_branch_insn(opcode: int) -> bool:
    cls = opcode & BPF_CLASS_MASK
    return opcode not in {BPF_CALL, BPF_EXIT} and cls in {BPF_JMP_CLASS, BPF_JMP32_CLASS}


def normalize_branch_offset(insn: tuple[int, int, int, int, int]) -> tuple[int, int, int, int, int]:
    opcode, dst, src, off, imm = insn
    if is_branch_insn(opcode):
        return (opcode, dst, src, 0, imm)
    return (opcode, dst, src, off, imm)


def is_lddw_slot(insns: list[tuple[int, int, int, int, int]], idx: int) -> bool:
    return insns[idx][0] == BPF_LDDW or (idx > 0 and insns[idx - 1][0] == BPF_LDDW)


def is_k2_window_insn(
    insns: list[tuple[int, int, int, int, int]],
    idx: int,
    protected: set[int],
) -> bool:
    if idx in protected or is_lddw_slot(insns, idx):
        return False
    opcode, _dst, _src, _off, _imm = insns[idx]
    cls = opcode & BPF_CLASS_MASK
    if is_control_insn(opcode):
        return False
    if cls in {BPF_LD_CLASS, BPF_LDX_CLASS, BPF_ST_CLASS, BPF_STX_CLASS}:
        return False
    if opcode not in BPF_ALU_OPS:
        return False
    return True


def helper_arg_protected_indices(insns: list[tuple[int, int, int, int, int]]) -> set[int]:
    protected: set[int] = set()
    block_start = 0
    lookback = int(os.environ.get("BPFREJIT_K2_HELPER_ARG_LOOKBACK", "12"))
    if lookback < 0:
        raise ValueError("BPFREJIT_K2_HELPER_ARG_LOOKBACK must be non-negative")
    for idx, (opcode, _dst, _src, _off, imm) in enumerate(insns):
        if opcode == BPF_CALL:
            if imm not in NO_ARG_HELPERS:
                for protected_idx in range(max(block_start, idx - lookback), idx):
                    protected.add(protected_idx)
            block_start = idx + 1
        elif is_control_insn(opcode):
            block_start = idx + 1
    return protected


def splits_lddw_pair(insns: list[tuple[int, int, int, int, int]], start: int, end: int) -> bool:
    return (start > 0 and insns[start - 1][0] == BPF_LDDW) or insns[end][0] == BPF_LDDW


def reg_written(insn: tuple[int, int, int, int, int]) -> int | None:
    opcode, dst, _src, _off, _imm = insn
    if opcode in STACK_STORE_OPS:
        return None
    if opcode in BPF_ALU_OPS or (opcode & BPF_CLASS_MASK) == 0x01:
        return dst
    return None


def call_sequence(insns: list[tuple[int, int, int, int, int]]) -> list[int]:
    return [imm for opcode, _dst, _src, _off, imm in insns if opcode == BPF_CALL]


def helper_arg_writes(insns: list[tuple[int, int, int, int, int]]) -> list[tuple[int, set[int]]]:
    calls: list[tuple[int, set[int]]] = []
    writes: set[int] = set()
    for insn in insns:
        opcode, _dst, _src, _off, imm = insn
        if opcode == BPF_CALL:
            calls.append((imm, set(writes & HELPER_ARG_REGS)))
            writes.clear()
            continue
        if is_control_insn(opcode):
            writes.clear()
            continue
        written = reg_written(insn)
        if written is not None:
            writes.add(written)
    return calls


def validate_k2_output_structure(
    input_insns: list[tuple[int, int, int, int, int]],
    output_insns: list[tuple[int, int, int, int, int]],
    windows: list[tuple[int, int]],
) -> str | None:
    input_calls = call_sequence(input_insns)
    output_calls = call_sequence(output_insns)
    if input_calls != output_calls:
        return "helper_call_sequence_changed"

    input_writes = helper_arg_writes(input_insns)
    output_writes = helper_arg_writes(output_insns)
    if len(input_writes) != len(output_writes):
        return "helper_call_count_changed"
    for call_idx, ((helper, before), (out_helper, after)) in enumerate(zip(input_writes, output_writes)):
        if helper != out_helper:
            return f"helper_call_changed_at_{call_idx}"
        if helper in NO_ARG_HELPERS:
            continue
        missing = sorted(before - after)
        if missing:
            regs = ",".join(f"r{reg}" for reg in missing)
            return f"helper_arg_writes_removed_call_{call_idx}_helper_{helper}_{regs}"

    window_slots: set[int] = set()
    for start, end in windows:
        window_slots.update(range(start, end + 1))

    normalized_input = [normalize_branch_offset(insn) for insn in input_insns]
    normalized_output = [normalize_branch_offset(insn) for insn in output_insns]
    matcher = difflib.SequenceMatcher(None, normalized_input, normalized_output, autojunk=False)
    input_to_output: dict[int, int] = {}
    window_replacements: list[tuple[int, int, int, int]] = []
    for tag, i1, i2, j1, j2 in matcher.get_opcodes():
        if tag == "equal":
            for input_idx, output_idx in zip(range(i1, i2), range(j1, j2)):
                input_to_output[input_idx] = output_idx
            continue
        changed_input = set(range(i1, i2))
        if changed_input:
            edit_in_window = not (changed_input - window_slots)
        else:
            edit_in_window = i1 in window_slots or (i1 > 0 and i1 - 1 in window_slots)
        if not edit_in_window:
            return f"outside_window_changed_{i1}_{i2}"
        window_replacements.append((i1, i2, j1, j2))
        for opcode, _dst, _src, _off, _imm in output_insns[j1:j2]:
            cls = opcode & BPF_CLASS_MASK
            if opcode not in BPF_ALU_OPS or cls in {
                BPF_LD_CLASS,
                BPF_LDX_CLASS,
                BPF_ST_CLASS,
                BPF_STX_CLASS,
                BPF_JMP_CLASS,
                BPF_JMP32_CLASS,
            }:
                return f"unsafe_replacement_opcode_0x{opcode:02x}"

    for input_idx, output_idx in input_to_output.items():
        input_insn = input_insns[input_idx]
        output_insn = output_insns[output_idx]
        if input_insn == output_insn:
            continue
        if normalize_branch_offset(input_insn) != normalize_branch_offset(output_insn):
            return f"outside_window_changed_{input_idx}_{input_idx + 1}"
        opcode, _dst, _src, input_off, _imm = input_insn
        _opcode, _dst2, _src2, output_off, _imm2 = output_insn
        if not is_branch_insn(opcode):
            return f"outside_window_changed_{input_idx}_{input_idx + 1}"
        input_target = input_idx + 1 + input_off
        output_target = output_idx + 1 + output_off
        if input_target == len(input_insns):
            if output_target != len(output_insns):
                return f"branch_target_changed_{input_idx}"
            continue
        if not 0 <= input_target < len(input_insns):
            return f"branch_target_out_of_range_{input_idx}"
        expected_output = input_to_output.get(input_target)
        if expected_output is not None:
            if output_target != expected_output:
                return f"branch_target_changed_{input_idx}"
            continue
        target_replacement = next(
            (
                (rep_j1, rep_j2)
                for rep_i1, rep_i2, rep_j1, rep_j2 in window_replacements
                if rep_i1 <= input_target < rep_i2
            ),
            None,
        )
        if target_replacement is None:
            return f"branch_target_changed_{input_idx}"
        rep_j1, rep_j2 = target_replacement
        if rep_j1 == rep_j2:
            if output_target != rep_j1:
                return f"branch_target_changed_{input_idx}"
        elif not rep_j1 <= output_target < rep_j2:
            return f"branch_target_changed_{input_idx}"
    return None


def score_window(insns: list[tuple[int, int, int, int, int]], start: int, end: int) -> int:
    score = end - start + 1
    writes: dict[int, int] = {}
    for insn in insns[start : end + 1]:
        opcode, dst, src, off, imm = insn
        if opcode in BPF_ALU_OPS:
            score += 2
        if opcode == BPF_LDDW:
            score += 2
        if opcode in STACK_STORE_OPS and dst == 10:
            score += 3
            if imm == 0:
                score += 2
        written = reg_written(insn)
        if written is not None:
            writes[written] = writes.get(written, 0) + 1
        if opcode == 0xBF and dst == src:
            score -= 2
    score += sum(max(0, count - 1) * 3 for count in writes.values())
    return score


def choose_k2_windows(insns: list[tuple[int, int, int, int, int]]) -> list[tuple[int, int]]:
    max_windows = int(os.environ.get("BPFREJIT_K2_MAX_WINDOWS", "8"))
    max_window_len = int(os.environ.get("BPFREJIT_K2_MAX_WINDOW_LEN", "9"))
    min_window_len = int(os.environ.get("BPFREJIT_K2_MIN_WINDOW_LEN", "2"))
    if max_windows <= 0 or max_window_len < min_window_len:
        return []

    protected = helper_arg_protected_indices(insns)
    candidates: list[tuple[int, int, int]] = []
    segment_start: int | None = None
    for idx in range(len(insns) + 1):
        if idx < len(insns) and is_k2_window_insn(insns, idx, protected):
            if segment_start is None:
                segment_start = idx
            continue
        if segment_start is not None:
            segment_end = idx - 1
            segment_len = segment_end - segment_start + 1
            for length in range(min(max_window_len, segment_len), min_window_len - 1, -1):
                for start in range(segment_start, segment_end - length + 2):
                    end = start + length - 1
                    if splits_lddw_pair(insns, start, end):
                        continue
                    candidates.append((score_window(insns, start, end), start, end))
            segment_start = None

    candidates.sort(key=lambda item: (-item[0], -(item[2] - item[1] + 1), item[1]))
    selected: list[tuple[int, int]] = []
    occupied: set[int] = set()
    for _score, start, end in candidates:
        window_slots = set(range(start, end + 1))
        if occupied & window_slots:
            continue
        selected.append((start, end))
        occupied.update(window_slots)
        if len(selected) >= max_windows:
            break
    selected.sort()
    return selected


def has_exit(insns: list[tuple[int, int, int, int, int]]) -> bool:
    return any(opcode == BPF_EXIT for opcode, _dst, _src, _off, _imm in insns)


def is_return_filler_program(insns: list[tuple[int, int, int, int, int]]) -> bool:
    if len(insns) < 64:
        return False
    for idx, (opcode, dst, src, off, _imm) in enumerate(insns):
        if idx == len(insns) - 1 and opcode == BPF_EXIT:
            return True
        if opcode not in {0xB4, 0xB7} or dst != 0 or src != 0 or off != 0:
            return False
    return False


def run_k2(cmd: list[str], *, cwd: Path, env: dict[str, str], timeout_s: float) -> subprocess.CompletedProcess[str]:
    proc = subprocess.Popen(
        cmd,
        cwd=str(cwd),
        env=env,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        text=True,
        preexec_fn=os.setsid,
    )
    try:
        stdout, stderr = proc.communicate(timeout=timeout_s)
    except subprocess.TimeoutExpired:
        os.killpg(proc.pid, signal.SIGKILL)
        stdout, stderr = proc.communicate()
        raise subprocess.TimeoutExpired(cmd, timeout_s, output=stdout, stderr=stderr)
    return subprocess.CompletedProcess(cmd, proc.returncode, stdout, stderr)


def write_report(path: Path, payload: dict) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(json.dumps(payload, indent=2, sort_keys=True) + "\n")


def base_report(args: argparse.Namespace, input_path: Path) -> dict:
    return {
        "pass": "k2",
        "prog_id": args.prog_id,
        "prog_type": args.prog_type,
        "target": args.target,
        "input_sha256": sha256_file(input_path),
        "insn_count_before": input_path.stat().st_size // 8,
        "sites_matched": 0,
        "sites_applied": 0,
        "sites_skipped": 0,
        "skip_reasons": {},
        "diagnostics": [],
    }


def fail(report_path: Path, report: dict, message: str, code: int = 1) -> None:
    report = dict(report)
    report["error"] = message
    report.setdefault("diagnostics", []).append(message)
    write_report(report_path, report)
    print(message, file=sys.stderr)
    raise SystemExit(code)


def finish_unchanged(
    report_path: Path,
    report: dict,
    input_path: Path,
    output_path: Path,
    *,
    reason: str,
    matched: bool = False,
) -> int:
    output_path.parent.mkdir(parents=True, exist_ok=True)
    shutil.copyfile(input_path, output_path)
    output_sha = sha256_file(output_path)
    matched_count = int(report.get("sites_matched", 0)) if matched else 0
    report["output_sha256"] = output_sha
    report["insn_count_after"] = report["insn_count_before"]
    report["insn_delta"] = 0
    report["sites_matched"] = matched_count
    report["sites_applied"] = 0
    report["sites_skipped"] = matched_count
    report["skip_reasons"] = {reason: matched_count} if matched_count else {}
    report.setdefault("diagnostics", []).extend(
        [
            f"decision=unchanged_input",
            f"not_applied_reason={reason}",
        ]
    )
    write_report(report_path, report)
    return 0


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--input", required=True)
    parser.add_argument("--output", required=True)
    parser.add_argument("--report", required=True)
    parser.add_argument("--workdir", required=True)
    parser.add_argument("--prog-type", required=True)
    parser.add_argument("--prog-id", required=True)
    parser.add_argument("--target", required=True)
    parser.add_argument("--map-ids", default="")
    parser.add_argument("--map-values", default="")
    args = parser.parse_args()

    input_path = Path(args.input).resolve()
    output_path = Path(args.output).resolve()
    report_path = Path(args.report).resolve()
    workdir = Path(args.workdir).resolve() / "k2"
    bin_dir = Path(__file__).resolve().parent / "bin"
    main_bin = bin_dir / "main_ebpf.out"
    z3_bin = bin_dir / "z3server.out"
    libz3 = bin_dir / "libz3.so"

    report = base_report(args, input_path)
    try:
        for required in (main_bin, z3_bin, libz3):
            if not required.is_file():
                raise FileNotFoundError(f"missing K2 runtime artifact: {required}")
            if required != libz3 and not os.access(required, os.X_OK):
                raise PermissionError(f"K2 binary is not executable: {required}")

        workdir.mkdir(parents=True, exist_ok=True)
        k2_input = workdir / "input.ins"
        k2_maps = workdir / "input.maps"
        k2_desc = workdir / "input.desc"
        k2_out = workdir / "out"
        if k2_out.exists():
            shutil.rmtree(k2_out)
        k2_out.mkdir()
        shutil.copyfile(input_path, k2_input)
        input_bytes = input_path.read_bytes()
        input_insns = unpack_bpf_insns(input_bytes)
        max_input_insns = int(os.environ.get("BPFREJIT_K2_MAX_INPUT_INSNS", "1600"))
        if max_input_insns < 0:
            raise ValueError("BPFREJIT_K2_MAX_INPUT_INSNS must be non-negative")
        if max_input_insns > 0 and len(input_insns) > max_input_insns:
            report["diagnostics"].append(
                f"k2_unsupported_shape=input_too_large:{len(input_insns)}>{max_input_insns}"
            )
            return finish_unchanged(
                report_path,
                report,
                input_path,
                output_path,
                reason="input_too_large",
                matched=False,
            )
        if is_return_filler_program(input_insns):
            report["diagnostics"].append("k2_unsupported_shape=return_filler")
            return finish_unchanged(
                report_path,
                report,
                input_path,
                output_path,
                reason="no_candidate_windows",
                matched=False,
            )
        windows = choose_k2_windows(input_insns)
        report["sites_matched"] = len(windows)
        report["diagnostics"].append(
            "k2_windows="
            + ",".join(f"{start}-{end}" for start, end in windows[:16])
            + (",..." if len(windows) > 16 else "")
        )
        if not windows:
            return finish_unchanged(
                report_path,
                report,
                input_path,
                output_path,
                reason="no_candidate_windows",
                matched=False,
            )
        if not k2_input_model_supported(args.prog_type):
            report["diagnostics"].append(f"k2_unsupported_input_model={args.prog_type}")
            return finish_unchanged(
                report_path,
                report,
                input_path,
                output_path,
                reason="unsupported_input_model",
                matched=True,
            )

        map_ids = parse_map_ids(args.map_ids)
        map_values_dir = Path(args.map_values).resolve()
        if map_ids and not map_values_dir.is_dir():
            raise FileNotFoundError(f"MAP_VALUES directory does not exist: {map_values_dir}")
        try:
            write_k2_maps(k2_maps, map_ids, map_values_dir)
        except Exception as exc:
            report["diagnostics"].append(f"k2_map_metadata_unavailable={exc}")
            return finish_unchanged(
                report_path,
                report,
                input_path,
                output_path,
                reason="unsupported_map_metadata",
                matched=False,
            )
        write_k2_desc(k2_desc, args.prog_type)

        timeout_s = float(os.environ.get("BPFREJIT_K2_TIMEOUT", "12"))
        niter = int(os.environ.get("BPFREJIT_K2_NITER", "200"))
        if timeout_s <= 0:
            raise ValueError("BPFREJIT_K2_TIMEOUT must be positive")
        if niter <= 0:
            raise ValueError("BPFREJIT_K2_NITER must be positive")
        reset_win_niter = int(
            os.environ.get("BPFREJIT_K2_RESET_WIN_NITER", str(max(1, niter // max(1, len(windows)))))
        )
        if reset_win_niter <= 0:
            raise ValueError("BPFREJIT_K2_RESET_WIN_NITER must be positive")
        port = choose_port()
        env = dict(os.environ)
        env["LD_LIBRARY_PATH"] = f"{bin_dir}:{env.get('LD_LIBRARY_PATH', '')}"
        cmd = [
            str(main_bin),
            "--bm_from_file",
            "--bytecode",
            str(k2_input),
            "--map",
            str(k2_maps),
            "--desc",
            str(k2_desc),
            "--path_res",
            str(k2_out) + "/",
            "-n",
            str(niter),
            "-k",
            "1",
            "--w_p",
            os.environ.get("BPFREJIT_K2_W_P", "1"),
            "--reset_win_niter",
            str(reset_win_niter),
            "--port",
            str(port),
            "--logger_level",
            os.environ.get("BPFREJIT_K2_LOGGER_LEVEL", "0"),
            "--is_win",
            "--win_s_list",
            ",".join(str(start) for start, _end in windows),
            "--win_e_list",
            ",".join(str(end) for _start, end in windows),
        ]
        started = time.monotonic()
        try:
            result = run_k2(cmd, cwd=bin_dir, env=env, timeout_s=timeout_s)
        except subprocess.TimeoutExpired as exc:
            report["diagnostics"].extend(
                [
                    f"k2_timeout_s={timeout_s}",
                    f"k2_stdout_tail={truncate_text(exc.output or '')}",
                    f"k2_stderr_tail={truncate_text(exc.stderr or '')}",
                ]
            )
            return finish_unchanged(
                report_path,
                report,
                input_path,
                output_path,
                reason="k2_timeout",
                matched=True,
            )
        elapsed_s = time.monotonic() - started
        report["diagnostics"].extend(
            [
                f"k2_cmd={' '.join(cmd)}",
                f"k2_elapsed_s={elapsed_s:.6f}",
                f"k2_returncode={result.returncode}",
                f"k2_stdout_tail={truncate_text(result.stdout)}",
                f"k2_stderr_tail={truncate_text(result.stderr)}",
            ]
        )
        if result.returncode != 0:
            report["diagnostics"].append(f"K2 exited with status {result.returncode}")
            return finish_unchanged(
                report_path,
                report,
                input_path,
                output_path,
                reason="k2_failed",
                matched=True,
            )

        text_out = k2_out / "output0.bpf_insns"
        if not text_out.is_file():
            report["diagnostics"].append(f"K2 did not produce {text_out}")
            return finish_unchanged(
                report_path,
                report,
                input_path,
                output_path,
                reason="k2_missing_output",
                matched=True,
            )
        try:
            output_bytes = pack_text_bpf_insns(text_out)
            output_insns = unpack_bpf_insns(output_bytes)
            if has_exit(input_insns) and not has_exit(output_insns):
                raise ValueError("K2 output removed every BPF_EXIT instruction")
            unsafe_reason = validate_k2_output_structure(input_insns, output_insns, windows)
            if unsafe_reason is not None:
                report["diagnostics"].append(f"k2_unsafe_output={unsafe_reason}")
                return finish_unchanged(
                    report_path,
                    report,
                    input_path,
                    output_path,
                    reason="k2_unsafe_output",
                    matched=True,
                )
        except Exception as exc:
            report["diagnostics"].append(f"K2 output parse failed: {exc}")
            return finish_unchanged(
                report_path,
                report,
                input_path,
                output_path,
                reason="k2_invalid_output",
                matched=True,
            )
        output_path.write_bytes(output_bytes)
        output_sha = sha256_file(output_path)
        report["output_sha256"] = output_sha
        report["insn_count_after"] = len(output_bytes) // 8
        report["insn_delta"] = report["insn_count_after"] - report["insn_count_before"]
        if output_sha != report["input_sha256"]:
            report["sites_applied"] = 1
            report["sites_skipped"] = max(0, len(windows) - 1)
        else:
            report["sites_skipped"] = len(windows)
            report["skip_reasons"] = {"unchanged": len(windows)}
        write_report(report_path, report)
        return 0
    except SystemExit:
        raise
    except Exception as exc:
        message = f"K2 wrapper error: {exc}"
        if "missing K2 runtime artifact" in message or "K2 binary is not executable" in message:
            fail(report_path, report, message)
        report["diagnostics"].append(message)
        return finish_unchanged(
            report_path,
            report,
            input_path,
            output_path,
            reason="k2_wrapper_unsupported",
            matched=False,
        )
    return 1


if __name__ == "__main__":
    raise SystemExit(main())
