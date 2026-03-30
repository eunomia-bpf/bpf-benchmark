"""Shared helpers for e2e benchmark cases.

Consolidates utility functions that were previously copy-pasted across
tracee, tetragon, bpftrace, and scx case files.
"""
from __future__ import annotations

import copy
import platform
import statistics
import sys
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
from runner.libs.daemon_session import DaemonSession
from runner.libs.kinsn import (
    capture_daemon_kinsn_discovery as _capture_daemon_kinsn_discovery,
    capture_kinsn_module_snapshot as _capture_kinsn_module_snapshot,
    expected_kinsn_modules as _expected_kinsn_modules,
    relpath,
    run_kinsn_module_loader as _run_kinsn_module_loader,
)

MAX_PERSISTED_STRING_CHARS = 16_384
_PENDING_KINSN_METADATA: list[dict[str, object]] = []


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


def rejit_result_has_any_apply(rejit_result: Mapping[str, object] | None) -> bool:
    if not isinstance(rejit_result, Mapping):
        return False
    per_program = rejit_result.get("per_program")
    if isinstance(per_program, Mapping) and per_program:
        return any(
            bool(record.get("applied"))
            for record in per_program.values()
            if isinstance(record, Mapping)
        )
    counts = rejit_result.get("counts")
    applied_sites = int(((counts or {}).get("applied_sites", 0)) or 0) if isinstance(counts, Mapping) else 0
    return bool(rejit_result.get("applied")) or applied_sites > 0


def rejit_result_all_applied(rejit_result: Mapping[str, object] | None) -> bool:
    if not isinstance(rejit_result, Mapping):
        return False
    per_program = rejit_result.get("per_program")
    if isinstance(per_program, Mapping) and per_program:
        return all(
            bool(record.get("applied"))
            for record in per_program.values()
            if isinstance(record, Mapping)
        )
    return bool(rejit_result.get("applied"))


def rejit_program_result(
    rejit_result: Mapping[str, object] | None,
    prog_id: int,
) -> dict[str, object]:
    if not isinstance(rejit_result, Mapping):
        return {}
    per_program = rejit_result.get("per_program")
    if not isinstance(per_program, Mapping):
        return {}
    record = per_program.get(int(prog_id))
    if record is None:
        record = per_program.get(str(int(prog_id)))
    return dict(record) if isinstance(record, Mapping) else {}


def _lifecycle_metadata_payload(kinsn_metadata: Mapping[str, object] | None) -> dict[str, object]:
    if kinsn_metadata is None:
        return {}
    return {"kinsn_modules": copy.deepcopy(dict(kinsn_metadata))}


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


def prepare_daemon_session(
    daemon_session: DaemonSession,
    *,
    daemon_binary: Path | None = None,
) -> PreparedDaemonSession:
    binary = (daemon_binary or daemon_session.daemon_binary).resolve()
    metadata = copy.deepcopy(getattr(daemon_session, "kinsn_metadata", {}) or {})
    if not metadata:
        expected_modules = _expected_kinsn_modules()
        before_snapshot = _capture_kinsn_module_snapshot(expected_modules)
        module_load = _run_kinsn_module_loader(
            expected_modules,
            before_snapshot=before_snapshot,
        )
        metadata = {
            "captured_at": datetime.now(timezone.utc).isoformat(),
            "expected_modules": expected_modules,
            "module_snapshot_before_daemon": before_snapshot,
            "module_load": module_load,
        }
    metadata["captured_at"] = datetime.now(timezone.utc).isoformat()
    metadata["daemon_binary"] = relpath(binary)
    metadata["daemon_kinsn_discovery"] = _capture_daemon_kinsn_discovery(
        daemon_session.stdout_path,
        daemon_session.stderr_path,
    )
    metadata["status"] = "ready"
    return PreparedDaemonSession(
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
        run_post_rejit = rejit_result_has_any_apply(rejit_result)
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
            status = str(kinsn_metadata.get("status") or "").strip().lower()
            if status != "aborted":
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
    """Return the current HEAD commit hash."""
    value = run_command(["git", "rev-parse", "HEAD"], timeout=15).stdout.strip()
    if not value:
        raise RuntimeError("git rev-parse returned an empty HEAD revision")
    return value


def host_metadata() -> dict[str, object]:
    """Collect basic host information for result provenance."""
    metadata = {
        "hostname": platform.node(),
        "platform": platform.platform(),
        "kernel": platform.release(),
        "python": sys.version.split()[0],
    }
    try:
        metadata["git_sha"] = git_sha()
    except Exception as exc:
        metadata["git_sha"] = None
        metadata["git_sha_error"] = str(exc)
    return metadata


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
