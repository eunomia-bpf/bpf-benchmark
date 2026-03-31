#!/usr/bin/env python3
from __future__ import annotations

import argparse
import json
import sys
from collections import Counter
from datetime import datetime, timezone
from pathlib import Path
from typing import Any, Mapping, Sequence

REPO_ROOT = Path(__file__).resolve().parents[1]
if str(REPO_ROOT) not in sys.path:
    sys.path.insert(0, str(REPO_ROOT))

from runner.libs import ROOT_DIR, ensure_parent, write_json, write_text
from runner.libs.app_runners import get_app_runner
from runner.libs.app_suite_schema import AppSpec, AppWorkload, load_app_suite_from_yaml
from runner.libs.bpf_stats import enable_bpf_stats
from runner.libs.case_common import (
    attach_pending_result_metadata,
    prepare_daemon_session,
    rejit_program_result,
    rejit_result_has_any_apply,
    reset_pending_result_metadata,
    run_app_runner_lifecycle,
    wait_for_suite_quiescence,
)
from runner.libs.daemon_session import DaemonSession
from runner.libs.metrics import sample_bpf_stats
from runner.libs.rejit import benchmark_rejit_enabled_passes
from runner.libs.statistics import geometric_mean


DEFAULT_MACRO_APPS_YAML = ROOT_DIR / "corpus" / "config" / "macro_apps.yaml"
DEFAULT_DAEMON = ROOT_DIR / "daemon" / "target" / "release" / "bpfrejit-daemon"
DEFAULT_OUTPUT_JSON = ROOT_DIR / "corpus" / "results" / "vm_corpus.json"
DEFAULT_OUTPUT_MD = ROOT_DIR / "corpus" / "results" / "vm_corpus.md"
SECTION_TYPE_PREFIXES = {
    "xdp": "xdp",
    "tc": "sched_cls",
    "classifier": "sched_cls",
    "cgroup_skb": "cgroup_skb",
    "socket": "socket_filter",
}


def parse_args(argv: list[str] | None = None) -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="Run the app-native corpus suite driver.")
    parser.add_argument("--suite", default=str(DEFAULT_MACRO_APPS_YAML))
    parser.add_argument("--daemon", default=str(DEFAULT_DAEMON))
    parser.add_argument("--samples", type=int, default=0)
    parser.add_argument("--workload-seconds", type=float, default=0.0)
    parser.add_argument("--output-json", default=str(DEFAULT_OUTPUT_JSON))
    parser.add_argument("--output-md", default=str(DEFAULT_OUTPUT_MD))
    parser.add_argument("--filter", action="append", dest="filters")
    args = parser.parse_args(argv)
    if args.samples is not None and int(args.samples) < 0:
        raise SystemExit("--samples must be >= 0")
    if float(args.workload_seconds) < 0:
        raise SystemExit("--workload-seconds must be >= 0")
    return args


def _workload_payload(workload: AppWorkload) -> dict[str, str]:
    return {
        "corpus": workload.corpus,
        "e2e": workload.e2e,
    }


def _print_progress(event: str, **fields: object) -> None:
    payload = {"event": event}
    payload.update(fields)
    print(json.dumps(payload, sort_keys=True), flush=True)


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
    prog_ids: Sequence[int],
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


def _workload_ops_per_sec(workload: Mapping[str, object] | None) -> float | None:
    if not isinstance(workload, Mapping):
        return None
    value = workload.get("ops_per_sec")
    if not isinstance(value, (int, float)):
        return None
    return float(value)


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


def _has_phase_measurement(records: Mapping[str, Mapping[str, object]]) -> bool:
    for record in records.values():
        exec_ns = record.get("exec_ns")
        if isinstance(exec_ns, (int, float)) and float(exec_ns) > 0.0:
            return True
    return False


def _has_comparable_measurement(program_measurements: Mapping[str, Mapping[str, object]]) -> bool:
    for record in program_measurements.values():
        if bool(record.get("comparable")):
            return True
    return False


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


