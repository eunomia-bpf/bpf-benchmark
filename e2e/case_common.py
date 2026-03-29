"""Shared helpers for e2e benchmark cases.

Consolidates utility functions that were previously copy-pasted across
tracee, tetragon, bpftrace, katran, and scx case files.
"""
from __future__ import annotations

import copy
import json
import platform
import statistics
import sys
import tempfile
from dataclasses import dataclass, field
from datetime import datetime, timezone
from pathlib import Path
from typing import Callable, Mapping, Sequence

from runner.libs import (
    ROOT_DIR,
    run_command,
    write_json,
    write_text,
)

MAX_PERSISTED_STRING_CHARS = 16_384
_PENDING_KINSN_METADATA: list[dict[str, object]] = []
_KINSN_MODULE_ARCH_DIRS = {
    "x86_64": "x86",
    "aarch64": "arm64",
}


def reset_pending_result_metadata() -> None:
    _PENDING_KINSN_METADATA.clear()


def attach_pending_result_metadata(payload: dict[str, object]) -> dict[str, object]:
    if not _PENDING_KINSN_METADATA:
        return payload

    metadata = payload.get("metadata")
    metadata_payload = dict(metadata) if isinstance(metadata, Mapping) else {}

    existing_kinsn = metadata_payload.get("kinsn_modules")
    kinsn_payload = dict(existing_kinsn) if isinstance(existing_kinsn, Mapping) else {}

    lifecycle_runs: list[object] = []
    existing_runs = kinsn_payload.get("lifecycle_runs")
    if isinstance(existing_runs, list):
        lifecycle_runs.extend(copy.deepcopy(existing_runs))
    lifecycle_runs.extend(copy.deepcopy(_PENDING_KINSN_METADATA))

    kinsn_payload["count"] = len(lifecycle_runs)
    kinsn_payload["lifecycle_runs"] = lifecycle_runs
    metadata_payload["kinsn_modules"] = kinsn_payload
    payload["metadata"] = metadata_payload

    _PENDING_KINSN_METADATA.clear()
    return payload


def _append_pending_kinsn_metadata(record: Mapping[str, object]) -> None:
    payload = copy.deepcopy(dict(record))
    payload["lifecycle_index"] = len(_PENDING_KINSN_METADATA) + 1
    _PENDING_KINSN_METADATA.append(payload)


def _expected_kinsn_modules() -> list[str]:
    arch_dir = _KINSN_MODULE_ARCH_DIRS.get(platform.machine())
    if arch_dir is None:
        return []
    module_dir = ROOT_DIR / "module" / arch_dir
    if not module_dir.exists():
        return []
    return sorted(
        path.stem
        for path in module_dir.glob("bpf_*.ko")
        if path.is_file() and path.stem != "bpf_barrier"
    )


def _loaded_bpf_modules_from_lsmod() -> tuple[list[str], str] | None:
    completed = run_command(["lsmod"], timeout=10, check=False)
    if completed.returncode != 0:
        return None
    filtered_lines = [
        line.rstrip()
        for line in completed.stdout.splitlines()[1:]
        if line.startswith("bpf_")
    ]
    modules = sorted({line.split()[0] for line in filtered_lines if line.split()})
    return modules, "\n".join(filtered_lines)


def _loaded_bpf_modules_from_sysfs() -> tuple[list[str], str]:
    entries = sorted(path.name for path in Path("/sys/module").glob("bpf_*") if path.is_dir())
    return entries, "\n".join(entries)


