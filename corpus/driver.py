#!/usr/bin/env python3
from __future__ import annotations

import argparse
import json
import math
import sys
from collections import Counter
from dataclasses import dataclass
from datetime import datetime, timezone
from pathlib import Path
from typing import Any, Callable, Mapping, Sequence

REPO_ROOT = Path(__file__).resolve().parents[1]
if str(REPO_ROOT) not in sys.path:
    sys.path.insert(0, str(REPO_ROOT))

from runner.libs import ROOT_DIR
from runner.libs.benchmark_catalog import (
    DEFAULT_CORPUS_SAMPLES,
    DEFAULT_CORPUS_WORKLOAD_DURATION_S,
)
from runner.libs.app_runners import get_app_runner
from runner.libs.app_runners.base import AppRunner
from runner.libs.app_suite_schema import AppSpec, AppSuite, load_app_suite_from_yaml
from runner.libs.bpf_stats import compute_delta, enable_bpf_stats, sample_bpf_stats
from runner.libs.case_common import (
    CaseLifecycleState,
    LifecycleRunResult,
    live_rejit_prog_ids,
    prepare_daemon_session,
    wait_for_suite_quiescence,
)
from runner.libs.app_runners.process_support import programs_after
from runner.libs.rejit import (
    DaemonSession,
    benchmark_rejit_enabled_passes,
    benchmark_run_provenance,
    compact_rejit_results_for_artifact,
)
from runner.libs.run_artifacts import (
    ArtifactSession,
    current_process_identity,
    derive_run_type,
)


DEFAULT_MACRO_APPS_YAML = ROOT_DIR / "corpus" / "config" / "macro_apps.yaml"
DEFAULT_DAEMON = ROOT_DIR / "daemon" / "target" / "release" / "bpfrejit-daemon"
DEFAULT_OUTPUT_JSON = ROOT_DIR / "corpus" / "results" / "vm_corpus.json"
def parse_args(argv: list[str] | None = None) -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="Run the app-native corpus suite driver.")
    parser.add_argument("--suite", default=str(DEFAULT_MACRO_APPS_YAML))
    parser.add_argument("--daemon", default=str(DEFAULT_DAEMON))
    parser.add_argument("--samples", type=int, default=0)
    parser.add_argument("--output-json", default=str(DEFAULT_OUTPUT_JSON))
    parser.add_argument(
        "--no-kinsn",
        action="store_true",
        help="Disable loading kinsn modules for this corpus run.",
    )
    args = parser.parse_args(argv)
    if args.samples is not None and int(args.samples) < 0:
        raise SystemExit("--samples must be >= 0")
    return args

def _print_progress(event: str, **fields: object) -> None:
    payload = {"event": event}
    payload.update(fields)
    print(json.dumps(payload, sort_keys=True), flush=True)


def _daemon_exit_error(daemon_session: DaemonSession) -> str | None:
    returncode = daemon_session.proc.poll()
    if returncode is None:
        return None
    return f"daemon session exited early (rc={returncode})"


def _workload_seconds() -> float:
    return float(DEFAULT_CORPUS_WORKLOAD_DURATION_S)


def _app_workload_seconds(
    args: argparse.Namespace,
    app: AppSpec,
) -> float:
    if app.duration_s is not None:
        return float(app.duration_s)
    return _workload_seconds()


def _sample_count(args: argparse.Namespace) -> int:
    explicit = int(args.samples or 0)
    if explicit > 0: return explicit
    return int(DEFAULT_CORPUS_SAMPLES)


def _measure_runner_phase(
    runner: AppRunner,
    prog_ids: Sequence[int],
    *,
    workload_seconds: float,
    samples: int,
    warmup: bool = False,
) -> dict[str, object]:
    logical_prog_ids = [int(prog_id) for prog_id in prog_ids if int(prog_id) > 0]
    if not logical_prog_ids:
        raise RuntimeError("workload measurement requires at least one live BPF program id")
    workloads: list[dict[str, object]] = []
    if warmup:
        runner.run_workload(workload_seconds)
    initial_stats = sample_bpf_stats(logical_prog_ids)
    for _ in range(samples):
        workloads.append(runner.run_workload(workload_seconds).to_dict())
    final_stats = sample_bpf_stats(logical_prog_ids)
    return {
        "workloads": workloads,
        "bpf": compute_delta(initial_stats, final_stats),
    }


