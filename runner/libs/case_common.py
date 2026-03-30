"""Shared helpers for e2e benchmark cases.

Consolidates utility functions that were previously copy-pasted across
tracee, tetragon, bpftrace, katran, and scx case files.
"""
from __future__ import annotations

import copy
import platform
import statistics
import sys
from contextlib import contextmanager
from dataclasses import dataclass, field
from datetime import datetime, timezone
from pathlib import Path
from typing import Callable, Iterator, Mapping, Sequence

from runner.libs import (
    ROOT_DIR,
    run_command,
    write_json,
    write_text,
)
from runner.libs.daemon_session import DaemonSession

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


@dataclass(slots=True)
class PreparedDaemonSession:
    session: DaemonSession
    metadata: dict[str, object]


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


@contextmanager
def open_prepared_daemon_session(daemon_binary: Path) -> Iterator[PreparedDaemonSession]:
    binary = daemon_binary.resolve()
    expected_modules = _expected_kinsn_modules()
    before_snapshot = _capture_kinsn_module_snapshot(expected_modules)
    module_load = _run_kinsn_module_loader(
        expected_modules,
        before_snapshot=before_snapshot,
    )
    with DaemonSession.start(binary) as daemon_session:
        metadata = {
            "captured_at": datetime.now(timezone.utc).isoformat(),
            "daemon_binary": relpath(binary),
            "expected_modules": expected_modules,
            "module_snapshot_before_daemon": before_snapshot,
            "module_load": module_load,
            "daemon_kinsn_discovery": _capture_daemon_kinsn_discovery(
                daemon_session.stdout_path,
                daemon_session.stderr_path,
            ),
            "status": "ready",
        }
        yield PreparedDaemonSession(
            session=daemon_session,
            metadata=metadata,
        )


def _clone_daemon_metadata(
    daemon_session: PreparedDaemonSession,
    requested_prog_ids: Sequence[int],
) -> dict[str, object]:
    metadata = copy.deepcopy(daemon_session.metadata)
    metadata["captured_at"] = datetime.now(timezone.utc).isoformat()
    metadata["requested_prog_ids"] = [int(value) for value in requested_prog_ids if int(value) > 0]
    metadata["status"] = "pending"
    return metadata


def _daemon_exit_error(daemon_session: DaemonSession) -> str | None:
    returncode = daemon_session.proc.poll()
    if returncode is None:
        return None
    return f"daemon session exited early (rc={returncode})"


def run_case_lifecycle(
    *,
    daemon_session: PreparedDaemonSession,
    setup: Callable[[], object],
    start: Callable[[object], CaseLifecycleState],
    workload: Callable[[object, CaseLifecycleState, str], Mapping[str, object] | None],
    stop: Callable[[object, CaseLifecycleState], None],
    cleanup: Callable[[object], None],
    enabled_passes: Sequence[str] | None = None,
    before_baseline: Callable[[object, CaseLifecycleState], LifecycleAbort | None] | None = None,
    after_baseline: Callable[[object, CaseLifecycleState, Mapping[str, object]], Mapping[str, object] | None] | None = None,
    before_rejit: Callable[[object, CaseLifecycleState, Mapping[str, object]], LifecycleAbort | None] | None = None,
    should_run_post_rejit: Callable[[Mapping[str, object]], bool] | None = None,
) -> LifecycleRunResult:
    """Run the shared E2E lifecycle for a live program session.

    E2E cases already share repo-specific runner implementations in
    ``runner/libs/app_runners/``. This helper centralizes the repeated
    daemon-scan/apply ordering around those case-specific hooks:

    1. setup
    2. start
    3. optional pre-baseline checks
    4. baseline workload
    5. optional after-baseline work
    6. scan + daemon apply
    7. post-ReJIT workload
    8. stop + cleanup
    """
    from runner.libs.rejit import benchmark_rejit_enabled_passes

    setup_state = setup()
    lifecycle_state: CaseLifecycleState | None = None
    baseline: Mapping[str, object] | None = None
    scan_results: dict[int, dict[str, object]] = {}
    rejit_result: dict[str, object] | None = None
    post_rejit: Mapping[str, object] | None = None
    artifacts: dict[str, object] = {}
    abort: LifecycleAbort | None = None
    kinsn_metadata: dict[str, object] | None = None
    active_daemon_session = daemon_session.session

    try:
        lifecycle_state = start(setup_state)
        artifacts.update(_artifact_dict(lifecycle_state.artifacts))
        requested_prog_ids = lifecycle_state.requested_prog_ids()
        if not requested_prog_ids:
            raise RuntimeError("lifecycle did not provide any requested program ids")
        kinsn_metadata = _clone_daemon_metadata(daemon_session, requested_prog_ids)

        if before_baseline is not None:
            abort = before_baseline(setup_state, lifecycle_state)
            if abort is not None:
                assert kinsn_metadata is not None
                kinsn_metadata["status"] = "aborted"
                kinsn_metadata["reason"] = abort.reason
                kinsn_metadata["abort_phase"] = "before_baseline"
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

        if before_rejit is not None:
            abort = before_rejit(setup_state, lifecycle_state, baseline)
            if abort is not None:
                assert kinsn_metadata is not None
                kinsn_metadata["status"] = "aborted"
                kinsn_metadata["reason"] = abort.reason
                kinsn_metadata["abort_phase"] = "before_rejit"
                artifacts.update(_artifact_dict(abort.artifacts))
                return LifecycleRunResult(
                    setup_state=setup_state,
                    state=lifecycle_state,
                    baseline=baseline,
                    scan_results={},
                    rejit_result=None,
                    post_rejit=None,
                    artifacts=artifacts,
                    metadata=_lifecycle_metadata_payload(kinsn_metadata),
                    abort=abort,
                )

        daemon_error = _daemon_exit_error(active_daemon_session)
        if daemon_error is not None:
            raise RuntimeError(daemon_error)
        scan_results = active_daemon_session.scan_programs(
            requested_prog_ids,
            **lifecycle_state.scan_kwargs,
        )
        daemon_error = _daemon_exit_error(active_daemon_session)
        if daemon_error is not None:
            raise RuntimeError(daemon_error)
        rejit_result = active_daemon_session.apply_rejit(
            requested_prog_ids,
            enabled_passes=enabled_passes or benchmark_rejit_enabled_passes(),
        )
        kinsn_metadata["status"] = "completed"
        run_post_rejit = bool(rejit_result.get("applied"))
        if should_run_post_rejit is not None:
            run_post_rejit = bool(should_run_post_rejit(rejit_result))
        if run_post_rejit:
            post_rejit = workload(setup_state, lifecycle_state, "post_rejit")
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
