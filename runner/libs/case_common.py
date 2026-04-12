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

from runner.libs import run_command
from runner.libs.app_runners.base import AppRunner
from runner.libs.bpf_stats import list_program_ids, sample_bpf_stats
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
    metadata_payload = dict(payload.get("metadata") if isinstance(payload.get("metadata"), Mapping) else {})
    existing_kinsn = metadata_payload.get("kinsn_modules")
    kinsn_payload = dict(existing_kinsn) if isinstance(existing_kinsn, Mapping) else {}
    existing_runs = kinsn_payload.get("lifecycle_runs")
    lifecycle_runs: list[object] = list(copy.deepcopy(existing_runs)) if isinstance(existing_runs, list) else []
    lifecycle_runs.extend(copy.deepcopy(_PENDING_KINSN_METADATA))
    kinsn_payload["count"] = len(lifecycle_runs)
    kinsn_payload["lifecycle_runs"] = lifecycle_runs
    metadata_payload["kinsn_modules"] = kinsn_payload
    payload["metadata"] = metadata_payload
    _PENDING_KINSN_METADATA.clear()
    return payload


def _current_program_ids() -> tuple[int, ...]:
    return tuple(sorted(list_program_ids()))


def wait_for_suite_quiescence(
    *,
    stable_s: float = DEFAULT_SUITE_QUIESCE_STABLE_S,
    timeout_s: float = DEFAULT_SUITE_QUIESCE_TIMEOUT_S,
    poll_s: float = DEFAULT_SUITE_QUIESCE_POLL_S,
) -> None:
    deadline = time.monotonic() + max(0.0, float(timeout_s))
    stable_window, poll_interval = max(0.0, float(stable_s)), max(0.05, float(poll_s))
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
    rendered = ", ".join(str(pid) for pid in (previous_ids or ()))
    raise RuntimeError(f"kernel program table did not quiesce between suite entries within "
                       f"{float(timeout_s):.1f}s; last visible prog_ids=[{rendered}]")


def _append_pending_kinsn_metadata(record: Mapping[str, object]) -> None:
    payload = copy.deepcopy(dict(record))
    payload["lifecycle_index"] = len(_PENDING_KINSN_METADATA) + 1
    _PENDING_KINSN_METADATA.append(payload)


def rejit_result_has_any_apply(rejit_result: Mapping[str, object] | None) -> bool:
    if not isinstance(rejit_result, Mapping):
        return False
    per_program = rejit_result.get("per_program")
    if isinstance(per_program, Mapping) and per_program:
        return any(bool(r.get("applied")) for r in per_program.values() if isinstance(r, Mapping))
    counts = rejit_result.get("counts")
    applied_sites = int(((counts or {}).get("applied_sites", 0)) or 0) if isinstance(counts, Mapping) else 0
    return bool(rejit_result.get("applied")) or applied_sites > 0


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


def prepare_daemon_session(
    daemon_session: DaemonSession,
    *,
    daemon_binary: Path | None = None,
) -> PreparedDaemonSession:
    binary = (daemon_binary or daemon_session.daemon_binary).resolve()
    metadata = copy.deepcopy(getattr(daemon_session, "kinsn_metadata", {}) or {})
    if not bool(getattr(daemon_session, "load_kinsn", False)):
        return PreparedDaemonSession(session=daemon_session, metadata={})
    if not metadata:
        raise RuntimeError("daemon session requested kinsn loading but did not capture kinsn metadata")
    metadata.update(captured_at=datetime.now(timezone.utc).isoformat(), daemon_binary=relpath(binary),
                    daemon_kinsn_discovery=_capture_daemon_kinsn_discovery(daemon_session.stdout_path, daemon_session.stderr_path),
                    status="ready")
    return PreparedDaemonSession(session=daemon_session, metadata=metadata)