def _measurement_bpf_records(measurement: Mapping[str, object] | None) -> dict[int, Mapping[str, object]]:
    if not isinstance(measurement, Mapping):
        return {}
    raw_bpf = measurement.get("bpf")
    if not isinstance(raw_bpf, Mapping):
        return {}
    return {
        int(prog_id): record
        for prog_id, record in raw_bpf.items()
        if isinstance(record, Mapping)
    }


def _build_program_ratio_entry(
    app_result: Mapping[str, object],
    *,
    prog_id: int,
    baseline_record: Mapping[str, object],
    post_rejit_record: Mapping[str, object],
) -> dict[str, object] | None:
    baseline_runs = int(baseline_record.get("run_cnt_delta", 0) or 0)
    post_rejit_runs = int(post_rejit_record.get("run_cnt_delta", 0) or 0)
    if baseline_runs <= 0 or post_rejit_runs <= 0:
        return None

    baseline_avg = baseline_record.get("avg_ns_per_run")
    post_rejit_avg = post_rejit_record.get("avg_ns_per_run")
    if baseline_avg is None or post_rejit_avg is None:
        raise RuntimeError(f"missing avg_ns_per_run for comparable program id {prog_id}")

    baseline_avg_value = float(baseline_avg)
    post_rejit_avg_value = float(post_rejit_avg)
    if baseline_avg_value <= 0.0:
        raise RuntimeError(f"baseline avg_ns_per_run must be > 0 for comparable program id {prog_id}")
    if post_rejit_avg_value < 0.0:
        raise RuntimeError(f"post_rejit avg_ns_per_run must be >= 0 for comparable program id {prog_id}")

    program_name = str(post_rejit_record.get("name") or baseline_record.get("name") or f"id-{prog_id}")
    return {
        "app": str(app_result.get("app") or ""),
        "runner": str(app_result.get("runner") or ""),
        "workload": str(app_result.get("selected_workload") or ""),
        "program_id": int(prog_id),
        "program": program_name,
        "type": str(post_rejit_record.get("type") or baseline_record.get("type") or ""),
        "ratio": post_rejit_avg_value / baseline_avg_value,
        "baseline_avg_ns_per_run": baseline_avg_value,
        "post_rejit_avg_ns_per_run": post_rejit_avg_value,
        "baseline_run_cnt_delta": baseline_runs,
        "post_rejit_run_cnt_delta": post_rejit_runs,
        "baseline_run_time_ns_delta": int(baseline_record.get("run_time_ns_delta", 0) or 0),
        "post_rejit_run_time_ns_delta": int(post_rejit_record.get("run_time_ns_delta", 0) or 0),
    }


def _geometric_mean(values: Sequence[float]) -> float | None:
    if not values:
        return None
    if any(value < 0.0 for value in values):
        raise RuntimeError("geometric mean requires non-negative values")
    if any(value == 0.0 for value in values):
        return 0.0
    return math.exp(sum(math.log(value) for value in values) / len(values))


def _build_corpus_summary(
    results: Sequence[Mapping[str, object]],
) -> tuple[list[dict[str, object]], dict[str, object]]:
    per_program: list[dict[str, object]] = []
    for app_result in results:
        baseline_records = _measurement_bpf_records(app_result.get("baseline"))
        post_rejit_records = _measurement_bpf_records(app_result.get("post_rejit"))
        for prog_id in sorted(set(baseline_records) & set(post_rejit_records)):
            entry = _build_program_ratio_entry(
                app_result,
                prog_id=prog_id,
                baseline_record=baseline_records[prog_id],
                post_rejit_record=post_rejit_records[prog_id],
            )
            if entry is not None:
                per_program.append(entry)

    ratios = [float(entry["ratio"]) for entry in per_program]
    return per_program, {
        "per_program_geomean": _geometric_mean(ratios),
        "program_count": len(per_program),
        "wins": sum(1 for ratio in ratios if ratio < 1.0),
        "losses": sum(1 for ratio in ratios if ratio > 1.0),
    }

