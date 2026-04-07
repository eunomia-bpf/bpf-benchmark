#!/usr/bin/env python3
from __future__ import annotations

import argparse
import json
import os
import sys
from collections import Counter
from dataclasses import dataclass, field
from datetime import datetime, timezone
from pathlib import Path
from typing import Any, Mapping, Sequence

REPO_ROOT = Path(__file__).resolve().parents[1]
if str(REPO_ROOT) not in sys.path:
    sys.path.insert(0, str(REPO_ROOT))

from runner.libs import ROOT_DIR, ensure_parent, write_json, write_text
from runner.libs.app_runners import get_app_runner
from runner.libs.app_runners.base import AppRunner
from runner.libs.app_suite_schema import AppSpec, AppWorkload, load_app_suite_from_yaml
from runner.libs.bpf_stats import enable_bpf_stats, sample_bpf_stats
from runner.libs.case_common import (
    _append_pending_kinsn_metadata,
    _clone_daemon_metadata,
    _merge_group_rejit_results,
    _resolve_apply_passes_by_program,
    _resolve_scan_pass_selection,
    CaseLifecycleState,
    attach_pending_result_metadata,
    prepare_daemon_session,
    rejit_program_result,
    reset_pending_result_metadata,
    run_app_runner_lifecycle,
    wait_for_suite_quiescence,
)
from runner.libs.daemon_session import DaemonSession
from runner.libs.rejit import benchmark_rejit_enabled_passes, collect_effective_enabled_passes
from runner.libs.run_artifacts import (
    ArtifactSession,
    current_process_identity,
    derive_run_type,
    repo_relative_path,
)
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
    parser.add_argument(
        "--rejit-passes",
        default=None,
        help="Comma-separated ReJIT passes to enable for corpus apply. Pass an empty string to run zero passes.",
    )
    parser.add_argument(
        "--no-kinsn",
        action="store_true",
        help="Disable loading kinsn modules for this corpus run.",
    )
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


def _restore_environment(saved_env: dict[str, str]) -> None:
    for key in list(os.environ.keys()):
        if key not in saved_env:
            del os.environ[key]
    os.environ.update(saved_env)


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
    runner: AppRunner,
    prog_ids: Sequence[int],
    *,
    workload_seconds: float,
    samples: int,
) -> dict[str, object]:
    workloads: list[dict[str, object]] = []
    last_workload: dict[str, object] | None = None
    initial_stats = sample_bpf_stats(list(prog_ids), prog_fds=runner.program_fds)
    for _ in range(samples):
        workload = runner.run_workload(workload_seconds).to_dict()
        last_workload = dict(workload)
        workloads.append(dict(workload))
    final_stats = sample_bpf_stats(list(prog_ids), prog_fds=runner.program_fds)
    return {
        "workload": last_workload,
        "workloads": workloads,
        "initial_stats": initial_stats,
        "final_stats": final_stats,
    }


def _normalized_stats_snapshot(raw_stats: Mapping[object, object] | None) -> dict[int, dict[str, object]]:
    normalized: dict[int, dict[str, object]] = {}
    if raw_stats is None:
        return normalized
    if not isinstance(raw_stats, Mapping):
        raise RuntimeError(f"stats snapshot must be a mapping, got {type(raw_stats)!r}")
    for raw_key, raw_value in raw_stats.items():
        try:
            prog_id = int(raw_key)
        except (TypeError, ValueError) as exc:
            raise RuntimeError(f"stats snapshot contains invalid program id: {raw_key!r}") from exc
        if not isinstance(raw_value, Mapping):
            raise RuntimeError(f"stats snapshot for program {prog_id} is not a mapping")
        normalized[prog_id] = {str(field): value for field, value in raw_value.items()}
    return normalized


def _measurement_program_stats(
    measurement: Mapping[str, object] | None,
    prog_ids: Sequence[int],
) -> dict[str, dict[str, object]]:
    if not isinstance(measurement, Mapping):
        return {}
    initial_snapshot = _normalized_stats_snapshot(measurement.get("initial_stats"))
    final_snapshot = _normalized_stats_snapshot(measurement.get("final_stats"))
    return _program_stats_by_prog_id(
        _program_phase_stats(final_snapshot, initial_snapshot),
        prog_ids,
    )


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


def _apply_record_changed(apply_record: Mapping[str, object] | None) -> bool:
    if not isinstance(apply_record, Mapping):
        return False
    counts = apply_record.get("counts")
    if isinstance(counts, Mapping) and int(counts.get("applied_sites", 0) or 0) > 0:
        return True
    summary = apply_record.get("summary")
    if isinstance(summary, Mapping):
        if bool(summary.get("program_changed")):
            return True
        if int(summary.get("total_sites_applied", 0) or 0) > 0:
            return True
    debug_result = apply_record.get("debug_result")
    if isinstance(debug_result, Mapping):
        if bool(debug_result.get("changed")):
            return True
        debug_summary = debug_result.get("summary")
        if isinstance(debug_summary, Mapping):
            if bool(debug_summary.get("program_changed")):
                return True
            if int(debug_summary.get("total_sites_applied", 0) or 0) > 0:
                return True
        raw_passes_applied = debug_result.get("passes_applied")
        if isinstance(raw_passes_applied, Sequence) and not isinstance(raw_passes_applied, (str, bytes, bytearray)):
            return any(str(pass_name).strip() for pass_name in raw_passes_applied)
    return False


