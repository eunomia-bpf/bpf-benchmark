#!/usr/bin/env python3
from __future__ import annotations

import argparse
import json
import sys
import time
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
from runner.libs.app_runners.scx import ScxRunner
from runner.libs.app_suite_schema import AppSpec, AppWorkload, load_app_suite_from_yaml
from runner.libs.bpf_stats import enable_bpf_stats, sample_bpf_stats
from runner.libs.case_common import (
    CaseLifecycleState,
    prepare_daemon_session,
    rejit_program_result,
    run_lifecycle_sessions,
    wait_for_suite_quiescence,
)
from runner.libs.app_runners.process_support import programs_after
from runner.libs.rejit import (
    DaemonSession,
    benchmark_run_provenance,
    scan_site_totals_for_passes,
)
from runner.libs.run_artifacts import (
    ArtifactSession,
    current_process_identity,
    derive_run_type,
)
from runner.libs.statistics import geometric_mean


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
ZERO_SITES_FOUND_REASON = "zero_sites_found"
ALL_SITES_ROLLED_BACK_REASON = "all_sites_rolled_back"
APPLIED_BUT_IDENTICAL_REASON = "applied_but_identical"
NO_PASSES_REQUESTED_REASON = "no_passes_requested"
NO_PROGRAMS_CHANGED_IN_LOADER_REASON = "no_programs_changed_in_loader"


def parse_args(argv: list[str] | None = None) -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="Run the app-native corpus suite driver.")
    parser.add_argument("--suite", default=str(DEFAULT_MACRO_APPS_YAML))
    parser.add_argument("--daemon", default=str(DEFAULT_DAEMON))
    parser.add_argument("--samples", type=int, default=0)
    parser.add_argument("--workload-seconds", type=float, default=0.0)
    parser.add_argument("--output-json", default=str(DEFAULT_OUTPUT_JSON))
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


def _infer_prog_type_name(program: Any) -> str:
    section_name = str(getattr(program, "section_name", "") or "").strip().lower()
    section_root = section_name.split("/", 1)[0]
    if section_root in SECTION_TYPE_PREFIXES:
        return SECTION_TYPE_PREFIXES[section_root]
    for prefix, inferred_type in SECTION_TYPE_PREFIXES.items():
        if section_name.startswith(prefix):
            return inferred_type
    return "unspec"


def _has_phase_measurement(records: Mapping[str, Mapping[str, object]]) -> bool:
    for record in records.values():
        run_cnt = record.get("run_cnt")
        if isinstance(run_cnt, (int, float)) and float(run_cnt) > 0.0:
            return True
        run_time_ns = record.get("run_time_ns")
        if isinstance(run_time_ns, (int, float)) and float(run_time_ns) > 0.0:
            return True
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
    if explicit > 0: return explicit
    default_value = float(suite_defaults.get("duration_s", 10.0) or 10.0)
    if default_value <= 0: raise RuntimeError(f"invalid app suite default duration_s: {default_value}")
    return default_value


def _app_workload_seconds(
    args: argparse.Namespace,
    suite_defaults: Mapping[str, object],
    app: AppSpec,
) -> float:
    explicit = float(args.workload_seconds or 0.0)
    if explicit > 0: return explicit
    if app.duration_s is not None: return float(app.duration_s)
    return _workload_seconds(args, suite_defaults)


def _sample_count(args: argparse.Namespace, suite_defaults: Mapping[str, object]) -> int:
    explicit = int(args.samples or 0)
    if explicit > 0: return explicit
    return max(1, int(suite_defaults.get("samples", 1) or 1))


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
    last_workload: dict[str, object] | None = None
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
        workload = runner.run_workload(workload_seconds).to_dict()
        last_workload = dict(workload)
        workloads.append(dict(workload))
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
        "workload": last_workload,
        "workloads": workloads,
        "initial_stats": initial_stats,
        "final_stats": final_stats,
        "live_prog_id_map": {
            str(logical_prog_id): int(sampled_prog_id)
            for logical_prog_id, sampled_prog_id in live_prog_id_map.items()
            if int(logical_prog_id) > 0 and int(sampled_prog_id) > 0
        },
        "live_programs": [dict(program) for program in live_programs],
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


def _program_label(app_name: str, program_name: str, prog_id: int) -> str:
    return f"{app_name}:{program_name or f'prog_{prog_id}'}#{prog_id}"


