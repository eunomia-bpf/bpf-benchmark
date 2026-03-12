from __future__ import annotations

import ctypes
import ctypes.util
import json
import os
import re
import tempfile
from dataclasses import dataclass
from functools import lru_cache
from pathlib import Path
from typing import Any, Iterable, Mapping

from . import run_command
from .metrics import sample_bpf_stats


@dataclass(frozen=True, slots=True)
class PolicyTarget:
    prog_id: int
    object_path: Path | str | None = None
    program_name: str | None = None
    policy_file: Path | str | None = None


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
        "bitfield_sites": 0,
        "zero_ext_sites": 0,
        "endian_sites": 0,
        "branch_flip_sites": 0,
    }
    payload = None
    stripped_stdout = stdout.strip()
    if stripped_stdout.startswith("{"):
        try:
            candidate = json.loads(stripped_stdout)
        except json.JSONDecodeError:
            candidate = None
        if isinstance(candidate, dict):
            payload = candidate
    for line in reversed(stdout.splitlines()):
        if payload is not None:
            break
        text = line.strip()
        if not text.startswith("{"):
            continue
        try:
            candidate = json.loads(text)
        except json.JSONDecodeError:
            continue
        if isinstance(candidate, dict):
            payload = candidate
            break
    if payload is not None:
        summary = payload.get("summary") if isinstance(payload.get("summary"), dict) else payload
        counts["total_sites"] = int(summary.get("total_sites", 0) or 0)
        counts["cmov_sites"] = int(summary.get("cmov_sites", 0) or 0)
        counts["wide_sites"] = int(summary.get("wide_sites", 0) or 0)
        counts["rotate_sites"] = int(summary.get("rotate_sites", 0) or 0)
        counts["lea_sites"] = int(summary.get("lea_sites", 0) or 0)
        counts["bitfield_sites"] = int(
            summary.get("bitfield_sites", summary.get("extract_sites", 0)) or 0
        )
        counts["zero_ext_sites"] = int(summary.get("zero_ext_sites", 0) or 0)
        counts["endian_sites"] = int(summary.get("endian_sites", 0) or 0)
        counts["branch_flip_sites"] = int(summary.get("branch_flip_sites", 0) or 0)
        if counts["total_sites"] == 0:
            counts["total_sites"] = (
                counts["cmov_sites"]
                + counts["wide_sites"]
                + counts["rotate_sites"]
                + counts["lea_sites"]
                + counts["bitfield_sites"]
                + counts["zero_ext_sites"]
                + counts["endian_sites"]
                + counts["branch_flip_sites"]
            )
        return counts
    patterns = {
        "total_sites": r"Accepted\s+(\d+)\s+v5 site",
        "cmov_sites": r"cmov:\s+(\d+)",
        "wide_sites": r"wide:\s+(\d+)",
        "rotate_sites": r"rotate:\s+(\d+)",
        "lea_sites": r"lea:\s+(\d+)",
        "bitfield_sites": r"extract:\s*(\d+)",
        "zero_ext_sites": r"zeroext:\s*(\d+)",
        "endian_sites": r"endian:\s*(\d+)",
        "branch_flip_sites": r"bflip:\s*(\d+)",
    }
    for field, pattern in patterns.items():
        match = re.search(pattern, stdout)
        if match:
            counts[field] = int(match.group(1))
    if counts["total_sites"] == 0:
        counts["total_sites"] = (
            counts["cmov_sites"]
            + counts["wide_sites"]
            + counts["rotate_sites"]
            + counts["lea_sites"]
            + counts["bitfield_sites"]
            + counts["zero_ext_sites"]
            + counts["endian_sites"]
            + counts["branch_flip_sites"]
        )
    return counts


