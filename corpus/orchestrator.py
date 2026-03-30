#!/usr/bin/env python3
from __future__ import annotations

import argparse
import json
import sys
from collections import Counter
from datetime import datetime, timezone
from pathlib import Path
from typing import Any, Mapping

REPO_ROOT = Path(__file__).resolve().parents[1]
if str(REPO_ROOT) not in sys.path:
    sys.path.insert(0, str(REPO_ROOT))

from runner.libs import ROOT_DIR, ensure_parent, write_json
from runner.libs.app_runners import get_app_runner
from runner.libs.app_suite_schema import AppSpec, load_app_suite_from_yaml
from runner.libs.bpf_stats import enable_bpf_stats, read_program_stats
from runner.libs.daemon_session import DaemonSession
from runner.libs.rejit import benchmark_rejit_enabled_passes


DEFAULT_MACRO_APPS_YAML = ROOT_DIR / "corpus" / "config" / "macro_apps.yaml"
DEFAULT_DAEMON = ROOT_DIR / "daemon" / "target" / "release" / "bpfrejit-daemon"
DEFAULT_OUTPUT_JSON = ROOT_DIR / "corpus" / "results" / "vm_corpus.json"
SECTION_TYPE_PREFIXES = {
    "xdp": "xdp",
    "tc": "sched_cls",
    "classifier": "sched_cls",
    "cgroup_skb": "cgroup_skb",
    "socket": "socket_filter",
}


def parse_args(argv: list[str] | None = None) -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="Run the app-native corpus orchestrator.")
    parser.add_argument("--suite", default=str(DEFAULT_MACRO_APPS_YAML))
    parser.add_argument("--daemon", default=str(DEFAULT_DAEMON))
    parser.add_argument("--repeat", type=int, default=0)
    parser.add_argument("--workload-seconds", type=float, default=0.0)
    parser.add_argument("--output-json", default=str(DEFAULT_OUTPUT_JSON))
    parser.add_argument("--filter", action="append", dest="filters")
    args = parser.parse_args(argv)
    if args.repeat is not None and int(args.repeat) < 0:
        raise SystemExit("--repeat must be >= 0")
    if float(args.workload_seconds) < 0:
        raise SystemExit("--workload-seconds must be >= 0")
    return args


def _program_phase_stats(
    current: Mapping[int, Mapping[str, object]],
    previous: Mapping[int, Mapping[str, object]] | None = None,
) -> dict[int, dict[str, object]]:
    results: dict[int, dict[str, object]] = {}
    for prog_id, current_stats in current.items():
        base = previous.get(prog_id, {}) if previous else {}
        run_cnt = int(current_stats.get("run_cnt", 0) or 0) - int(base.get("run_cnt", 0) or 0)
        run_time_ns = int(current_stats.get("run_time_ns", 0) or 0) - int(base.get("run_time_ns", 0) or 0)
        exec_ns = (run_time_ns / run_cnt) if run_cnt > 0 else None
        results[int(prog_id)] = {
            "id": int(current_stats.get("id", prog_id) or prog_id),
            "name": str(current_stats.get("name", "")),
            "type": str(current_stats.get("type", "")),
            "run_cnt": run_cnt,
            "run_time_ns": run_time_ns,
            "exec_ns": exec_ns,
            "bytes_jited": int(current_stats.get("bytes_jited", 0) or 0),
            "bytes_xlated": int(current_stats.get("bytes_xlated", 0) or 0),
        }
    return results


def _program_stats_by_prog_id(
    phase_stats: Mapping[int, Mapping[str, object]],
    prog_ids: list[int],
) -> dict[str, dict[str, object]]:
    return {
        str(prog_id): dict(phase_stats[prog_id])
        for prog_id in prog_ids
        if int(prog_id) in phase_stats
    }


def _mean_exec_ns(records: Mapping[str, Mapping[str, object]]) -> float | None:
    values = [
        float(record["exec_ns"])
        for record in records.values()
        if isinstance(record.get("exec_ns"), (int, float))
    ]
    if not values:
        return None
    return sum(values) / len(values)


