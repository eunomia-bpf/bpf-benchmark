from __future__ import annotations

import ctypes
import ctypes.util
import os
import time
from contextlib import contextmanager
from functools import lru_cache
from pathlib import Path

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
    except AttributeError:
        pass
    try:
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
def enable_bpf_stats() -> object:
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


def sample_bpf_stats(
    prog_ids: list[int] | tuple[int, ...],
    *,
    prog_fds: dict[int, int] | None = None,
) -> dict[int, dict[str, object]]:
    if not prog_ids:
        return {}
    wanted = {int(prog_id) for prog_id in prog_ids}
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
        stats[prog_id] = {
            "id": prog_id,
            "name": str(record.get("name", "")),
            "type": str(record.get("type", "")),
            "run_cnt": int(record.get("run_cnt", 0) or 0),
            "run_time_ns": int(record.get("run_time_ns", 0) or 0),
            "bytes_jited": int(record.get("bytes_jited", 0) or 0),
            "bytes_xlated": int(record.get("bytes_xlated", 0) or 0),
        }
    for prog_id in wanted:
        fd = None
        if prog_fds and int(prog_id) in prog_fds:
            fd = os.dup(int(prog_fds[int(prog_id)]))
        else:
            fd = _prog_fd_by_id(int(prog_id))
        if fd is None:
            continue
        try:
            info = _prog_info_from_fd(fd)
            if info is None:
                continue
            entry = stats.setdefault(
                int(prog_id),
                {
                    "id": int(prog_id),
                    "name": "",
                    "type": "",
                    "run_cnt": 0,
                    "run_time_ns": 0,
                    "bytes_jited": 0,
                    "bytes_xlated": 0,
                },
            )
            entry["id"] = int(info.id)
            entry["name"] = bytes(info.name).split(b"\0", 1)[0].decode("utf-8", "replace")
            entry["run_cnt"] = int(info.run_cnt)
            entry["run_time_ns"] = int(info.run_time_ns)
            entry["bytes_jited"] = int(info.jited_prog_len)
            entry["bytes_xlated"] = int(info.xlated_prog_len)
        finally:
            os.close(fd)
    return stats


def _read_pid_ticks(pid: int) -> tuple[int, int] | None:
    try:
        fields = Path(f"/proc/{pid}/stat").read_text().split()
    except OSError:
        return None
    if len(fields) < 15:
        return None
    return int(fields[13]), int(fields[14])


def sample_cpu_usage(pids: list[int] | tuple[int, ...], duration_s: int | float) -> dict[int, dict[str, float]]:
    clock_ticks = float(os.sysconf(os.sysconf_names["SC_CLK_TCK"]))
    requested = [int(pid) for pid in pids if int(pid) > 0]
    if not requested:
        return {}
    before = {pid: _read_pid_ticks(pid) for pid in requested}
    start = time.monotonic()
    time.sleep(max(0.0, float(duration_s)))
    elapsed = time.monotonic() - start
    if elapsed <= 0:
        return {}

    samples: dict[int, dict[str, float]] = {}
    for pid in requested:
        start_ticks = before.get(pid)
        end_ticks = _read_pid_ticks(pid)
        if start_ticks is None or end_ticks is None:
            continue
        user_delta = max(0, end_ticks[0] - start_ticks[0])
        sys_delta = max(0, end_ticks[1] - start_ticks[1])
        samples[pid] = {
            "user_pct": (user_delta / clock_ticks) * 100.0 / elapsed,
            "sys_pct": (sys_delta / clock_ticks) * 100.0 / elapsed,
        }
    return samples


def _read_total_cpu() -> tuple[int, int] | None:
    try:
        line = Path("/proc/stat").read_text().splitlines()[0]
    except (IndexError, OSError):
        return None
    parts = line.split()
    if not parts or parts[0] != "cpu":
        return None
    values = [int(value) for value in parts[1:]]
    idle = values[3] + (values[4] if len(values) > 4 else 0)
    total = sum(values)
    return idle, total


def sample_total_cpu_usage(duration_s: int | float) -> dict[str, float]:
    before = _read_total_cpu()
    time.sleep(max(0.0, float(duration_s)))
    after = _read_total_cpu()
    if before is None or after is None:
        return {}
    idle_delta = max(0, after[0] - before[0])
    total_delta = max(1, after[1] - before[1])
    return {"busy_pct": (1.0 - (idle_delta / total_delta)) * 100.0}


def compute_delta(
    before: dict[int, dict[str, object]],
    after: dict[int, dict[str, object]],
) -> dict[str, object]:
    program_deltas: dict[int, dict[str, object]] = {}
    total_run_cnt = 0
    total_run_time_ns = 0
    for prog_id in sorted(set(before) | set(after)):
        previous = before.get(prog_id, {})
        current = after.get(prog_id, {})
        run_cnt_delta = int(current.get("run_cnt", 0) or 0) - int(previous.get("run_cnt", 0) or 0)
        run_time_delta = int(current.get("run_time_ns", 0) or 0) - int(previous.get("run_time_ns", 0) or 0)
        total_run_cnt += max(0, run_cnt_delta)
        total_run_time_ns += max(0, run_time_delta)
        program_deltas[prog_id] = {
            "id": prog_id,
            "name": str(current.get("name") or previous.get("name") or f"id-{prog_id}"),
            "type": str(current.get("type") or previous.get("type") or ""),
            "run_cnt_delta": run_cnt_delta,
            "run_time_ns_delta": run_time_delta,
            "avg_ns_per_run": (run_time_delta / run_cnt_delta) if run_cnt_delta > 0 else None,
            "bytes_jited": int(current.get("bytes_jited", 0) or previous.get("bytes_jited", 0) or 0),
            "bytes_xlated": int(current.get("bytes_xlated", 0) or previous.get("bytes_xlated", 0) or 0),
        }
    return {
        "programs": program_deltas,
        "summary": {
            "total_events": total_run_cnt,
            "total_run_time_ns": total_run_time_ns,
            "avg_ns_per_run": (total_run_time_ns / total_run_cnt) if total_run_cnt > 0 else None,
            "active_programs": sum(1 for record in program_deltas.values() if int(record["run_cnt_delta"]) > 0),
        },
    }


__all__ = [
    "compute_delta",
    "enable_bpf_stats",
    "sample_bpf_stats",
    "sample_cpu_usage",
    "sample_total_cpu_usage",
]