def _scx_post_rejit_prog_id_map(lifecycle: CaseLifecycleState) -> dict[int, int]:
    runner = lifecycle.runtime
    if not isinstance(runner, ScxRunner):
        return {}
    previous_programs = [
        dict(program)
        for program in (lifecycle.artifacts.get("programs") or [])
        if int(program.get("id", 0) or 0) > 0 and str(program.get("name") or "").strip()
    ]
    if not previous_programs:
        return {}
    previous_name_by_id = {
        int(program["id"]): str(program["name"]).strip()
        for program in previous_programs
    }
    refreshed_programs = runner.refresh_live_programs()
    lifecycle.artifacts["post_rejit_programs"] = [dict(program) for program in refreshed_programs]
    refreshed_id_by_name = {
        str(program.get("name") or "").strip(): int(program.get("id", 0) or 0)
        for program in refreshed_programs
        if int(program.get("id", 0) or 0) > 0 and str(program.get("name") or "").strip()
    }
    remapped = {
        int(logical_prog_id): int(refreshed_id_by_name[program_name])
        for logical_prog_id, program_name in previous_name_by_id.items()
        if int(logical_prog_id) in {int(prog_id) for prog_id in lifecycle.prog_ids if int(prog_id) > 0}
        and int(refreshed_id_by_name.get(program_name, 0) or 0) > 0
    }
    if remapped:
        lifecycle.artifacts["post_rejit_program_id_map"] = {
            str(logical_prog_id): int(sampled_prog_id)
            for logical_prog_id, sampled_prog_id in remapped.items()
        }
    return remapped


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


def _phase_exec_ns(record: Mapping[str, object] | None) -> float | None:
    if not isinstance(record, Mapping):
        return None
    value = record.get("exec_ns")
    if not isinstance(value, (int, float)):
        return None
    return float(value)


def _ordered_enabled_passes(raw: object) -> list[str]:
    if not isinstance(raw, Sequence) or isinstance(raw, (str, bytes, bytearray)):
        return []
    ordered: list[str] = []
    seen: set[str] = set()
    for value in raw:
        pass_name = str(value).strip()
        if not pass_name or pass_name in seen:
            continue
        seen.add(pass_name)
        ordered.append(pass_name)
    return ordered


def _non_negative_int(value: object) -> int | None:
    if isinstance(value, bool) or not isinstance(value, int):
        return None
    return value if value >= 0 else None


def _apply_record_total_sites_applied(apply_record: Mapping[str, object] | None) -> int:
    if not isinstance(apply_record, Mapping):
        return 0
    summary = apply_record.get("summary")
    if isinstance(summary, Mapping):
        if (total_sites_applied := _non_negative_int(summary.get("total_sites_applied"))) is not None:
            return total_sites_applied
    raw_passes = apply_record.get("passes")
    if isinstance(raw_passes, Sequence) and not isinstance(raw_passes, (str, bytes, bytearray)):
        total_sites_applied = 0
        for item in raw_passes:
            if not isinstance(item, Mapping):
                continue
            total_sites_applied += int(item.get("sites_applied", 0) or 0)
        return total_sites_applied
    return 0


def _apply_record_requested_passes(apply_record: Mapping[str, object] | None) -> list[str]:
    if not isinstance(apply_record, Mapping):
        return []
    requested_passes = _ordered_enabled_passes(apply_record.get("enabled_passes"))
    if requested_passes:
        return requested_passes
    raw_passes = apply_record.get("passes")
    if not isinstance(raw_passes, Sequence) or isinstance(raw_passes, (str, bytes, bytearray)):
        return []
    return _ordered_enabled_passes(
        [
            item.get("pass_name")
            for item in raw_passes
            if isinstance(item, Mapping)
        ]
    )


def _apply_record_requested_site_totals(apply_record: Mapping[str, object] | None) -> tuple[int, int]:
    requested_passes = _apply_record_requested_passes(apply_record)
    if not requested_passes:
        return 0, _apply_record_total_sites_applied(apply_record)
    scan = apply_record.get("scan") if isinstance(apply_record, Mapping) else None
    scan_counts = scan.get("counts") if isinstance(scan, Mapping) else None
    sites_found_by_pass = scan_site_totals_for_passes(scan_counts, requested_passes)
    return sum(sites_found_by_pass.values()), _apply_record_total_sites_applied(apply_record)


def _apply_record_no_change_reason(apply_record: Mapping[str, object] | None) -> str:
    if not isinstance(apply_record, Mapping):
        return NO_PROGRAMS_CHANGED_IN_LOADER_REASON
    requested_passes = _apply_record_requested_passes(apply_record)
    if not requested_passes:
        return NO_PASSES_REQUESTED_REASON
    total_sites_found, total_sites_applied = _apply_record_requested_site_totals(apply_record)
    if total_sites_found == 0:
        return ZERO_SITES_FOUND_REASON
    if total_sites_applied == 0:
        return ALL_SITES_ROLLED_BACK_REASON
    if not bool(apply_record.get("changed")):
        return APPLIED_BUT_IDENTICAL_REASON
    return NO_PROGRAMS_CHANGED_IN_LOADER_REASON


