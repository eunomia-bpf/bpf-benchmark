"""Shared helpers for e2e benchmark cases.

Consolidates utility functions that were previously copy-pasted across
tracee, tetragon, bpftrace, and scx case files.
"""
from __future__ import annotations

import copy
import os
import platform
import statistics
import sys
import threading
import time
from dataclasses import dataclass, field
from datetime import datetime, timezone
from pathlib import Path
from typing import Callable, Mapping, Sequence

from runner.libs import (
    resolve_bpftool_binary,
    run_command,
    run_json_command,
    write_json,
    write_text,
)
from runner.libs.app_runners.base import AppRunner
from runner.libs.bpf_stats import sample_bpf_stats
from runner.libs.rejit import DaemonSession
from runner.libs.kinsn import (
    capture_daemon_kinsn_discovery as _capture_daemon_kinsn_discovery,
    relpath,
)
from runner.libs.metrics import (
    compute_delta,
    sample_cpu_usage,
    sample_total_cpu_usage,
    start_sampler_thread,
)

MAX_PERSISTED_STRING_CHARS = 16_384
_PENDING_KINSN_METADATA: list[dict[str, object]] = []
DEFAULT_SUITE_QUIESCE_TIMEOUT_S = 20.0
DEFAULT_SUITE_QUIESCE_STABLE_S = 2.0
DEFAULT_SUITE_QUIESCE_POLL_S = 0.2
_BENCH_PASSES_ENV = "BPFREJIT_BENCH_PASSES"


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


def _current_program_ids() -> tuple[int, ...]:
    command = [resolve_bpftool_binary(), "-j", "-p", "prog", "show"]
    if os.geteuid() != 0:
        command = ["sudo", *command]
    payload = run_json_command(command, timeout=30)
    if not isinstance(payload, list):
        raise RuntimeError("bpftool prog show returned unexpected payload while waiting for suite quiescence")
    prog_ids = sorted(
        int(record.get("id", -1))
        for record in payload
        if isinstance(record, Mapping) and int(record.get("id", -1)) > 0
    )
    return tuple(prog_ids)


def wait_for_suite_quiescence(
    *,
    stable_s: float = DEFAULT_SUITE_QUIESCE_STABLE_S,
    timeout_s: float = DEFAULT_SUITE_QUIESCE_TIMEOUT_S,
    poll_s: float = DEFAULT_SUITE_QUIESCE_POLL_S,
) -> None:
    deadline = time.monotonic() + max(0.0, float(timeout_s))
    stable_window = max(0.0, float(stable_s))
    poll_interval = max(0.05, float(poll_s))
    previous_ids: tuple[int, ...] | None = None
    stable_since: float | None = None
    while True:
        now = time.monotonic()
        current_ids = _current_program_ids()
        if current_ids == previous_ids:
            if stable_since is None:
                stable_since = now
            if now - stable_since >= stable_window:
                return
        else:
            previous_ids = current_ids
            stable_since = now
        if now >= deadline:
            break
        time.sleep(min(poll_interval, max(0.0, deadline - now)))
    rendered = ", ".join(str(prog_id) for prog_id in (previous_ids or ()))
    raise RuntimeError(
        "kernel program table did not quiesce between suite entries within "
        f"{float(timeout_s):.1f}s; last visible prog_ids=[{rendered}]"
    )


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

@dataclass
class CaseLifecycleState:
    runtime: AppRunner
    target_prog_ids: list[int] = field(default_factory=list)
    apply_prog_ids: list[int] = field(default_factory=list)
    scan_kwargs: dict[str, object] = field(default_factory=dict)
    artifacts: dict[str, object] = field(default_factory=dict)

    def requested_prog_ids(self) -> list[int]:
        raw_prog_ids = self.apply_prog_ids or self.target_prog_ids
        return [int(value) for value in raw_prog_ids if int(value) > 0]


@dataclass
class PreparedDaemonSession:
    session: DaemonSession
    metadata: dict[str, object]