def _capture_kinsn_module_snapshot(expected_modules: Sequence[str]) -> dict[str, object]:
    snapshot = _loaded_bpf_modules_from_lsmod()
    source = "lsmod"
    if snapshot is None:
        snapshot = _loaded_bpf_modules_from_sysfs()
        source = "sysfs"

    loaded_modules, raw_output = snapshot
    expected = sorted({str(name) for name in expected_modules if str(name).strip()})
    resident_expected = [name for name in expected if name in loaded_modules]
    missing_expected = [name for name in expected if name not in resident_expected]
    return {
        "captured_at": datetime.now(timezone.utc).isoformat(),
        "source": source,
        "raw_output": raw_output,
        "loaded_bpf_modules": loaded_modules,
        "expected_modules": expected,
        "resident_expected_modules": resident_expected,
        "missing_expected_modules": missing_expected,
    }


def _run_kinsn_module_loader(
    expected_modules: Sequence[str],
    *,
    before_snapshot: Mapping[str, object],
) -> dict[str, object]:
    script_path = ROOT_DIR / "module" / "load_all.sh"
    if not script_path.exists():
        return {
            "invoked_at": datetime.now(timezone.utc).isoformat(),
            "script_path": relpath(script_path),
            "status": "missing_script",
            "exit_code": None,
            "stdout": "",
            "stderr": "",
            "expected_modules": sorted({str(name) for name in expected_modules if str(name).strip()}),
            "loaded_modules": list(before_snapshot.get("resident_expected_modules") or []),
            "newly_loaded_modules": [],
            "failed_modules": list(before_snapshot.get("missing_expected_modules") or []),
            "snapshot_after": dict(before_snapshot),
        }

    completed = run_command([str(script_path)], timeout=120, check=False)
    after_snapshot = _capture_kinsn_module_snapshot(expected_modules)

    expected = list(after_snapshot.get("expected_modules") or [])
    before_loaded = {
        str(name)
        for name in before_snapshot.get("resident_expected_modules") or []
        if str(name).strip()
    }
    after_loaded = {
        str(name)
        for name in after_snapshot.get("resident_expected_modules") or []
        if str(name).strip()
    }

    loaded_modules = [name for name in expected if name in after_loaded]
    newly_loaded_modules = [name for name in expected if name in after_loaded and name not in before_loaded]
    failed_modules = [name for name in expected if name not in after_loaded]

    status = "ok"
    if completed.returncode != 0:
        status = "error"
    elif failed_modules:
        status = "partial"

    return {
        "invoked_at": datetime.now(timezone.utc).isoformat(),
        "script_path": relpath(script_path),
        "status": status,
        "exit_code": completed.returncode,
        "stdout": (completed.stdout or "").strip(),
        "stderr": (completed.stderr or "").strip(),
        "expected_modules": expected,
        "loaded_modules": loaded_modules,
        "newly_loaded_modules": newly_loaded_modules,
        "failed_modules": failed_modules,
        "snapshot_after": after_snapshot,
    }


def _read_text_file(path: Path | None) -> str:
    if path is None or not path.exists():
        return ""
    return path.read_text(encoding="utf-8", errors="replace")


def _capture_daemon_kinsn_discovery(stdout_path: Path | None, stderr_path: Path | None) -> dict[str, object]:
    stdout_text = _read_text_file(stdout_path).strip()
    stderr_text = _read_text_file(stderr_path).strip()
    status = "ok" if "kinsn discovery:" in stderr_text else "missing"
    return {
        "captured_at": datetime.now(timezone.utc).isoformat(),
        "status": status,
        "stdout_path": relpath(stdout_path) if stdout_path is not None else None,
        "stderr_path": relpath(stderr_path) if stderr_path is not None else None,
        "stdout": stdout_text,
        "stderr": stderr_text,
        "discovery_log": stderr_text,
    }


def _initial_kinsn_metadata(requested_prog_ids: Sequence[int]) -> dict[str, object]:
    return {
        "captured_at": datetime.now(timezone.utc).isoformat(),
        "requested_prog_ids": [int(value) for value in requested_prog_ids if int(value) > 0],
        "expected_modules": _expected_kinsn_modules(),
        "status": "pending",
    }