def build_markdown(payload: Mapping[str, object]) -> str:
    return "\n".join(
        [
            "# Corpus Benchmark",
            "",
            "```json",
            json.dumps(payload, indent=2, sort_keys=True, default=str),
            "```",
        ]
    )


def _build_runner_state(
    app: AppSpec,
    runner: AppRunner,
    started_prog_ids: Sequence[int],
) -> CaseLifecycleState:
    prog_ids = [int(value) for value in started_prog_ids if int(value) > 0]
    if not prog_ids: raise RuntimeError(f"{app.name}: runner did not return any live prog_ids")
    programs = [dict(program) for program in runner.programs]
    if not programs: raise RuntimeError(f"{app.name}: runner did not expose any live programs")
    return CaseLifecycleState(
        runtime=runner, prog_ids=list(prog_ids),
        artifacts={"programs": programs, "rejit_policy_context": {
            "repo": str(app.name).strip(), "category": str(app.runner).strip(), "level": "corpus"}},
    )


def _tracked_prog_id_set(prog_ids: Sequence[int]) -> frozenset[int]:
    return frozenset(int(prog_id) for prog_id in prog_ids if int(prog_id) > 0)


@dataclass(frozen=True)
class RediscoveredPrograms:
    programs: list[dict[str, object]]
    source: str


def _rediscover_session_programs(
    session: "CorpusAppSession",
    *,
    phase: str,
    missing_ids: Sequence[int],
    tracked_prog_ids: Sequence[int],
    claimed_ids: Sequence[int],
    candidate_sources: Sequence[tuple[str, Callable[[], object]]],
) -> RediscoveredPrograms:
    def normalize_programs(programs: object) -> list[dict[str, object]]:
        if not isinstance(programs, Sequence) or isinstance(programs, (str, bytes, bytearray)):
            return []
        deduped: dict[int, dict[str, object]] = {}
        for program in programs:
            if not isinstance(program, Mapping):
                continue
            prog_id = int(program.get("id", 0) or 0)
            if prog_id <= 0:
                continue
            deduped[prog_id] = dict(program)
        return [deduped[prog_id] for prog_id in sorted(deduped)]

    def program_identity(program: Mapping[str, object]) -> tuple[str, str, str, str, int]:
        return (
            str(program.get("name") or ""),
            str(program.get("type") or ""),
            str(program.get("attach_type") or program.get("expected_attach_type") or ""),
            str(program.get("attach_to") or program.get("attach_target") or program.get("attach_btf_name") or ""),
            int(program.get("attach_btf_id", 0) or 0),
        )

    expected_programs = normalize_programs(session.runner.live_rejit_programs())
    if not expected_programs:
        expected_programs = normalize_programs(session.state.artifacts.get("programs"))
    tracked_ids = [int(prog_id) for prog_id in tracked_prog_ids if int(prog_id) > 0]
    if not expected_programs:
        raise RuntimeError(
            f"{session.app.name}: tracked BPF program ids disappeared before {phase}; "
            f"rediscovery found no live replacement programs: "
            f"missing_ids={list(missing_ids)}, tracked_ids={tracked_ids}"
        )

    claimed = {int(prog_id) for prog_id in claimed_ids if int(prog_id) > 0}
    overlapping_claimed: set[int] = set()
    for source, load_programs in candidate_sources:
        remaining = Counter(program_identity(program) for program in expected_programs)
        matched_programs: list[dict[str, object]] = []
        for program in normalize_programs(load_programs()):
            identity = program_identity(program)
            if remaining[identity] <= 0:
                continue
            prog_id = int(program["id"])
            if prog_id in claimed:
                overlapping_claimed.add(prog_id)
                continue
            matched_programs.append(dict(program))
            remaining[identity] -= 1
        if matched_programs:
            return RediscoveredPrograms(programs=matched_programs, source=source)

    if claimed_overlap := sorted(overlapping_claimed):
        raise RuntimeError(
            f"{session.app.name}: tracked BPF program ids disappeared before {phase}; "
            f"rediscovered replacements overlap another session's claimed ids: "
            f"missing_ids={list(missing_ids)}, tracked_ids={tracked_ids}, "
            f"claimed_overlap={claimed_overlap}"
        )
    raise RuntimeError(
        f"{session.app.name}: tracked BPF program ids disappeared before {phase}; "
        f"rediscovery found no live replacement programs: "
        f"missing_ids={list(missing_ids)}, tracked_ids={tracked_ids}"
    )