@dataclass(frozen=True)
class LifecycleAbort:
    status: str
    reason: str
    artifacts: Mapping[str, object] | None = None


@dataclass
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
    if not bool(getattr(daemon_session, "load_kinsn", False)):
        return PreparedDaemonSession(
            session=daemon_session,
            metadata={},
        )
    if not metadata:
        raise RuntimeError("daemon session requested kinsn loading but did not capture kinsn metadata")
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


def _normalize_enabled_passes(enabled_passes: Sequence[str] | None) -> list[str]:
    if enabled_passes is None:
        return []
    normalized: list[str] = []
    seen: set[str] = set()
    for pass_name in enabled_passes:
        name = str(pass_name).strip()
        if not name or name in seen:
            continue
        seen.add(name)
        normalized.append(name)
    return normalized


def _program_records_by_id(programs: object) -> dict[int, dict[str, object]]:
    if not isinstance(programs, Sequence) or isinstance(programs, (str, bytes, bytearray)):
        return {}
    records: dict[int, dict[str, object]] = {}
    for raw_program in programs:
        if not isinstance(raw_program, Mapping):
            continue
        prog_id = int(raw_program.get("id", 0) or 0)
        if prog_id <= 0:
            continue
        records[prog_id] = dict(raw_program)
    return records


def _program_policy_context(
    *,
    prog_id: int,
    program: Mapping[str, object] | None,
    artifacts: Mapping[str, object],
) -> dict[str, object]:
    context: dict[str, object] = {}
    base_context = artifacts.get("rejit_policy_context")
    if isinstance(base_context, Mapping):
        context.update(
            {
                str(key): value
                for key, value in base_context.items()
                if str(key).strip() and str(value).strip()
            }
        )

    per_program_contexts = artifacts.get("rejit_policy_context_by_prog_id")
    if isinstance(per_program_contexts, Mapping):
        raw_program_context = per_program_contexts.get(int(prog_id))
        if raw_program_context is None:
            raw_program_context = per_program_contexts.get(str(int(prog_id)))
        if isinstance(raw_program_context, Mapping):
            context.update(
                {
                    str(key): value
                    for key, value in raw_program_context.items()
                    if str(key).strip() and str(value).strip()
                }
            )

    if isinstance(program, Mapping):
        object_value = (
            program.get("object")
            or program.get("object_basename")
            or program.get("object_relpath")
        )
        program_value = program.get("program") or program.get("prog_name") or program.get("name")
        section_value = program.get("section") or program.get("section_name")
        prog_type_value = (
            program.get("prog_type")
            or program.get("prog_type_name")
            or program.get("type")
        )

        if str(object_value or "").strip() and "object" not in context:
            context["object"] = str(object_value).strip()
        if str(program_value or "").strip() and "program" not in context:
            context["program"] = str(program_value).strip()
        if str(section_value or "").strip() and "section" not in context:
            context["section"] = str(section_value).strip()
        if str(prog_type_value or "").strip() and "prog_type" not in context:
            context["prog_type"] = str(prog_type_value).strip()

        for key in ("object_relpath", "object_basename", "family", "category", "level", "repo"):
            value = program.get(key)
            if str(value or "").strip() and key not in context:
                context[key] = str(value).strip()

    return context


def _scan_record_counts(scan_results: Mapping[int, Mapping[str, object]], prog_id: int) -> dict[str, object]:
    record = scan_results.get(int(prog_id))
    if record is None:
        record = scan_results.get(str(int(prog_id)))  # type: ignore[arg-type]
    if not isinstance(record, Mapping):
        return {}
    counts = record.get("counts")
    if isinstance(counts, Mapping):
        return dict(counts)
    sites = record.get("sites")
    if isinstance(sites, Mapping):
        return dict(sites)
    return {}


