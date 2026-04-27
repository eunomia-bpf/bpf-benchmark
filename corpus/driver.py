#!/usr/bin/env python3
from __future__ import annotations

import argparse
import json
import sys
import time
from dataclasses import dataclass
from datetime import datetime, timezone
from pathlib import Path
from typing import Any, Mapping, Sequence

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
from runner.libs.app_runners.scx import ScxRunner
from runner.libs.app_suite_schema import AppSpec, AppSuite, load_app_suite_from_yaml
from runner.libs.bpf_stats import compute_delta, enable_bpf_stats, sample_bpf_stats
from runner.libs.case_common import (
    CaseLifecycleState,
    prepare_daemon_session,
    run_lifecycle_sessions,
    wait_for_suite_quiescence,
)
from runner.libs.app_runners.process_support import programs_after
from runner.libs.rejit import (
    DaemonSession,
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
    parser.add_argument(
        "--filter",
        action="append",
        dest="filters",
        help="Substring filter on app name/runner/workload. Repeat for OR. Selects a subset of apps to run.",
    )
    parser.add_argument(
        "--workload-seconds",
        type=float,
        default=None,
        help=f"Override per-app workload duration in seconds (default: {DEFAULT_CORPUS_WORKLOAD_DURATION_S}).",
    )
    args = parser.parse_args(argv)
    if args.samples is not None and int(args.samples) < 0:
        raise SystemExit("--samples must be >= 0")
    if args.workload_seconds is not None and args.workload_seconds <= 0:
        raise SystemExit("--workload-seconds must be > 0")
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


def _workload_seconds(args: argparse.Namespace | None = None) -> float:
    override = getattr(args, "workload_seconds", None) if args is not None else None
    if override is not None:
        return float(override)
    return float(DEFAULT_CORPUS_WORKLOAD_DURATION_S)


def _app_workload_seconds(
    args: argparse.Namespace,
    app: AppSpec,
) -> float:
    if app.duration_s is not None:
        return float(app.duration_s)
    return _workload_seconds(args)


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
    sampled_prog_id_map: Mapping[int, int] | None = None,
) -> dict[str, object]:
    logical_prog_ids = [int(prog_id) for prog_id in prog_ids if int(prog_id) > 0]
    logical_programs = [
        dict(program)
        for program in getattr(runner, "programs", [])
        if int(program.get("id", 0) or 0) > 0 and str(program.get("name") or "").strip()
    ]
    sampled_prog_ids = (
        [
            int(sampled_prog_id_map.get(prog_id, 0) or 0)
            for prog_id in logical_prog_ids
            if int(sampled_prog_id_map.get(prog_id, 0) or 0) > 0
        ]
        if sampled_prog_id_map is not None
        else list(logical_prog_ids)
    )
    workloads: list[dict[str, object]] = []
    live_prog_id_map: dict[int, int] = {}
    live_programs: list[dict[str, object]] = []
    if isinstance(runner, ScxRunner) and sampled_prog_id_map is None:
        initial_stats, live_prog_id_map, live_programs = _sample_scx_measurement_stats(
            runner,
            logical_prog_ids,
            previous_programs=logical_programs,
        )
    else:
        initial_stats = sample_bpf_stats(sampled_prog_ids)
    for _ in range(samples):
        workloads.append(runner.run_workload(workload_seconds).to_dict())
    if isinstance(runner, ScxRunner) and sampled_prog_id_map is None:
        final_stats, live_prog_id_map, live_programs = _sample_scx_measurement_stats(
            runner,
            logical_prog_ids,
            previous_programs=logical_programs,
        )
    else:
        final_stats = sample_bpf_stats(sampled_prog_ids)
    if sampled_prog_id_map is not None:
        sampled_to_target = {
            int(sampled_prog_id): int(target_prog_id)
            for target_prog_id, sampled_prog_id in sampled_prog_id_map.items()
            if int(target_prog_id) > 0 and int(sampled_prog_id) > 0
        }

        def remap_stats(raw_stats: Mapping[int, Mapping[str, object]]) -> dict[int, dict[str, object]]:
            remapped: dict[int, dict[str, object]] = {}
            for sampled_prog_id, record in raw_stats.items():
                target_prog_id = sampled_to_target.get(int(sampled_prog_id))
                if target_prog_id is None:
                    continue
                entry = dict(record)
                entry["sampled_prog_id"] = int(sampled_prog_id)
                entry["id"] = int(target_prog_id)
                remapped[int(target_prog_id)] = entry
            return remapped

        initial_stats = remap_stats(initial_stats)
        final_stats = remap_stats(final_stats)
    return {
        "workloads": workloads,
        "bpf": compute_delta(initial_stats, final_stats),
    }