def _refresh_active_session_programs(
    sessions: Sequence["CorpusAppSession"],
    phase: str,
) -> None:
    current_programs_by_id: dict[int, dict[str, object]] = {}
    current_programs_raw = programs_after(())
    if isinstance(current_programs_raw, Sequence) and not isinstance(
        current_programs_raw,
        (str, bytes, bytearray),
    ):
        for program in current_programs_raw:
            if not isinstance(program, Mapping):
                continue
            prog_id = int(program.get("id", 0) or 0)
            if prog_id <= 0:
                continue
            current_programs_by_id[prog_id] = dict(program)
    current_programs = [current_programs_by_id[prog_id] for prog_id in sorted(current_programs_by_id)]
    current_prog_ids = frozenset(current_programs_by_id)
    claimed_ids: set[int] = set()
    for session in sessions:
        tracked_prog_ids = _tracked_prog_id_set(session.state.prog_ids)
        if not tracked_prog_ids:
            raise RuntimeError(f"{session.app.name}: no tracked BPF program ids remain before {phase}")
        live_programs: list[dict[str, object]]
        if missing_ids := sorted(tracked_prog_ids - current_prog_ids):
            discover_source = ""
            candidate_sources: list[tuple[str, Callable[[], object]]] = []
            refresh = getattr(session.runner, "refresh_programs", None)
            if callable(refresh):
                discover_source = "runner.refresh_programs"
                candidate_sources.append((discover_source, refresh))
            else:
                runtime_session = getattr(session.runner, "session", None)
                refresh = getattr(runtime_session, "refresh_programs", None)
                if callable(refresh):
                    discover_source = "runner.session.refresh_programs"
                    candidate_sources.append((discover_source, refresh))
                else:
                    discover = getattr(runtime_session, "_discover_programs", None)
                    if callable(discover):
                        discover_source = "runner.session._discover_programs"
                        candidate_sources.append((discover_source, discover))
            candidate_sources.append(("bpftool prog show", lambda: current_programs))
            rediscovered = _rediscover_session_programs(
                session,
                phase=phase,
                missing_ids=missing_ids,
                tracked_prog_ids=sorted(tracked_prog_ids),
                claimed_ids=sorted(claimed_ids),
                candidate_sources=candidate_sources,
            )
            live_programs = rediscovered.programs
            discover_source = discover_source or rediscovered.source
            expected_count = len(tracked_prog_ids)
            refreshed_count = len(live_programs)
            refreshed_ids = [int(program["id"]) for program in live_programs]
            refreshed_id_set = set(refreshed_ids)
            if refreshed_id_set != tracked_prog_ids:
                raise RuntimeError(
                    f"{session.app.name}: rediscovery changed tracked BPF program ids "
                    f"before {phase}: refreshed_count={refreshed_count}, "
                    f"expected_count={expected_count}, expected_ids={sorted(tracked_prog_ids)}, "
                    f"refreshed_ids={refreshed_ids}, "
                    f"missing_ids={sorted(tracked_prog_ids - refreshed_id_set)}, "
                    f"unexpected_ids={sorted(refreshed_id_set - tracked_prog_ids)}, "
                    f"original_missing_ids={missing_ids}, "
                    f"discover_source={discover_source}"
                )
        else:
            if overlapping_ids := sorted(tracked_prog_ids & claimed_ids):
                raise RuntimeError(
                    f"{session.app.name}: BPF program ids are already claimed by another session before {phase}: "
                    f"{overlapping_ids}"
                )
            live_programs = [dict(current_programs_by_id[prog_id]) for prog_id in sorted(tracked_prog_ids)]
        if overlapping_ids := sorted(
            int(program["id"]) for program in live_programs if int(program["id"]) in claimed_ids
        ):
            raise RuntimeError(
                f"{session.app.name}: BPF program ids are already claimed by another session before {phase}: "
                f"{overlapping_ids}"
            )
        session.state.prog_ids = [int(program["id"]) for program in live_programs]
        session.state.artifacts["programs"] = live_programs
        session.runner.programs = [dict(program) for program in live_programs]
        claimed_ids.update(session.state.prog_ids)