def _apply_record_program_changed(apply_record: Mapping[str, object] | None) -> bool:
    if not isinstance(apply_record, Mapping):
        return False
    return bool(apply_record.get("changed"))


def _comparison_exclusion_reason(
    baseline_exec_ns: float | None,
    rejit_exec_ns: float | None,
    *,
    had_post_rejit: bool,
    apply_record: Mapping[str, object],
) -> str:
    apply_error = str(apply_record.get("error") or "").strip()
    if baseline_exec_ns is None:
        return "missing_baseline_exec_ns"
    if baseline_exec_ns <= 0.0:
        return "non_positive_baseline_exec_ns"
    if not _apply_record_program_changed(apply_record):
        if apply_error:
            return f"apply_error: {apply_error}"
        return _apply_record_no_change_reason(apply_record)
    if not had_post_rejit:
        if apply_error:
            return f"apply_error: {apply_error}"
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
        changed = _apply_record_program_changed(apply_record)
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


def _result_comparison_rows(result: Mapping[str, object]) -> list[dict[str, object]]:
    return _result_program_rows(result)


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
) -> dict[str, object]:
    status_counts = Counter(str(result.get("status") or "error") for result in results)
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
        "app_count": len(results),
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
    state: CaseLifecycleState | None = None,
    baseline_measurement: Mapping[str, object] | None = None,
    apply_result: Mapping[str, object] | None = None,
    rejit_measurement: Mapping[str, object] | None = None,
) -> dict[str, object]:
    prog_ids = [] if state is None else [int(value) for value in state.prog_ids if int(value) > 0]
    live_programs = [] if state is None else [dict(program) for program in (state.artifacts.get("programs") or [])]
    baseline_programs = _measurement_program_stats(baseline_measurement, prog_ids)
    had_post_rejit = isinstance(rejit_measurement, Mapping)
    rejit_programs = _measurement_program_stats(rejit_measurement, prog_ids)
    normalized_apply_result = dict(apply_result or {})
    program_measurements = {}
    raw_apply_per_program = normalized_apply_result.get("per_program")
    if live_programs and isinstance(raw_apply_per_program, Mapping):
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
        "selected_workload": app.workload_for("corpus"),
        "status": "error",
        "error": str(error),
        "program_measurements": program_measurements,
        "rejit_applied": bool(normalized_apply_result.get("applied")),
    }