def _resolve_scan_pass_selection(
    enabled_passes: Sequence[str] | None,
) -> tuple[list[str], object | None, str]:
    from runner.libs.rejit import (
        benchmark_policy_candidate_passes,
        benchmark_rejit_enabled_passes,
        load_benchmark_config,
    )

    explicit_passes = _normalize_enabled_passes(enabled_passes)
    if enabled_passes is not None:
        return explicit_passes, None, "explicit"
    if _BENCH_PASSES_ENV in os.environ:
        return benchmark_rejit_enabled_passes(), None, "env_override"

    benchmark_config = load_benchmark_config()
    return benchmark_policy_candidate_passes(benchmark_config), benchmark_config, "benchmark_config"


def _resolve_apply_passes_by_program(
    *,
    requested_prog_ids: Sequence[int],
    lifecycle_state: CaseLifecycleState,
    scan_results: Mapping[int, Mapping[str, object]],
    enabled_passes: Sequence[str] | None,
    benchmark_config: object | None,
) -> dict[int, list[str]]:
    from runner.libs.rejit import benchmark_rejit_enabled_passes, resolve_program_enabled_passes

    explicit_passes = _normalize_enabled_passes(enabled_passes)
    if enabled_passes is not None:
        return {
            int(prog_id): list(explicit_passes)
            for prog_id in requested_prog_ids
        }
    if _BENCH_PASSES_ENV in os.environ:
        selected = benchmark_rejit_enabled_passes()
        return {
            int(prog_id): list(selected)
            for prog_id in requested_prog_ids
        }
    if not isinstance(benchmark_config, Mapping):
        raise RuntimeError("benchmark pass plan expected a loaded benchmark config")

    programs_by_id = _program_records_by_id(lifecycle_state.artifacts.get("programs"))
    enabled_by_prog: dict[int, list[str]] = {}
    for prog_id in requested_prog_ids:
        enabled_by_prog[int(prog_id)] = resolve_program_enabled_passes(
            benchmark_config,
            context=_program_policy_context(
                prog_id=int(prog_id),
                program=programs_by_id.get(int(prog_id)),
                artifacts=lifecycle_state.artifacts,
            ),
            site_counts=_scan_record_counts(scan_results, int(prog_id)),
        )
    return enabled_by_prog


