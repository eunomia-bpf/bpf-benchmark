#!/usr/bin/env python3
from __future__ import annotations

import argparse
import ctypes
import errno
import json
import os
import platform
import re
import sys
from dataclasses import dataclass
from datetime import datetime, timezone
from pathlib import Path
from typing import Any, Mapping, Sequence

if __package__ in {None, ""}:
    sys.path.insert(0, str(Path(__file__).resolve().parents[2]))

from runner.libs import ROOT_DIR, write_json  # noqa: E402


BPF_MAP_LOOKUP_ELEM = 1
BPF_MAP_GET_NEXT_KEY = 4
BPF_PROG_GET_NEXT_ID = 11
BPF_PROG_GET_FD_BY_ID = 13
BPF_MAP_GET_FD_BY_ID = 14
BPF_OBJ_GET_INFO_BY_FD = 15

BPF_OBJ_NAME_LEN = 16

BPF_MAP_TYPE_HASH = 1
BPF_MAP_TYPE_ARRAY = 2
BPF_MAP_TYPE_PERCPU_HASH = 5
BPF_MAP_TYPE_PERCPU_ARRAY = 6
BPF_MAP_TYPE_LRU_HASH = 9
BPF_MAP_TYPE_LRU_PERCPU_HASH = 10
BPF_MAP_TYPE_LPM_TRIE = 11
BPF_MAP_TYPE_HASH_OF_MAPS = 13

ARRAY_MAP_TYPES = {
    BPF_MAP_TYPE_ARRAY,
    BPF_MAP_TYPE_PERCPU_ARRAY,
}

HASH_MAP_TYPES = {
    BPF_MAP_TYPE_HASH,
    BPF_MAP_TYPE_PERCPU_HASH,
    BPF_MAP_TYPE_LRU_HASH,
    BPF_MAP_TYPE_LRU_PERCPU_HASH,
    BPF_MAP_TYPE_LPM_TRIE,
    BPF_MAP_TYPE_HASH_OF_MAPS,
}

MAP_TYPE_NAMES = {
    BPF_MAP_TYPE_HASH: "BPF_MAP_TYPE_HASH",
    BPF_MAP_TYPE_ARRAY: "BPF_MAP_TYPE_ARRAY",
    BPF_MAP_TYPE_PERCPU_HASH: "BPF_MAP_TYPE_PERCPU_HASH",
    BPF_MAP_TYPE_PERCPU_ARRAY: "BPF_MAP_TYPE_PERCPU_ARRAY",
    BPF_MAP_TYPE_LRU_HASH: "BPF_MAP_TYPE_LRU_HASH",
    BPF_MAP_TYPE_LRU_PERCPU_HASH: "BPF_MAP_TYPE_LRU_PERCPU_HASH",
    BPF_MAP_TYPE_LPM_TRIE: "BPF_MAP_TYPE_LPM_TRIE",
    BPF_MAP_TYPE_HASH_OF_MAPS: "BPF_MAP_TYPE_HASH_OF_MAPS",
}


def _sys_bpf_number() -> int:
    machine = platform.machine().lower()
    if machine in {"x86_64", "amd64"}:
        return 321
    if machine in {"aarch64", "arm64"}:
        return 280
    raise RuntimeError(f"unsupported architecture for raw bpf syscalls: {machine}")


SYS_BPF = _sys_bpf_number()
LIBC = ctypes.CDLL(None, use_errno=True)
LIBC.syscall.restype = ctypes.c_long


class AttrGetNextId(ctypes.Structure):
    _fields_ = [
        ("start_id", ctypes.c_uint32),
        ("next_id", ctypes.c_uint32),
        ("open_flags", ctypes.c_uint32),
        ("_pad", ctypes.c_ubyte * (128 - 12)),
    ]


class AttrGetFdById(ctypes.Structure):
    _fields_ = [
        ("prog_id", ctypes.c_uint32),
        ("next_id", ctypes.c_uint32),
        ("open_flags", ctypes.c_uint32),
        ("_pad", ctypes.c_ubyte * (128 - 12)),
    ]


