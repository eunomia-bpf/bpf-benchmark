from __future__ import annotations

import ctypes
import ctypes.util
import os
import re
from functools import lru_cache
from pathlib import Path

from . import run_command
from .metrics import sample_bpf_stats


@lru_cache(maxsize=1)
def _libbpf() -> ctypes.CDLL:
    path = ctypes.util.find_library("bpf") or "libbpf.so.1"
    lib = ctypes.CDLL(path, use_errno=True)
    lib.bpf_prog_get_fd_by_id.argtypes = [ctypes.c_uint32]
    lib.bpf_prog_get_fd_by_id.restype = ctypes.c_int
    return lib


def _prog_fd_by_id(prog_id: int) -> int:
    fd = int(_libbpf().bpf_prog_get_fd_by_id(int(prog_id)))
    if fd < 0:
        err = ctypes.get_errno()
        proc_fd = _dup_prog_fd_from_proc(prog_id)
        if proc_fd is not None:
            return proc_fd
        raise OSError(err, f"bpf_prog_get_fd_by_id({prog_id}) failed")
    return fd


def _dup_prog_fd_from_proc(prog_id: int) -> int | None:
    wanted = f"prog_id:\t{int(prog_id)}"
    alt_wanted = f"prog_id: {int(prog_id)}"
    for proc_dir in Path("/proc").iterdir():
        if not proc_dir.name.isdigit():
            continue
        fdinfo_dir = proc_dir / "fdinfo"
        if not fdinfo_dir.exists():
            continue
        for entry in fdinfo_dir.iterdir():
            try:
                text = entry.read_text()
            except OSError:
                continue
            if wanted not in text and alt_wanted not in text:
                continue
            fd_path = proc_dir / "fd" / entry.name
            try:
                return os.open(fd_path, os.O_RDONLY | os.O_CLOEXEC)
            except OSError:
                continue
    return None


def _scanner_counts(stdout: str) -> dict[str, int]:
    counts = {
        "total_sites": 0,
        "cmov_sites": 0,
        "wide_sites": 0,
        "rotate_sites": 0,
        "lea_sites": 0,
    }
    patterns = {
        "total_sites": r"Accepted\s+(\d+)\s+v5 site",
        "cmov_sites": r"cmov:\s+(\d+)",
        "wide_sites": r"wide:\s+(\d+)",
        "rotate_sites": r"rotate:\s+(\d+)",
        "lea_sites": r"lea:\s+(\d+)",
    }
    for field, pattern in patterns.items():
        match = re.search(pattern, stdout)
        if match:
            counts[field] = int(match.group(1))
    return counts


def _take_prog_fd(prog_id: int, prog_fds: dict[int, int] | None = None) -> int:
    if prog_fds and int(prog_id) in prog_fds:
        return os.dup(int(prog_fds[int(prog_id)]))
    return _prog_fd_by_id(int(prog_id))


def scan_programs(
    prog_ids: list[int] | tuple[int, ...],
    scanner_binary: str | Path,
    *,
    prog_fds: dict[int, int] | None = None,
) -> dict[int, dict[str, object]]:
    results: dict[int, dict[str, object]] = {}
    stats = sample_bpf_stats(list(prog_ids), prog_fds=prog_fds)
    for prog_id in prog_ids:
        try:
            fd = _take_prog_fd(int(prog_id), prog_fds)
        except OSError as exc:
            program_name = str(stats.get(int(prog_id), {}).get("name", f"id-{prog_id}"))
            results[int(prog_id)] = {
                "program_name": program_name,
                "sites": _scanner_counts(""),
                "error": str(exc),
                "stdout_tail": "",
                "stderr_tail": "",
            }
            continue
        try:
            os.set_inheritable(fd, True)
            program_name = str(stats.get(int(prog_id), {}).get("name", f"id-{prog_id}"))
            completed = run_command(
                [
                    str(scanner_binary),
                    "scan",
                    "--prog-fd",
                    str(fd),
                    "--all",
                    "--v5",
                    "--program-name",
                    program_name,
                ],
                check=False,
                timeout=60,
                pass_fds=(fd,),
            )
            results[int(prog_id)] = {
                "program_name": program_name,
                "sites": _scanner_counts(completed.stdout or ""),
                "error": "" if completed.returncode == 0 else (completed.stderr or completed.stdout).strip(),
                "stdout_tail": completed.stdout[-4000:] if completed.stdout else "",
                "stderr_tail": completed.stderr[-4000:] if completed.stderr else "",
            }
        finally:
            os.close(fd)
    return results


def apply_recompile(
    prog_ids: list[int] | tuple[int, ...],
    scanner_binary: str | Path,
    *,
    prog_fds: dict[int, int] | None = None,
) -> dict[int, dict[str, object]]:
    results: dict[int, dict[str, object]] = {}
    stats = sample_bpf_stats(list(prog_ids), prog_fds=prog_fds)
    for prog_id in prog_ids:
        try:
            fd = _take_prog_fd(int(prog_id), prog_fds)
        except OSError as exc:
            program_name = str(stats.get(int(prog_id), {}).get("name", f"id-{prog_id}"))
            results[int(prog_id)] = {
                "program_name": program_name,
                "counts": _scanner_counts(""),
                "applied": False,
                "error": str(exc),
                "stdout_tail": "",
                "stderr_tail": "",
            }
            continue
        try:
            os.set_inheritable(fd, True)
            program_name = str(stats.get(int(prog_id), {}).get("name", f"id-{prog_id}"))
            completed = run_command(
                [
                    str(scanner_binary),
                    "apply",
                    "--prog-fd",
                    str(fd),
                    "--all",
                    "--v5",
                    "--program-name",
                    program_name,
                ],
                check=False,
                timeout=60,
                pass_fds=(fd,),
            )
            results[int(prog_id)] = {
                "program_name": program_name,
                "counts": _scanner_counts(completed.stdout or ""),
                "applied": completed.returncode == 0,
                "error": "" if completed.returncode == 0 else (completed.stderr or completed.stdout).strip(),
                "stdout_tail": completed.stdout[-4000:] if completed.stdout else "",
                "stderr_tail": completed.stderr[-4000:] if completed.stderr else "",
            }
        finally:
            os.close(fd)
    return results


__all__ = [
    "apply_recompile",
    "scan_programs",
]