def _lifecycle_metadata_payload(kinsn_metadata: Mapping[str, object] | None) -> dict[str, object]:
    if kinsn_metadata is None:
        return {}
    return {"kinsn_modules": copy.deepcopy(dict(kinsn_metadata))}


# ---------------------------------------------------------------------------
# Path helpers
# ---------------------------------------------------------------------------

def relpath(path: Path) -> str:
    try:
        return path.resolve().relative_to(ROOT_DIR).as_posix()
    except ValueError:
        return str(path.resolve())


def _program_names_match(live_name: str, object_program_name: str) -> bool:
    if not live_name or not object_program_name:
        return False
    return (
        live_name == object_program_name
        or object_program_name.startswith(live_name)
        or live_name.startswith(object_program_name)
    )


def build_map_capture_specs(
    live_programs: Sequence[Mapping[str, object]],
    *,
    repo_name: str,
    object_paths: Sequence[Path],
    runner_binary: Path | None = None,
) -> dict[str, object]:
    from runner.libs.object_discovery import discover_object_programs

    discovered_candidates: list[dict[str, str]] = []
    discovery_errors: list[str] = []
    if runner_binary is None or not runner_binary.exists():
        missing_runner = "not provided" if runner_binary is None else relpath(runner_binary)
        discovery_errors.append(f"runner binary unavailable for object discovery: {missing_runner}")
    else:
        for object_path in object_paths:
            try:
                listing = discover_object_programs(runner_binary, object_path)
            except Exception as exc:
                discovery_errors.append(f"{relpath(object_path)}: {exc}")
                continue
            for entry in listing:
                discovered_candidates.append(
                    {
                        "object_name": object_path.name,
                        "program_name": entry.name,
                    }
                )

    program_specs: list[dict[str, object]] = []
    unmatched_programs: list[str] = []
    ambiguous_programs: list[dict[str, object]] = []
    seen_targets: set[tuple[str, str, str]] = set()

    for program in live_programs:
        prog_id = int(program.get("id", 0) or 0)
        if prog_id <= 0:
            continue
        live_name = str(program.get("name") or f"prog_{prog_id}")

        matches = [item for item in discovered_candidates if _program_names_match(live_name, item["program_name"])]
        exact_matches = [item for item in matches if item["program_name"] == live_name]
        selected: dict[str, str] | None = None

        if len(exact_matches) == 1:
            selected = exact_matches[0]
        elif len(matches) == 1:
            selected = matches[0]
        elif len(matches) > 1:
            ambiguous_programs.append(
                {
                    "prog_id": prog_id,
                    "live_name": live_name,
                    "matches": [f"{item['object_name']}:{item['program_name']}" for item in matches],
                }
            )
        else:
            unmatched_programs.append(live_name)

        object_name = "unknown"
        program_name = live_name
        if selected is not None:
            object_name = selected["object_name"]
            program_name = selected["program_name"]

        if (repo_name, object_name, program_name) in seen_targets:
            program_name = f"{program_name}_prog{prog_id}"
        seen_targets.add((repo_name, object_name, program_name))
        program_specs.append(
            {
                "prog_id": prog_id,
                "repo": repo_name,
                "object": object_name,
                "program": program_name,
                "qualified_prog_name": f"{repo_name}/{object_name}:{program_name}",
            }
        )

    return {
        "program_specs": program_specs,
        "discovered_object_paths": [relpath(path) for path in object_paths],
        "discovery_errors": discovery_errors,
        "unmatched_programs": unmatched_programs,
        "ambiguous_programs": ambiguous_programs,
    }