class AttrGetInfoByFd(ctypes.Structure):
    _fields_ = [
        ("bpf_fd", ctypes.c_uint32),
        ("info_len", ctypes.c_uint32),
        ("info", ctypes.c_uint64),
        ("_pad", ctypes.c_ubyte * (128 - 16)),
    ]


class AttrMapElem(ctypes.Structure):
    _fields_ = [
        ("map_fd", ctypes.c_uint32),
        ("_pad0", ctypes.c_uint32),
        ("key", ctypes.c_uint64),
        ("value", ctypes.c_uint64),
        ("flags", ctypes.c_uint64),
        ("_pad", ctypes.c_ubyte * (128 - 32)),
    ]


class AttrMapGetNextKey(ctypes.Structure):
    _fields_ = [
        ("map_fd", ctypes.c_uint32),
        ("_pad0", ctypes.c_uint32),
        ("key", ctypes.c_uint64),
        ("next_key", ctypes.c_uint64),
        ("_pad", ctypes.c_ubyte * (128 - 24)),
    ]


class BpfProgInfo(ctypes.Structure):
    _fields_ = [
        ("prog_type", ctypes.c_uint32),
        ("id", ctypes.c_uint32),
        ("tag", ctypes.c_ubyte * 8),
        ("jited_prog_len", ctypes.c_uint32),
        ("xlated_prog_len", ctypes.c_uint32),
        ("jited_prog_insns", ctypes.c_uint64),
        ("xlated_prog_insns", ctypes.c_uint64),
        ("load_time", ctypes.c_uint64),
        ("created_by_uid", ctypes.c_uint32),
        ("nr_map_ids", ctypes.c_uint32),
        ("map_ids", ctypes.c_uint64),
        ("name", ctypes.c_char * BPF_OBJ_NAME_LEN),
        ("ifindex", ctypes.c_uint32),
        ("gpl_compatible_pad", ctypes.c_uint32),
        ("netns_dev", ctypes.c_uint64),
        ("netns_ino", ctypes.c_uint64),
        ("nr_jited_ksyms", ctypes.c_uint32),
        ("nr_jited_func_lens", ctypes.c_uint32),
        ("jited_ksyms", ctypes.c_uint64),
        ("jited_func_lens", ctypes.c_uint64),
        ("btf_id", ctypes.c_uint32),
        ("func_info_rec_size", ctypes.c_uint32),
        ("func_info", ctypes.c_uint64),
        ("nr_func_info", ctypes.c_uint32),
        ("nr_line_info", ctypes.c_uint32),
        ("line_info", ctypes.c_uint64),
        ("jited_line_info", ctypes.c_uint64),
        ("nr_jited_line_info", ctypes.c_uint32),
        ("line_info_rec_size", ctypes.c_uint32),
        ("jited_line_info_rec_size", ctypes.c_uint32),
        ("nr_prog_tags", ctypes.c_uint32),
        ("prog_tags", ctypes.c_uint64),
        ("run_time_ns", ctypes.c_uint64),
        ("run_cnt", ctypes.c_uint64),
        ("recursion_misses", ctypes.c_uint64),
        ("verified_insns", ctypes.c_uint32),
        ("attach_btf_obj_id", ctypes.c_uint32),
        ("attach_btf_id", ctypes.c_uint32),
        ("orig_prog_len", ctypes.c_uint32),
        ("orig_prog_insns", ctypes.c_uint64),
    ]


