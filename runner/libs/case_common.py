from __future__ import annotations

import copy
import os
import platform
import statistics
import sys
import threading
import time
from dataclasses import dataclass, field
from typing import Callable, Mapping, Sequence

from runner.libs import run_command
from runner.libs.app_runners.base import AppRunner
from runner.libs.bpf_stats import compute_delta, list_program_ids, sample_bpf_stats
from runner.libs.rejit import DaemonSession
from runner.libs.kinsn import relpath
from runner.libs.metrics import sample_cpu_usage, sample_total_cpu_usage, start_sampler_thread

DEFAULT_SUITE_QUIESCE_TIMEOUT_S = 20.0
DEFAULT_SUITE_QUIESCE_STABLE_S = 2.0
DEFAULT_SUITE_QUIESCE_POLL_S = 0.2
_BENCH_PASSES_ENV = "BPFREJIT_BENCH_PASSES"


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
        current_ids = tuple(sorted(list_program_ids()))
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
def rejit_result_has_any_apply(rejit_result: Mapping[str, object] | None) -> bool:
    def _non_negative_int(value: object) -> int | None:
        if isinstance(value, bool) or not isinstance(value, int):
            return None
        return value if value >= 0 else None

    def _record_changed(record: Mapping[str, object] | None) -> bool:
        if not isinstance(record, Mapping):
            return False
        changed = record.get("changed")
        if isinstance(changed, bool) and changed:
            return True
        summary = record.get("summary")
        if isinstance(summary, Mapping):
            if (_non_negative_int(summary.get("total_sites_applied")) or 0) > 0:
                return True
        debug_result = record.get("debug_result")
        if isinstance(debug_result, Mapping):
            if isinstance(debug_result.get("changed"), bool) and bool(debug_result.get("changed")):
                return True
            debug_summary = debug_result.get("summary")
            if isinstance(debug_summary, Mapping):
                if (_non_negative_int(debug_summary.get("total_sites_applied")) or 0) > 0:
                    return True
        return False

    if not isinstance(rejit_result, Mapping):
        return False
    per_program = rejit_result.get("per_program")
    if isinstance(per_program, Mapping) and per_program:
        return any(_record_changed(r if isinstance(r, Mapping) else None) for r in per_program.values())
    return _record_changed(rejit_result)


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


@dataclass
class CaseLifecycleState:
    runtime: AppRunner
    prog_ids: list[int] = field(default_factory=list)
    artifacts: dict[str, object] = field(default_factory=dict)


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
    state: CaseLifecycleState | None
    baseline: Mapping[str, object] | None
    scan_results: dict[int, dict[str, object]]
    rejit_result: dict[str, object] | None
    post_rejit: Mapping[str, object] | None
    artifacts: dict[str, object] = field(default_factory=dict)
    abort: LifecycleAbort | None = None


def prepare_daemon_session(
    daemon_session: DaemonSession,
) -> PreparedDaemonSession:
    metadata = copy.deepcopy(getattr(daemon_session, "kinsn_metadata", {}) or {})
    if not bool(getattr(daemon_session, "load_kinsn", False)):
        return PreparedDaemonSession(session=daemon_session, metadata={})
    if not metadata:
        raise RuntimeError("daemon session requested kinsn loading but did not capture kinsn metadata")
    metadata["daemon_binary"] = relpath(daemon_session.daemon_binary.resolve())
    return PreparedDaemonSession(session=daemon_session, metadata=metadata)

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
    return {}


def _resolve_scan_pass_selection(
    enabled_passes: Sequence[str] | None,
) -> tuple[list[str], object | None]:
    from runner.libs.rejit import (
        benchmark_policy_candidate_passes,
        benchmark_rejit_enabled_passes,
        load_benchmark_config,
    )

    explicit_passes = _normalize_enabled_passes(enabled_passes)
    if enabled_passes is not None:
        return explicit_passes, None
    if _BENCH_PASSES_ENV in os.environ:
        return benchmark_rejit_enabled_passes(), None

    benchmark_config = load_benchmark_config()
    return benchmark_policy_candidate_passes(benchmark_config), benchmark_config