def _merge_group_rejit_results(
    *,
    requested_prog_ids: Sequence[int],
    group_results: Sequence[tuple[list[int], Mapping[str, object]]],
    enabled_passes_by_prog: Mapping[int, Sequence[str]],
    scan_enabled_passes: Sequence[str],
    selection_source: str,
    benchmark_config: object | None,
) -> dict[str, object]:
    per_program: dict[int, dict[str, object]] = {}
    outputs: list[str] = []
    total_sites = 0
    applied_sites = 0
    exit_code = 0
    errors: list[str] = []

    def failure_record_for_prog(
        prog_id: int,
        *,
        group_exit_code: int,
        group_error: str,
        group_counts: Mapping[str, object] | None,
    ) -> dict[str, object]:
        counts_mapping = group_counts if isinstance(group_counts, Mapping) else {}
        return {
            "prog_id": int(prog_id),
            "applied": False,
            "changed": False,
            "output": "",
            "exit_code": group_exit_code,
            "counts": {
                "total_sites": int(counts_mapping.get("total_sites", 0) or 0),
                "applied_sites": int(counts_mapping.get("applied_sites", 0) or 0),
            },
            "error": group_error,
        }

    for group_prog_ids, result in group_results:
        output = str(result.get("output") or "")
        if output:
            outputs.append(output)
        group_exit_code = int(result.get("exit_code", 0) or 0)
        exit_code = max(exit_code, group_exit_code)

        counts = result.get("counts")
        if isinstance(counts, Mapping):
            total_sites += int(counts.get("total_sites", 0) or 0)
            applied_sites += int(counts.get("applied_sites", 0) or 0)

        error = str(result.get("error") or "").strip()
        if error:
            errors.append(error)

        raw_per_program = result.get("per_program")
        if not isinstance(raw_per_program, Mapping):
            if group_exit_code != 0 or error:
                for prog_id in group_prog_ids:
                    per_program[int(prog_id)] = failure_record_for_prog(
                        int(prog_id),
                        group_exit_code=group_exit_code,
                        group_error=error or "group REJIT apply failed before per-program records were available",
                        group_counts=counts if isinstance(counts, Mapping) else None,
                    )
                continue
            raise RuntimeError("group REJIT result is missing per_program records")
        per_program_records = raw_per_program
        for prog_id in group_prog_ids:
            raw_record = per_program_records.get(int(prog_id))
            if raw_record is None:
                raw_record = per_program_records.get(str(int(prog_id)))
            if isinstance(raw_record, Mapping):
                per_program[int(prog_id)] = dict(raw_record)
                continue
            if group_exit_code != 0 or error:
                per_program[int(prog_id)] = failure_record_for_prog(
                    int(prog_id),
                    group_exit_code=group_exit_code,
                    group_error=error or f"group REJIT apply failed for prog {prog_id}",
                    group_counts=counts if isinstance(counts, Mapping) else None,
                )
                continue
            raise RuntimeError(f"group REJIT result is missing per_program record for prog {prog_id}")

    applied_any = any(bool(record.get("applied")) for record in per_program.values())
    all_applied = bool(per_program) and all(bool(record.get("applied")) for record in per_program.values())
    merged: dict[str, object] = {
        "applied": applied_any,
        "applied_any": applied_any,
        "all_applied": all_applied,
        "output": "\n".join(fragment for fragment in outputs if fragment),
        "exit_code": exit_code,
        "per_program": per_program,
        "counts": {
            "total_sites": total_sites,
            "applied_sites": applied_sites,
        },
        "program_counts": {
            "requested": len([int(prog_id) for prog_id in requested_prog_ids if int(prog_id) > 0]),
            "applied": sum(1 for record in per_program.values() if bool(record.get("applied"))),
            "not_applied": sum(1 for record in per_program.values() if not bool(record.get("applied"))),
        },
        "error": "; ".join(errors),
        "selection_source": selection_source,
        "scan_enabled_passes": list(scan_enabled_passes),
        "effective_enabled_passes_by_program": {
            str(int(prog_id)): [str(pass_name) for pass_name in enabled_passes_by_prog.get(int(prog_id), ())]
            for prog_id in requested_prog_ids
            if int(prog_id) > 0
        },
    }
    if isinstance(benchmark_config, Mapping):
        profile_name = str(benchmark_config.get("profile") or "").strip()
        if profile_name:
            merged["benchmark_profile"] = profile_name
    return merged


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
        if bool(getattr(active_daemon_session, "load_kinsn", False)):
            kinsn_metadata = _clone_daemon_metadata(daemon_session, requested_prog_ids)

        if before_baseline is not None:
            abort = before_baseline(setup_state, lifecycle_state)
            if abort is not None:
                if kinsn_metadata is not None:
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
                if kinsn_metadata is not None:
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

        requested_prog_ids = lifecycle_state.requested_prog_ids()
        if not requested_prog_ids:
            raise RuntimeError("lifecycle did not provide any requested program ids after baseline")
        if kinsn_metadata is not None:
            kinsn_metadata["requested_prog_ids"] = list(requested_prog_ids)

        scan_enabled_passes, benchmark_config, selection_source = _resolve_scan_pass_selection(
            enabled_passes,
        )

        daemon_error = _daemon_exit_error(active_daemon_session)
        if daemon_error is not None:
            raise RuntimeError(daemon_error)
        scan_kwargs = dict(lifecycle_state.scan_kwargs)
        scan_kwargs["enabled_passes"] = list(scan_enabled_passes)
        scan_results = active_daemon_session.scan_programs(
            requested_prog_ids,
            **scan_kwargs,
        )
        daemon_error = _daemon_exit_error(active_daemon_session)
        if daemon_error is not None:
            raise RuntimeError(daemon_error)
        apply_enabled_passes_by_prog = _resolve_apply_passes_by_program(
            requested_prog_ids=requested_prog_ids,
            lifecycle_state=lifecycle_state,
            scan_results=scan_results,
            enabled_passes=enabled_passes,
            benchmark_config=benchmark_config,
        )
        grouped_prog_ids: dict[tuple[str, ...], list[int]] = {}
        for prog_id in requested_prog_ids:
            pass_tuple = tuple(apply_enabled_passes_by_prog.get(int(prog_id), ()))
            grouped_prog_ids.setdefault(pass_tuple, []).append(int(prog_id))

        group_rejit_results: list[tuple[list[int], Mapping[str, object]]] = []
        for pass_tuple, group_prog_ids in grouped_prog_ids.items():
            group_rejit_results.append(
                (
                    list(group_prog_ids),
                    active_daemon_session.apply_rejit(
                        group_prog_ids,
                        enabled_passes=list(pass_tuple),
                    ),
                )
            )
        rejit_result = _merge_group_rejit_results(
            requested_prog_ids=requested_prog_ids,
            group_results=group_rejit_results,
            enabled_passes_by_prog=apply_enabled_passes_by_prog,
            scan_enabled_passes=scan_enabled_passes,
            selection_source=selection_source,
            benchmark_config=benchmark_config,
        )
        if kinsn_metadata is not None:
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