def capture_map_state(
    *,
    captured_from: str,
    program_specs: Sequence[Mapping[str, object]],
    optimize_results: Mapping[int, Mapping[str, object]],
    fixture_root: Path | None = None,
) -> dict[str, object]:
    if not program_specs:
        return {
            "generated_at": datetime.now(timezone.utc).isoformat(),
            "captured_from": captured_from,
            "status": "skipped",
            "reason": "no program specs were provided for map capture",
            "programs_seen": 0,
            "programs_selected": 0,
            "programs_written": 0,
            "programs": [],
            "skipped_programs": [],
            "errors": [],
        }

    inline_capture_programs: list[dict[str, object]] = []
    normalized_results: list[tuple[int, Mapping[str, object]]] = []
    capture_prog_ids: set[int] = set()
    for raw_prog_id, raw_result in optimize_results.items():
        if not isinstance(raw_result, Mapping):
            continue
        prog_id = int(raw_prog_id)
        normalized_results.append((prog_id, raw_result))

        summary = raw_result.get("summary") if isinstance(raw_result.get("summary"), Mapping) else {}
        applied_sites = int((summary or {}).get("total_sites_applied", 0) or 0)
        raw_entries = raw_result.get("inlined_map_entries")
        inlined_entry_count = (
            len([entry for entry in raw_entries if isinstance(entry, Mapping)])
            if isinstance(raw_entries, list)
            else 0
        )
        if applied_sites > 0 or inlined_entry_count > 0:
            capture_prog_ids.add(prog_id)

    for prog_id, result in sorted(normalized_results, key=lambda item: item[0]):
        kernel_prog_name = str(result.get("kernel_prog_name") or f"prog_{prog_id}")
        raw_entries = result.get("inlined_map_entries")
        inlined_map_entries = (
            [dict(entry) for entry in raw_entries if isinstance(entry, Mapping)]
            if isinstance(raw_entries, list)
            else []
        )
        inline_capture_programs.append(
            {
                "prog_id": prog_id,
                "kernel_prog_name": kernel_prog_name,
                "inlined_map_entries": inlined_map_entries,
            }
        )

    filtered_program_specs = [
        dict(spec)
        for spec in program_specs
        if int(spec.get("prog_id", 0) or 0) in capture_prog_ids
    ]
    if not filtered_program_specs:
        return {
            "generated_at": datetime.now(timezone.utc).isoformat(),
            "captured_from": captured_from,
            "status": "skipped",
            "reason": "no optimized programs reported applied sites or inline capture entries",
            "programs_seen": len(program_specs),
            "programs_selected": 0,
            "programs_written": 0,
            "programs": [],
            "skipped_programs": [],
            "errors": [],
        }

    fixture_dir = fixture_root or (ROOT_DIR / "corpus" / "fixtures")
    script_path = ROOT_DIR / "runner" / "scripts" / "capture_map_state.py"
    if not script_path.exists():
        raise RuntimeError(f"map capture script is missing: {script_path}")

    with tempfile.TemporaryDirectory(prefix="map-capture-") as tempdir:
        tempdir_path = Path(tempdir)
        spec_path = tempdir_path / "program_specs.json"
        inline_capture_path = tempdir_path / "inline_capture.json"
        write_json(spec_path, filtered_program_specs)
        write_json(inline_capture_path, inline_capture_programs)
        command = [
            sys.executable or "python3",
            str(script_path),
            "--captured-from",
            captured_from,
            "--fixture-root",
            str(fixture_dir),
            "--program-specs",
            str(spec_path),
            "--inline-capture-json",
            str(inline_capture_path),
        ]
        completed = run_command(command, timeout=600)

    payload = json.loads(completed.stdout)
    if not isinstance(payload, dict):
        raise RuntimeError("map capture script returned a non-object JSON payload")
    return payload


# ---------------------------------------------------------------------------
# Lifecycle helpers
# ---------------------------------------------------------------------------

@dataclass(slots=True)
class CaseLifecycleState:
    runtime: object
    target_prog_ids: list[int] = field(default_factory=list)
    apply_prog_ids: list[int] = field(default_factory=list)
    scan_kwargs: dict[str, object] = field(default_factory=dict)
    artifacts: dict[str, object] = field(default_factory=dict)

    def requested_prog_ids(self) -> list[int]:
        raw_prog_ids = self.apply_prog_ids or self.target_prog_ids
        return [int(value) for value in raw_prog_ids if int(value) > 0]