def _rejit_result_has_any_change(rejit_result: Mapping[str, object] | None) -> bool:
    if not isinstance(rejit_result, Mapping):
        return False
    per_program = rejit_result.get("per_program")
    if isinstance(per_program, Mapping) and per_program:
        return any(
            _apply_record_changed(record if isinstance(record, Mapping) else None)
            for record in per_program.values()
        )
    return _apply_record_changed(rejit_result)


def _comparison_exclusion_reason(
    baseline_exec_ns: float | None,
    rejit_exec_ns: float | None,
    *,
    had_post_rejit: bool,
    any_changed: bool,
    apply_record: Mapping[str, object],
) -> str:
    apply_error = str(apply_record.get("error") or "").strip()
    if baseline_exec_ns is None:
        return "missing_baseline_exec_ns"
    if baseline_exec_ns <= 0.0:
        return "non_positive_baseline_exec_ns"
    if not _apply_record_changed(apply_record):
        if apply_error:
            return f"apply_error: {apply_error}"
        return "no_programs_changed_in_loader"
    if not had_post_rejit:
        if apply_error:
            return f"apply_error: {apply_error}"
        if not any_changed:
            return "no_programs_changed_in_loader"
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
    any_changed = _rejit_result_has_any_change(apply_result)
    for live_program in live_programs:
        prog_id = int(live_program.get("id", 0) or 0)
        if prog_id <= 0:
            continue
        program_name = str(live_program.get("name") or f"prog_{prog_id}")
        baseline_record = dict(baseline_programs.get(str(prog_id), {}))
        rejit_record = dict(rejit_programs.get(str(prog_id), {}))
        apply_record = rejit_program_result(apply_result, prog_id)
        if not apply_record:
            raise RuntimeError(
                f"{app_name}: REJIT result is missing per-program apply record for prog {prog_id}"
            )
        applied = bool(apply_record.get("applied"))
        changed = _apply_record_changed(apply_record)
        baseline_exec_ns = _phase_exec_ns(baseline_record)
        rejit_exec_ns = _phase_exec_ns(rejit_record)
        comparable = (
            changed
            and baseline_exec_ns is not None
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
                any_changed=any_changed,
                apply_record=apply_record,
            )
        rows[str(prog_id)] = {
            "id": prog_id,
            "label": _program_label(app_name, program_name, prog_id),
            "name": program_name,
            "type": str(live_program.get("type") or _infer_prog_type_name(live_program)),
            "applied": applied,
            "changed": changed,
            "comparable": comparable,
            "speedup": speedup,
            "comparison_exclusion_reason": exclusion_reason,
            "baseline": baseline_record,
            "rejit": rejit_record if had_post_rejit else {},
            "apply": apply_record,
        }
    return rows


def _result_program_rows(result: Mapping[str, object]) -> list[dict[str, object]]:
    return [
        dict(row)
        for row in (result.get("program_measurements") or {}).values()
        if isinstance(row, Mapping)
    ]


def _app_measurement_row(result: Mapping[str, object]) -> dict[str, object] | None:
    measurement = result.get("app_measurement")
    if not isinstance(measurement, Mapping):
        return None
    app_name = str(result.get("app") or "")
    apply_result = result.get("rejit_apply")
    apply_record = dict(apply_result) if isinstance(apply_result, Mapping) else {}
    applied = bool(apply_record.get("applied"))
    changed = _apply_record_changed(apply_record)
    baseline = measurement.get("baseline")
    post_rejit = measurement.get("post_rejit")
    speedup = measurement.get("speedup")
    comparable = changed and isinstance(speedup, (int, float)) and float(speedup) > 0.0
    exclusion_reason = ""
    apply_error = str(apply_record.get("error") or "").strip()
    if not comparable:
        if not isinstance(baseline, (int, float)):
            exclusion_reason = "missing_baseline_app_metric"
        elif float(baseline) <= 0.0:
            exclusion_reason = "non_positive_baseline_app_metric"
        elif not changed:
            exclusion_reason = f"apply_error: {apply_error}" if apply_error else "no_programs_changed_in_loader"
        elif not bool(result.get("had_post_rejit_measurement")):
            if apply_error:
                exclusion_reason = f"apply_error: {apply_error}"
            else:
                exclusion_reason = "missing_post_rejit_measurement"
        elif not isinstance(post_rejit, (int, float)):
            exclusion_reason = f"apply_error: {apply_error}" if apply_error else "missing_rejit_app_metric"
        elif float(post_rejit) <= 0.0:
            exclusion_reason = "non_positive_rejit_app_metric"
        else:
            exclusion_reason = "missing_app_speedup"
    return {
        "id": 0,
        "label": f"{app_name}:app",
        "name": "__app__",
        "type": "app",
        "unit": "app",
        "metric": str(measurement.get("metric") or ""),
        "applied": applied,
        "changed": changed,
        "comparable": comparable,
        "speedup": float(speedup) if comparable else None,
        "comparison_exclusion_reason": exclusion_reason,
        "baseline": {"value": baseline},
        "rejit": {"value": post_rejit} if bool(result.get("had_post_rejit_measurement")) else {},
        "apply": apply_record,
    }


def _result_comparison_rows(result: Mapping[str, object]) -> list[dict[str, object]]:
    rows = _result_program_rows(result)
    if str(result.get("measurement_mode") or "").strip() == "app":
        app_row = _app_measurement_row(result)
        if app_row is not None:
            rows.append(app_row)
    return rows