class BpfMapInfo(ctypes.Structure):
    _fields_ = [
        ("map_type", ctypes.c_uint32),
        ("id", ctypes.c_uint32),
        ("key_size", ctypes.c_uint32),
        ("value_size", ctypes.c_uint32),
        ("max_entries", ctypes.c_uint32),
        ("map_flags", ctypes.c_uint32),
        ("name", ctypes.c_char * BPF_OBJ_NAME_LEN),
        ("ifindex", ctypes.c_uint32),
        ("btf_vmlinux_value_type_id", ctypes.c_uint32),
        ("netns_dev", ctypes.c_uint64),
        ("netns_ino", ctypes.c_uint64),
        ("btf_id", ctypes.c_uint32),
        ("btf_key_type_id", ctypes.c_uint32),
        ("btf_value_type_id", ctypes.c_uint32),
        ("btf_vmlinux_id", ctypes.c_uint32),
        ("map_extra", ctypes.c_uint64),
        ("hash", ctypes.c_uint64),
        ("hash_size", ctypes.c_uint32),
    ]


@dataclass(frozen=True, slots=True)
class ProgramSpec:
    prog_id: int
    repo: str
    object_name: str
    program_name: str
    qualified_prog_name: str | None = None


def _sys_bpf(cmd: int, attr: ctypes.Structure) -> int:
    ret = int(
        LIBC.syscall(
            ctypes.c_long(SYS_BPF),
            ctypes.c_long(int(cmd)),
            ctypes.c_void_p(ctypes.addressof(attr)),
            ctypes.c_ulong(ctypes.sizeof(attr)),
        )
    )
    if ret >= 0:
        return ret
    err = ctypes.get_errno()
    raise OSError(err, os.strerror(err))


def _decode_name(raw: bytes | bytearray) -> str:
    return bytes(raw).split(b"\0", 1)[0].decode("utf-8", "replace")


def _map_type_name(map_type: int) -> str:
    return MAP_TYPE_NAMES.get(int(map_type), f"BPF_MAP_TYPE_{int(map_type)}")


def _sanitize_segment(value: str) -> str:
    sanitized = re.sub(r"[^A-Za-z0-9._-]+", "_", value.strip())
    return sanitized or "unknown"


def _possible_cpu_count() -> int:
    possible = Path("/sys/devices/system/cpu/possible")
    if not possible.exists():
        return max(1, os.cpu_count() or 1)
    count = 0
    for chunk in possible.read_text().strip().split(","):
        chunk = chunk.strip()
        if not chunk:
            continue
        if "-" in chunk:
            start_text, end_text = chunk.split("-", 1)
            count += int(end_text) - int(start_text) + 1
        else:
            count += 1
    return max(1, count)


