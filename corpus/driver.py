#!/usr/bin/env python3
from __future__ import annotations

import argparse
import json
import sys
from collections import Counter
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
from runner.libs.app_suite_schema import AppSpec, AppSuite, load_app_suite_from_yaml
from runner.libs.bpf_stats import compute_delta, enable_bpf_stats, sample_bpf_stats
from runner.libs.case_common import (
    CaseLifecycleState,
    annotate_workload_measurement,
    measurement_workload_miss,
    merge_measurement_limitations,
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
    return annotate_workload_measurement(
        {
            "workloads": workloads,
            "bpf": compute_delta(initial_stats, final_stats),
        }
    )

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


def _normalize_live_programs(programs: object) -> list[dict[str, object]]:
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


def _session_program_records(session: "CorpusAppSession") -> list[dict[str, object]]:
    programs = _normalize_live_programs(session.runner.live_rejit_programs())
    if programs:
        return programs
    return _normalize_live_programs(session.state.artifacts.get("programs"))


def _program_identity(program: Mapping[str, object]) -> tuple[str, str, str, str, int]:
    return (
        str(program.get("name") or ""),
        str(program.get("type") or ""),
        str(program.get("attach_type") or program.get("expected_attach_type") or ""),
        str(program.get("attach_to") or program.get("attach_target") or program.get("attach_btf_name") or ""),
        int(program.get("attach_btf_id", 0) or 0),
    )


def _match_programs_by_identity(
    candidates: Sequence[Mapping[str, object]],
    expected_programs: Sequence[Mapping[str, object]],
    *,
    claimed_ids: Sequence[int] = (),
) -> tuple[list[dict[str, object]], list[int]]:
    remaining = Counter(_program_identity(program) for program in expected_programs)
    claimed = {int(prog_id) for prog_id in claimed_ids if int(prog_id) > 0}
    matched: list[dict[str, object]] = []
    overlapping_claimed: set[int] = set()
    for program in _normalize_live_programs(candidates):
        identity = _program_identity(program)
        if remaining[identity] <= 0:
            continue
        prog_id = int(program["id"])
        if prog_id in claimed:
            overlapping_claimed.add(prog_id)
            continue
        matched.append(dict(program))
        remaining[identity] -= 1
    return matched, sorted(overlapping_claimed)


def _runner_rediscovered_programs(session: "CorpusAppSession") -> tuple[list[dict[str, object]], str]:
    refresh = getattr(session.runner, "refresh_programs", None)
    if callable(refresh):
        return _normalize_live_programs(refresh()), "runner.refresh_programs"
    runtime_session = getattr(session.runner, "session", None)
    refresh = getattr(runtime_session, "refresh_programs", None)
    if callable(refresh):
        return _normalize_live_programs(refresh()), "runner.session.refresh_programs"
    discover = getattr(runtime_session, "_discover_programs", None)
    if callable(discover):
        return _normalize_live_programs(discover()), "runner.session._discover_programs"
    return [], ""


def _rediscover_session_programs(
    session: "CorpusAppSession",
    *,
    current_programs: Sequence[Mapping[str, object]],
    claimed_ids: Sequence[int],
) -> tuple[list[dict[str, object]], str, list[int]]:
    expected_programs = _session_program_records(session)
    if not expected_programs:
        return [], "", []
    overlapping_claimed: set[int] = set()
    runner_programs, source = _runner_rediscovered_programs(session)
    if runner_programs:
        matched_programs, claimed_overlap = _match_programs_by_identity(
            runner_programs,
            expected_programs,
            claimed_ids=claimed_ids,
        )
        overlapping_claimed.update(claimed_overlap)
        if matched_programs:
            return matched_programs, source, sorted(overlapping_claimed)
    matched_programs, claimed_overlap = _match_programs_by_identity(
        current_programs,
        expected_programs,
        claimed_ids=claimed_ids,
    )
    overlapping_claimed.update(claimed_overlap)
    return matched_programs, source or "bpftool prog show", sorted(overlapping_claimed)


def _refresh_active_session_programs(
    sessions: Sequence["CorpusAppSession"],
    phase: str,
) -> None:
    current_programs = _normalize_live_programs(programs_after(()))
    current_programs_by_id = {
        int(program["id"]): dict(program)
        for program in current_programs
    }
    current_prog_ids = frozenset(current_programs_by_id)
    claimed_ids: set[int] = set()
    for session in sessions:
        tracked_prog_ids = _tracked_prog_id_set(session.state.prog_ids)
        if not tracked_prog_ids:
            raise RuntimeError(f"{session.app.name}: no tracked BPF program ids remain before {phase}")
        live_programs: list[dict[str, object]]
        if missing_ids := sorted(tracked_prog_ids - current_prog_ids):
            live_programs, discover_source, claimed_overlap = _rediscover_session_programs(
                session,
                current_programs=current_programs,
                claimed_ids=sorted(claimed_ids),
            )
            if not live_programs:
                if claimed_overlap:
                    raise RuntimeError(
                        f"{session.app.name}: tracked BPF program ids disappeared before {phase}; "
                        f"rediscovered replacements overlap another session's claimed ids: "
                        f"missing_ids={missing_ids}, tracked_ids={sorted(tracked_prog_ids)}, "
                        f"claimed_overlap={claimed_overlap}"
                    )
                raise RuntimeError(
                    f"{session.app.name}: tracked BPF program ids disappeared before {phase}; "
                    f"rediscovery found no live replacement programs: "
                    f"missing_ids={missing_ids}, tracked_ids={sorted(tracked_prog_ids)}"
                )
            expected_count = len(tracked_prog_ids)
            refreshed_count = len(live_programs)
            if refreshed_count < expected_count:
                _print_progress(
                    "session_warning",
                    app=session.app.name,
                    runner=session.app.runner,
                    phase=phase,
                    warning=(
                        f"rediscovery returned fewer programs than expected: "
                        f"{refreshed_count}/{expected_count}; accepting partial set"
                    ),
                    missing_ids=missing_ids,
                    refreshed_ids=[int(program["id"]) for program in live_programs],
                    discover_source=discover_source,
                )
            _print_progress(
                "session_warning",
                app=session.app.name,
                runner=session.app.runner,
                phase=phase,
                warning="tracked BPF program ids changed; refreshed live session programs",
                previous_ids=sorted(tracked_prog_ids),
                missing_ids=missing_ids,
                refreshed_ids=[int(program["id"]) for program in live_programs],
                expected_count=expected_count,
                refreshed_count=refreshed_count,
                discover_source=discover_source,
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
    workload_miss = measurement_workload_miss(baseline_measurement) or measurement_workload_miss(
        rejit_measurement
    )
    return {
        "app": app.name,
        "runner": app.runner,
        "selected_workload": app.workload_for("corpus"),
        "status": "error",
        "error": str(error),
        "workload_miss": workload_miss,
        "limitations": merge_measurement_limitations(baseline_measurement, rejit_measurement),
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
    workload_miss = measurement_workload_miss(baseline_measurement) or measurement_workload_miss(
        rejit_measurement
    )
    return {
        "app": app.name,
        "runner": app.runner,
        "selected_workload": app.workload_for("corpus"),
        "status": "ok",
        "error": "",
        "workload_miss": workload_miss,
        "limitations": merge_measurement_limitations(baseline_measurement, rejit_measurement),
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
                    lifecycle_results, fatal_error = run_lifecycle_sessions(
                        daemon_session=prepared_daemon_session,
                        sessions=sessions,
                        get_state=lambda session: session.state,
                        measure=lambda session, state, _phase: _measure_runner_phase(
                            session.runner,
                            state.prog_ids,
                            workload_seconds=session.workload_seconds,
                            samples=samples,
                            warmup=(_phase == "baseline"),
                        ),
                        stop=lambda session, _: session.runner.stop(),
                        refresh_sessions=_refresh_active_session_programs,
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