def _build_app_error_result(
    app: AppSpec,
    *,
    error: str,
    baseline_measurement: Mapping[str, object] | None = None,
    apply_result: Mapping[str, object] | None = None,
    rejit_measurement: Mapping[str, object] | None = None,
) -> dict[str, object]:
    return {
        "app": app.name,
        "runner": app.runner,
        "selected_workload": app.workload_for("corpus"),
        "status": "error",
        "error": str(error),
        "baseline": dict(baseline_measurement) if isinstance(baseline_measurement, Mapping) else None,
        "post_rejit": dict(rejit_measurement) if isinstance(rejit_measurement, Mapping) else None,
        "rejit_result": dict(apply_result) if isinstance(apply_result, Mapping) else None,
    }


def _build_app_ok_result(
    app: AppSpec,
    *,
    baseline_measurement: Mapping[str, object],
    apply_result: Mapping[str, object] | None,
    rejit_measurement: Mapping[str, object] | None,
) -> dict[str, object]:
    return {
        "app": app.name,
        "runner": app.runner,
        "selected_workload": app.workload_for("corpus"),
        "status": "ok",
        "error": "",
        "baseline": dict(baseline_measurement),
        "post_rejit": dict(rejit_measurement) if isinstance(rejit_measurement, Mapping) else None,
        "rejit_result": dict(apply_result) if isinstance(apply_result, Mapping) else None,
    }


@dataclass
class CorpusAppSession:
    app: AppSpec
    runner: AppRunner
    state: CaseLifecycleState
    workload_seconds: float