@dataclass(frozen=True, slots=True)
class LifecycleAbort:
    status: str
    reason: str
    artifacts: Mapping[str, object] | None = None


@dataclass(slots=True)
class LifecycleRunResult:
    setup_state: object
    state: CaseLifecycleState | None
    baseline: Mapping[str, object] | None
    scan_results: dict[int, dict[str, object]]
    rejit_result: dict[str, object] | None
    post_rejit: Mapping[str, object] | None
    artifacts: dict[str, object] = field(default_factory=dict)
    metadata: dict[str, object] = field(default_factory=dict)
    abort: LifecycleAbort | None = None


def _artifact_dict(value: Mapping[str, object] | None) -> dict[str, object]:
    if value is None:
        return {}
    return dict(value)


def run_case_lifecycle(
    *,
    daemon_binary: Path,
    setup: Callable[[], object],
    start: Callable[[object], CaseLifecycleState],
    workload: Callable[[object, CaseLifecycleState, str], Mapping[str, object] | None],
    stop: Callable[[object, CaseLifecycleState], None],
    cleanup: Callable[[object], None],
    enabled_passes: Sequence[str] | None = None,
    before_baseline: Callable[[object, CaseLifecycleState], LifecycleAbort | None] | None = None,
    after_baseline: Callable[[object, CaseLifecycleState, Mapping[str, object]], Mapping[str, object] | None] | None = None,
    before_rejit: Callable[[object, CaseLifecycleState, Mapping[str, object]], str | None] | None = None,
    should_run_post_rejit: Callable[[Mapping[str, object]], bool] | None = None,
) -> LifecycleRunResult:
    """Run the shared E2E lifecycle for a live program session.

    TODO: the case-specific ``start`` / ``workload`` / ``stop`` hooks should
    move into ``runner/libs/app_runners/`` so corpus and E2E share one
    lifecycle surface per repo. This helper centralizes the repeated phase
    ordering until that extraction lands:

    1. setup
    2. start
    3. optional pre-baseline checks
    4. baseline workload
    5. optional after-baseline work
    6. scan + daemon apply
    7. post-ReJIT workload
    8. stop + cleanup
    """
    from runner.libs.rejit import (
        _start_daemon_server,
        _stop_daemon_server,
        apply_daemon_rejit,
        benchmark_rejit_enabled_passes,
        scan_programs,
    )

    setup_state = setup()
    lifecycle_state: CaseLifecycleState | None = None
    baseline: Mapping[str, object] | None = None
    scan_results: dict[int, dict[str, object]] = {}
    rejit_result: dict[str, object] | None = None
    post_rejit: Mapping[str, object] | None = None
    artifacts: dict[str, object] = {}
    abort: LifecycleAbort | None = None
    kinsn_metadata: dict[str, object] | None = None

    try:
        lifecycle_state = start(setup_state)
        artifacts.update(_artifact_dict(lifecycle_state.artifacts))
        kinsn_metadata = _initial_kinsn_metadata(lifecycle_state.requested_prog_ids())

        if before_baseline is not None:
            abort = before_baseline(setup_state, lifecycle_state)
            if abort is not None:
                assert kinsn_metadata is not None
                kinsn_metadata["status"] = "skipped"
                kinsn_metadata["reason"] = abort.reason
                kinsn_metadata["skipped_phase"] = "before_baseline"
                artifacts.update(_artifact_dict(abort.artifacts))
                return LifecycleRunResult(
                    setup_state=setup_state,
                    state=lifecycle_state,
                    baseline=None,
                    scan_results={},
                    rejit_result=None,
                    post_rejit=None,
                    artifacts=artifacts,
                    metadata=_lifecycle_metadata_payload(kinsn_metadata),
                    abort=abort,
                )

        baseline = workload(setup_state, lifecycle_state, "baseline")
        if baseline is None:
            raise RuntimeError("baseline workload returned no result")
        artifacts.update(_artifact_dict(lifecycle_state.artifacts))

        if after_baseline is not None:
            artifacts.update(_artifact_dict(after_baseline(setup_state, lifecycle_state, baseline)))

        skip_rejit_reason = None
        if before_rejit is not None:
            skip_rejit_reason = before_rejit(setup_state, lifecycle_state, baseline)

        requested_prog_ids = lifecycle_state.requested_prog_ids()
        assert kinsn_metadata is not None
        kinsn_metadata["requested_prog_ids"] = requested_prog_ids
        if skip_rejit_reason is not None:
            kinsn_metadata["status"] = "skipped"
            kinsn_metadata["reason"] = skip_rejit_reason
            kinsn_metadata["skipped_phase"] = "before_rejit"
            rejit_result = {
                "applied": False,
                "reason": skip_rejit_reason,
                "error": skip_rejit_reason,
            }
        elif requested_prog_ids:
            before_snapshot = _capture_kinsn_module_snapshot(kinsn_metadata.get("expected_modules") or [])
            kinsn_metadata["module_snapshot_before_daemon"] = before_snapshot
            kinsn_metadata["module_load"] = _run_kinsn_module_loader(
                kinsn_metadata.get("expected_modules") or [],
                before_snapshot=before_snapshot,
            )
            kinsn_metadata["status"] = "daemon_starting"
            try:
                daemon_server = _start_daemon_server(daemon_binary)
            except Exception as exc:
                kinsn_metadata["status"] = "daemon_start_failed"
                kinsn_metadata["error"] = str(exc)
                raise
            kinsn_metadata["daemon_kinsn_discovery"] = _capture_daemon_kinsn_discovery(
                daemon_server[3],
                daemon_server[4],
            )
            kinsn_metadata["status"] = "daemon_started"
            try:
                scan_results = scan_programs(
                    requested_prog_ids,
                    daemon_binary,
                    daemon_socket_path=daemon_server[1],
                    daemon_proc=daemon_server[0],
                    daemon_stdout_path=daemon_server[3],
                    daemon_stderr_path=daemon_server[4],
                    **lifecycle_state.scan_kwargs,
                )
                rejit_result = apply_daemon_rejit(
                    requested_prog_ids,
                    enabled_passes=enabled_passes or benchmark_rejit_enabled_passes(),
                    daemon_socket_path=daemon_server[1],
                    daemon_proc=daemon_server[0],
                    daemon_stdout_path=daemon_server[3],
                    daemon_stderr_path=daemon_server[4],
                )
            finally:
                _stop_daemon_server(daemon_server[0], daemon_server[1], daemon_server[2])
            kinsn_metadata["status"] = "completed"
            run_post_rejit = bool(rejit_result.get("applied"))
            if should_run_post_rejit is not None:
                run_post_rejit = bool(should_run_post_rejit(rejit_result))
            if run_post_rejit:
                post_rejit = workload(setup_state, lifecycle_state, "post_rejit")
        else:
            kinsn_metadata["status"] = "skipped"
            kinsn_metadata["reason"] = "no requested program ids"
        return LifecycleRunResult(
            setup_state=setup_state,
            state=lifecycle_state,
            baseline=baseline,
            scan_results=scan_results,
            rejit_result=rejit_result,
            post_rejit=post_rejit,
            artifacts=artifacts,
            metadata=_lifecycle_metadata_payload(kinsn_metadata),
            abort=abort,
        )
    except Exception as exc:
        if kinsn_metadata is not None:
            status = str(kinsn_metadata.get("status") or "")
            if status in {"", "pending"}:
                kinsn_metadata["status"] = "error"
            kinsn_metadata.setdefault("error", str(exc))
        raise
    finally:
        if kinsn_metadata is not None:
            artifacts["kinsn_modules"] = copy.deepcopy(kinsn_metadata)
            _append_pending_kinsn_metadata(kinsn_metadata)
        try:
            if lifecycle_state is not None:
                stop(setup_state, lifecycle_state)
        finally:
            cleanup(setup_state)


