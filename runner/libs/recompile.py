from __future__ import annotations

import json
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


def _scanner_counts(stdout: str) -> dict[str, int]:
    counts = {
        "total_sites": 0,
        "cmov_sites": 0,
        "wide_sites": 0,
        "rotate_sites": 0,
        "lea_sites": 0,
        "bitfield_sites": 0,
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
        counts["endian_sites"] = int(summary.get("endian_sites", 0) or 0)
        counts["branch_flip_sites"] = int(summary.get("branch_flip_sites", 0) or 0)
        if counts["total_sites"] == 0:
            counts["total_sites"] = (
                counts["cmov_sites"]
                + counts["wide_sites"]
                + counts["rotate_sites"]
                + counts["lea_sites"]
                + counts["bitfield_sites"]
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
            + counts["endian_sites"]
            + counts["branch_flip_sites"]
        )
    return counts


def _counts_from_family_counts(family_counts: Mapping[str, Any] | None) -> dict[str, int]:
    raw = family_counts or {}
    counts = {
        "total_sites": 0,
        "cmov_sites": int(raw.get("cmov", 0) or 0),
        "wide_sites": int(raw.get("wide", 0) or 0),
        "rotate_sites": int(raw.get("rotate", 0) or 0),
        "lea_sites": int(raw.get("lea", 0) or 0),
        "bitfield_sites": int(raw.get("extract", 0) or 0),
        "endian_sites": int(raw.get("endian", 0) or 0),
        "branch_flip_sites": int(raw.get("branch-flip", 0) or 0),
    }
    counts["total_sites"] = (
        counts["cmov_sites"]
        + counts["wide_sites"]
        + counts["rotate_sites"]
        + counts["lea_sites"]
        + counts["bitfield_sites"]
        + counts["endian_sites"]
        + counts["branch_flip_sites"]
    )
    return counts


def _write_live_remapped_policy(
    policy_path: str,
    live_manifest: Mapping[str, Any],
    *,
    program_name: str,
) -> tuple[Path, dict[str, Any]]:
    from .policy import remap_policy_v3_to_live

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


def _normalize_policy_path(value: Path | str | None) -> str | None:
    if value is None:
        return None
    return str(Path(value).resolve())


@lru_cache(maxsize=None)
def _policy_program_name(policy_path: str) -> str | None:
    from .policy import parse_policy_v3

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
    from .policy import resolve_policy_path

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


def _enumerate_scan_one(scanner_binary: str | Path, prog_id: int) -> dict[str, Any]:
    """Use scanner enumerate --prog-id <id> --json to scan a single live program.

    Returns the raw parsed JSON record from the enumerate output array, or raises
    RuntimeError on failure.  The enumerate subcommand opens the fd itself (via
    BPF_PROG_GET_FD_BY_ID) so no caller-held fd is needed.
    """
    completed = run_command(
        [
            str(scanner_binary),
            "enumerate",
            "--prog-id",
            str(prog_id),
            "--all",
            "--json",
        ],
        check=False,
        timeout=60,
    )
    if completed.returncode != 0:
        detail = (completed.stderr or completed.stdout or "").strip()
        raise RuntimeError(detail or f"enumerate --prog-id {prog_id} failed")
    stdout = (completed.stdout or "").strip()
    # Output is a JSON array: [{...}]
    try:
        payload = json.loads(stdout)
    except json.JSONDecodeError as exc:
        raise RuntimeError(f"enumerate --prog-id {prog_id} returned non-JSON: {stdout[:200]}") from exc
    if not isinstance(payload, list):
        raise RuntimeError(f"enumerate --prog-id {prog_id} returned non-list JSON: {type(payload)}")
    if not payload:
        raise RuntimeError(f"enumerate --prog-id {prog_id} returned empty list")
    return dict(payload[0])


def _enumerate_apply_one(
    scanner_binary: str | Path,
    prog_id: int,
    *,
    policy_dir: str | None = None,
) -> dict[str, Any]:
    """Use scanner enumerate --prog-id <id> --recompile [--policy-dir <dir>] for one program.

    Returns the raw parsed JSON record from the enumerate output array, or raises
    RuntimeError on failure.
    """
    cmd = [
        str(scanner_binary),
        "enumerate",
        "--prog-id",
        str(prog_id),
        "--all",
        "--recompile",
        "--json",
    ]
    if policy_dir is not None:
        cmd.extend(["--policy-dir", str(policy_dir)])
    completed = run_command(cmd, check=False, timeout=60)
    if completed.returncode != 0:
        detail = (completed.stderr or completed.stdout or "").strip()
        raise RuntimeError(detail or f"enumerate --prog-id {prog_id} --recompile failed")
    stdout = (completed.stdout or "").strip()
    try:
        payload = json.loads(stdout)
    except json.JSONDecodeError as exc:
        raise RuntimeError(
            f"enumerate --prog-id {prog_id} --recompile returned non-JSON: {stdout[:200]}"
        ) from exc
    if not isinstance(payload, list):
        raise RuntimeError(
            f"enumerate --prog-id {prog_id} --recompile returned non-list: {type(payload)}"
        )
    if not payload:
        raise RuntimeError(f"enumerate --prog-id {prog_id} --recompile returned empty list")
    return dict(payload[0])


def _scan_counts_from_enumerate(record: Mapping[str, Any]) -> dict[str, int]:
    """Convert an enumerate JSON record's site fields into the _scanner_counts shape.

    When the enumerate record includes a per-site "sites" array (new format),
    per-family counts are derived from it.  Otherwise, only total_sites is
    populated (legacy format without per-site detail).
    """
    total = int(record.get("total_sites", 0) or 0)
    counts: dict[str, int] = {
        "total_sites": total,
        "cmov_sites": 0,
        "wide_sites": 0,
        "rotate_sites": 0,
        "lea_sites": 0,
        "bitfield_sites": 0,
        "endian_sites": 0,
        "branch_flip_sites": 0,
    }
    sites = record.get("sites")
    if isinstance(sites, list):
        _family_to_count_key = {
            "cmov": "cmov_sites",
            "wide": "wide_sites",
            "rotate": "rotate_sites",
            "lea": "lea_sites",
            "extract": "bitfield_sites",
            "endian": "endian_sites",
            "branch-flip": "branch_flip_sites",
        }
        for site in sites:
            if not isinstance(site, Mapping):
                continue
            family = str(site.get("family", "")).strip()
            key = _family_to_count_key.get(family)
            if key:
                counts[key] += 1
    return counts


def scan_programs(
    prog_ids: list[int] | tuple[int, ...],
    scanner_binary: str | Path,
    *,
    prog_fds: dict[int, int] | None = None,
) -> dict[int, dict[str, object]]:
    results: dict[int, dict[str, object]] = {}
    stats = sample_bpf_stats(list(prog_ids), prog_fds=prog_fds)
    for prog_id in prog_ids:
        program_name = str(stats.get(int(prog_id), {}).get("name", f"id-{prog_id}"))
        try:
            record = _enumerate_scan_one(scanner_binary, int(prog_id))
            enum_name = str(record.get("name") or "").strip()
            if enum_name:
                program_name = enum_name
            results[int(prog_id)] = {
                "program_name": program_name,
                "sites": _scan_counts_from_enumerate(record),
                "enumerate_record": record,
                "error": str(record.get("error") or ""),
                "stdout_tail": "",
                "stderr_tail": "",
            }
        except Exception as exc:
            results[int(prog_id)] = {
                "program_name": program_name,
                "sites": _scan_counts_from_enumerate({}),
                "error": str(exc),
                "stdout_tail": "",
                "stderr_tail": "",
            }
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
        results[int(prog_id)] = _apply_one_enumerate(
            scanner_binary,
            int(prog_id),
            program_name=program_name,
            selected_policy=selected_policy,
            blind_apply=blind_apply,
        )
    return results


def _apply_one_enumerate(
    scanner_binary: str | Path,
    prog_id: int,
    *,
    program_name: str,
    selected_policy: str | None,
    blind_apply: bool,
) -> dict[str, object]:
    """Apply recompile using enumerate --prog-id --recompile."""
    policy_mode = "policy-file" if selected_policy else "blind-apply-v5"
    scan_record: dict[str, Any] | None = None
    live_manifest: dict[str, Any] | None = None
    remap_summary: dict[str, Any] | None = None
    temp_policy_dir: tempfile.TemporaryDirectory | None = None  # type: ignore[type-arg]
    policy_dir_path: str | None = None
    try:
        if selected_policy is not None:
            scan_record = _enumerate_scan_one(scanner_binary, prog_id)
            enum_name = str(scan_record.get("name") or "").strip()
            if enum_name:
                program_name = enum_name
            enum_sites = scan_record.get("sites")
            if not isinstance(enum_sites, list):
                raise RuntimeError(
                    f"enumerate --prog-id {prog_id} --json did not return per-site data"
                )
            live_manifest = {"sites": enum_sites}
            temp_dir_obj = tempfile.TemporaryDirectory(prefix="e2e-enumerate-policy-dir-")
            temp_policy_dir = temp_dir_obj
            policy_dir_path = temp_dir_obj.name
            _temp_path, remap_summary = _write_live_remapped_policy(
                selected_policy,
                live_manifest,
                program_name=program_name,
            )
            dest_path = Path(policy_dir_path) / f"{program_name}.policy.yaml"
            try:
                import shutil as _shutil

                _shutil.move(str(_temp_path), str(dest_path))
            except OSError:
                try:
                    _temp_path.unlink(missing_ok=True)
                except OSError:
                    pass
                raise
            if int(remap_summary.get("remapped_sites", 0) or 0) <= 0:
                return {
                    "program_name": program_name,
                    "counts": _counts_from_family_counts(remap_summary.get("remapped_family_counts")),
                    "applied": False,
                    "noop": True,
                    "policy_file": selected_policy,
                    "policy_remap": remap_summary,
                    "policy_mode": policy_mode,
                    "error": "",
                    "stdout_tail": (
                        "Accepted 0 v5 site(s)\n"
                        "Skipped BPF_PROG_JIT_RECOMPILE because policy filtering left no live sites.\n"
                    ),
                    "stderr_tail": "",
                }
        record = _enumerate_apply_one(
            scanner_binary,
            prog_id,
            policy_dir=policy_dir_path,
        )
        enum_name = str(record.get("name") or "").strip()
        if enum_name:
            program_name = enum_name
        record_error = str(record.get("error") or "")
        applied = bool(record.get("recompile_ok", False))
        total_sites = int(record.get("total_sites", 0) or 0)
        return {
            "program_name": program_name,
            "counts": _scan_counts_from_enumerate(record),
            "enumerate_record": record,
            "applied": applied,
            "policy_file": selected_policy,
            "policy_remap": remap_summary,
            "policy_mode": policy_mode,
            "error": record_error,
            "stdout_tail": (
                f"enumerate --prog-id {prog_id} --recompile: "
                f"total_sites={total_sites} applied={applied}"
            ),
            "stderr_tail": "",
        }
    except Exception as exc:
        if remap_summary is not None:
            failure_counts = _counts_from_family_counts(remap_summary.get("remapped_family_counts"))
        elif scan_record is not None:
            failure_counts = _scan_counts_from_enumerate(scan_record)
        else:
            failure_counts = _scanner_counts("")
        return {
            "program_name": program_name,
            "counts": failure_counts,
            "applied": False,
            "policy_file": selected_policy,
            "policy_remap": remap_summary,
            "policy_mode": policy_mode,
            "error": str(exc),
            "stdout_tail": "",
            "stderr_tail": "",
        }
    finally:
        if temp_policy_dir is not None:
            try:
                temp_policy_dir.cleanup()
            except Exception:
                pass


__all__ = [
    "PolicyTarget",
    "apply_recompile",
    "resolve_policy_files",
    "scan_programs",
]