def _default_runner_lifecycle_state(
    runner: AppRunner,
    started_prog_ids: Sequence[int],
) -> CaseLifecycleState:
    prog_ids = [int(value) for value in started_prog_ids if int(value) > 0]
    if not prog_ids:
        raise RuntimeError("app runner did not return any live prog_ids")
    programs = [dict(program) for program in runner.programs]
    if not programs:
        raise RuntimeError("app runner did not expose any live programs")
    return CaseLifecycleState(
        runtime=runner,
        target_prog_ids=list(prog_ids),
        apply_prog_ids=list(prog_ids),
        artifacts={
            "runner_artifacts": dict(runner.artifacts),
            "programs": programs,
            "command_used": [str(item) for item in runner.command_used],
        },
    )


def run_app_runner_lifecycle(
    *,
    daemon_session: PreparedDaemonSession,
    runner: AppRunner,
    measure: Callable[[CaseLifecycleState, str], Mapping[str, object] | None],
    enabled_passes: Sequence[str] | None = None,
    build_state: Callable[[AppRunner, list[int]], CaseLifecycleState] | None = None,
    before_baseline: Callable[[object, CaseLifecycleState], LifecycleAbort | None] | None = None,
    after_baseline: Callable[[object, CaseLifecycleState, Mapping[str, object]], Mapping[str, object] | None] | None = None,
    before_rejit: Callable[[object, CaseLifecycleState, Mapping[str, object]], LifecycleAbort | None] | None = None,
    should_run_post_rejit: Callable[[Mapping[str, object]], bool] | None = None,
) -> LifecycleRunResult:
    """Run the shared daemon scan/apply lifecycle around a repo AppRunner."""

    def setup() -> None:
        return None

    def start(_: object) -> CaseLifecycleState:
        started_prog_ids = [int(value) for value in runner.start() if int(value) > 0]
        if build_state is not None:
            return build_state(runner, started_prog_ids)
        return _default_runner_lifecycle_state(runner, started_prog_ids)

    def workload(_: object, lifecycle: CaseLifecycleState, phase_name: str) -> Mapping[str, object] | None:
        return measure(lifecycle, phase_name)

    def stop(_: object, lifecycle: CaseLifecycleState) -> None:
        runtime = lifecycle.runtime
        if not isinstance(runtime, AppRunner):
            raise RuntimeError(f"runner lifecycle expected AppRunner runtime, got {type(runtime)!r}")
        runtime.stop()

    def cleanup(_: object) -> None:
        return None

    return run_case_lifecycle(
        daemon_session=daemon_session,
        setup=setup,
        start=start,
        workload=workload,
        stop=stop,
        cleanup=cleanup,
        enabled_passes=enabled_passes,
        before_baseline=before_baseline,
        after_baseline=after_baseline,
        before_rejit=before_rejit,
        should_run_post_rejit=should_run_post_rejit,
    )