def _app_workload_seconds(
    args: argparse.Namespace,
    suite_defaults: Mapping[str, object],
    app: AppSpec,
) -> float:
    explicit = float(args.workload_seconds or 0.0)
    if explicit > 0:
        return explicit
    if app.duration_s is not None:
        return float(app.duration_s)
    return _workload_seconds(args, suite_defaults)


def _sample_count(args: argparse.Namespace, suite_defaults: Mapping[str, object]) -> int:
    explicit = int(args.samples or 0)
    if explicit > 0:
        return explicit
    return max(1, int(suite_defaults.get("samples", 1) or 1))


def _measure_runner_phase(
    runner: object,
    prog_ids: Sequence[int],
    *,
    workload_seconds: float,
    samples: int,
) -> dict[str, object]:
    workloads: list[dict[str, object]] = []
    last_workload: dict[str, object] | None = None
    prog_fds = getattr(runner, "program_fds", None)
    initial_stats = sample_bpf_stats(list(prog_ids), prog_fds=prog_fds)
    for _ in range(samples):
        workload = runner.run_workload(workload_seconds).to_dict()
        last_workload = dict(workload)
        workloads.append(dict(workload))
    final_stats = sample_bpf_stats(list(prog_ids), prog_fds=prog_fds)
    return {
        "workload": last_workload,
        "workloads": workloads,
        "initial_stats": initial_stats,
        "final_stats": final_stats,
    }


def _selected_live_programs(
    live_programs: Sequence[Mapping[str, object]],
    prog_ids: Sequence[int],
) -> list[dict[str, object]]:
    wanted = {int(prog_id) for prog_id in prog_ids if int(prog_id) > 0}
    return [
        dict(program)
        for program in live_programs
        if int(program.get("id", 0) or 0) in wanted
    ]


def _program_label(app_name: str, program_name: str, prog_id: int) -> str:
    return f"{app_name}:{program_name or f'prog_{prog_id}'}#{prog_id}"


def _phase_exec_ns(record: Mapping[str, object] | None) -> float | None:
    if not isinstance(record, Mapping):
        return None
    value = record.get("exec_ns")
    if not isinstance(value, (int, float)):
        return None
    return float(value)


def _comparison_exclusion_reason(
    baseline_exec_ns: float | None,
    rejit_exec_ns: float | None,
    *,
    had_post_rejit: bool,
    any_applied: bool,
    apply_record: Mapping[str, object],
) -> str:
    apply_error = str(apply_record.get("error") or "").strip()
    if baseline_exec_ns is None:
        return "missing_baseline_exec_ns"
    if baseline_exec_ns <= 0.0:
        return "non_positive_baseline_exec_ns"
    if not had_post_rejit:
        if apply_error:
            return f"apply_error: {apply_error}"
        if not any_applied:
            return "no_programs_applied_in_loader"
        return "missing_post_rejit_measurement"
    if rejit_exec_ns is None:
        if apply_error:
            return f"apply_error: {apply_error}"
        return "missing_rejit_exec_ns"
    if rejit_exec_ns <= 0.0:
        return "non_positive_rejit_exec_ns"
    return ""