def _infer_prog_type_name(program: Any) -> str:
    prog_type = str(getattr(program, "prog_type_name", "") or "").strip().lower()
    if prog_type and prog_type != "unspec":
        return prog_type
    section_name = str(getattr(program, "section_name", "") or "").strip().lower()
    section_root = section_name.split("/", 1)[0]
    if section_root in SECTION_TYPE_PREFIXES:
        return SECTION_TYPE_PREFIXES[section_root]
    for prefix, inferred_type in SECTION_TYPE_PREFIXES.items():
        if section_name.startswith(prefix):
            return inferred_type
    return prog_type or "unspec"


def _validate_phase_measurement(
    phase_name: str,
    records: Mapping[int, Mapping[str, object]],
    live_programs: list[dict[str, object]],
) -> None:
    errors: list[str] = []
    for program in live_programs:
        prog_id = int(program.get("id", 0) or 0)
        program_name = str(program.get("name") or f"prog_{prog_id}")
        record = records.get(prog_id)
        if record is None:
            errors.append(f"{phase_name}: missing stats for live program {program_name!r} (id={prog_id})")
            continue
        run_cnt = int(record.get("run_cnt", 0) or 0)
        exec_ns = record.get("exec_ns")
        if run_cnt <= 0:
            errors.append(f"{phase_name}: live program {program_name!r} observed zero runs")
        if not isinstance(exec_ns, (int, float)):
            errors.append(f"{phase_name}: live program {program_name!r} is missing exec_ns")
    if errors:
        raise RuntimeError("; ".join(errors))


def _daemon_exit_error(daemon_session: DaemonSession) -> str | None:
    returncode = daemon_session.proc.poll()
    if returncode is None:
        return None
    return f"daemon session exited early (rc={returncode})"


def _workload_seconds(args: argparse.Namespace, suite_defaults: Mapping[str, object]) -> float:
    explicit = float(args.workload_seconds or 0.0)
    if explicit > 0:
        return explicit
    default_value = float(suite_defaults.get("duration_s", 10.0) or 10.0)
    if default_value <= 0:
        raise RuntimeError(f"invalid app suite default duration_s: {default_value}")
    return default_value


def _repeat_count(args: argparse.Namespace, suite_defaults: Mapping[str, object]) -> int:
    explicit = int(args.repeat or 0)
    if explicit > 0:
        return explicit
    return max(1, int(suite_defaults.get("repeat", 1) or 1))


def _run_app(
    app: AppSpec,
    *,
    daemon_session: DaemonSession,
    workload_seconds: float,
) -> dict[str, object]:
    runner = get_app_runner(
        app.runner,
        app_name=app.name,
        workload=app.workload,
        **app.args,
    )
    prog_ids: list[int] = []
    live_programs: list[dict[str, object]] = []
    baseline_phase: dict[int, dict[str, object]] = {}
    rejit_phase: dict[int, dict[str, object]] = {}
    baseline_workload: dict[str, object] | None = None
    rejit_workload: dict[str, object] | None = None
    apply_result: dict[str, object] = {}

    try:
        prog_ids = [int(value) for value in runner.start() if int(value) > 0]
        if not prog_ids:
            raise RuntimeError(f"{app.name}: app runner did not return any live prog_ids")
        live_programs = [dict(program) for program in getattr(runner, "programs", [])]
        if not live_programs:
            raise RuntimeError(f"{app.name}: app runner did not expose any live programs")

        with enable_bpf_stats():
            baseline_workload = runner.run_workload(workload_seconds).to_dict()
            baseline_snapshot = read_program_stats(prog_ids)
            apply_result = daemon_session.apply_rejit(
                prog_ids,
                enabled_passes=benchmark_rejit_enabled_passes(),
            )
            rejit_snapshot: Mapping[int, Mapping[str, object]] = {}
            if bool(apply_result.get("applied")):
                rejit_workload = runner.run_workload(workload_seconds).to_dict()
                rejit_snapshot = read_program_stats(prog_ids)

        baseline_phase = _program_phase_stats(baseline_snapshot)
        _validate_phase_measurement("baseline", baseline_phase, live_programs)
        if bool(apply_result.get("applied")):
            rejit_phase = _program_phase_stats(rejit_snapshot, baseline_snapshot)
            _validate_phase_measurement("rejit", rejit_phase, live_programs)
    finally:
        runner.stop()

    programs_by_id = _program_stats_by_prog_id(baseline_phase, prog_ids)
    rejit_programs_by_id = _program_stats_by_prog_id(rejit_phase, prog_ids)
    status = "ok" if bool(apply_result.get("applied")) else "error"
    error = str(apply_result.get("error") or "").strip()
    if status == "error" and not error:
        error = "daemon apply did not report success"

    return {
        "app": app.name,
        "runner": app.runner,
        "workload": app.workload,
        "args": dict(app.args),
        "status": status,
        "error": error,
        "prog_ids": prog_ids,
        "programs": live_programs,
        "baseline": {
            "programs": programs_by_id,
            "exec_ns_mean": _mean_exec_ns(programs_by_id),
        },
        "baseline_workload": baseline_workload,
        "rejit_apply": dict(apply_result),
        "rejit": {
            "programs": rejit_programs_by_id,
            "exec_ns_mean": _mean_exec_ns(rejit_programs_by_id),
        } if rejit_phase else None,
        "rejit_workload": rejit_workload,
        "process": dict(getattr(runner, "process_output", {})),
        "command_used": [str(item) for item in (getattr(runner, "command_used", []) or [])],
    }