def _clone_daemon_metadata(daemon_session: PreparedDaemonSession, requested_prog_ids: Sequence[int]) -> dict[str, object]:
    metadata = copy.deepcopy(daemon_session.metadata)
    metadata.update(captured_at=datetime.now(timezone.utc).isoformat(),
                    requested_prog_ids=[int(v) for v in requested_prog_ids if int(v) > 0],
                    status="pending")
    return metadata


def _daemon_exit_error(daemon_session: DaemonSession) -> str | None:
    returncode = daemon_session.proc.poll()
    return None if returncode is None else f"daemon session exited early (rc={returncode})"


def _normalize_enabled_passes(enabled_passes: Sequence[str] | None) -> list[str]:
    if enabled_passes is None:
        return []
    seen: set[str] = set()
    result: list[str] = []
    for p in enabled_passes:
        if (n := str(p).strip()) and n not in seen:
            seen.add(n); result.append(n)
    return result


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
    if isinstance(bc := artifacts.get("rejit_policy_context"), Mapping):
        context.update({str(k): v for k, v in bc.items() if str(k).strip() and str(v).strip()})
    if isinstance(ppc := artifacts.get("rejit_policy_context_by_prog_id"), Mapping):
        raw = ppc.get(int(prog_id)) or ppc.get(str(int(prog_id)))
        if isinstance(raw, Mapping):
            context.update({str(k): v for k, v in raw.items() if str(k).strip() and str(v).strip()})
    if isinstance(program, Mapping):
        for key, value in (
            ("object", program.get("object") or program.get("object_basename") or program.get("object_relpath")),
            ("program", program.get("program") or program.get("prog_name") or program.get("name")),
            ("section", program.get("section") or program.get("section_name")),
            ("prog_type", program.get("prog_type") or program.get("prog_type_name") or program.get("type")),
        ):
            if str(value or "").strip() and key not in context:
                context[key] = str(value).strip()
        for key in ("object_relpath", "object_basename", "family", "category", "level", "repo"):
            if str(v := program.get(key) or "").strip() and key not in context:
                context[key] = str(v).strip()
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
        return {int(prog_id): list(explicit_passes) for prog_id in requested_prog_ids}
    if _BENCH_PASSES_ENV in os.environ:
        selected = benchmark_rejit_enabled_passes()
        return {int(prog_id): list(selected) for prog_id in requested_prog_ids}
    if not isinstance(benchmark_config, Mapping):
        raise RuntimeError("benchmark pass plan expected a loaded benchmark config")
    programs_by_id = _program_records_by_id(lifecycle_state.artifacts.get("programs"))
    return {
        int(prog_id): resolve_program_enabled_passes(
            benchmark_config,
            context=_program_policy_context(prog_id=int(prog_id), program=programs_by_id.get(int(prog_id)),
                                             artifacts=lifecycle_state.artifacts),
            site_counts=_scan_record_counts(scan_results, int(prog_id)),
        )
        for prog_id in requested_prog_ids
    }


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

    def _fail_rec(pid: int, ec: int, err: str, gc: Mapping[str, object] | None) -> dict[str, object]:
        cm = gc if isinstance(gc, Mapping) else {}
        return {"prog_id": int(pid), "applied": False, "changed": False, "output": "", "exit_code": ec,
                "counts": {"total_sites": int(cm.get("total_sites", 0) or 0), "applied_sites": int(cm.get("applied_sites", 0) or 0)},
                "error": err}

    for group_prog_ids, result in group_results:
        if (output := str(result.get("output") or "")):
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
        gc = counts if isinstance(counts, Mapping) else None
        if not isinstance(raw_per_program, Mapping):
            if group_exit_code != 0 or error:
                for prog_id in group_prog_ids:
                    per_program[int(prog_id)] = _fail_rec(int(prog_id), group_exit_code,
                        error or "group REJIT apply failed before per-program records were available", gc)
                continue
            raise RuntimeError("group REJIT result is missing per_program records")
        for prog_id in group_prog_ids:
            raw_record = raw_per_program.get(int(prog_id)) or raw_per_program.get(str(int(prog_id)))
            if isinstance(raw_record, Mapping):
                per_program[int(prog_id)] = dict(raw_record)
                continue
            if group_exit_code != 0 or error:
                per_program[int(prog_id)] = _fail_rec(int(prog_id), group_exit_code,
                    error or f"group REJIT apply failed for prog {prog_id}", gc)
                continue
            raise RuntimeError(f"group REJIT result is missing per_program record for prog {prog_id}")

    applied_any = any(bool(record.get("applied")) for record in per_program.values())
    all_applied = bool(per_program) and all(bool(record.get("applied")) for record in per_program.values())
    n_req = len([p for p in requested_prog_ids if int(p) > 0])
    n_applied = sum(1 for r in per_program.values() if bool(r.get("applied")))
    merged: dict[str, object] = {
        "applied": applied_any, "applied_any": applied_any, "all_applied": all_applied,
        "output": "\n".join(f for f in outputs if f),
        "exit_code": exit_code, "per_program": per_program,
        "counts": {"total_sites": total_sites, "applied_sites": applied_sites},
        "program_counts": {"requested": n_req, "applied": n_applied, "not_applied": n_req - n_applied},
        "error": "; ".join(errors), "selection_source": selection_source,
        "scan_enabled_passes": list(scan_enabled_passes),
        "effective_enabled_passes_by_program": {
            str(int(prog_id)): [str(p) for p in enabled_passes_by_prog.get(int(prog_id), ())]
            for prog_id in requested_prog_ids if int(prog_id) > 0
        },
    }
    if isinstance(benchmark_config, Mapping) and (pn := str(benchmark_config.get("profile") or "").strip()):
        merged["benchmark_profile"] = pn
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

    def _abort_result(bl: Mapping[str, object] | None, phase: str) -> LifecycleRunResult:
        assert abort is not None
        if kinsn_metadata is not None:
            kinsn_metadata.update(status="aborted", reason=abort.reason, abort_phase=phase)
        artifacts.update(dict(abort.artifacts) if abort.artifacts else {})
        return LifecycleRunResult(
            setup_state=setup_state, state=lifecycle_state, baseline=bl,
            scan_results={}, rejit_result=None, post_rejit=None, artifacts=artifacts,
            metadata=_lifecycle_metadata_payload(kinsn_metadata), abort=abort,
        )

    try:
        lifecycle_state = start(setup_state)
        artifacts.update(dict(lifecycle_state.artifacts))
        requested_prog_ids = lifecycle_state.requested_prog_ids()
        if not requested_prog_ids:
            raise RuntimeError("lifecycle did not provide any requested program ids")
        if bool(getattr(active_daemon_session, "load_kinsn", False)):
            kinsn_metadata = _clone_daemon_metadata(daemon_session, requested_prog_ids)

        if before_baseline is not None:
            abort = before_baseline(setup_state, lifecycle_state)
            if abort is not None:
                return _abort_result(None, "before_baseline")

        baseline = workload(setup_state, lifecycle_state, "baseline")
        if baseline is None:
            raise RuntimeError("baseline workload returned no result")
        artifacts.update(dict(lifecycle_state.artifacts))

        if after_baseline is not None:
            result = after_baseline(setup_state, lifecycle_state, baseline)
            if result:
                artifacts.update(dict(result))

        if before_rejit is not None:
            abort = before_rejit(setup_state, lifecycle_state, baseline)
            if abort is not None:
                return _abort_result(baseline, "before_rejit")

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

        group_rejit_results: list[tuple[list[int], Mapping[str, object]]] = [
            (list(gids), active_daemon_session.apply_rejit(gids, enabled_passes=list(pt)))
            for pt, gids in grouped_prog_ids.items()
        ]
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
            setup_state=setup_state, state=lifecycle_state, baseline=baseline,
            scan_results=scan_results, rejit_result=rejit_result, post_rejit=post_rejit,
            artifacts=artifacts, metadata=_lifecycle_metadata_payload(kinsn_metadata), abort=abort,
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