def _scanner_json_payload(stdout: str) -> dict[str, Any] | None:
    payload = None
    stripped_stdout = stdout.strip()
    if stripped_stdout.startswith("{"):
        try:
            candidate = json.loads(stripped_stdout)
        except json.JSONDecodeError:
            candidate = None
        if isinstance(candidate, dict):
            payload = candidate
    for line in reversed(stdout.splitlines()):
        if payload is not None:
            break
        text = line.strip()
        if not text.startswith("{"):
            continue
        try:
            candidate = json.loads(text)
        except json.JSONDecodeError:
            continue
        if isinstance(candidate, dict):
            payload = candidate
            break
    return payload


def _scan_live_manifest(scanner_binary: str | Path, fd: int, program_name: str) -> dict[str, Any]:
    completed = run_command(
        [
            str(scanner_binary),
            "scan",
            "--prog-fd",
            str(fd),
            "--all",
            "--json",
            "--v5",
            "--program-name",
            program_name,
        ],
        check=False,
        timeout=60,
        pass_fds=(fd,),
    )
    if completed.returncode != 0:
        detail = (completed.stderr or completed.stdout or "").strip()
        raise RuntimeError(detail or "scanner scan failed")
    payload = _scanner_json_payload(completed.stdout or "")
    if payload is None:
        raise RuntimeError("scanner scan did not return a JSON manifest")
    return payload


def _write_live_remapped_policy(
    policy_path: str,
    live_manifest: Mapping[str, Any],
    *,
    program_name: str,
) -> tuple[Path, dict[str, Any]]:
    from corpus.policy_utils import remap_policy_v3_to_live

    text, summary = remap_policy_v3_to_live(
        Path(policy_path),
        live_manifest,
        program_name=program_name,
        comments=[f"Source policy: {Path(policy_path).resolve()}"],
    )
    with tempfile.NamedTemporaryFile(
        mode="w",
        encoding="utf-8",
        prefix="e2e-live-policy-",
        suffix=".policy.yaml",
        delete=False,
    ) as handle:
        handle.write(text)
        temp_path = Path(handle.name)
    return temp_path, {
        "explicit_sites": summary.explicit_sites,
        "remapped_sites": summary.remapped_sites,
        "dropped_sites": summary.dropped_sites,
        "live_total_sites": summary.live_total_sites,
        "policy_family_counts": summary.policy_family_counts,
        "live_family_counts": summary.live_family_counts,
        "remapped_family_counts": summary.remapped_family_counts,
        "dropped_family_counts": summary.dropped_family_counts,
    }


def _take_prog_fd(prog_id: int, prog_fds: dict[int, int] | None = None) -> int:
    if prog_fds and int(prog_id) in prog_fds:
        return os.dup(int(prog_fds[int(prog_id)]))
    return _prog_fd_by_id(int(prog_id))


def _normalize_policy_path(value: Path | str | None) -> str | None:
    if value is None:
        return None
    return str(Path(value).resolve())


@lru_cache(maxsize=None)
def _policy_program_name(policy_path: str) -> str | None:
    from corpus.policy_utils import parse_policy_v3

    try:
        document = parse_policy_v3(Path(policy_path))
    except Exception:
        return None
    if not document.program:
        return None
    return str(document.program)


def _requested_program_name(stats_name: str, policy_path: str | None) -> str:
    if policy_path is None:
        return stats_name
    return _policy_program_name(policy_path) or stats_name