def _build_program_measurements(
    app_name: str,
    live_programs: Sequence[Mapping[str, object]],
    baseline_programs: Mapping[str, Mapping[str, object]],
    rejit_programs: Mapping[str, Mapping[str, object]],
    apply_result: Mapping[str, object],
    *,
    had_post_rejit: bool,
) -> dict[str, dict[str, object]]:
    rows: dict[str, dict[str, object]] = {}
    any_applied = rejit_result_has_any_apply(apply_result)
    for live_program in live_programs:
        prog_id = int(live_program.get("id", 0) or 0)
        if prog_id <= 0:
            continue
        program_name = str(live_program.get("name") or f"prog_{prog_id}")
        baseline_record = dict(baseline_programs.get(str(prog_id), {}))
        rejit_record = dict(rejit_programs.get(str(prog_id), {}))
        apply_record = rejit_program_result(apply_result, prog_id)
        if not apply_record and isinstance(apply_result, Mapping):
            apply_record = {
                "applied": bool(apply_result.get("applied")),
                "error": str(apply_result.get("error") or ""),
                "counts": dict(apply_result.get("counts") or {}) if isinstance(apply_result.get("counts"), Mapping) else {},
            }
        baseline_exec_ns = _phase_exec_ns(baseline_record)
        rejit_exec_ns = _phase_exec_ns(rejit_record)
        comparable = (
            baseline_exec_ns is not None
            and baseline_exec_ns > 0.0
            and rejit_exec_ns is not None
            and rejit_exec_ns > 0.0
        )
        speedup = (baseline_exec_ns / rejit_exec_ns) if comparable else None
        exclusion_reason = ""
        if not comparable:
            exclusion_reason = _comparison_exclusion_reason(
                baseline_exec_ns,
                rejit_exec_ns,
                had_post_rejit=had_post_rejit,
                any_applied=any_applied,
                apply_record=apply_record,
            )
        rows[str(prog_id)] = {
            "id": prog_id,
            "label": _program_label(app_name, program_name, prog_id),
            "name": program_name,
            "type": str(live_program.get("type") or _infer_prog_type_name(live_program)),
            "applied": bool(apply_record.get("applied")),
            "comparable": comparable,
            "speedup": speedup,
            "comparison_exclusion_reason": exclusion_reason,
            "baseline": baseline_record,
            "rejit": rejit_record if had_post_rejit else {},
            "apply": apply_record,
        }
    return rows


def _comparison_rows(
    results: Sequence[Mapping[str, object]],
) -> tuple[list[dict[str, object]], list[dict[str, object]], list[dict[str, object]]]:
    comparable_rows: list[dict[str, object]] = []
    applied_rows: list[dict[str, object]] = []
    excluded_rows: list[dict[str, object]] = []
    for result in results:
        app_name = str(result.get("app") or "")
        for row in (result.get("program_measurements") or {}).values():
            if not isinstance(row, Mapping):
                continue
            row_payload = dict(row)
            row_payload["app"] = app_name
            if bool(row.get("comparable")):
                comparable_rows.append(row_payload)
                if bool(row.get("applied")):
                    applied_rows.append(row_payload)
                continue
            excluded_rows.append(
                {
                    "app": app_name,
                    "program_id": int(row.get("id", 0) or 0),
                    "program": str(row.get("name") or ""),
                    "label": str(row.get("label") or ""),
                    "applied": bool(row.get("applied")),
                    "reason": str(row.get("comparison_exclusion_reason") or "unknown"),
                    "apply_error": str(((row.get("apply") or {}).get("error")) or ""),
                }
            )
    return comparable_rows, applied_rows, excluded_rows


def _per_app_breakdown(results: Sequence[Mapping[str, object]]) -> list[dict[str, object]]:
    breakdown: list[dict[str, object]] = []
    for result in results:
        program_rows = [
            dict(row)
            for row in (result.get("program_measurements") or {}).values()
            if isinstance(row, Mapping)
        ]
        comparable_speedups = [
            float(row["speedup"])
            for row in program_rows
            if bool(row.get("comparable")) and isinstance(row.get("speedup"), (int, float))
        ]
        applied_speedups = [
            float(row["speedup"])
            for row in program_rows
            if bool(row.get("applied")) and bool(row.get("comparable")) and isinstance(row.get("speedup"), (int, float))
        ]
        exclusions = [
            {
                "program_id": int(row.get("id", 0) or 0),
                "program": str(row.get("name") or ""),
                "label": str(row.get("label") or ""),
                "reason": str(row.get("comparison_exclusion_reason") or "unknown"),
            }
            for row in program_rows
            if not bool(row.get("comparable"))
        ]
        breakdown.append(
            {
                "app": str(result.get("app") or ""),
                "runner": str(result.get("runner") or ""),
                "workload": str(result.get("selected_workload") or ""),
                "status": str(result.get("status") or ""),
                "program_count": len(program_rows),
                "applied_program_count": sum(1 for row in program_rows if bool(row.get("applied"))),
                "comparable_program_count": len(comparable_speedups),
                "sample_count": len(comparable_speedups),
                "applied_only_geomean": geometric_mean(applied_speedups),
                "all_comparable_geomean": geometric_mean(comparable_speedups),
                "comparison_exclusions": exclusions,
            }
        )
    return breakdown