def _default_runner_lifecycle_state(runner: AppRunner, started_prog_ids: Sequence[int]) -> CaseLifecycleState:
    prog_ids = [int(value) for value in started_prog_ids if int(value) > 0]
    if not prog_ids:
        raise RuntimeError("app runner did not return any live prog_ids")
    programs = [dict(program) for program in runner.programs]
    if not programs:
        raise RuntimeError("app runner did not expose any live programs")
    return CaseLifecycleState(
        runtime=runner, target_prog_ids=list(prog_ids), apply_prog_ids=list(prog_ids),
        artifacts={"runner_artifacts": dict(runner.artifacts), "programs": programs,
                   "command_used": [str(item) for item in runner.command_used]},
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
    def _start(_: object) -> CaseLifecycleState:
        ids = [int(v) for v in runner.start() if int(v) > 0]
        return build_state(runner, ids) if build_state is not None else _default_runner_lifecycle_state(runner, ids)

    return run_case_lifecycle(
        daemon_session=daemon_session,
        setup=lambda: None,
        start=_start,
        workload=lambda _, lc, ph: measure(lc, ph),
        stop=lambda _, lc: lc.runtime.stop(),
        cleanup=lambda _: None,
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
    stats_source = sample_bpf_stats(list(prog_ids), prog_fds=runner.program_fds) if initial_stats is None else initial_stats
    before_bpf = {int(key): dict(value) for key, value in stats_source.items()}
    cpu_holder: dict[int, dict[str, float]] = {}
    system_cpu_holder: dict[str, float] = {}
    sampler_errors: list[str] = []
    threads: list[threading.Thread] = []
    if agent_pid is not None and int(agent_pid) > 0:
        threads.append(start_sampler_thread(label=f"agent cpu pid={int(agent_pid)}", errors=sampler_errors,
                                             target=lambda: cpu_holder.update(sample_cpu_usage([int(agent_pid)], duration_s))))
    threads.append(start_sampler_thread(label="system cpu", errors=sampler_errors,
                                         target=lambda: system_cpu_holder.update(sample_total_cpu_usage(duration_s))))
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
    measurement: dict[str, object] = {
        "workload": workload_result.to_dict(), "initial_stats": {int(k): dict(v) for k, v in before_bpf.items()},
        "final_stats": {int(k): dict(v) for k, v in after_bpf.items()},
        "bpf": compute_delta(before_bpf, after_bpf), "system_cpu": system_cpu_holder,
    }
    if agent_pid is not None and int(agent_pid) > 0:
        agent_cpu = cpu_holder.get(int(agent_pid), {})
        total_pct: float | None = (float(agent_cpu.get("user_pct", 0.0)) + float(agent_cpu.get("sys_pct", 0.0))) if agent_cpu else None
        measurement["agent_cpu"] = {"user_pct": agent_cpu.get("user_pct"), "sys_pct": agent_cpu.get("sys_pct"), "total_pct": total_pct}
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
    baseline_status, baseline_reason = "error", ""
    programs: list[dict[str, object]] = []
    prog_ids: list[int] = []
    try:
        lifecycle_result = run_app_runner_lifecycle(
            daemon_session=prepared_daemon_session, runner=runner, measure=measure,
            enabled_passes=enabled_passes, build_state=build_state,
            before_baseline=before_baseline, after_baseline=after_baseline,
            before_rejit=before_rejit, should_run_post_rejit=should_run_post_rejit,
        )
        programs = [dict(p) for p in (lifecycle_result.artifacts.get("programs") or [])]
        if lifecycle_result.state is not None:
            prog_ids = [int(v) for v in lifecycle_result.state.target_prog_ids if int(v) > 0]
        if lifecycle_result.baseline is not None:
            baseline_status = str(lifecycle_result.baseline.get("status") or "error")
            baseline_reason = str(lifecycle_result.baseline.get("reason") or "")
            if isinstance(mp := lifecycle_result.baseline.get("measurement"), Mapping):
                baseline_measurement = dict(mp)
        scan_results = lifecycle_result.scan_results
        rejit_apply = lifecycle_result.rejit_result
        if isinstance(lifecycle_result.post_rejit, Mapping):
            if isinstance(mp := lifecycle_result.post_rejit.get("measurement"), Mapping):
                post_measurement = dict(mp)
    except Exception as exc:
        baseline_reason = str(exc)
    process_output = dict(runner.process_output)
    site_totals = aggregate_scan_site_totals(scan_results, fields=site_totals_fields) if scan_results else zero_site_totals(site_totals_fields)
    scan_results_str = {str(key): value for key, value in scan_results.items()}
    baseline: dict[str, object] = {
        "phase": "baseline", "status": baseline_status, "reason": baseline_reason,
        "programs": programs, "prog_ids": prog_ids,
        "scan_results": scan_results_str, "site_totals": site_totals,
        "measurement": baseline_measurement, "process": process_output,
    }
    if baseline["status"] != "ok" and not baseline["reason"]:
        baseline["reason"] = (str(process_output.get("stderr_tail") or "")
                               or str(process_output.get("stdout_tail") or "") or "unknown failure")
    rejit: dict[str, object] | None = None
    if baseline["status"] == "ok" and rejit_apply is not None:
        _shared = {"programs": programs, "prog_ids": prog_ids, "scan_results": scan_results_str,
                   "site_totals": site_totals, "rejit_result": rejit_apply, "process": process_output}
        if rejit_result_has_any_apply(rejit_apply):
            rr = "" if post_measurement is not None else "post-ReJIT measurement is missing"
            rejit = {"phase": "post_rejit", "status": "ok" if not rr else "error", "reason": rr,
                     "measurement": post_measurement, **_shared}
        elif (rejit_error := str(rejit_apply.get("error") or "").strip()):
            rejit = {"phase": "post_rejit", "status": "error", "reason": rejit_error, "measurement": None, **_shared}
    return baseline, rejit


def git_sha() -> str:
    value = run_command(["git", "rev-parse", "HEAD"], timeout=15).stdout.strip()
    if not value:
        raise RuntimeError("git rev-parse returned an empty HEAD revision")
    return value


def host_metadata() -> dict[str, object]:
    metadata: dict[str, object] = {"hostname": platform.node(), "platform": platform.platform(),
                                    "kernel": platform.release(), "python": sys.version.split()[0]}
    try:
        metadata["git_sha"] = git_sha()
    except Exception as exc:
        metadata["git_sha"] = None
        metadata["git_sha_error"] = str(exc)
    return metadata


def summarize_numbers(values: Sequence[float | int | None]) -> dict[str, float | int | None]:
    filtered = [float(v) for v in values if v is not None]
    if not filtered:
        return {"count": 0, "mean": None, "median": None, "min": None, "max": None}
    return {"count": len(filtered), "mean": statistics.mean(filtered),
            "median": statistics.median(filtered), "min": min(filtered), "max": max(filtered)}


def percent_delta(before: object, after: object) -> float | None:
    if before in (None, 0) or after is None:
        return None
    return ((float(after) - float(before)) / float(before)) * 100.0


def percentile(values: Sequence[float], pct: float) -> float | None:
    items = sorted(float(v) for v in values)
    if not items: return None
    if len(items) == 1: return items[0]
    rank = max(0.0, min(1.0, pct / 100.0)) * (len(items) - 1)
    lower = int(rank)
    upper = min(len(items) - 1, lower + 1)
    return items[lower] * (1.0 - (rank - lower)) + items[upper] * (rank - lower)


def speedup_ratio(before: object, after: object) -> float | None:
    if before in (None, 0) or after in (None, 0):
        return None
    return float(before) / float(after)