def measure_app_runner_workload(
    runner: AppRunner,
    duration_s: int | float,
    prog_ids: Sequence[int],
    *,
    agent_pid: int | None = None,
    initial_stats: Mapping[int, Mapping[str, object]] | None = None,
) -> dict[str, object]:
    stats_source = (
        sample_bpf_stats(list(prog_ids), prog_fds=runner.program_fds)
        if initial_stats is None
        else initial_stats
    )
    before_bpf = {
        int(key): dict(value)
        for key, value in stats_source.items()
    }
    cpu_holder: dict[int, dict[str, float]] = {}
    system_cpu_holder: dict[str, float] = {}
    sampler_errors: list[str] = []
    threads: list[threading.Thread] = []

    if agent_pid is not None and int(agent_pid) > 0:
        cpu_thread = start_sampler_thread(
            label=f"agent cpu pid={int(agent_pid)}",
            errors=sampler_errors,
            target=lambda: cpu_holder.update(sample_cpu_usage([int(agent_pid)], duration_s)),
        )
        threads.append(cpu_thread)

    system_thread = start_sampler_thread(
        label="system cpu",
        errors=sampler_errors,
        target=lambda: system_cpu_holder.update(sample_total_cpu_usage(duration_s)),
    )
    threads.append(system_thread)

    try:
        workload_result = runner.run_workload(float(duration_s))
    finally:
        for thread in threads:
            thread.join()
    if sampler_errors:
        raise RuntimeError("; ".join(sampler_errors))
    if not system_cpu_holder:
        raise RuntimeError("system cpu sampler produced no data")
    if agent_pid is not None and int(agent_pid) > 0 and int(agent_pid) not in cpu_holder:
        raise RuntimeError(f"agent cpu sampler produced no data for pid={int(agent_pid)}")

    after_bpf = sample_bpf_stats(list(prog_ids), prog_fds=runner.program_fds)
    measurement = {
        "workload": workload_result.to_dict(),
        "initial_stats": {int(key): dict(value) for key, value in before_bpf.items()},
        "final_stats": {int(key): dict(value) for key, value in after_bpf.items()},
        "bpf": compute_delta(before_bpf, after_bpf),
        "system_cpu": system_cpu_holder,
    }
    if agent_pid is not None and int(agent_pid) > 0:
        agent_cpu = cpu_holder.get(int(agent_pid), {})
        total_pct: float | None = None
        if agent_cpu:
            total_pct = float(agent_cpu.get("user_pct", 0.0)) + float(agent_cpu.get("sys_pct", 0.0))
        measurement["agent_cpu"] = {
            "user_pct": agent_cpu.get("user_pct"),
            "sys_pct": agent_cpu.get("sys_pct"),
            "total_pct": total_pct,
        }
    return measurement


def zero_site_totals(fields: Sequence[str]) -> dict[str, int]:
    return {str(field): 0 for field in fields if str(field).strip()}


def aggregate_scan_site_totals(
    records: Mapping[int, Mapping[str, object]],
    *,
    fields: Sequence[str],
) -> dict[str, int]:
    totals = zero_site_totals(fields)
    for record in records.values():
        counts = record.get("sites") or record.get("counts") or {}
        for site_field in totals:
            totals[site_field] += int(counts.get(site_field, 0) or 0)
    return totals