def _scx_live_prog_id_map_for_runner(
    runner: ScxRunner,
    logical_prog_ids: Sequence[int],
    *,
    previous_programs: Sequence[Mapping[str, object]],
) -> tuple[dict[int, int], list[dict[str, object]]]:
    logical_ids = [int(prog_id) for prog_id in logical_prog_ids if int(prog_id) > 0]
    if not logical_ids:
        return {}, []
    wanted = {int(prog_id) for prog_id in logical_ids}
    previous_name_by_id = {
        int(program["id"]): str(program["name"]).strip()
        for program in previous_programs
        if int(program.get("id", 0) or 0) in wanted and str(program.get("name") or "").strip()
    }
    refreshed_programs = runner.refresh_live_programs()
    refreshed_id_by_name = {
        str(program.get("name") or "").strip(): int(program.get("id", 0) or 0)
        for program in refreshed_programs
        if int(program.get("id", 0) or 0) > 0 and str(program.get("name") or "").strip()
    }
    live_ids = {int(program.get("id", 0) or 0) for program in refreshed_programs}
    remapped = {
        int(logical_prog_id): int(refreshed_id_by_name[program_name])
        for logical_prog_id, program_name in previous_name_by_id.items()
        if int(refreshed_id_by_name.get(program_name, 0) or 0) > 0
    }
    for logical_prog_id in logical_ids:
        if int(logical_prog_id) in remapped:
            continue
        if int(logical_prog_id) in live_ids:
            remapped[int(logical_prog_id)] = int(logical_prog_id)
    return remapped, [dict(program) for program in refreshed_programs]


def _sample_scx_measurement_stats(
    runner: ScxRunner,
    logical_prog_ids: Sequence[int],
    *,
    previous_programs: Sequence[Mapping[str, object]],
) -> tuple[dict[int, dict[str, object]], dict[int, int], list[dict[str, object]]]:
    live_prog_id_map: dict[int, int] = {}
    live_programs: list[dict[str, object]] = []
    raw_stats: dict[int, dict[str, object]] | None = None
    last_error: RuntimeError | None = None
    candidates = list(previous_programs)
    for attempt in range(4):
        live_prog_id_map, live_programs = _scx_live_prog_id_map_for_runner(
            runner,
            logical_prog_ids,
            previous_programs=candidates,
        )
        sampled_prog_ids = sorted({int(sampled_prog_id) for sampled_prog_id in live_prog_id_map.values() if int(sampled_prog_id) > 0})
        if not sampled_prog_ids:
            last_error = RuntimeError(f"{type(runner).__name__}: did not expose any live scheduler programs for stats sampling")
        else:
            try:
                raw_stats = sample_bpf_stats(sampled_prog_ids)
                break
            except RuntimeError as exc:
                last_error = exc
        candidates = live_programs or candidates
        if attempt < 3:
            time.sleep(0.25)
    if raw_stats is None:
        raise last_error or RuntimeError(f"{type(runner).__name__}: stats sampling returned no records")
    sampled_to_target = {
        int(sampled_prog_id): int(target_prog_id)
        for target_prog_id, sampled_prog_id in live_prog_id_map.items()
        if int(target_prog_id) > 0 and int(sampled_prog_id) > 0
    }
    remapped: dict[int, dict[str, object]] = {}
    for sampled_prog_id, record in raw_stats.items():
        target_prog_id = sampled_to_target.get(int(sampled_prog_id))
        if target_prog_id is None:
            continue
        entry = dict(record)
        entry["sampled_prog_id"] = int(sampled_prog_id)
        entry["id"] = int(target_prog_id)
        remapped[int(target_prog_id)] = entry
    if not remapped:
        raise RuntimeError(f"{type(runner).__name__}: stats sampling returned no logical program records")
    return remapped, live_prog_id_map, live_programs

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