def _comparison_rows(
    results: Sequence[Mapping[str, object]],
) -> tuple[list[dict[str, object]], list[dict[str, object]], list[dict[str, object]]]:
    comparable_rows: list[dict[str, object]] = []
    applied_rows: list[dict[str, object]] = []
    excluded_rows: list[dict[str, object]] = []
    for result in results:
        app_name = str(result.get("app") or "")
        for row in _result_comparison_rows(result):
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
                    "unit": str(row.get("unit") or "program"),
                    "program_id": int(row.get("id", 0) or 0),
                    "program": str(row.get("name") or ""),
                    "label": str(row.get("label") or ""),
                    "applied": bool(row.get("applied")),
                    "changed": bool(row.get("changed")),
                    "reason": str(row.get("comparison_exclusion_reason") or "unknown"),
                    "apply_error": str(((row.get("apply") or {}).get("error")) or ""),
                }
            )
    return comparable_rows, applied_rows, excluded_rows


def _per_app_breakdown(results: Sequence[Mapping[str, object]]) -> list[dict[str, object]]:
    breakdown: list[dict[str, object]] = []
    for result in results:
        program_rows = _result_program_rows(result)
        comparison_rows = _result_comparison_rows(result)
        comparable_speedups = [
            float(row["speedup"])
            for row in comparison_rows
            if bool(row.get("comparable")) and isinstance(row.get("speedup"), (int, float))
        ]
        applied_speedups = [
            float(row["speedup"])
            for row in comparison_rows
            if bool(row.get("applied")) and bool(row.get("comparable")) and isinstance(row.get("speedup"), (int, float))
        ]
        exclusions = [
            {
                "program_id": int(row.get("id", 0) or 0),
                "program": str(row.get("name") or ""),
                "label": str(row.get("label") or ""),
                "unit": str(row.get("unit") or "program"),
                "reason": str(row.get("comparison_exclusion_reason") or "unknown"),
            }
            for row in comparison_rows
            if not bool(row.get("comparable"))
        ]
        breakdown.append(
            {
                "app": str(result.get("app") or ""),
                "runner": str(result.get("runner") or ""),
                "workload": str(result.get("selected_workload") or ""),
                "measurement_mode": str(result.get("measurement_mode") or ""),
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
        len(_result_program_rows(result))
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


def _active_program_ids(
    initial_stats: Mapping[int, Mapping[str, object]],
    final_stats: Mapping[int, Mapping[str, object]],
    candidate_prog_ids: Sequence[int],
) -> list[int]:
    selected: list[int] = []
    for prog_id in candidate_prog_ids:
        normalized_prog_id = int(prog_id)
        if normalized_prog_id <= 0:
            continue
        before = initial_stats.get(normalized_prog_id) or {}
        after = final_stats.get(normalized_prog_id) or {}
        run_cnt_delta = int(after.get("run_cnt", 0) or 0) - int(before.get("run_cnt", 0) or 0)
        run_time_delta = int(after.get("run_time_ns", 0) or 0) - int(before.get("run_time_ns", 0) or 0)
        if run_cnt_delta > 0 or run_time_delta > 0:
            selected.append(normalized_prog_id)
    return selected


def _build_runner_state(
    app: AppSpec,
    runner: AppRunner,
    started_prog_ids: Sequence[int],
) -> CaseLifecycleState:
    prog_ids = [int(value) for value in started_prog_ids if int(value) > 0]
    if not prog_ids:
        raise RuntimeError(f"{app.name}: runner did not return any live prog_ids")
    programs = [dict(program) for program in runner.programs]
    if not programs:
        raise RuntimeError(f"{app.name}: runner did not expose any live programs")
    return CaseLifecycleState(
        runtime=runner,
        target_prog_ids=list(prog_ids),
        apply_prog_ids=list(prog_ids),
        artifacts={
            "runner_artifacts": dict(runner.artifacts),
            "programs": programs,
            "command_used": [str(item) for item in runner.command_used],
            "rejit_policy_context": {
                "repo": str(app.name).strip(),
                "category": str(app.runner).strip(),
                "level": "corpus",
            },
        },
    )


def _configure_program_selection(
    app: AppSpec,
    runner: AppRunner,
    lifecycle: CaseLifecycleState,
    *,
    measurement_mode: str,
    baseline_measurement: Mapping[str, object],
) -> None:
    initial_stats = _normalized_stats_snapshot(baseline_measurement.get("initial_stats"))
    final_stats = _normalized_stats_snapshot(baseline_measurement.get("final_stats"))
    selected = runner.select_corpus_program_ids(initial_stats, final_stats)
    if selected is None and measurement_mode == "program":
        selected = _active_program_ids(initial_stats, final_stats, lifecycle.target_prog_ids)
    if selected is None:
        return
    selected_prog_ids = [
        int(prog_id)
        for prog_id in selected
        if int(prog_id) > 0
    ]
    if not selected_prog_ids:
        raise RuntimeError(
            f"{app.name}: workload {app.workload_for('corpus')!r} did not execute any target programs during baseline"
        )
    lifecycle.target_prog_ids = list(selected_prog_ids)
    lifecycle.apply_prog_ids = list(selected_prog_ids)
    selected_programs = _selected_live_programs(
        lifecycle.artifacts.get("programs") or [],
        selected_prog_ids,
    )
    if selected_programs:
        lifecycle.artifacts["programs"] = selected_programs


def _build_app_error_result(
    app: AppSpec,
    *,
    workload_seconds: float,
    error: str,
    measurement_mode: str | None = None,
    runner: AppRunner | None = None,
    state: CaseLifecycleState | None = None,
    baseline_measurement: Mapping[str, object] | None = None,
    apply_result: Mapping[str, object] | None = None,
    rejit_measurement: Mapping[str, object] | None = None,
) -> dict[str, object]:
    baseline_workload = None
    baseline_workloads: list[dict[str, object]] = []
    if isinstance(baseline_measurement, Mapping):
        raw_baseline_workload = baseline_measurement.get("workload")
        if isinstance(raw_baseline_workload, Mapping):
            baseline_workload = dict(raw_baseline_workload)
        baseline_workloads = [
            dict(workload)
            for workload in (baseline_measurement.get("workloads") or [])
            if isinstance(workload, Mapping)
        ]
    prog_ids = [] if state is None else [int(value) for value in state.target_prog_ids if int(value) > 0]
    live_programs = [] if state is None else [dict(program) for program in (state.artifacts.get("programs") or [])]
    baseline_programs = _measurement_program_stats(baseline_measurement, prog_ids)
    had_post_rejit = isinstance(rejit_measurement, Mapping)
    rejit_programs = _measurement_program_stats(rejit_measurement, prog_ids)
    rejit_workload = None
    rejit_workloads: list[dict[str, object]] = []
    if isinstance(rejit_measurement, Mapping):
        raw_rejit_workload = rejit_measurement.get("workload")
        if isinstance(raw_rejit_workload, Mapping):
            rejit_workload = dict(raw_rejit_workload)
        rejit_workloads = [
            dict(workload)
            for workload in (rejit_measurement.get("workloads") or [])
            if isinstance(workload, Mapping)
        ]
    normalized_apply_result = dict(apply_result or {})
    program_measurements = {}
    raw_apply_per_program = normalized_apply_result.get("per_program")
    if (
        str(measurement_mode or "").strip() == "program"
        and live_programs
        and isinstance(raw_apply_per_program, Mapping)
    ):
        program_measurements = _build_program_measurements(
            app.name,
            live_programs,
            baseline_programs,
            rejit_programs,
            normalized_apply_result,
            had_post_rejit=had_post_rejit,
        )
    return {
        "app": app.name,
        "runner": app.runner,
        "workload": _workload_payload(app.workload),
        "selected_workload": app.workload_for("corpus"),
        "measurement_mode": str(measurement_mode or ""),
        "configured_workload_seconds": float(workload_seconds),
        "args": dict(app.args),
        "status": "error",
        "error": str(error),
        "prog_ids": prog_ids,
        "programs": live_programs,
        "program_measurements": program_measurements,
        "app_measurement": None,
        "baseline": {
            "programs": baseline_programs,
            "exec_ns_mean": _mean_exec_ns(baseline_programs),
        },
        "baseline_workload": baseline_workload,
        "baseline_workloads": baseline_workloads,
        "rejit_apply": normalized_apply_result,
        "rejit": {
            "programs": rejit_programs,
            "exec_ns_mean": _mean_exec_ns(rejit_programs),
        } if had_post_rejit else None,
        "had_post_rejit_measurement": had_post_rejit,
        "rejit_workload": rejit_workload,
        "rejit_workloads": rejit_workloads,
        "process": {} if runner is None else dict(runner.process_output),
        "command_used": []
        if state is None
        else [str(item) for item in (state.artifacts.get("command_used") or [])],
    }


def _slice_scan_results(
    scan_results: Mapping[int, Mapping[str, object]],
    prog_ids: Sequence[int],
) -> dict[int, dict[str, object]]:
    return {
        int(prog_id): dict(scan_results[int(prog_id)])
        for prog_id in prog_ids
        if int(prog_id) in scan_results
    }


def _slice_rejit_result(
    rejit_result: Mapping[str, object],
    prog_ids: Sequence[int],
) -> dict[str, object]:
    requested_prog_ids = [int(value) for value in prog_ids if int(value) > 0]
    if not requested_prog_ids:
        return {}

    per_program: dict[int, dict[str, object]] = {}
    outputs: list[str] = []
    errors: list[str] = []
    total_sites = 0
    applied_sites = 0
    exit_code = 0
    effective_enabled_passes_by_program: dict[str, list[str]] = {}
    raw_effective_enabled = rejit_result.get("effective_enabled_passes_by_program")
    for prog_id in requested_prog_ids:
        record = rejit_program_result(rejit_result, prog_id)
        if not record:
            continue
        per_program[int(prog_id)] = dict(record)
        output = str(record.get("output") or "")
        if output:
            outputs.append(output)
        exit_code = max(exit_code, int(record.get("exit_code", 0) or 0))
        counts = record.get("counts")
        if isinstance(counts, Mapping):
            total_sites += int(counts.get("total_sites", 0) or 0)
            applied_sites += int(counts.get("applied_sites", 0) or 0)
        error = str(record.get("error") or "").strip()
        if error:
            errors.append(error)
        if isinstance(raw_effective_enabled, Mapping):
            raw_passes = raw_effective_enabled.get(str(int(prog_id)))
            if raw_passes is None:
                raw_passes = raw_effective_enabled.get(int(prog_id))
            if isinstance(raw_passes, Sequence) and not isinstance(raw_passes, (str, bytes, bytearray)):
                effective_enabled_passes_by_program[str(int(prog_id))] = [
                    str(pass_name)
                    for pass_name in raw_passes
                    if str(pass_name).strip()
                ]

    applied_any = any(bool(record.get("applied")) for record in per_program.values())
    all_applied = bool(per_program) and all(bool(record.get("applied")) for record in per_program.values())
    error_message = "; ".join(errors)
    if not error_message and not per_program:
        error_message = str(rejit_result.get("error") or "").strip()
    sliced = {
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
            "requested": len(requested_prog_ids),
            "applied": sum(1 for record in per_program.values() if bool(record.get("applied"))),
            "not_applied": sum(1 for record in per_program.values() if not bool(record.get("applied"))),
        },
        "error": error_message,
        "selection_source": str(rejit_result.get("selection_source") or ""),
        "scan_enabled_passes": list(rejit_result.get("scan_enabled_passes") or []),
        "effective_enabled_passes_by_program": effective_enabled_passes_by_program,
    }
    benchmark_profile = str(rejit_result.get("benchmark_profile") or "").strip()
    if benchmark_profile:
        sliced["benchmark_profile"] = benchmark_profile
    return sliced


def _finalize_app_result(
    app: AppSpec,
    *,
    runner: AppRunner,
    state: CaseLifecycleState,
    workload_seconds: float,
    measurement_mode: str,
    baseline_measurement: Mapping[str, object],
    apply_result: Mapping[str, object] | None,
    rejit_measurement: Mapping[str, object] | None,
) -> dict[str, object]:
    prog_ids = [int(value) for value in state.target_prog_ids if int(value) > 0]
    live_programs = [dict(program) for program in (state.artifacts.get("programs") or [])]
    if not live_programs:
        raise RuntimeError(f"{app.name}: runner lifecycle did not expose any live programs")

    baseline_initial_snapshot = _normalized_stats_snapshot(baseline_measurement.get("initial_stats"))
    baseline_final_snapshot = _normalized_stats_snapshot(baseline_measurement.get("final_stats"))
    baseline_workload = dict(baseline_measurement.get("workload") or {}) if baseline_measurement.get("workload") else None
    baseline_workloads = [dict(workload) for workload in (baseline_measurement.get("workloads") or [])]
    baseline_phase = _program_phase_stats(baseline_final_snapshot, baseline_initial_snapshot)
    programs_by_id = _program_stats_by_prog_id(baseline_phase, prog_ids)

    had_post_rejit = rejit_measurement is not None
    rejit_programs_by_id: dict[str, dict[str, object]] = {}
    rejit_workload: dict[str, object] | None = None
    rejit_workloads: list[dict[str, object]] = []
    if had_post_rejit:
        rejit_initial_snapshot = _normalized_stats_snapshot(rejit_measurement.get("initial_stats"))
        rejit_final_snapshot = _normalized_stats_snapshot(rejit_measurement.get("final_stats"))
        rejit_workload = dict(rejit_measurement.get("workload") or {}) if rejit_measurement.get("workload") else None
        rejit_workloads = [dict(workload) for workload in (rejit_measurement.get("workloads") or [])]
        rejit_phase = _program_phase_stats(rejit_final_snapshot, rejit_initial_snapshot)
        rejit_programs_by_id = _program_stats_by_prog_id(rejit_phase, prog_ids)

    normalized_apply_result = dict(apply_result or {})
    error = str(normalized_apply_result.get("error") or "").strip()
    if measurement_mode == "program" and not _has_phase_measurement(programs_by_id):
        raise RuntimeError(
            f"{app.name}: workload {app.workload_for('corpus')!r} did not execute any target programs during baseline"
        )
    if measurement_mode == "program" and had_post_rejit and not error and not _has_phase_measurement(rejit_programs_by_id):
        raise RuntimeError(
            f"{app.name}: workload {app.workload_for('corpus')!r} did not execute any target programs after rejit"
        )
    status = "error" if error else "ok"
    program_measurements = _build_program_measurements(
        app.name,
        live_programs,
        programs_by_id,
        rejit_programs_by_id,
        normalized_apply_result,
        had_post_rejit=had_post_rejit,
    )
    app_measurement: dict[str, object] | None = None
    if measurement_mode == "app":
        baseline_ops_per_sec = _workload_ops_per_sec(baseline_workload)
        rejit_ops_per_sec = _workload_ops_per_sec(rejit_workload)
        if baseline_ops_per_sec is None or baseline_ops_per_sec <= 0.0:
            raise RuntimeError(f"{app.name}: workload {app.workload_for('corpus')!r} did not produce a baseline throughput measurement")
        if had_post_rejit and not error and (rejit_ops_per_sec is None or rejit_ops_per_sec <= 0.0):
            raise RuntimeError(f"{app.name}: workload {app.workload_for('corpus')!r} did not produce a post-rejit throughput measurement")
        app_measurement = {
            "metric": "ops_per_sec",
            "baseline": baseline_ops_per_sec,
            "post_rejit": rejit_ops_per_sec,
            "speedup": None
            if rejit_ops_per_sec is None
            else (rejit_ops_per_sec / baseline_ops_per_sec),
        }
    elif not error and _rejit_result_has_any_change(normalized_apply_result) and not _has_comparable_measurement(program_measurements):
        raise RuntimeError(
            f"{app.name}: workload {app.workload_for('corpus')!r} produced no comparable target program measurements"
        )

    return {
        "app": app.name,
        "runner": app.runner,
        "workload": _workload_payload(app.workload),
        "selected_workload": app.workload_for("corpus"),
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
        "rejit_apply": normalized_apply_result,
        "rejit": {
            "programs": rejit_programs_by_id,
            "exec_ns_mean": _mean_exec_ns(rejit_programs_by_id),
        } if had_post_rejit else None,
        "had_post_rejit_measurement": had_post_rejit,
        "rejit_workload": rejit_workload,
        "rejit_workloads": rejit_workloads,
        "process": dict(runner.process_output),
        "command_used": [str(item) for item in (state.artifacts.get("command_used") or [])],
    }


@dataclass(slots=True)
class CorpusAppSession:
    app: AppSpec
    runner: AppRunner
    state: CaseLifecycleState
    measurement_mode: str
    workload_seconds: float
    kinsn_metadata: dict[str, object] | None = None
    baseline_measurement: dict[str, object] | None = None
    scan_results: dict[int, dict[str, object]] = field(default_factory=dict)
    apply_result: dict[str, object] = field(default_factory=dict)
    rejit_measurement: dict[str, object] | None = None
    error: str = ""
    stop_error: str = ""
    stopped: bool = False
    kinsn_recorded: bool = False

    def requested_prog_ids(self) -> list[int]:
        return [int(value) for value in self.state.apply_prog_ids if int(value) > 0]


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
    measurement_mode = runner.corpus_measurement_mode().strip()
    if measurement_mode not in {"program", "app"}:
        raise RuntimeError(f"{app.name}: runner returned unsupported corpus measurement mode {measurement_mode!r}")

    def before_rejit(_setup_state: object, lifecycle: object, baseline: Mapping[str, object]) -> object | None:
        measurement = dict((baseline.get("measurement") or {}))
        _configure_program_selection(
            app,
            runner,
            lifecycle,
            measurement_mode=measurement_mode,
            baseline_measurement=measurement,
        )
        return None

    with enable_bpf_stats():
        lifecycle_result = run_app_runner_lifecycle(
            daemon_session=daemon_session,
            runner=runner,
            build_state=lambda current_runner, started_prog_ids: _build_runner_state(
                app,
                current_runner,
                started_prog_ids,
            ),
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

    baseline_measurement = dict((lifecycle_result.baseline.get("measurement") or {}))
    rejit_measurement = (
        dict((lifecycle_result.post_rejit or {}).get("measurement") or {})
        if lifecycle_result.post_rejit is not None
        else None
    )
    return _finalize_app_result(
        app,
        runner=runner,
        state=lifecycle_result.state,
        workload_seconds=workload_seconds,
        measurement_mode=measurement_mode,
        baseline_measurement=baseline_measurement,
        apply_result=lifecycle_result.rejit_result,
        rejit_measurement=rejit_measurement,
    )


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
    results_by_name: dict[str, dict[str, object]] = {}
    completed_apps: set[str] = set()
    fatal_error = ""
    reset_pending_result_metadata()

    with DaemonSession.start(daemon_binary, load_kinsn=not bool(args.no_kinsn)) as daemon_session:
        prepared_daemon_session = prepare_daemon_session(
            daemon_session,
            daemon_binary=daemon_binary,
        )
        sessions: list[CorpusAppSession] = []
        active_sessions: list[CorpusAppSession] = []

        try:
            with enable_bpf_stats():
                for app in suite.apps:
                    _print_progress(
                        "app_start",
                        app=app.name,
                        runner=app.runner,
                        workload=app.workload_for("corpus"),
                    )
                    app_workload_seconds = _app_workload_seconds(args, suite.defaults, app)
                    runner: AppRunner | None = None
                    try:
                        runner = get_app_runner(
                            app.runner,
                            app_name=app.name,
                            workload=app.workload_for("corpus"),
                            **app.args,
                        )
                        measurement_mode = runner.corpus_measurement_mode().strip()
                        if measurement_mode not in {"program", "app"}:
                            raise RuntimeError(
                                f"{app.name}: runner returned unsupported corpus measurement mode {measurement_mode!r}"
                            )
                        started_prog_ids = [int(value) for value in runner.start() if int(value) > 0]
                        state = _build_runner_state(app, runner, started_prog_ids)
                        session = CorpusAppSession(
                            app=app,
                            runner=runner,
                            state=state,
                            measurement_mode=measurement_mode,
                            workload_seconds=app_workload_seconds,
                            kinsn_metadata=(
                                _clone_daemon_metadata(prepared_daemon_session, state.requested_prog_ids())
                                if bool(getattr(daemon_session, "load_kinsn", False))
                                else None
                            ),
                        )
                        sessions.append(session)
                        active_sessions.append(session)
                    except Exception as exc:
                        if runner is not None:
                            try:
                                runner.stop()
                            except Exception:
                                pass
                        result = _build_app_error_result(
                            app,
                            workload_seconds=app_workload_seconds,
                            error=str(exc),
                        )
                        results_by_name[app.name] = result
                        completed_apps.add(app.name)
                        _print_progress(
                            "app_done",
                            app=app.name,
                            status=result.get("status"),
                            error=result.get("error"),
                            program_count=0,
                        )
                    daemon_error = _daemon_exit_error(daemon_session)
                    if daemon_error is not None:
                        fatal_error = daemon_error
                        break

                if not fatal_error:
                    surviving_sessions: list[CorpusAppSession] = []
                    for session in active_sessions:
                        try:
                            session.baseline_measurement = _measure_runner_phase(
                                session.runner,
                                session.state.target_prog_ids,
                                workload_seconds=session.workload_seconds,
                                samples=samples,
                            )
                            _configure_program_selection(
                                session.app,
                                session.runner,
                                session.state,
                                measurement_mode=session.measurement_mode,
                                baseline_measurement=session.baseline_measurement,
                            )
                            surviving_sessions.append(session)
                        except Exception as exc:
                            session.error = str(exc)
                            if session.kinsn_metadata is not None:
                                session.kinsn_metadata["status"] = "error"
                                session.kinsn_metadata["error"] = session.error
                            try:
                                session.runner.stop()
                                session.stopped = True
                            except Exception as stop_exc:
                                session.stop_error = str(stop_exc)
                            try:
                                wait_for_suite_quiescence()
                            except Exception as quiesce_exc:
                                session.error = f"{session.error}; {quiesce_exc}"
                            error_message = session.error
                            if session.stop_error:
                                error_message = f"{error_message}; stop failed: {session.stop_error}"
                            result = _build_app_error_result(
                                session.app,
                                workload_seconds=session.workload_seconds,
                                error=error_message,
                                measurement_mode=session.measurement_mode,
                                runner=session.runner,
                                state=session.state,
                                baseline_measurement=session.baseline_measurement,
                                apply_result=session.apply_result,
                                rejit_measurement=session.rejit_measurement,
                            )
                            results_by_name[session.app.name] = result
                            completed_apps.add(session.app.name)
                            _print_progress(
                                "app_done",
                                app=session.app.name,
                                status=result.get("status"),
                                error=result.get("error"),
                                program_count=0,
                            )
                        daemon_error = _daemon_exit_error(daemon_session)
                        if daemon_error is not None:
                            fatal_error = daemon_error
                            break
                    active_sessions = surviving_sessions

                if not fatal_error and active_sessions:
                    requested_prog_ids = [
                        prog_id
                        for session in active_sessions
                        for prog_id in session.requested_prog_ids()
                    ]
                    scan_enabled_passes, benchmark_config, selection_source = _resolve_scan_pass_selection(None)
                    scan_results = prepared_daemon_session.session.scan_programs(
                        requested_prog_ids,
                        enabled_passes=scan_enabled_passes,
                    )
                    apply_enabled_passes_by_prog: dict[int, list[str]] = {}
                    for session in active_sessions:
                        apply_enabled_passes_by_prog.update(
                            _resolve_apply_passes_by_program(
                                requested_prog_ids=session.requested_prog_ids(),
                                lifecycle_state=session.state,
                                scan_results=scan_results,
                                enabled_passes=None,
                                benchmark_config=benchmark_config,
                            )
                        )
                        session.scan_results = _slice_scan_results(
                            scan_results,
                            session.requested_prog_ids(),
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
                                prepared_daemon_session.session.apply_rejit(
                                    group_prog_ids,
                                    enabled_passes=list(pass_tuple),
                                ),
                            )
                        )

                    merged_rejit_result = _merge_group_rejit_results(
                        requested_prog_ids=requested_prog_ids,
                        group_results=group_rejit_results,
                        enabled_passes_by_prog=apply_enabled_passes_by_prog,
                        scan_enabled_passes=scan_enabled_passes,
                        selection_source=selection_source,
                        benchmark_config=benchmark_config,
                    )
                    for session in active_sessions:
                        session.apply_result = _slice_rejit_result(
                            merged_rejit_result,
                            session.requested_prog_ids(),
                        )
                        if session.kinsn_metadata is not None:
                            session.kinsn_metadata["status"] = "completed"

                    daemon_error = _daemon_exit_error(daemon_session)
                    if daemon_error is not None:
                        fatal_error = daemon_error

                if not fatal_error:
                    for session in active_sessions:
                        if not _rejit_result_has_any_change(session.apply_result):
                            continue
                        try:
                            session.rejit_measurement = _measure_runner_phase(
                                session.runner,
                                session.state.target_prog_ids,
                                workload_seconds=session.workload_seconds,
                                samples=samples,
                            )
                        except Exception as exc:
                            session.error = str(exc)
                            if session.kinsn_metadata is not None:
                                session.kinsn_metadata["status"] = "error"
                                session.kinsn_metadata["error"] = session.error
                        daemon_error = _daemon_exit_error(daemon_session)
                        if daemon_error is not None:
                            fatal_error = daemon_error
                            break
        finally:
            for session in sessions:
                if not session.stopped:
                    try:
                        session.runner.stop()
                    except Exception as exc:
                        session.stop_error = str(exc)
                    finally:
                        session.stopped = True
                if session.kinsn_metadata is not None and not session.kinsn_recorded:
                    if str(session.kinsn_metadata.get("status") or "").strip() == "":
                        session.kinsn_metadata["status"] = "error" if fatal_error or session.error else "completed"
                    if session.error and str(session.kinsn_metadata.get("error") or "").strip() == "":
                        session.kinsn_metadata["error"] = session.error
                    if fatal_error and str(session.kinsn_metadata.get("error") or "").strip() == "":
                        session.kinsn_metadata["error"] = fatal_error
                    _append_pending_kinsn_metadata(session.kinsn_metadata)
                    session.kinsn_recorded = True

        for session in sessions:
            if session.app.name in completed_apps:
                continue
            error_message = session.error
            if fatal_error:
                error_message = fatal_error if not error_message else f"{error_message}; {fatal_error}"
            if session.stop_error:
                error_message = session.stop_error if not error_message else f"{error_message}; stop failed: {session.stop_error}"
            if error_message:
                result = _build_app_error_result(
                    session.app,
                    workload_seconds=session.workload_seconds,
                    error=error_message,
                    measurement_mode=session.measurement_mode,
                    runner=session.runner,
                    state=session.state,
                    baseline_measurement=session.baseline_measurement,
                    apply_result=session.apply_result,
                    rejit_measurement=session.rejit_measurement,
                )
            else:
                try:
                    result = _finalize_app_result(
                        session.app,
                        runner=session.runner,
                        state=session.state,
                        workload_seconds=session.workload_seconds,
                        measurement_mode=session.measurement_mode,
                        baseline_measurement=session.baseline_measurement or {},
                        apply_result=session.apply_result,
                        rejit_measurement=session.rejit_measurement,
                    )
                    if session.stop_error:
                        result["status"] = "error"
                        result["error"] = session.stop_error
                except Exception as exc:
                    result = _build_app_error_result(
                        session.app,
                        workload_seconds=session.workload_seconds,
                        error=str(exc),
                        measurement_mode=session.measurement_mode,
                        runner=session.runner,
                        state=session.state,
                        baseline_measurement=session.baseline_measurement,
                        apply_result=session.apply_result,
                        rejit_measurement=session.rejit_measurement,
                    )
            results_by_name[session.app.name] = result
            completed_apps.add(session.app.name)
            _print_progress(
                "app_done",
                app=session.app.name,
                status=result.get("status"),
                error=result.get("error"),
                program_count=len(result.get("program_measurements") or {}),
            )

        daemon_socket = str(prepared_daemon_session.session.socket_path)
        kinsn_metadata = dict(prepared_daemon_session.metadata)

    results = [
        results_by_name.get(app.name)
        or _build_app_error_result(
            app,
            workload_seconds=_app_workload_seconds(args, suite.defaults, app),
            error=fatal_error or "corpus suite did not produce a result",
        )
        for app in suite.apps
    ]
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


def build_run_metadata(
    args: argparse.Namespace,
    payload: dict[str, object],
    *,
    resolved_samples: int,
    resolved_workload_seconds: float,
) -> dict[str, object]:
    requested_rejit_passes = benchmark_rejit_enabled_passes()
    selected_rejit_passes = collect_effective_enabled_passes(payload)
    if not selected_rejit_passes:
        selected_rejit_passes = list(requested_rejit_passes)
    metadata = {
        "generated_at": datetime.now(timezone.utc).isoformat(),
        "suite": "corpus",
        "manifest": str(Path(args.suite).resolve()),
        "filters": list(args.filters or []),
        "samples": int(resolved_samples),
        "workload_seconds": float(resolved_workload_seconds),
        "kinsn_enabled": not bool(args.no_kinsn),
        "selected_rejit_passes": selected_rejit_passes,
        "optimization_summary": payload.get("summary") if isinstance(payload, Mapping) else {},
    }
    if selected_rejit_passes != requested_rejit_passes:
        metadata["requested_rejit_passes"] = list(requested_rejit_passes)
    metadata.update(current_process_identity())
    return metadata


def main(argv: list[str] | None = None) -> int:
    args = parse_args(argv)
    saved_env = os.environ.copy()
    if args.rejit_passes is not None:
        os.environ["BPFREJIT_BENCH_PASSES"] = str(args.rejit_passes).strip()
    output_json = Path(args.output_json).resolve()
    output_md = Path(args.output_md).resolve()
    metadata_suite_path = Path(args.suite).resolve()
    metadata_suite, _metadata_suite_summary = load_app_suite_from_yaml(
        metadata_suite_path,
        filters=list(args.filters or []),
    )
    resolved_workload_seconds = _workload_seconds(args, metadata_suite.defaults)
    resolved_samples = _sample_count(args, metadata_suite.defaults)
    run_type = derive_run_type(output_json, "vm_corpus")
    started_at = datetime.now(timezone.utc).isoformat()
    progress_payload: dict[str, object] = {
        "suite": "corpus",
        "status": "running",
        "filters": list(args.filters or []),
        "samples": int(resolved_samples),
        "workload_seconds": float(resolved_workload_seconds),
        "kinsn_enabled": not bool(args.no_kinsn),
    }
    metadata_payload: dict[str, object] = progress_payload

    def build_artifact_metadata(
        status: str,
        session_started_at: str,
        updated_at: str,
        error_message: str | None,
    ) -> dict[str, object]:
        metadata = build_run_metadata(
            args,
            metadata_payload,
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
    artifact_result_json = session.run_dir / "result.json"
    artifact_result_md = session.run_dir / "result.md"
    session.write(status="running", progress_payload=progress_payload)

    try:
        payload = run_suite(args)
        markdown = build_markdown(payload) + "\n"
        metadata_payload = payload
        ensure_parent(artifact_result_json)
        ensure_parent(artifact_result_md)
        write_json(artifact_result_json, payload)
        write_text(artifact_result_md, markdown)
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
        metadata_payload = {
            "status": "error",
            "error_message": str(exc),
        }
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
    finally:
        _restore_environment(saved_env)


if __name__ == "__main__":
    raise SystemExit(main())