def _finalize_app_result(
    app: AppSpec,
    *,
    state: CaseLifecycleState,
    baseline_measurement: Mapping[str, object],
    apply_result: Mapping[str, object] | None,
    rejit_measurement: Mapping[str, object] | None,
) -> dict[str, object]:
    prog_ids = [int(value) for value in state.prog_ids if int(value) > 0]
    live_programs = [dict(program) for program in (state.artifacts.get("programs") or [])]
    if not live_programs:
        raise RuntimeError(f"{app.name}: runner lifecycle did not expose any live programs")

    baseline_initial_snapshot = _normalized_stats_snapshot(baseline_measurement.get("initial_stats"))
    baseline_final_snapshot = _normalized_stats_snapshot(baseline_measurement.get("final_stats"))
    baseline_phase = _program_phase_stats(baseline_final_snapshot, baseline_initial_snapshot)
    programs_by_id = _program_stats_by_prog_id(baseline_phase, prog_ids)

    had_post_rejit = rejit_measurement is not None
    rejit_programs_by_id: dict[str, dict[str, object]] = {}
    if had_post_rejit:
        rejit_initial_snapshot = _normalized_stats_snapshot(rejit_measurement.get("initial_stats"))
        rejit_final_snapshot = _normalized_stats_snapshot(rejit_measurement.get("final_stats"))
        rejit_phase = _program_phase_stats(rejit_final_snapshot, rejit_initial_snapshot)
        rejit_programs_by_id = _program_stats_by_prog_id(rejit_phase, prog_ids)

    normalized_apply_result = dict(apply_result or {})
    apply_error = str(normalized_apply_result.get("error") or "").strip()
    if not _has_phase_measurement(programs_by_id):
        raise RuntimeError(
            f"{app.name}: workload {app.workload_for('corpus')!r} did not execute any target programs during baseline"
        )
    if had_post_rejit and not apply_error and not _has_phase_measurement(rejit_programs_by_id):
        raise RuntimeError(
            f"{app.name}: workload {app.workload_for('corpus')!r} did not execute any target programs after rejit"
        )
    program_measurements = _build_program_measurements(
        app.name,
        live_programs,
        programs_by_id,
        rejit_programs_by_id,
        normalized_apply_result,
        had_post_rejit=had_post_rejit,
    )
    has_comparable_measurement = _has_comparable_measurement(program_measurements)
    if not apply_error and any(bool(row.get("changed")) for row in program_measurements.values()) and not has_comparable_measurement:
        raise RuntimeError(
            f"{app.name}: workload {app.workload_for('corpus')!r} produced no comparable target program measurements"
        )
    # A single apply failure should not fail the whole app if other programs
    # in the same loader instance still produced comparable measurements.
    fatal_apply_error = bool(apply_error) and not has_comparable_measurement
    status = "error" if fatal_apply_error else "ok"
    error = apply_error if fatal_apply_error else ""

    return {
        "app": app.name,
        "runner": app.runner,
        "selected_workload": app.workload_for("corpus"),
        "status": status,
        "error": error,
        "program_measurements": program_measurements,
        "rejit_applied": bool(normalized_apply_result.get("applied")),
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

    workload_seconds = _workload_seconds(args, suite.defaults)
    samples = _sample_count(args, suite.defaults)
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
                    app_workload_seconds = _app_workload_seconds(args, suite.defaults, app)
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
                        if runner is not None:
                            try:
                                runner.stop()
                            except Exception as stop_exc:
                                stop_error = str(stop_exc)
                        error_message = str(exc)
                        if stop_error:
                            error_message = f"{error_message}; stop failed: {stop_error}"
                        result = _build_app_error_result(app, error=error_message)
                        results_by_name[app.name] = result
                        completed_apps.add(app.name)
                        _print_progress("app_done", app=app.name, status=result.get("status"),
                                        error=result.get("error"), program_count=0)
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
                    state=session.state,
                    baseline_measurement=baseline_measurement,
                    apply_result=apply_result,
                    rejit_measurement=rejit_measurement,
                )
            else:
                try:
                    result = _finalize_app_result(
                        session.app,
                        state=session.state,
                        baseline_measurement=baseline_measurement or {},
                        apply_result=apply_result,
                        rejit_measurement=rejit_measurement,
                    )
                except Exception as exc:
                    result = _build_app_error_result(
                        session.app,
                        error=str(exc),
                        state=session.state,
                        baseline_measurement=baseline_measurement,
                        apply_result=apply_result,
                        rejit_measurement=rejit_measurement,
                    )
            results_by_name[session.app.name] = result; completed_apps.add(session.app.name)
            _print_progress("app_done", app=session.app.name, status=result.get("status"),
                            error=result.get("error"), program_count=len(result.get("program_measurements") or {}))

        kinsn_metadata = dict(prepared_daemon_session.metadata)

    results = [
        results_by_name.get(app.name)
        or _build_app_error_result(
            app,
            error=fatal_error or "corpus suite did not produce a result",
        )
        for app in suite.apps
    ]
    summary = _build_summary(results)
    payload = {
        "generated_at": datetime.now(timezone.utc).isoformat(),
        "manifest": str(suite_path),
        "suite_name": suite.suite_name,
        "daemon": str(daemon_binary),
        "samples": samples,
        "workload_seconds": workload_seconds,
        "results": results,
        "kinsn_modules": kinsn_metadata,
        "summary": summary,
        "status": "ok" if int((summary.get("statuses") or {}).get("error", 0)) == 0 else "error",
    }
    if fatal_error:
        payload["fatal_error"] = fatal_error
    return payload


def build_run_metadata(
    args: argparse.Namespace,
    payload: dict[str, object],
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
        "optimization_summary": payload.get("summary") if isinstance(payload, Mapping) else {},
    }
    metadata.update(benchmark_run_provenance())
    metadata.update(current_process_identity())
    return metadata


def main(argv: list[str] | None = None) -> int:
    args = parse_args(argv)
    output_json = Path(args.output_json).resolve()
    suite = load_app_suite_from_yaml(Path(args.suite).resolve())
    resolved_workload_seconds = _workload_seconds(args, suite.defaults)
    resolved_samples = _sample_count(args, suite.defaults)
    run_type = derive_run_type(output_json, "vm_corpus")
    started_at = datetime.now(timezone.utc).isoformat()
    progress_payload: dict[str, object] = {
        "suite": "corpus",
        "status": "running",
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
        payload = run_suite(args, suite)
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

if __name__ == "__main__":
    raise SystemExit(main())