def _run_suite_lifecycle_sessions(
    prepared_daemon_session: object,
    sessions: Sequence[CorpusAppSession],
    *,
    samples: int,
) -> tuple[list[LifecycleRunResult], str]:
    if not hasattr(prepared_daemon_session, "session"):
        raise RuntimeError("prepared daemon session is required")
    active_daemon_session = prepared_daemon_session.session
    session_list = list(sessions)
    lifecycle_results = [
        LifecycleRunResult(state=session.state, baseline=None, rejit_result=None, post_rejit=None)
        for session in session_list
    ]
    session_results = list(zip(session_list, lifecycle_results))
    fatal_error = ""
    apply_enabled_passes = benchmark_rejit_enabled_passes()

    def stop_session(session: CorpusAppSession, result: LifecycleRunResult) -> None:
        if result.stopped:
            return
        try:
            session.runner.stop()
        except Exception as exc:
            result.stop_error = str(exc)
        finally:
            result.stopped = True

    def record_baseline_failure(
        session: CorpusAppSession,
        result: LifecycleRunResult,
        error: str,
    ) -> None:
        result.error = str(error)
        stop_session(session, result)
        try:
            wait_for_suite_quiescence()
        except Exception as quiesce_exc:
            extra = str(quiesce_exc)
            result.error = f"{result.error}; {extra}" if result.error else extra

    def check_daemon() -> None:
        if daemon_error := _daemon_exit_error(active_daemon_session):
            raise RuntimeError(daemon_error)

    def session_workload(session: CorpusAppSession) -> str:
        workload_for = getattr(session.app, "workload_for", None)
        if callable(workload_for):
            return str(workload_for("corpus"))
        return str(getattr(session.app, "workload", ""))

    try:
        active_pairs = list(session_results)
        if active_pairs:
            _print_progress("lifecycle_phase_start", phase="baseline_refresh", apps=len(active_pairs))
            _refresh_active_session_programs([session for session, _ in active_pairs], "baseline")
            _print_progress("lifecycle_phase_done", phase="baseline_refresh", apps=len(active_pairs))

        surviving_pairs: list[tuple[CorpusAppSession, LifecycleRunResult]] = []
        for session, result in active_pairs:
            prog_ids = [int(value) for value in result.state.prog_ids if int(value) > 0]
            if not prog_ids:
                record_baseline_failure(session, result, "lifecycle did not provide any program ids")
            else:
                try:
                    _print_progress(
                        "measurement_start",
                        app=session.app.name,
                        runner=session.app.runner,
                        phase="baseline",
                        workload=session_workload(session),
                        samples=samples,
                    )
                    result.baseline = _measure_runner_phase(
                        session.runner,
                        result.state.prog_ids,
                        workload_seconds=session.workload_seconds,
                        samples=samples,
                        warmup=True,
                    )
                    _print_progress(
                        "measurement_done",
                        app=session.app.name,
                        runner=session.app.runner,
                        phase="baseline",
                        status="ok",
                    )
                    surviving_pairs.append((session, result))
                except Exception as exc:
                    _print_progress(
                        "measurement_done",
                        app=session.app.name,
                        runner=session.app.runner,
                        phase="baseline",
                        status="error",
                        error=str(exc),
                    )
                    record_baseline_failure(session, result, str(exc))
            check_daemon()

        active_pairs = surviving_pairs
        if active_pairs:
            _print_progress("lifecycle_phase_start", phase="rejit_refresh", apps=len(active_pairs))
            _refresh_active_session_programs([session for session, _ in active_pairs], "rejit")
            _print_progress("lifecycle_phase_done", phase="rejit_refresh", apps=len(active_pairs))

        surviving_pairs = []
        for session, result in active_pairs:
            prog_ids = live_rejit_prog_ids(result.state)
            if not prog_ids:
                raise RuntimeError("lifecycle did not provide any program ids after baseline")
            result.rejit_prog_ids = prog_ids
            surviving_pairs.append((session, result))

        active_pairs = surviving_pairs
        for session, result in active_pairs:
            _print_progress(
                "rejit_start",
                app=session.app.name,
                runner=session.app.runner,
                program_count=len(result.rejit_prog_ids),
            )
            result.rejit_result = active_daemon_session.apply_rejit(
                result.rejit_prog_ids,
                enabled_passes=apply_enabled_passes,
            )
            _print_progress(
                "rejit_done",
                app=session.app.name,
                runner=session.app.runner,
                status="ok" if not str(result.rejit_result.get("error") or "").strip() else "error",
            )
            check_daemon()

        for session, result in active_pairs:
            try:
                _print_progress(
                    "measurement_start",
                    app=session.app.name,
                    runner=session.app.runner,
                    phase="post_rejit",
                    workload=session_workload(session),
                    samples=samples,
                )
                result.post_rejit = _measure_runner_phase(
                    session.runner,
                    result.state.prog_ids,
                    workload_seconds=session.workload_seconds,
                    samples=samples,
                    warmup=True,
                )
                _print_progress(
                    "measurement_done",
                    app=session.app.name,
                    runner=session.app.runner,
                    phase="post_rejit",
                    status="ok",
                )
            except Exception as exc:
                result.error = str(exc)
                _print_progress(
                    "measurement_done",
                    app=session.app.name,
                    runner=session.app.runner,
                    phase="post_rejit",
                    status="error",
                    error=str(exc),
                )
            check_daemon()
    except Exception as exc:
        fatal_error = str(exc)
    finally:
        for session, result in session_results:
            if not result.stopped:
                stop_session(session, result)

    return lifecycle_results, fatal_error