def _build_summary(
    results: Sequence[Mapping[str, object]],
    *,
    selected_apps: int,
    status_counts: Mapping[str, int],
) -> dict[str, object]:
    comparable_rows, applied_rows, excluded_rows = _comparison_rows(results)
    comparable_speedups = [
        float(row["speedup"])
        for row in comparable_rows
        if isinstance(row.get("speedup"), (int, float))
    ]
    applied_speedups = [
        float(row["speedup"])
        for row in applied_rows
        if isinstance(row.get("speedup"), (int, float))
    ]
    exclusion_reason_counts = Counter(str(row.get("reason") or "unknown") for row in excluded_rows)
    discovered_programs = sum(
        len(result.get("program_measurements") or {})
        for result in results
        if isinstance(result, Mapping)
    )
    return {
        "selected_apps": selected_apps,
        "discovered_programs": discovered_programs,
        "statuses": dict(sorted(status_counts.items())),
        "sample_count": len(comparable_speedups),
        "applied_sample_count": len(applied_speedups),
        "applied_only_geomean": geometric_mean(applied_speedups),
        "all_comparable_geomean": geometric_mean(comparable_speedups),
        "comparison_exclusion_reasons": excluded_rows,
        "comparison_exclusion_reason_counts": dict(sorted(exclusion_reason_counts.items())),
        "per_app": _per_app_breakdown(results),
    }


def _format_ratio(value: object) -> str:
    if not isinstance(value, (int, float)) or float(value) <= 0.0:
        return "n/a"
    return f"{float(value):.3f}x"


def build_markdown(payload: Mapping[str, object]) -> str:
    summary = payload.get("summary") if isinstance(payload.get("summary"), Mapping) else {}
    lines = [
        "# Corpus Authoritative Summary",
        "",
        f"- Generated: {payload.get('generated_at')}",
        f"- Manifest: `{payload.get('manifest')}`",
        f"- Daemon: `{payload.get('daemon')}`",
        f"- Samples: `{payload.get('samples')}`",
        f"- Workload seconds: `{payload.get('workload_seconds')}`",
        f"- Status: `{payload.get('status')}`",
        f"- Applied-only geomean (baseline/rejit): `{_format_ratio(summary.get('applied_only_geomean'))}`",
        f"- All-comparable geomean (baseline/rejit): `{_format_ratio(summary.get('all_comparable_geomean'))}`",
        f"- Sample count: `{summary.get('sample_count')}`",
        "",
        "## Per-App Breakdown",
        "",
        "| App | Runner | Workload | Programs | Applied | Comparable | Applied-only | All-comparable |",
        "| --- | --- | --- | ---: | ---: | ---: | ---: | ---: |",
    ]
    for row in summary.get("per_app") or []:
        if not isinstance(row, Mapping):
            continue
        lines.append(
            "| "
            + " | ".join(
                [
                    str(row.get("app") or ""),
                    str(row.get("runner") or ""),
                    str(row.get("workload") or ""),
                    str(int(row.get("program_count", 0) or 0)),
                    str(int(row.get("applied_program_count", 0) or 0)),
                    str(int(row.get("comparable_program_count", 0) or 0)),
                    _format_ratio(row.get("applied_only_geomean")),
                    _format_ratio(row.get("all_comparable_geomean")),
                ]
            )
            + " |"
        )
    lines.extend(
        [
            "",
            "## Comparison Exclusion Reasons",
            "",
        ]
    )
    exclusion_counts = summary.get("comparison_exclusion_reason_counts") or {}
    if not exclusion_counts:
        lines.append("- none")
    else:
        for reason, count in sorted(exclusion_counts.items()):
            lines.append(f"- `{reason}`: `{count}`")
    return "\n".join(lines)