def run_suite(args: argparse.Namespace) -> dict[str, object]:
    suite_path = Path(args.suite).resolve()
    suite, suite_summary = load_app_suite_from_yaml(
        suite_path,
        filters=list(args.filters or []),
    )
    daemon_binary = Path(args.daemon).resolve()
    if not daemon_binary.exists():
        raise RuntimeError(f"daemon binary not found: {daemon_binary}")

    workload_seconds = _workload_seconds(args, suite.defaults)
    repeat = _repeat_count(args, suite.defaults)
    results: list[dict[str, object]] = []
    fatal_error = ""

    with DaemonSession.start(daemon_binary) as daemon_session:
        for app in suite.apps:
            try:
                result = _run_app(
                    app,
                    daemon_session=daemon_session,
                    workload_seconds=workload_seconds,
                )
            except Exception as exc:
                result = {
                    "app": app.name,
                    "runner": app.runner,
                    "workload": app.workload,
                    "args": dict(app.args),
                    "status": "error",
                    "error": str(exc),
                }
            results.append(result)
            daemon_error = _daemon_exit_error(daemon_session)
            if daemon_error is not None:
                fatal_error = daemon_error
                break

        if fatal_error:
            selected_names = {str(result.get("app") or "") for result in results}
            for app in suite.apps:
                if app.name in selected_names:
                    continue
                results.append(
                    {
                        "app": app.name,
                        "runner": app.runner,
                        "workload": app.workload,
                        "args": dict(app.args),
                        "status": "error",
                        "error": fatal_error,
                    }
                )
        daemon_socket = str(daemon_session.socket_path)

    status_counts = Counter(str(result.get("status") or "error") for result in results)
    live_program_count = sum(len(result.get("programs") or []) for result in results if isinstance(result, Mapping))
    payload = {
        "generated_at": datetime.now(timezone.utc).isoformat(),
        "manifest": str(suite_path),
        "suite_name": suite.suite_name,
        "daemon": str(daemon_binary),
        "daemon_socket": daemon_socket,
        "filters": list(args.filters or []),
        "repeat": repeat,
        "workload_seconds": workload_seconds,
        "suite_summary": suite_summary,
        "results": results,
        "summary": {
            "selected_apps": len(suite.apps),
            "discovered_programs": live_program_count,
            "statuses": dict(sorted(status_counts.items())),
        },
        "status": "ok" if status_counts.get("error", 0) == 0 else "error",
    }
    if fatal_error:
        payload["fatal_error"] = fatal_error
    return payload


def main(argv: list[str] | None = None) -> int:
    args = parse_args(argv)
    payload = run_suite(args)
    output_path = Path(args.output_json).resolve()
    ensure_parent(output_path)
    write_json(output_path, payload)
    print(json.dumps({"status": payload["status"], "output_json": str(output_path)}, indent=2))
    return 0 if payload["status"] == "ok" else 1


if __name__ == "__main__":
    raise SystemExit(main())