def run_suite(args: argparse.Namespace, suite: AppSuite) -> dict[str, object]:
    suite_path = suite.manifest_path.resolve()
    daemon_binary = Path(args.daemon).resolve()
    if not daemon_binary.exists():
        raise RuntimeError(f"daemon binary not found: {daemon_binary}")

    workload_seconds = _workload_seconds()
    samples = _sample_count(args)
    results_by_name: dict[str, dict[str, object]] = {}
    lifecycle_by_app: dict[str, Any] = {}
    completed_apps: set[str] = set()
    fatal_error = ""

    with DaemonSession.start(daemon_binary, load_kinsn=not bool(args.no_kinsn)) as daemon_session:
        prepared_daemon_session = prepare_daemon_session(daemon_session)
        sessions: list[CorpusAppSession] = []

        try:
            with enable_bpf_stats():
                for app in suite.apps:
                    _print_progress("app_start", app=app.name, runner=app.runner, workload=app.workload_for("corpus"))
                    app_workload_seconds = _app_workload_seconds(args, app)
                    runner: AppRunner | None = None
                    try:
                        runner = get_app_runner(app.runner, workload=app.workload_for("corpus"), **app.args)
                        started_prog_ids = [int(value) for value in runner.start() if int(value) > 0]
                        state = _build_runner_state(app, runner, started_prog_ids)
                        session = CorpusAppSession(
                            app=app,
                            runner=runner,
                            state=state,
                            workload_seconds=app_workload_seconds,
                        )
                        sessions.append(session)
                    except Exception as exc:
                        stop_error = ""
                        quiesce_error = ""
                        if runner is not None:
                            try:
                                runner.stop()
                            except Exception as stop_exc:
                                stop_error = str(stop_exc)
                            try:
                                wait_for_suite_quiescence()
                            except Exception as quiesce_exc:
                                quiesce_error = str(quiesce_exc)
                        error_message = str(exc)
                        if stop_error:
                            error_message = f"{error_message}; stop failed: {stop_error}"
                        if quiesce_error:
                            error_message = f"{error_message}; quiesce failed: {quiesce_error}"
                        result = _build_app_error_result(app, error=error_message)
                        results_by_name[app.name] = result
                        completed_apps.add(app.name)
                        _print_progress("app_done", app=app.name, status=result.get("status"),
                                        error=result.get("error"))
                    daemon_error = _daemon_exit_error(daemon_session)
                    if daemon_error is not None: fatal_error = daemon_error; break

                if not fatal_error and sessions:
                    lifecycle_results, fatal_error = _run_suite_lifecycle_sessions(
                        prepared_daemon_session,
                        sessions,
                        samples=samples,
                    )
                    lifecycle_by_app = {session.app.name: lifecycle for session, lifecycle in zip(sessions, lifecycle_results)}
        finally:
            for session in sessions:
                lifecycle = lifecycle_by_app.get(session.app.name)
                if lifecycle is not None and bool(lifecycle.stopped): continue
                try:
                    session.runner.stop()
                except Exception as exc:
                    if lifecycle is not None:
                        lifecycle.stop_error = str(exc)
                        lifecycle.stopped = True
                else:
                    if lifecycle is not None:
                        lifecycle.stopped = True
        for session in sessions:
            if session.app.name in completed_apps: continue
            lifecycle = lifecycle_by_app.get(session.app.name)
            baseline_measurement = dict(lifecycle.baseline) if lifecycle is not None and isinstance(lifecycle.baseline, Mapping) else None
            apply_result = dict(lifecycle.rejit_result or {}) if lifecycle is not None else {}
            rejit_measurement = dict(lifecycle.post_rejit) if lifecycle is not None and isinstance(lifecycle.post_rejit, Mapping) else None
            error_message = str(lifecycle.error or "") if lifecycle is not None else ""
            stop_error = str(lifecycle.stop_error or "") if lifecycle is not None else ""
            if fatal_error: error_message = fatal_error if not error_message else f"{error_message}; {fatal_error}"
            if stop_error: error_message = stop_error if not error_message else f"{error_message}; stop failed: {stop_error}"
            if error_message:
                result = _build_app_error_result(
                    session.app,
                    error=error_message,
                    baseline_measurement=baseline_measurement,
                    apply_result=apply_result,
                    rejit_measurement=rejit_measurement,
                )
            else:
                apply_error = str(apply_result.get("error") or "").strip() if isinstance(apply_result, Mapping) else ""
                if apply_error:
                    result = _build_app_error_result(
                        session.app,
                        error=apply_error,
                        baseline_measurement=baseline_measurement,
                        apply_result=apply_result,
                        rejit_measurement=rejit_measurement,
                    )
                elif baseline_measurement is None:
                    result = _build_app_error_result(
                        session.app,
                        error="baseline measurement is missing",
                        baseline_measurement=baseline_measurement,
                        apply_result=apply_result,
                        rejit_measurement=rejit_measurement,
                    )
                else:
                    result = _build_app_ok_result(
                        session.app,
                        baseline_measurement=baseline_measurement,
                        apply_result=apply_result,
                        rejit_measurement=rejit_measurement,
                    )
            results_by_name[session.app.name] = result; completed_apps.add(session.app.name)
            _print_progress("app_done", app=session.app.name, status=result.get("status"),
                            error=result.get("error"))

        kinsn_metadata = dict(prepared_daemon_session.metadata)

    results = [
        results_by_name.get(app.name)
        or _build_app_error_result(
            app,
            error=fatal_error or "corpus suite did not produce a result",
        )
        for app in suite.apps
    ]
    per_program, summary = _build_corpus_summary(results)
    payload = {
        "generated_at": datetime.now(timezone.utc).isoformat(),
        "manifest": str(suite_path),
        "suite_name": suite.suite_name,
        "daemon": str(daemon_binary),
        "samples": samples,
        "workload_seconds": workload_seconds,
        "results": results,
        "per_program": per_program,
        "summary": summary,
        "kinsn_modules": kinsn_metadata,
        "status": "error" if any(str(result.get("status") or "error") != "ok" for result in results) else "ok",
    }
    if fatal_error:
        payload["fatal_error"] = fatal_error
    return payload