def _resolve_apply_passes_by_program(
    *,
    prog_ids: Sequence[int],
    lifecycle_state: CaseLifecycleState,
    scan_results: Mapping[int, Mapping[str, object]],
    enabled_passes: Sequence[str] | None,
    benchmark_config: object | None,
) -> dict[int, list[str]]:
    from runner.libs.rejit import benchmark_rejit_enabled_passes, resolve_program_enabled_passes

    explicit_passes = _normalize_enabled_passes(enabled_passes)
    if enabled_passes is not None:
        return {int(prog_id): list(explicit_passes) for prog_id in prog_ids}
    if _BENCH_PASSES_ENV in os.environ:
        selected = benchmark_rejit_enabled_passes()
        return {int(prog_id): list(selected) for prog_id in prog_ids}
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
        for prog_id in prog_ids
    }


def _merge_group_rejit_results(
    *,
    prog_ids: Sequence[int],
    group_results: Sequence[tuple[list[int], Mapping[str, object]]],
) -> dict[str, object]:
    per_program: dict[int, dict[str, object]] = {}
    outputs: list[str] = []
    exit_code = 0
    errors: list[str] = []

    def _fail_rec(pid: int, ec: int, err: str) -> dict[str, object]:
        return {
            "prog_id": int(pid),
            "applied": False,
            "changed": False,
            "output": "",
            "exit_code": ec,
            "error": err,
        }

    for group_prog_ids, result in group_results:
        if (output := str(result.get("output") or "")):
            outputs.append(output)
        group_exit_code = int(result.get("exit_code", 0) or 0)
        exit_code = max(exit_code, group_exit_code)
        error = str(result.get("error") or "").strip()
        if error:
            errors.append(error)
        raw_per_program = result.get("per_program")
        if not isinstance(raw_per_program, Mapping):
            if group_exit_code != 0 or error:
                for prog_id in group_prog_ids:
                    per_program[int(prog_id)] = _fail_rec(
                        int(prog_id),
                        group_exit_code,
                        error or "group REJIT apply failed before per-program records were available",
                    )
                continue
            raise RuntimeError("group REJIT result is missing per_program records")
        for prog_id in group_prog_ids:
            raw_record = raw_per_program.get(int(prog_id)) or raw_per_program.get(str(int(prog_id)))
            if isinstance(raw_record, Mapping):
                per_program[int(prog_id)] = dict(raw_record)
                continue
            if group_exit_code != 0 or error:
                per_program[int(prog_id)] = _fail_rec(
                    int(prog_id),
                    group_exit_code,
                    error or f"group REJIT apply failed for prog {prog_id}",
                )
                continue
            raise RuntimeError(f"group REJIT result is missing per_program record for prog {prog_id}")

    applied = any(bool(record.get("applied")) for record in per_program.values())
    changed = any(bool(record.get("changed")) for record in per_program.values())
    n_req = len([p for p in prog_ids if int(p) > 0])
    n_applied = sum(1 for r in per_program.values() if bool(r.get("applied")))
    merged: dict[str, object] = {
        "applied": applied,
        "changed": changed,
        "output": "\n".join(f for f in outputs if f),
        "exit_code": exit_code, "per_program": per_program,
        "program_counts": {"requested": n_req, "applied": n_applied, "not_applied": n_req - n_applied},
        "error": "; ".join(errors),
    }
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
    resolve_rejit_prog_ids: Callable[[object, CaseLifecycleState, Mapping[str, object]], Sequence[int] | None] | None = None,
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
    active_daemon_session = daemon_session.session

    def _abort_result(bl: Mapping[str, object] | None) -> LifecycleRunResult:
        assert abort is not None
        artifacts.update(dict(abort.artifacts) if abort.artifacts else {})
        return LifecycleRunResult(
            state=lifecycle_state,
            baseline=bl,
            scan_results={},
            rejit_result=None,
            post_rejit=None,
            artifacts=artifacts,
            abort=abort,
        )

    try:
        lifecycle_state = start(setup_state)
        artifacts.update(dict(lifecycle_state.artifacts))
        prog_ids = [int(v) for v in lifecycle_state.prog_ids if int(v) > 0]
        if not prog_ids:
            raise RuntimeError("lifecycle did not provide any program ids")

        if before_baseline is not None:
            abort = before_baseline(setup_state, lifecycle_state)
            if abort is not None:
                return _abort_result(None)

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
                return _abort_result(baseline)

        prog_ids = [int(v) for v in lifecycle_state.prog_ids if int(v) > 0]
        if resolve_rejit_prog_ids is not None:
            prog_ids = [
                int(v)
                for v in (resolve_rejit_prog_ids(setup_state, lifecycle_state, baseline) or [])
                if int(v) > 0
            ]
        if not prog_ids:
            raise RuntimeError("lifecycle did not provide any program ids after baseline")

        scan_enabled_passes, benchmark_config = _resolve_scan_pass_selection(
            enabled_passes,
        )

        daemon_error = _daemon_exit_error(active_daemon_session)
        if daemon_error is not None:
            raise RuntimeError(daemon_error)
        scan_results = active_daemon_session.scan_programs(
            prog_ids,
            enabled_passes=scan_enabled_passes,
        )
        daemon_error = _daemon_exit_error(active_daemon_session)
        if daemon_error is not None:
            raise RuntimeError(daemon_error)
        apply_enabled_passes_by_prog = _resolve_apply_passes_by_program(
            prog_ids=prog_ids,
            lifecycle_state=lifecycle_state,
            scan_results=scan_results,
            enabled_passes=enabled_passes,
            benchmark_config=benchmark_config,
        )
        grouped_prog_ids: dict[tuple[str, ...], list[int]] = {}
        for prog_id in prog_ids:
            pass_tuple = tuple(apply_enabled_passes_by_prog.get(int(prog_id), ()))
            grouped_prog_ids.setdefault(pass_tuple, []).append(int(prog_id))

        group_rejit_results: list[tuple[list[int], Mapping[str, object]]] = [
            (list(gids), active_daemon_session.apply_rejit(gids, enabled_passes=list(pt)))
            for pt, gids in grouped_prog_ids.items()
        ]
        rejit_result = _merge_group_rejit_results(
            prog_ids=prog_ids,
            group_results=group_rejit_results,
        )
        run_post_rejit = rejit_result_has_any_apply(rejit_result)
        if should_run_post_rejit is not None:
            run_post_rejit = bool(should_run_post_rejit(rejit_result))
        if run_post_rejit:
            post_rejit = workload(setup_state, lifecycle_state, "post_rejit")
        return LifecycleRunResult(
            state=lifecycle_state,
            baseline=baseline,
            scan_results=scan_results,
            rejit_result=rejit_result,
            post_rejit=post_rejit,
            artifacts=artifacts,
            abort=abort,
        )
    finally:
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
        runtime=runner, prog_ids=list(prog_ids),
        artifacts={"programs": programs},
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
    resolve_rejit_prog_ids: Callable[[object, CaseLifecycleState, Mapping[str, object]], Sequence[int] | None] | None = None,
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
        resolve_rejit_prog_ids=resolve_rejit_prog_ids,
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
    stats_source = sample_bpf_stats(list(prog_ids)) if initial_stats is None else initial_stats
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
    after_bpf = sample_bpf_stats(list(prog_ids))
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
            prog_ids = [int(v) for v in lifecycle_result.state.prog_ids if int(v) > 0]
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
    site_totals = zero_site_totals(site_totals_fields)
    for record in scan_results.values():
        counts = record.get("counts") or {}
        for site_field in site_totals:
            site_totals[site_field] += int(counts.get(site_field, 0) or 0)
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