# ---------------------------------------------------------------------------
# Provenance helpers
# ---------------------------------------------------------------------------

def git_sha() -> str:
    """Return the current HEAD commit hash, or 'unknown' on failure."""
    try:
        return run_command(["git", "rev-parse", "HEAD"], timeout=15).stdout.strip()
    except Exception:
        return "unknown"


def host_metadata() -> dict[str, object]:
    """Collect basic host information for result provenance."""
    return {
        "hostname": platform.node(),
        "platform": platform.platform(),
        "kernel": platform.release(),
        "python": sys.version.split()[0],
        "git_sha": git_sha(),
    }


# ---------------------------------------------------------------------------
# Statistical helpers
# ---------------------------------------------------------------------------

def summarize_numbers(values: Sequence[float | int | None]) -> dict[str, float | int | None]:
    """Compute count/mean/median/min/max over non-None numeric values."""
    filtered = [float(value) for value in values if value is not None]
    if not filtered:
        return {
            "count": 0,
            "mean": None,
            "median": None,
            "min": None,
            "max": None,
        }
    return {
        "count": len(filtered),
        "mean": statistics.mean(filtered),
        "median": statistics.median(filtered),
        "min": min(filtered),
        "max": max(filtered),
    }


def percent_delta(before: object, after: object) -> float | None:
    """Compute percentage change from *before* to *after*."""
    if before in (None, 0) or after is None:
        return None
    return ((float(after) - float(before)) / float(before)) * 100.0