def run_app_runner_phase_records(
    *,
    runner: AppRunner,
    prepared_daemon_session: PreparedDaemonSession,
    measure: Callable[[CaseLifecycleState, str], Mapping[str, object] | None],
    site_totals_fields: Sequence[str],
    enabled_passes: Sequence[str] | None = None,
    build_state: Callable[[AppRunner, list[int]], CaseLifecycleState] | None = None,
    before_baseline: Callable[[object, CaseLifecycleState], LifecycleAbort | None] | None = None,
    after_baseline: Callable[[object, CaseLifecycleState, Mapping[str, object]], Mapping[str, object] | None] | None = None,
    before_rejit: Callable[[object, CaseLifecycleState, Mapping[str, object]], LifecycleAbort | None] | None = None,
    should_run_post_rejit: Callable[[Mapping[str, object]], bool] | None = None,
) -> tuple[dict[str, object], dict[str, object] | None]:
    baseline_measurement: dict[str, object] | None = None
    scan_results: dict[int, dict[str, object]] = {}
    rejit_apply: dict[str, object] | None = None
    post_measurement: dict[str, object] | None = None
    baseline_status = "error"
    baseline_reason = ""
    programs: list[dict[str, object]] = []
    prog_ids: list[int] = []

    try:
        lifecycle_result = run_app_runner_lifecycle(
            daemon_session=prepared_daemon_session,
            runner=runner,
            measure=measure,
            enabled_passes=enabled_passes,
            build_state=build_state,
            before_baseline=before_baseline,
            after_baseline=after_baseline,
            before_rejit=before_rejit,
            should_run_post_rejit=should_run_post_rejit,
        )
        programs = [dict(program) for program in (lifecycle_result.artifacts.get("programs") or [])]
        if lifecycle_result.state is not None:
            prog_ids = [int(value) for value in lifecycle_result.state.target_prog_ids if int(value) > 0]
        if lifecycle_result.baseline is not None:
            baseline_status = str(lifecycle_result.baseline.get("status") or "error")
            baseline_reason = str(lifecycle_result.baseline.get("reason") or "")
            measurement_payload = lifecycle_result.baseline.get("measurement")
            if isinstance(measurement_payload, Mapping):
                baseline_measurement = dict(measurement_payload)
        scan_results = lifecycle_result.scan_results
        rejit_apply = lifecycle_result.rejit_result
        if isinstance(lifecycle_result.post_rejit, Mapping):
            measurement_payload = lifecycle_result.post_rejit.get("measurement")
            if isinstance(measurement_payload, Mapping):
                post_measurement = dict(measurement_payload)
    except Exception as exc:
        baseline_reason = str(exc)

    process_output = dict(runner.process_output)
    site_totals = (
        aggregate_scan_site_totals(scan_results, fields=site_totals_fields)
        if scan_results
        else zero_site_totals(site_totals_fields)
    )
    baseline = {
        "phase": "baseline",
        "status": baseline_status,
        "reason": baseline_reason,
        "programs": programs,
        "prog_ids": prog_ids,
        "scan_results": {str(key): value for key, value in scan_results.items()},
        "site_totals": site_totals,
        "measurement": baseline_measurement,
        "process": process_output,
    }
    if baseline["status"] != "ok" and not baseline["reason"]:
        stderr_tail = str(process_output.get("stderr_tail") or "")
        stdout_tail = str(process_output.get("stdout_tail") or "")
        baseline["reason"] = stderr_tail or stdout_tail or "unknown failure"

    rejit: dict[str, object] | None = None
    if baseline["status"] == "ok" and rejit_apply is not None:
        if rejit_result_has_any_apply(rejit_apply):
            rejit_reason = ""
            if post_measurement is None:
                rejit_reason = "post-ReJIT measurement is missing"
            rejit = {
                "phase": "post_rejit",
                "status": "ok" if not rejit_reason else "error",
                "reason": rejit_reason,
                "programs": programs,
                "prog_ids": prog_ids,
                "scan_results": baseline["scan_results"],
                "site_totals": baseline["site_totals"],
                "rejit_result": rejit_apply,
                "measurement": post_measurement,
                "process": process_output,
            }
        else:
            rejit_error = str(rejit_apply.get("error") or "").strip()
            if rejit_error:
                rejit = {
                    "phase": "post_rejit",
                    "status": "error",
                    "reason": rejit_error,
                    "programs": programs,
                    "prog_ids": prog_ids,
                    "scan_results": baseline["scan_results"],
                    "site_totals": baseline["site_totals"],
                    "rejit_result": rejit_apply,
                    "measurement": None,
                    "process": process_output,
                }
    return baseline, rejit


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