def _run_app(
    app: AppSpec,
    *,
    daemon_session: object,
    workload_seconds: float,
    samples: int,
) -> dict[str, object]:
    selected_workload = app.workload_for("corpus")
    runner = get_app_runner(
        app.runner,
        app_name=app.name,
        workload=selected_workload,
        **app.args,
    )
    prog_ids: list[int] = []
    live_programs: list[dict[str, object]] = []
    baseline_phase: dict[int, dict[str, object]] = {}
    rejit_phase: dict[int, dict[str, object]] = {}
    baseline_workload: dict[str, object] | None = None
    baseline_workloads: list[dict[str, object]] = []
    rejit_workload: dict[str, object] | None = None
    rejit_workloads: list[dict[str, object]] = []
    apply_result: dict[str, object] = {}
    had_post_rejit = False
    measurement_mode = str(getattr(runner, "corpus_measurement_mode", lambda: "program")()).strip() or "program"

    def before_rejit(_setup_state: object, lifecycle: object, baseline: Mapping[str, object]) -> object | None:
        measurement = dict((baseline.get("measurement") or {}))
        initial_stats = measurement.get("initial_stats") or {}
        final_stats = measurement.get("final_stats") or {}
        selector = getattr(runner, "select_corpus_program_ids", None)
        if not callable(selector):
            return None
        selected = selector(initial_stats, final_stats)
        if selected is None:
            return None
        selected_prog_ids = [
            int(prog_id)
            for prog_id in selected
            if int(prog_id) > 0
        ]
        if not selected_prog_ids:
            raise RuntimeError(
                f"{app.name}: workload {selected_workload!r} did not execute any runner-selected programs during baseline"
            )
        lifecycle.target_prog_ids = list(selected_prog_ids)
        lifecycle.apply_prog_ids = list(selected_prog_ids)
        selected_programs = _selected_live_programs(
            lifecycle.artifacts.get("programs") or [],
            selected_prog_ids,
        )
        if selected_programs:
            lifecycle.artifacts["programs"] = selected_programs
        return None

    with enable_bpf_stats():
        lifecycle_result = run_app_runner_lifecycle(
            daemon_session=daemon_session,
            runner=runner,
            enabled_passes=benchmark_rejit_enabled_passes(),
            measure=lambda lifecycle, _phase_name: {
                "measurement": _measure_runner_phase(
                    lifecycle.runtime,
                    lifecycle.target_prog_ids,
                    workload_seconds=workload_seconds,
                    samples=samples,
                )
            },
            before_rejit=before_rejit,
        )

    if lifecycle_result.state is None or lifecycle_result.baseline is None:
        raise RuntimeError(f"{app.name}: runner lifecycle did not produce a baseline measurement")

    prog_ids = [int(value) for value in lifecycle_result.state.target_prog_ids if int(value) > 0]
    live_programs = [dict(program) for program in (lifecycle_result.artifacts.get("programs") or [])]
    baseline_measurement = dict((lifecycle_result.baseline.get("measurement") or {}))
    baseline_initial_snapshot = dict(baseline_measurement.get("initial_stats") or {})
    baseline_final_snapshot = dict(baseline_measurement.get("final_stats") or {})
    baseline_workload = dict(baseline_measurement.get("workload") or {}) if baseline_measurement.get("workload") else None
    baseline_workloads = [dict(workload) for workload in (baseline_measurement.get("workloads") or [])]
    apply_result = dict(lifecycle_result.rejit_result or {})
    had_post_rejit = lifecycle_result.post_rejit is not None
    if not live_programs:
        raise RuntimeError(f"{app.name}: runner lifecycle did not expose any live programs")

    baseline_phase = _program_phase_stats(baseline_final_snapshot, baseline_initial_snapshot)
    if had_post_rejit:
        rejit_measurement = dict((lifecycle_result.post_rejit or {}).get("measurement") or {})
        rejit_initial_snapshot = dict(rejit_measurement.get("initial_stats") or {})
        rejit_final_snapshot = dict(rejit_measurement.get("final_stats") or {})
        rejit_workload = dict(rejit_measurement.get("workload") or {}) if rejit_measurement.get("workload") else None
        rejit_workloads = [dict(workload) for workload in (rejit_measurement.get("workloads") or [])]
        rejit_phase = _program_phase_stats(rejit_final_snapshot, rejit_initial_snapshot)

    programs_by_id = _program_stats_by_prog_id(baseline_phase, prog_ids)
    rejit_programs_by_id = _program_stats_by_prog_id(rejit_phase, prog_ids)
    error = str(apply_result.get("error") or "").strip()
    if measurement_mode == "program" and not _has_phase_measurement(programs_by_id):
        raise RuntimeError(
            f"{app.name}: workload {selected_workload!r} did not execute any target programs during baseline"
        )
    if measurement_mode == "program" and had_post_rejit and not error and not _has_phase_measurement(rejit_programs_by_id):
        raise RuntimeError(
            f"{app.name}: workload {selected_workload!r} did not execute any target programs after rejit"
        )
    status = "error" if error else "ok"
    program_measurements = _build_program_measurements(
        app.name,
        live_programs,
        programs_by_id,
        rejit_programs_by_id,
        apply_result,
        had_post_rejit=had_post_rejit,
    )
    app_measurement: dict[str, object] | None = None
    if measurement_mode == "app":
        baseline_ops_per_sec = _workload_ops_per_sec(baseline_workload)
        rejit_ops_per_sec = _workload_ops_per_sec(rejit_workload)
        if baseline_ops_per_sec is None or baseline_ops_per_sec <= 0.0:
            raise RuntimeError(f"{app.name}: workload {selected_workload!r} did not produce a baseline throughput measurement")
        if had_post_rejit and not error and (rejit_ops_per_sec is None or rejit_ops_per_sec <= 0.0):
            raise RuntimeError(f"{app.name}: workload {selected_workload!r} did not produce a post-rejit throughput measurement")
        app_measurement = {
            "metric": "ops_per_sec",
            "baseline": baseline_ops_per_sec,
            "post_rejit": rejit_ops_per_sec,
            "speedup": None
            if rejit_ops_per_sec is None
            else (rejit_ops_per_sec / baseline_ops_per_sec),
        }
    elif not error and not _has_comparable_measurement(program_measurements):
        raise RuntimeError(
            f"{app.name}: workload {selected_workload!r} produced no comparable target program measurements"
        )

    return {
        "app": app.name,
        "runner": app.runner,
        "workload": _workload_payload(app.workload),
        "selected_workload": selected_workload,
        "measurement_mode": measurement_mode,
        "configured_workload_seconds": float(workload_seconds),
        "args": dict(app.args),
        "status": status,
        "error": error,
        "prog_ids": prog_ids,
        "programs": live_programs,
        "program_measurements": program_measurements,
        "app_measurement": app_measurement,
        "baseline": {
            "programs": programs_by_id,
            "exec_ns_mean": _mean_exec_ns(programs_by_id),
        },
        "baseline_workload": baseline_workload,
        "baseline_workloads": baseline_workloads,
        "rejit_apply": dict(apply_result),
        "rejit": {
            "programs": rejit_programs_by_id,
            "exec_ns_mean": _mean_exec_ns(rejit_programs_by_id),
        } if had_post_rejit else None,
        "had_post_rejit_measurement": had_post_rejit,
        "rejit_workload": rejit_workload,
        "rejit_workloads": rejit_workloads,
        "process": dict(getattr(runner, "process_output", {})),
        "command_used": [str(item) for item in (lifecycle_result.artifacts.get("command_used") or getattr(runner, "command_used", []) or [])],
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
    samples = _sample_count(args, suite.defaults)
    results: list[dict[str, object]] = []
    fatal_error = ""
    reset_pending_result_metadata()

    with DaemonSession.start(daemon_binary, load_kinsn=True) as daemon_session:
        prepared_daemon_session = prepare_daemon_session(
            daemon_session,
            daemon_binary=daemon_binary,
        )
        for index, app in enumerate(suite.apps):
            _print_progress(
                "app_start",
                app=app.name,
                runner=app.runner,
                workload=app.workload_for("corpus"),
            )
            try:
                app_workload_seconds = _app_workload_seconds(args, suite.defaults, app)
                result = _run_app(
                    app,
                    daemon_session=prepared_daemon_session,
                    workload_seconds=app_workload_seconds,
                    samples=samples,
                )
            except Exception as exc:
                result = {
                    "app": app.name,
                    "runner": app.runner,
                    "workload": _workload_payload(app.workload),
                    "selected_workload": app.workload_for("corpus"),
                    "configured_workload_seconds": _app_workload_seconds(args, suite.defaults, app),
                    "args": dict(app.args),
                    "status": "error",
                    "error": str(exc),
                    "program_measurements": {},
                }
            results.append(result)
            _print_progress(
                "app_done",
                app=app.name,
                status=result.get("status"),
                error=result.get("error"),
                program_count=len(result.get("program_measurements") or {}),
            )
            daemon_error = _daemon_exit_error(daemon_session)
            if daemon_error is not None:
                fatal_error = daemon_error
                break
            if index + 1 < len(suite.apps):
                wait_for_suite_quiescence()

        if fatal_error:
            selected_names = {str(result.get("app") or "") for result in results}
            for app in suite.apps:
                if app.name in selected_names:
                    continue
                results.append(
                    {
                        "app": app.name,
                        "runner": app.runner,
                        "workload": _workload_payload(app.workload),
                        "selected_workload": app.workload_for("corpus"),
                        "configured_workload_seconds": _app_workload_seconds(args, suite.defaults, app),
                        "args": dict(app.args),
                        "status": "error",
                        "error": fatal_error,
                        "program_measurements": {},
                    }
                )
        daemon_socket = str(prepared_daemon_session.session.socket_path)
        kinsn_metadata = dict(prepared_daemon_session.metadata)

    status_counts = Counter(str(result.get("status") or "error") for result in results)
    payload = {
        "generated_at": datetime.now(timezone.utc).isoformat(),
        "manifest": str(suite_path),
        "suite_name": suite.suite_name,
        "daemon": str(daemon_binary),
        "daemon_socket": daemon_socket,
        "filters": list(args.filters or []),
        "samples": samples,
        "workload_seconds": workload_seconds,
        "suite_summary": suite_summary,
        "results": results,
        "kinsn_modules": kinsn_metadata,
        "summary": _build_summary(
            results,
            selected_apps=len(suite.apps),
            status_counts=status_counts,
        ),
        "status": "ok" if status_counts.get("error", 0) == 0 else "error",
    }
    if fatal_error:
        payload["fatal_error"] = fatal_error
    return attach_pending_result_metadata(payload)


def main(argv: list[str] | None = None) -> int:
    args = parse_args(argv)
    payload = run_suite(args)
    output_json = Path(args.output_json).resolve()
    output_md = Path(args.output_md).resolve()
    ensure_parent(output_json)
    ensure_parent(output_md)
    write_json(output_json, payload)
    write_text(output_md, build_markdown(payload) + "\n")
    print(
        json.dumps(
            {
                "status": payload["status"],
                "output_json": str(output_json),
                "output_md": str(output_md),
            },
            indent=2,
        )
    )
    return 0 if payload["status"] == "ok" else 1


if __name__ == "__main__":
    raise SystemExit(main())