def resolve_policy_files(targets: Iterable[PolicyTarget]) -> dict[int, str]:
    from corpus.policy_utils import resolve_policy_path

    resolved: dict[int, str] = {}
    for target in targets:
        prog_id = int(target.prog_id)
        explicit_policy = _normalize_policy_path(target.policy_file)
        if explicit_policy is not None:
            resolved[prog_id] = explicit_policy
            continue
        if target.object_path is None:
            continue
        policy_path = resolve_policy_path(
            Path(target.object_path).resolve(),
            program_name=target.program_name,
        )
        if policy_path is not None:
            resolved[prog_id] = str(policy_path.resolve())
    return resolved


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
                    "--json",
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
    policy_file: str | Path | None = None,
    policy_files: Mapping[int, str | Path] | None = None,
    blind_apply: bool = False,
) -> dict[int, dict[str, object]]:
    results: dict[int, dict[str, object]] = {}
    stats = sample_bpf_stats(list(prog_ids), prog_fds=prog_fds)
    default_policy = _normalize_policy_path(policy_file)
    normalized_policy_files = {
        int(prog_id): normalized
        for prog_id, raw_path in (policy_files or {}).items()
        if (normalized := _normalize_policy_path(raw_path)) is not None
    }
    if blind_apply and (default_policy is not None or normalized_policy_files):
        raise ValueError("blind_apply cannot be combined with policy_file or policy_files")
    for prog_id in prog_ids:
        selected_policy = normalized_policy_files.get(int(prog_id), default_policy)
        stats_name = str(stats.get(int(prog_id), {}).get("name", f"id-{prog_id}"))
        program_name = _requested_program_name(stats_name, selected_policy)
        if selected_policy is None and not blind_apply:
            results[int(prog_id)] = {
                "program_name": program_name,
                "counts": _scanner_counts(""),
                "applied": False,
                "policy_file": None,
                "policy_mode": "stock",
                "error": "",
                "stdout_tail": "",
                "stderr_tail": "",
            }
            continue
        try:
            fd = _take_prog_fd(int(prog_id), prog_fds)
        except OSError as exc:
            results[int(prog_id)] = {
                "program_name": program_name,
                "counts": _scanner_counts(""),
                "applied": False,
                "policy_file": selected_policy,
                "policy_mode": "policy-file" if selected_policy else "blind-apply-v5",
                "error": str(exc),
                "stdout_tail": "",
                "stderr_tail": "",
            }
            continue
        live_manifest: dict[str, Any] | None = None
        remap_summary: dict[str, Any] | None = None
        effective_policy = selected_policy
        temp_policy_path: Path | None = None
        try:
            os.set_inheritable(fd, True)
            if selected_policy is not None:
                live_manifest = _scan_live_manifest(scanner_binary, fd, program_name)
                temp_policy_path, remap_summary = _write_live_remapped_policy(
                    selected_policy,
                    live_manifest,
                    program_name=program_name,
                )
                effective_policy = str(temp_policy_path)
            command = [
                str(scanner_binary),
                "apply",
                "--prog-fd",
                str(fd),
                "--v5",
                "--program-name",
                program_name,
            ]
            if effective_policy is not None:
                command.extend(["--config", effective_policy])
            else:
                command.append("--all")
            completed = run_command(
                command,
                check=False,
                timeout=60,
                pass_fds=(fd,),
            )
            results[int(prog_id)] = {
                "program_name": program_name,
                "counts": _scanner_counts(completed.stdout or ""),
                "applied": completed.returncode == 0,
                "policy_file": selected_policy,
                "policy_remap": remap_summary,
                "policy_mode": "policy-file" if selected_policy else "blind-apply-v5",
                "error": "" if completed.returncode == 0 else (completed.stderr or completed.stdout).strip(),
                "stdout_tail": completed.stdout[-4000:] if completed.stdout else "",
                "stderr_tail": completed.stderr[-4000:] if completed.stderr else "",
            }
        except Exception as exc:
            fallback_counts = _scanner_counts(json.dumps(live_manifest)) if live_manifest else _scanner_counts("")
            results[int(prog_id)] = {
                "program_name": program_name,
                "counts": fallback_counts,
                "applied": False,
                "policy_file": selected_policy,
                "policy_remap": remap_summary,
                "policy_mode": "policy-file" if selected_policy else "blind-apply-v5",
                "error": str(exc),
                "stdout_tail": "",
                "stderr_tail": "",
            }
        finally:
            if temp_policy_path is not None:
                temp_policy_path.unlink(missing_ok=True)
            os.close(fd)
    return results


__all__ = [
    "PolicyTarget",
    "apply_recompile",
    "resolve_policy_files",
    "scan_programs",
]