def build_run_metadata(
    args: argparse.Namespace,
    *,
    resolved_samples: int,
    resolved_workload_seconds: float,
) -> dict[str, object]:
    metadata = {
        "generated_at": datetime.now(timezone.utc).isoformat(),
        "suite": "corpus",
        "manifest": str(Path(args.suite).resolve()),
        "samples": int(resolved_samples),
        "workload_seconds": float(resolved_workload_seconds),
        "kinsn_enabled": not bool(args.no_kinsn),
    }
    metadata.update(benchmark_run_provenance())
    metadata.update(current_process_identity())
    return metadata


def main(argv: list[str] | None = None) -> int:
    args = parse_args(argv)
    output_json = Path(args.output_json).resolve()
    suite = load_app_suite_from_yaml(Path(args.suite).resolve())
    resolved_workload_seconds = _workload_seconds()
    resolved_samples = _sample_count(args)
    run_type = derive_run_type(output_json, "vm_corpus")
    started_at = datetime.now(timezone.utc).isoformat()
    progress_payload: dict[str, object] = {
        "suite": "corpus",
        "status": "running",
        "samples": int(resolved_samples),
        "workload_seconds": float(resolved_workload_seconds),
        "kinsn_enabled": not bool(args.no_kinsn),
    }

    def build_artifact_metadata(
        status: str,
        session_started_at: str,
        updated_at: str,
        error_message: str | None,
    ) -> dict[str, object]:
        metadata = build_run_metadata(
            args,
            resolved_samples=resolved_samples,
            resolved_workload_seconds=resolved_workload_seconds,
        )
        metadata["status"] = status
        metadata["started_at"] = session_started_at
        metadata["last_updated_at"] = updated_at
        if error_message:
            metadata["error_message"] = error_message
        return metadata

    session = ArtifactSession(
        output_path=output_json,
        run_type=run_type,
        generated_at=started_at,
        metadata_builder=build_artifact_metadata,
    )
    session.write(status="running", progress_payload=progress_payload)

    try:
        payload = run_suite(args, suite)
        payload = compact_rejit_results_for_artifact(payload)
        markdown = build_markdown(payload) + "\n"
        payload_status = str(payload.get("status") or "error").lower()
        error_message = str(payload.get("fatal_error") or "").strip()
        if payload_status == "ok":
            session.write(
                status="completed",
                progress_payload={
                    "suite": "corpus",
                    "status": "completed",
                    "completed_at": datetime.now(timezone.utc).isoformat(),
                },
                result_payload=payload,
                detail_texts={"result.md": markdown},
            )
        else:
            session.write(
                status="error",
                progress_payload={
                    "suite": "corpus",
                    "status": "error",
                    "failed_at": datetime.now(timezone.utc).isoformat(),
                    "error_message": error_message or "corpus suite reported errors",
                },
                result_payload=payload,
                detail_texts={"result.md": markdown},
                error_message=error_message or "corpus suite reported errors",
            )
        print(
            json.dumps(
                {
                    "status": payload_status,
                    "artifact_run_dir": str(session.run_dir),
                    "artifact_metadata": str(session.run_dir / "metadata.json"),
                },
                indent=2,
            )
        )
        return 0 if payload_status == "ok" else 1
    except Exception as exc:
        session.write(
            status="error",
            progress_payload={
                "suite": "corpus",
                "status": "error",
                "failed_at": datetime.now(timezone.utc).isoformat(),
                "error_message": str(exc),
            },
            error_message=str(exc),
        )
        raise

if __name__ == "__main__":
    raise SystemExit(main())