def _percpu_value_size(value_size: int) -> int:
    stride = ((int(value_size) + 7) // 8) * 8
    return stride * _possible_cpu_count()


def _lookup_value_size(map_info: BpfMapInfo) -> int:
    if int(map_info.map_type) in {BPF_MAP_TYPE_PERCPU_HASH, BPF_MAP_TYPE_PERCPU_ARRAY, BPF_MAP_TYPE_LRU_PERCPU_HASH}:
        return _percpu_value_size(int(map_info.value_size))
    return int(map_info.value_size)


def bpf_prog_get_next_id(start_id: int) -> int:
    attr = AttrGetNextId()
    attr.start_id = int(start_id)
    _sys_bpf(BPF_PROG_GET_NEXT_ID, attr)
    return int(attr.next_id)


def bpf_prog_get_fd_by_id(prog_id: int) -> int:
    attr = AttrGetFdById()
    attr.prog_id = int(prog_id)
    return _sys_bpf(BPF_PROG_GET_FD_BY_ID, attr)


def bpf_map_get_fd_by_id(map_id: int) -> int:
    attr = AttrGetFdById()
    attr.prog_id = int(map_id)
    return _sys_bpf(BPF_MAP_GET_FD_BY_ID, attr)


def _bpf_obj_get_info_by_fd(fd: int, info: ctypes.Structure) -> None:
    attr = AttrGetInfoByFd()
    attr.bpf_fd = int(fd)
    attr.info_len = ctypes.sizeof(info)
    attr.info = ctypes.addressof(info)
    _sys_bpf(BPF_OBJ_GET_INFO_BY_FD, attr)


def bpf_prog_get_info(fd: int) -> BpfProgInfo:
    info = BpfProgInfo()
    _bpf_obj_get_info_by_fd(fd, info)
    return info


def bpf_prog_get_map_ids(fd: int) -> tuple[BpfProgInfo, list[int]]:
    info = bpf_prog_get_info(fd)
    if int(info.nr_map_ids) <= 0:
        return info, []

    count = int(info.nr_map_ids)
    map_ids_buffer = (ctypes.c_uint32 * count)()
    second_info = BpfProgInfo()
    second_info.nr_map_ids = count
    second_info.map_ids = ctypes.addressof(map_ids_buffer)
    _bpf_obj_get_info_by_fd(fd, second_info)
    return second_info, [int(map_ids_buffer[index]) for index in range(int(second_info.nr_map_ids))]


def bpf_map_get_info(fd: int) -> BpfMapInfo:
    info = BpfMapInfo()
    _bpf_obj_get_info_by_fd(fd, info)
    return info


def bpf_map_lookup_elem(fd: int, key: bytes, value_size: int) -> bytes:
    key_buffer = (ctypes.c_ubyte * len(key)).from_buffer_copy(key)
    value_buffer = (ctypes.c_ubyte * int(value_size))()
    attr = AttrMapElem()
    attr.map_fd = int(fd)
    attr.key = ctypes.addressof(key_buffer)
    attr.value = ctypes.addressof(value_buffer)
    attr.flags = 0
    _sys_bpf(BPF_MAP_LOOKUP_ELEM, attr)
    return bytes(value_buffer)


def bpf_map_get_next_key(fd: int, current_key: bytes | None, key_size: int) -> bytes | None:
    current_buffer: ctypes.Array[ctypes.c_ubyte] | None = None
    next_buffer = (ctypes.c_ubyte * int(key_size))()
    attr = AttrMapGetNextKey()
    attr.map_fd = int(fd)
    if current_key is not None:
        current_buffer = (ctypes.c_ubyte * len(current_key)).from_buffer_copy(current_key)
        attr.key = ctypes.addressof(current_buffer)
    else:
        attr.key = 0
    attr.next_key = ctypes.addressof(next_buffer)
    try:
        _sys_bpf(BPF_MAP_GET_NEXT_KEY, attr)
    except OSError as exc:
        if exc.errno == errno.ENOENT:
            return None
        raise
    return bytes(next_buffer)


def iter_prog_ids() -> list[int]:
    program_ids: list[int] = []
    current = 0
    while True:
        try:
            current = bpf_prog_get_next_id(current)
        except OSError as exc:
            if exc.errno == errno.ENOENT:
                break
            raise
        program_ids.append(int(current))
    return program_ids


def array_entries(map_info: BpfMapInfo, fd: int) -> list[dict[str, str]]:
    entries: list[dict[str, str]] = []
    key_size = int(map_info.key_size)
    value_size = _lookup_value_size(map_info)
    for index in range(int(map_info.max_entries)):
        key = int(index).to_bytes(key_size, byteorder="little", signed=False)
        value = bpf_map_lookup_elem(fd, key, value_size)
        entries.append({"key_hex": key.hex(), "value_hex": value.hex()})
    return entries


def hash_entries(map_info: BpfMapInfo, fd: int) -> list[dict[str, str]]:
    entries: list[dict[str, str]] = []
    key_size = int(map_info.key_size)
    value_size = _lookup_value_size(map_info)
    current_key: bytes | None = None
    while True:
        next_key = bpf_map_get_next_key(fd, current_key, key_size)
        if next_key is None:
            break
        value = bpf_map_lookup_elem(fd, next_key, value_size)
        entries.append({"key_hex": next_key.hex(), "value_hex": value.hex()})
        current_key = next_key
    return entries


def capture_map_entries(map_info: BpfMapInfo, fd: int) -> tuple[list[dict[str, str]], str | None]:
    map_type = int(map_info.map_type)
    if map_type in ARRAY_MAP_TYPES:
        return array_entries(map_info, fd), None
    if map_type in HASH_MAP_TYPES:
        return hash_entries(map_info, fd), None
    return [], f"unsupported map type for dump: {_map_type_name(map_type)}"


def _normalize_spec_record(raw: Mapping[str, object]) -> ProgramSpec:
    prog_id = int(raw.get("prog_id", 0) or 0)
    repo = str(raw.get("repo", "live") or "live")
    object_name = str(raw.get("object", "unknown") or "unknown")
    program_name = str(raw.get("program", f"prog_{prog_id}") or f"prog_{prog_id}")
    qualified = raw.get("qualified_prog_name")
    qualified_name = None if qualified in (None, "") else str(qualified)
    if prog_id <= 0:
        raise ValueError(f"invalid program spec: {raw}")
    return ProgramSpec(
        prog_id=prog_id,
        repo=repo,
        object_name=object_name,
        program_name=program_name,
        qualified_prog_name=qualified_name,
    )


def load_program_specs(path: Path | None) -> dict[int, ProgramSpec] | None:
    if path is None:
        return None
    payload = json.loads(path.read_text())
    if not isinstance(payload, list):
        raise RuntimeError(f"program spec file must contain a JSON array: {path}")
    specs: dict[int, ProgramSpec] = {}
    for item in payload:
        if not isinstance(item, Mapping):
            raise RuntimeError(f"program spec entry is not a JSON object: {item!r}")
        spec = _normalize_spec_record(item)
        specs[spec.prog_id] = spec
    return specs


def _default_program_spec(prog_id: int, kernel_prog_name: str) -> ProgramSpec:
    base_name = kernel_prog_name or f"prog_{prog_id}"
    safe_name = _sanitize_segment(base_name)
    return ProgramSpec(
        prog_id=prog_id,
        repo="live",
        object_name="unknown",
        program_name=safe_name,
        qualified_prog_name=f"live/unknown:{base_name}",
    )


def _program_fixture_path(fixture_root: Path, spec: ProgramSpec) -> Path:
    return (
        fixture_root
        / _sanitize_segment(spec.repo)
        / _sanitize_segment(spec.object_name)
        / f"{_sanitize_segment(spec.program_name)}.json"
    )


def capture_program(prog_id: int, spec: ProgramSpec, *, captured_from: str, fixture_root: Path) -> dict[str, object]:
    prog_fd = bpf_prog_get_fd_by_id(prog_id)
    map_ids: list[int] = []
    try:
        prog_info, map_ids = bpf_prog_get_map_ids(prog_fd)
        kernel_prog_name = _decode_name(prog_info.name)
        qualified_prog_name = spec.qualified_prog_name or f"{spec.repo}/{spec.object_name}:{spec.program_name}"
        fixture_path = _program_fixture_path(fixture_root, spec)
        maps_payload: list[dict[str, object]] = []
        map_errors: list[str] = []
        for map_id in map_ids:
            map_fd = bpf_map_get_fd_by_id(map_id)
            try:
                map_info = bpf_map_get_info(map_fd)
                try:
                    entries, capture_error = capture_map_entries(map_info, map_fd)
                except Exception as exc:
                    entries = []
                    capture_error = str(exc)
                map_record: dict[str, object] = {
                    "map_id": int(map_id),
                    "map_name": _decode_name(map_info.name),
                    "map_type": _map_type_name(int(map_info.map_type)),
                    "key_size": int(map_info.key_size),
                    "value_size": int(map_info.value_size),
                    "max_entries": int(map_info.max_entries),
                    "entries": entries,
                }
                if capture_error is not None:
                    map_record["capture_error"] = capture_error
                    map_errors.append(f"map {map_id}: {capture_error}")
                maps_payload.append(map_record)
            finally:
                os.close(map_fd)

        fixture_payload = {
            "prog_id": int(prog_id),
            "prog_name": qualified_prog_name,
            "kernel_prog_name": kernel_prog_name,
            "captured_from": captured_from,
            "timestamp": datetime.now(timezone.utc).isoformat(),
            "maps": maps_payload,
        }
        write_json(fixture_path, fixture_payload)
        return {
            "prog_id": int(prog_id),
            "kernel_prog_name": kernel_prog_name,
            "prog_name": qualified_prog_name,
            "fixture_path": str(fixture_path.resolve()),
            "map_count": len(maps_payload),
            "map_errors": map_errors,
        }
    finally:
        os.close(prog_fd)


def capture_all_programs(
    *,
    captured_from: str,
    fixture_root: Path,
    program_specs: Mapping[int, ProgramSpec] | None,
) -> dict[str, object]:
    programs_seen = 0
    programs_selected = 0
    programs_written = 0
    results: list[dict[str, object]] = []
    skipped_programs: list[dict[str, object]] = []
    errors: list[dict[str, object]] = []

    for prog_id in iter_prog_ids():
        programs_seen += 1
        if program_specs is not None:
            spec = program_specs.get(prog_id)
            if spec is None:
                skipped_programs.append({"prog_id": int(prog_id), "reason": "not requested by program_specs"})
                continue
        else:
            prog_fd = bpf_prog_get_fd_by_id(prog_id)
            try:
                prog_info = bpf_prog_get_info(prog_fd)
                kernel_prog_name = _decode_name(prog_info.name)
            finally:
                os.close(prog_fd)
            spec = _default_program_spec(prog_id, kernel_prog_name)

        programs_selected += 1
        try:
            result = capture_program(prog_id, spec, captured_from=captured_from, fixture_root=fixture_root)
        except Exception as exc:
            errors.append({"prog_id": int(prog_id), "error": str(exc)})
            continue
        programs_written += 1
        results.append(result)

    requested_program_ids = sorted(int(prog_id) for prog_id in (program_specs or {}))
    seen_program_ids = {int(item["prog_id"]) for item in results}
    error_program_ids = {int(item["prog_id"]) for item in errors if "prog_id" in item}
    missing_requested = [
        {"prog_id": prog_id, "reason": "requested program ID was not found among live programs"}
        for prog_id in requested_program_ids
        if prog_id not in seen_program_ids and prog_id not in error_program_ids
    ]
    skipped_programs.extend(missing_requested)

    return {
        "generated_at": datetime.now(timezone.utc).isoformat(),
        "captured_from": captured_from,
        "fixture_root": str(fixture_root.resolve()),
        "programs_seen": programs_seen,
        "programs_selected": programs_selected,
        "programs_written": programs_written,
        "programs": results,
        "skipped_programs": skipped_programs,
        "errors": errors,
    }


def build_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(description="Capture live BPF map state into per-program corpus fixtures.")
    parser.add_argument("--captured-from", required=True, help="Provenance label such as e2e/tracee.")
    parser.add_argument(
        "--fixture-root",
        default=str(ROOT_DIR / "corpus" / "fixtures"),
        help="Root directory where per-program fixtures will be written.",
    )
    parser.add_argument(
        "--program-specs",
        help="Optional JSON array of per-program output specs; when set, only those program IDs are captured.",
    )
    parser.add_argument(
        "--manifest-json",
        help="Optional path to also write the summary manifest as JSON.",
    )
    return parser


def main(argv: Sequence[str] | None = None) -> int:
    parser = build_parser()
    args = parser.parse_args(argv)

    fixture_root = Path(args.fixture_root).resolve()
    fixture_root.mkdir(parents=True, exist_ok=True)
    program_specs = load_program_specs(Path(args.program_specs).resolve() if args.program_specs else None)
    manifest = capture_all_programs(
        captured_from=str(args.captured_from),
        fixture_root=fixture_root,
        program_specs=program_specs,
    )
    if args.manifest_json:
        write_json(Path(args.manifest_json).resolve(), manifest)
    json.dump(manifest, sys.stdout, indent=2, sort_keys=True)
    sys.stdout.write("\n")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
