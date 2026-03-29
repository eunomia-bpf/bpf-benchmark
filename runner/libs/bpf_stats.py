from __future__ import annotations

import ctypes
import ctypes.util
import os
from contextlib import contextmanager
from functools import lru_cache
from typing import Any

from . import resolve_bpftool_binary, run_json_command


BPF_STATS_RUN_TIME = 0
BPF_TAG_SIZE = 8
BPF_OBJ_NAME_LEN = 16


class BpfProgInfo(ctypes.Structure):
    _fields_ = [
        ("type", ctypes.c_uint32),
        ("id", ctypes.c_uint32),
        ("tag", ctypes.c_ubyte * BPF_TAG_SIZE),
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
        ("gpl_compatible", ctypes.c_uint32, 1),
        ("_bitfield_pad", ctypes.c_uint32, 31),
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
    ]


@lru_cache(maxsize=1)
def _libbpf() -> ctypes.CDLL:
    path = ctypes.util.find_library("bpf") or "libbpf.so.1"
    lib = ctypes.CDLL(path, use_errno=True)
    lib.bpf_enable_stats.argtypes = [ctypes.c_int]
    lib.bpf_enable_stats.restype = ctypes.c_int
    try:
        lib.bpf_prog_get_fd_by_id.argtypes = [ctypes.c_uint32]
        lib.bpf_prog_get_fd_by_id.restype = ctypes.c_int
        lib.bpf_prog_get_info_by_fd.argtypes = [
            ctypes.c_int,
            ctypes.POINTER(BpfProgInfo),
            ctypes.POINTER(ctypes.c_uint32),
        ]
        lib.bpf_prog_get_info_by_fd.restype = ctypes.c_int
    except AttributeError:
        pass
    return lib


@contextmanager
def enable_bpf_stats() -> Any:
    fd = int(_libbpf().bpf_enable_stats(BPF_STATS_RUN_TIME))
    if fd < 0:
        err = ctypes.get_errno()
        raise RuntimeError(f"bpf_enable_stats failed: {os.strerror(err)} (errno={err})")
    try:
        yield {"fd": fd}
    finally:
        os.close(fd)


def _prog_fd_by_id(prog_id: int) -> int | None:
    try:
        fd = int(_libbpf().bpf_prog_get_fd_by_id(int(prog_id)))
    except AttributeError:
        return None
    if fd < 0:
        return None
    return fd


def _prog_info_from_fd(fd: int) -> BpfProgInfo | None:
    try:
        prog_get_info_by_fd = _libbpf().bpf_prog_get_info_by_fd
    except AttributeError:
        return None
    info = BpfProgInfo()
    info_len = ctypes.c_uint32(ctypes.sizeof(info))
    rc = prog_get_info_by_fd(fd, ctypes.byref(info), ctypes.byref(info_len))
    if rc != 0:
        return None
    return info


def read_program_stats(prog_ids: list[int] | tuple[int, ...]) -> dict[int, dict[str, object]]:
    wanted = {int(prog_id) for prog_id in prog_ids if int(prog_id) > 0}
    if not wanted:
        return {}

    payload = run_json_command([resolve_bpftool_binary(), "-j", "-p", "prog", "show"], timeout=30)
    if not isinstance(payload, list):
        raise RuntimeError("bpftool prog show returned unexpected payload")

    stats: dict[int, dict[str, object]] = {}
    for record in payload:
        if not isinstance(record, dict):
            continue
        prog_id = int(record.get("id", -1))
        if prog_id not in wanted:
            continue
        run_cnt = int(record.get("run_cnt", 0) or 0)
        run_time_ns = int(record.get("run_time_ns", 0) or 0)
        stats[prog_id] = {
            "id": prog_id,
            "name": str(record.get("name", "")),
            "type": str(record.get("type", "")),
            "run_cnt": run_cnt,
            "run_time_ns": run_time_ns,
            "exec_ns": (run_time_ns / run_cnt) if run_cnt > 0 else None,
            "bytes_jited": int(record.get("bytes_jited", 0) or 0),
            "bytes_xlated": int(record.get("bytes_xlated", 0) or 0),
        }

    unresolved: dict[int, str] = {}
    for prog_id in sorted(wanted):
        fd = _prog_fd_by_id(prog_id)
        if fd is None:
            if prog_id not in stats:
                unresolved[prog_id] = "libbpf could not resolve a program FD by id"
            continue
        try:
            info = _prog_info_from_fd(fd)
            if info is None:
                if prog_id not in stats:
                    unresolved[prog_id] = "libbpf could not read program info from the resolved FD"
                continue
            run_cnt = int(info.run_cnt)
            run_time_ns = int(info.run_time_ns)
            entry = stats.setdefault(
                prog_id,
                {
                    "id": prog_id,
                    "name": "",
                    "type": "",
                    "run_cnt": 0,
                    "run_time_ns": 0,
                    "exec_ns": None,
                    "bytes_jited": 0,
                    "bytes_xlated": 0,
                },
            )
            entry["id"] = int(info.id)
            entry["name"] = bytes(info.name).split(b"\0", 1)[0].decode("utf-8", "replace")
            entry["run_cnt"] = run_cnt
            entry["run_time_ns"] = run_time_ns
            entry["exec_ns"] = (run_time_ns / run_cnt) if run_cnt > 0 else None
            entry["bytes_jited"] = int(info.jited_prog_len)
            entry["bytes_xlated"] = int(info.xlated_prog_len)
        finally:
            os.close(fd)

    missing = sorted(prog_id for prog_id in wanted if prog_id not in stats)
    if missing:
        details = [
            f"{prog_id}: {unresolved.get(prog_id, 'program stats were missing from both bpftool and libbpf')}"
            for prog_id in missing
        ]
        raise RuntimeError(f"failed to read BPF stats for requested program ids: {'; '.join(details)}")

    return stats


__all__ = [
    "enable_bpf_stats",
    "read_program_stats",
]