def _refresh_active_session_programs(sessions: Sequence["CorpusAppSession"]) -> None:
    current_programs = programs_after(())
    claimed_ids: set[int] = set()
    for session in reversed(sessions):
        live_programs = [dict(program) for program in programs_after(session.before_prog_ids, records=current_programs)
                         if int(program.get("id", 0) or 0) > 0 and int(program.get("id", 0) or 0) not in claimed_ids]
        if not live_programs:
            raise RuntimeError(f"{session.app.name}: failed to refresh live BPF programs before measurement/apply")
        session.state.prog_ids = [int(program["id"]) for program in live_programs]
        session.state.artifacts["programs"] = live_programs; session.runner.programs = [dict(program) for program in live_programs]
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
    before_prog_ids: list[int]
    workload_seconds: float


def run_suite(args: argparse.Namespace, suite: AppSuite) -> dict[str, object]:
    suite_path = suite.manifest_path.resolve()
    daemon_binary = Path(args.daemon).resolve()
    if not daemon_binary.exists():
        raise RuntimeError(f"daemon binary not found: {daemon_binary}")

    workload_seconds = _workload_seconds(args)
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
                def _on_session_failure(_: object, result: Any, phase: str) -> None:
                    if phase != "baseline": return
                    try:
                        wait_for_suite_quiescence()
                    except Exception as quiesce_exc:
                        result.error = f"{result.error}; {quiesce_exc}" if result.error else str(quiesce_exc)

                for app in suite.apps:
                    _print_progress("app_start", app=app.name, runner=app.runner, workload=app.workload_for("corpus"))
                    app_workload_seconds = _app_workload_seconds(args, app)
                    runner: AppRunner | None = None
                    try:
                        before_prog_ids = [int(program.get("id", 0) or 0) for program in programs_after(())]
                        runner = get_app_runner(app.runner, workload=app.workload_for("corpus"), **app.args)
                        started_prog_ids = [int(value) for value in runner.start() if int(value) > 0]
                        state = _build_runner_state(app, runner, started_prog_ids)
                        session = CorpusAppSession(
                            app=app,
                            runner=runner,
                            state=state,
                            before_prog_ids=before_prog_ids,
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
                    lifecycle_results, fatal_error = run_lifecycle_sessions(
                        daemon_session=prepared_daemon_session,
                        sessions=sessions,
                        get_state=lambda session: session.state,
                        measure=lambda session, state, _phase: _measure_runner_phase(
                            session.runner,
                            state.prog_ids,
                            workload_seconds=session.workload_seconds,
                            samples=samples,
                        ),
                        stop=lambda session, _: session.runner.stop(),
                        refresh_sessions=lambda lifecycle_sessions, _phase: _refresh_active_session_programs(lifecycle_sessions),
                        on_session_failure=_on_session_failure,
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
    payload = {
        "generated_at": datetime.now(timezone.utc).isoformat(),
        "manifest": str(suite_path),
        "suite_name": suite.suite_name,
        "daemon": str(daemon_binary),
        "samples": samples,
        "workload_seconds": workload_seconds,
        "results": results,
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
    suite = load_app_suite_from_yaml(Path(args.suite).resolve(), filters=list(args.filters or []))
    resolved_workload_seconds = _workload_seconds(args)
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