def percentile(values: Sequence[float], pct: float) -> float | None:
    """Linear-interpolation percentile over a sequence of floats."""
    items = sorted(float(value) for value in values)
    if not items:
        return None
    if len(items) == 1:
        return items[0]
    rank = max(0.0, min(1.0, pct / 100.0)) * (len(items) - 1)
    lower = int(rank)
    upper = min(len(items) - 1, lower + 1)
    weight = rank - lower
    return items[lower] * (1.0 - weight) + items[upper] * weight


def speedup_ratio(before: object, after: object) -> float | None:
    """Return before/after as a speedup multiplier, or None."""
    if before in (None, 0) or after in (None, 0):
        return None
    return float(before) / float(after)


# ---------------------------------------------------------------------------
# Result persistence
# ---------------------------------------------------------------------------

def persist_results(
    payload: Mapping[str, object],
    output_json: Path,
    output_md: Path,
    build_markdown: object,
) -> None:
    """Write JSON + markdown results and fix ownership.

    *build_markdown* must be a callable ``(payload) -> str`` supplied by
    the individual case, since each case has its own markdown format.
    """
    payload_dict = dict(payload)
    attach_pending_result_metadata(payload_dict)
    write_json(output_json, _compact_persisted_value(payload_dict))
    write_text(output_md, build_markdown(payload_dict))  # type: ignore[operator]


def _compact_persisted_value(value: object) -> object:
    if isinstance(value, dict):
        return {key: _compact_persisted_value(inner) for key, inner in value.items()}
    if isinstance(value, list):
        return [_compact_persisted_value(item) for item in value]
    if isinstance(value, tuple):
        return [_compact_persisted_value(item) for item in value]
    if isinstance(value, str) and len(value) > MAX_PERSISTED_STRING_CHARS:
        edge = max(1, MAX_PERSISTED_STRING_CHARS // 2)
        omitted = len(value) - (edge * 2)
        return (
            value[:edge]
            + f"\n...[truncated {omitted} chars]...\n"
            + value[-edge:]
        )
    return value
