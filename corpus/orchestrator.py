#!/usr/bin/env python3
from __future__ import annotations

import argparse
from dataclasses import is_dataclass, replace
import json
import sys
from collections import Counter, defaultdict
from datetime import datetime, timezone
from pathlib import Path
from typing import Any, Mapping

import yaml

REPO_ROOT = Path(__file__).resolve().parents[1]
if str(REPO_ROOT) not in sys.path:
    sys.path.insert(0, str(REPO_ROOT))

from runner.libs import ROOT_DIR, ensure_parent, write_json
from runner.libs.app_runners import get_app_runner
from runner.libs.app_runners.systemd import systemd_binary_for_object
from runner.libs.bpf_stats import enable_bpf_stats, read_program_stats
from runner.libs.corpus import load_targets_from_yaml
from runner.libs.daemon_session import DaemonSession
from runner.libs.rejit import benchmark_rejit_enabled_passes


DEFAULT_MACRO_CORPUS_YAML = ROOT_DIR / "corpus" / "config" / "macro_corpus.yaml"
DEFAULT_DAEMON = ROOT_DIR / "daemon" / "target" / "release" / "bpfrejit-daemon"
DEFAULT_OUTPUT_JSON = ROOT_DIR / "corpus" / "results" / "vm_corpus_new.json"
DEFAULT_BTF_PATH = Path("/sys/kernel/btf/vmlinux")
SECTION_TYPE_PREFIXES = {
    "xdp": "xdp",
    "tc": "sched_cls",
    "classifier": "sched_cls",
    "cgroup_skb": "cgroup_skb",
    "socket": "socket_filter",
}
SHARED_LOADER_REPOS = {
    "coroot-node-agent",
    "datadog-agent",
    "katran",
    "kubearmor",
    "tetragon",
    "tracee",
    "tubular",
}


def parse_args(argv: list[str] | None = None) -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="Run the new Python-only corpus orchestrator.")
    parser.add_argument("--suite", default=str(DEFAULT_MACRO_CORPUS_YAML))
    parser.add_argument("--daemon", default=str(DEFAULT_DAEMON))
    parser.add_argument("--bpftool", default="", help="Explicit bpftool binary.")
    parser.add_argument("--btf-custom-path", default=str(DEFAULT_BTF_PATH))
    parser.add_argument("--repeat", type=int, default=0)
    parser.add_argument("--workload-seconds", type=float, default=10.0)
    parser.add_argument("--output-json", default=str(DEFAULT_OUTPUT_JSON))
    parser.add_argument("--filter", action="append", dest="filters")
    parser.add_argument("--max-programs", type=int)
    args = parser.parse_args(argv)
    if args.repeat is not None and int(args.repeat) < 0:
        raise SystemExit("--repeat must be >= 0")
    if float(args.workload_seconds) <= 0:
        raise SystemExit("--workload-seconds must be > 0")
    return args


def _manifest_build_report(manifest_path: Path) -> dict[str, Any]:
    payload = yaml.safe_load(manifest_path.read_text(encoding="utf-8"))
    if not isinstance(payload, Mapping):
        raise RuntimeError(f"manifest is not a mapping: {manifest_path}")
    available_objects: set[str] = set()
    for entry in payload.get("objects", []):
        if not isinstance(entry, Mapping):
            continue
        source = entry.get("source")
        if not source:
            continue
        candidate = Path(source)
        resolved = candidate if candidate.is_absolute() else (ROOT_DIR / candidate)
        if resolved.exists():
            available_objects.add(str(resolved.resolve()))
    return {
        "path": manifest_path,
        "summary": {"available_total": len(available_objects)},
        "available_objects": available_objects,
        "supplemented_existing": 0,
    }


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


def _program_stats_by_name(
    phase_stats: Mapping[int, Mapping[str, object]],
    actual_programs: Mapping[str, int],
) -> dict[str, dict[str, object]]:
    records: dict[str, dict[str, object]] = {}
    for name, prog_id in actual_programs.items():
        stats = phase_stats.get(int(prog_id))
        if stats is None:
            continue
        records[name] = dict(stats)
    return records


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


def _split_objects_by_program_measurement(objects: list[Any]) -> list[Any]:
    split_objects: list[Any] = []
    for obj in objects:
        programs_by_measurement: dict[str, list[Any]] = {}
        for program in obj.programs:
            programs_by_measurement.setdefault(str(program.measurement), []).append(program)
        for measurement, programs in programs_by_measurement.items():
            if is_dataclass(obj):
                split_objects.append(replace(obj, measurement=measurement, programs=tuple(programs)))
                continue
            payload = dict(vars(obj))
            payload["measurement"] = measurement
            payload["programs"] = tuple(programs)
            split_objects.append(type(obj)(**payload))
    return split_objects


def _loader_instance_identity(obj: Any) -> tuple[tuple[object, ...], str]:
    repo = str(obj.repo or "").strip().lower()
    loader_binary = str(getattr(obj, "loader_binary", "") or "").strip()
    loader_args = tuple(str(arg) for arg in (getattr(obj, "loader_args", ()) or ()))
    if repo in SHARED_LOADER_REPOS:
        key = (repo, loader_binary, loader_args)
        return key, repo
    if repo == "bcc":
        label = Path(obj.object_abs_path).name.removesuffix(".bpf.o")
        return (repo, label), f"{repo}:{label}"
    if repo == "systemd":
        binary = str(systemd_binary_for_object(obj.object_abs_path))
        label = Path(binary).name
        return (repo, binary), f"{repo}:{label}"
    label = Path(obj.object_abs_path).name
    key = (
        repo,
        str(obj.object_abs_path),
        loader_binary,
        loader_args,
    )
    return key, f"{repo}:{label}"


def _group_app_native_loader_instances(indexed_objects: list[tuple[int, Any]]) -> list[tuple[str, list[tuple[int, Any]]]]:
    groups: dict[tuple[object, ...], tuple[str, list[tuple[int, Any]]]] = {}
    for indexed_object in indexed_objects:
        index, obj = indexed_object
        if str(obj.measurement) != "app_native":
            continue
        key, label = _loader_instance_identity(obj)
        if key not in groups:
            groups[key] = (label, [])
        groups[key][1].append((index, obj))
    return list(groups.values())


def _unsupported_measurement_result(obj: Any) -> dict[str, object]:
    return {
        "object": obj.object_path,
        "repo": obj.repo,
        "measurement": obj.measurement,
        "status": "error",
        "error": (
            f"unsupported corpus measurement {obj.measurement!r}: loader instances must come from native app runners; "
            "migrate this object to an app runner or remove it from the corpus suite"
        ),
    }


def _validate_phase_measurement(
    phase_name: str,
    records: Mapping[str, Mapping[str, object]],
    expected_program_names: list[str],
) -> None:
    errors: list[str] = []
    for program_name in expected_program_names:
        record = records.get(program_name)
        if record is None:
            errors.append(f"{phase_name}: missing stats for program {program_name!r}")
            continue
        run_cnt = int(record.get("run_cnt", 0) or 0)
        exec_ns = record.get("exec_ns")
        if run_cnt <= 0:
            errors.append(f"{phase_name}: program {program_name!r} observed zero runs")
        if not isinstance(exec_ns, (int, float)):
            errors.append(f"{phase_name}: program {program_name!r} is missing exec_ns")
    if errors:
        raise RuntimeError("; ".join(errors))


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


def _runner_kwargs_for_repo(
    repo: str,
    primary_obj: Any,
    expected_program_names: list[str],
) -> dict[str, object]:
    loader_binary = str(getattr(primary_obj, "loader_binary", "") or "").strip()
    loader_args = tuple(str(arg) for arg in (getattr(primary_obj, "loader_args", ()) or ()) if str(arg).strip())
    setup_script = str(getattr(primary_obj, "loader_setup_script", "") or "").strip()
    timeout_seconds = getattr(primary_obj, "loader_timeout_seconds", None)
    normalized = str(repo or "").strip().lower()

    if normalized == "bcc":
        kwargs: dict[str, object] = {
            "object_path": primary_obj.object_abs_path,
            "expected_program_names": expected_program_names,
        }
        if loader_binary:
            kwargs["tool_binary"] = loader_binary
        if loader_args:
            kwargs["tool_args"] = loader_args
        if timeout_seconds is not None:
            kwargs["attach_timeout_s"] = int(timeout_seconds)
        if setup_script:
            kwargs["setup_script"] = setup_script
        return kwargs

    if normalized == "tracee":
        kwargs = {
            "object_path": primary_obj.object_abs_path,
            "expected_program_names": expected_program_names,
        }
        if loader_binary:
            kwargs["tracee_binary"] = loader_binary
        if loader_args:
            kwargs["extra_args"] = loader_args
        if timeout_seconds is not None:
            kwargs["load_timeout_s"] = int(timeout_seconds)
        if setup_script:
            kwargs["setup_script"] = setup_script
        return kwargs

    if normalized == "tetragon":
        kwargs = {
            "object_path": primary_obj.object_abs_path,
            "expected_program_names": expected_program_names,
        }
        if loader_binary:
            kwargs["tetragon_binary"] = loader_binary
        if loader_args:
            kwargs["tetragon_extra_args"] = loader_args
        if timeout_seconds is not None:
            kwargs["load_timeout_s"] = int(timeout_seconds)
        if setup_script:
            kwargs["setup_script"] = setup_script
        return kwargs

    if normalized == "bpftrace":
        kwargs = {
            "object_path": primary_obj.object_abs_path,
            "expected_program_names": expected_program_names,
        }
        if str(primary_obj.object_abs_path).endswith(".bt"):
            kwargs["script_path"] = primary_obj.object_abs_path
            kwargs.pop("object_path", None)
        if timeout_seconds is not None:
            kwargs["attach_timeout_s"] = int(timeout_seconds)
        return kwargs

    if normalized == "scx":
        kwargs = {
            "object_path": primary_obj.object_abs_path,
        }
        if loader_binary:
            kwargs["scheduler_binary"] = loader_binary
        if loader_args:
            kwargs["scheduler_extra_args"] = loader_args
        if timeout_seconds is not None:
            kwargs["load_timeout_s"] = int(timeout_seconds)
        return kwargs

    if normalized == "katran":
        kwargs = {
            "object_path": primary_obj.object_abs_path,
        }
        if loader_binary:
            raise RuntimeError(f"katran app runner does not support loader_binary in corpus manifest: {loader_binary}")
        if loader_args:
            raise RuntimeError(f"katran app runner does not support loader_args in corpus manifest: {loader_args}")
        return kwargs

    kwargs = {
        "object_path": primary_obj.object_abs_path,
        "expected_program_names": expected_program_names,
    }
    if loader_binary:
        kwargs["loader_binary"] = loader_binary
    if loader_args:
        kwargs["loader_args"] = loader_args
    if timeout_seconds is not None:
        kwargs["load_timeout_s"] = int(timeout_seconds)
    return kwargs


def _assign_live_program_ids(
    indexed_objects: list[tuple[int, Any]],
    live_programs: list[dict[str, object]],
) -> tuple[dict[int, dict[str, int]], list[dict[str, object]]]:
    live_ids_by_name: dict[str, list[int]] = defaultdict(list)
    live_programs_by_id: dict[int, dict[str, object]] = {}
    for live_program in live_programs:
        prog_name = str(live_program.get("name") or "").strip()
        prog_id = int(live_program.get("id", 0) or 0)
        if not prog_name or prog_id <= 0:
            continue
        live_ids_by_name[prog_name].append(prog_id)
        live_programs_by_id[prog_id] = dict(live_program)

    assignments: dict[int, dict[str, int]] = {}
    errors: list[str] = []
    for index, obj in indexed_objects:
        seen_program_names: set[str] = set()
        object_assignments: dict[str, int] = {}
        for program in obj.programs:
            program_name = str(program.program_name)
            if program_name in seen_program_names:
                errors.append(f"{obj.object_path}: duplicate manifest program name {program_name!r} inside one object")
                continue
            seen_program_names.add(program_name)
            available_ids = live_ids_by_name.get(program_name)
            if not available_ids:
                errors.append(f"{obj.object_path}: live app runner did not load expected program {program_name!r}")
                continue
            object_assignments[program_name] = int(available_ids.pop(0))
        assignments[index] = object_assignments

    if errors:
        raise RuntimeError("; ".join(errors))

    leftover_ids = [prog_id for prog_ids in live_ids_by_name.values() for prog_id in prog_ids]
    leftover_programs = [live_programs_by_id[prog_id] for prog_id in leftover_ids if prog_id in live_programs_by_id]
    return assignments, leftover_programs


def _runner_programs_by_id(programs: list[dict[str, object]]) -> dict[int, dict[str, object]]:
    return {
        int(program.get("id", 0) or 0): dict(program)
        for program in programs
        if int(program.get("id", 0) or 0) > 0
    }


def _subset_runner_programs(
    programs_by_id: Mapping[int, Mapping[str, object]],
    prog_ids: list[int],
) -> list[dict[str, object]]:
    return [dict(programs_by_id[prog_id]) for prog_id in prog_ids if prog_id in programs_by_id]


def _subset_apply_result(
    apply_result: Mapping[str, object],
    prog_ids: list[int],
) -> dict[str, object]:
    raw_per_program = apply_result.get("per_program")
    per_program = dict(raw_per_program) if isinstance(raw_per_program, Mapping) else {}
    selected: dict[str, dict[str, object]] = {}
    total_sites = 0
    applied_sites = 0
    all_applied = True
    errors: list[str] = []

    for prog_id in prog_ids:
        raw_entry = per_program.get(prog_id)
        if raw_entry is None:
            raw_entry = per_program.get(str(prog_id))
        if not isinstance(raw_entry, Mapping):
            all_applied = False
            errors.append(f"missing daemon apply result for prog_id {prog_id}")
            continue
        entry = dict(raw_entry)
        selected[str(prog_id)] = entry
        all_applied = all_applied and bool(entry.get("applied"))
        counts = entry.get("counts") if isinstance(entry.get("counts"), Mapping) else {}
        total_sites += int((counts or {}).get("total_sites", 0) or 0)
        applied_sites += int((counts or {}).get("applied_sites", 0) or 0)
        error = str(entry.get("error") or "").strip()
        if error:
            errors.append(f"prog {prog_id}: {error}")

    if not selected and isinstance(apply_result.get("error"), str) and str(apply_result.get("error")).strip():
        errors.append(str(apply_result.get("error")).strip())

    return {
        "applied": all_applied and bool(selected),
        "exit_code": int(apply_result.get("exit_code", 0) or 0),
        "counts": {
            "total_sites": total_sites,
            "applied_sites": applied_sites,
        },
        "per_program": selected,
        "error": "; ".join(errors),
    }


def _run_app_native_loader_instance(
    indexed_objects: list[tuple[int, Any]],
    *,
    loader_label: str,
    daemon_session: DaemonSession,
    workload_seconds: float,
) -> tuple[list[tuple[int, dict[str, object]]], dict[str, object]]:
    if not indexed_objects:
        raise RuntimeError("app-native loader instance is empty")

    repo = str(indexed_objects[0][1].repo)
    primary_obj = indexed_objects[0][1]
    expected_program_names = [str(program.program_name) for _, obj in indexed_objects for program in obj.programs]
    runner = get_app_runner(repo, **_runner_kwargs_for_repo(repo, primary_obj, expected_program_names))
    batch_results: list[tuple[int, dict[str, object]]] = []
    batch_summary: dict[str, object]
    prog_ids: list[int] = []
    live_programs: list[dict[str, object]] = []
    unassigned_live_programs: list[dict[str, object]] = []
    programs_by_id: dict[int, dict[str, object]] = {}
    batch_apply_result: dict[str, object] = {}
    baseline_phase: dict[int, dict[str, object]] = {}
    rejit_phase: dict[int, dict[str, object]] = {}
    baseline_workload = None
    rejit_workload = None

    try:
        prog_ids = [int(value) for value in runner.start() if int(value) > 0]
        if not prog_ids:
            raise RuntimeError(f"{loader_label}: app runner did not return any live prog_ids")
        live_programs = [dict(program) for program in getattr(runner, "programs", [])]
        assignments_by_index, unassigned_live_programs = _assign_live_program_ids(indexed_objects, live_programs)
        programs_by_id = _runner_programs_by_id(live_programs)

        with enable_bpf_stats():
            baseline_workload = runner.run_workload(workload_seconds).to_dict()
            baseline_snapshot = read_program_stats(prog_ids)
            batch_apply_result = daemon_session.apply_rejit(
                prog_ids,
                enabled_passes=benchmark_rejit_enabled_passes(),
            )
            rejit_snapshot: Mapping[int, Mapping[str, object]] = {}
            if bool(batch_apply_result.get("applied")):
                rejit_workload = runner.run_workload(workload_seconds).to_dict()
                rejit_snapshot = read_program_stats(prog_ids)

        baseline_phase = _program_phase_stats(baseline_snapshot)
        rejit_phase = _program_phase_stats(rejit_snapshot, baseline_snapshot) if rejit_snapshot else {}
        for index, _obj in indexed_objects:
            assigned_programs = assignments_by_index.get(index, {})
            baseline_by_name = _program_stats_by_name(baseline_phase, assigned_programs)
            _validate_phase_measurement("baseline", baseline_by_name, list(assigned_programs))
            if bool(batch_apply_result.get("applied")):
                rejit_by_name = _program_stats_by_name(rejit_phase, assigned_programs)
                _validate_phase_measurement("rejit", rejit_by_name, list(assigned_programs))
    finally:
        runner.stop()

    runner_info = {
        "type": type(runner).__name__,
        "tool_name": getattr(runner, "tool_name", ""),
        "tool_binary": str(getattr(runner, "tool_binary", "") or ""),
        "loader_binary": str(getattr(runner, "loader_binary", "") or ""),
        "command_used": [str(item) for item in (getattr(runner, "command_used", []) or [])],
    }
    process_output = dict(getattr(runner, "process_output", {}))

    batch_summary = {
        "repo": repo,
        "loader_instance": loader_label,
        "measurement": "app_native",
        "status": "ok" if bool(batch_apply_result.get("applied")) else "error",
        "error": str(batch_apply_result.get("error") or "").strip(),
        "objects": [obj.object_path for _, obj in indexed_objects],
        "prog_ids": prog_ids,
        "runner": runner_info,
        "programs": live_programs,
        "unassigned_live_programs": unassigned_live_programs,
        "baseline": {
            "programs": _program_stats_by_prog_id(baseline_phase, prog_ids),
            "exec_ns_mean": _mean_exec_ns(_program_stats_by_prog_id(baseline_phase, prog_ids)),
        },
        "baseline_workload": baseline_workload,
        "rejit_apply": dict(batch_apply_result),
        "rejit": {
            "programs": _program_stats_by_prog_id(rejit_phase, prog_ids),
            "exec_ns_mean": _mean_exec_ns(_program_stats_by_prog_id(rejit_phase, prog_ids)),
        } if rejit_phase else None,
        "rejit_workload": rejit_workload,
        "process": process_output,
    }

    for index, obj in indexed_objects:
        assigned_programs = assignments_by_index.get(index, {})
        object_prog_ids = list(assigned_programs.values())
        object_apply = _subset_apply_result(batch_apply_result, object_prog_ids)
        baseline_by_name = _program_stats_by_name(baseline_phase, assigned_programs)
        rejit_by_name = _program_stats_by_name(rejit_phase, assigned_programs)
        object_error = str(object_apply.get("error") or "").strip()
        if not bool(batch_apply_result.get("applied")) and not object_error:
            object_error = str(batch_apply_result.get("error") or "").strip()

        batch_results.append(
            (
                index,
                {
                    "object": obj.object_path,
                    "repo": obj.repo,
                    "loader_instance": loader_label,
                    "measurement": "app_native",
                    "status": "ok" if bool(batch_apply_result.get("applied")) else "error",
                    "error": object_error,
                    "runner": runner_info,
                    "prog_ids": object_prog_ids,
                    "programs": _subset_runner_programs(programs_by_id, object_prog_ids),
                    "baseline": {
                        "programs": baseline_by_name,
                        "exec_ns_mean": _mean_exec_ns(baseline_by_name),
                    },
                    "rejit_apply": object_apply,
                    "rejit": {
                        "programs": rejit_by_name,
                        "exec_ns_mean": _mean_exec_ns(rejit_by_name),
                    } if rejit_by_name else None,
                    "process": process_output,
                },
            )
        )

    return batch_results, batch_summary


def _daemon_exit_error(daemon_session: DaemonSession) -> str | None:
    returncode = daemon_session.proc.poll()
    if returncode is None:
        return None
    return f"daemon session exited early (rc={returncode})"


def run_suite(args: argparse.Namespace) -> dict[str, object]:
    manifest_path = Path(args.suite).resolve()
    build_report = _manifest_build_report(manifest_path)
    objects, manifest_summary = load_targets_from_yaml(
        manifest_path,
        build_report,
        filters=list(args.filters or []),
        max_programs=args.max_programs,
    )
    repeat = int(args.repeat or 0) or int(
        ((yaml.safe_load(manifest_path.read_text(encoding="utf-8")) or {}).get("defaults") or {}).get("repeat", 1)
    )
    daemon_binary = Path(args.daemon).resolve()
    execution_units = _split_objects_by_program_measurement(objects)

    if not daemon_binary.exists():
        raise RuntimeError(f"daemon binary not found: {daemon_binary}")

    indexed_objects = list(enumerate(execution_units))
    app_native_groups = _group_app_native_loader_instances(indexed_objects)
    indexed_results: dict[int, dict[str, object]] = {}
    loader_batches: list[dict[str, object]] = []
    fatal_error = ""

    unsupported_units = [(index, obj) for index, obj in indexed_objects if str(obj.measurement) != "app_native"]
    for index, obj in unsupported_units:
        indexed_results[index] = _unsupported_measurement_result(obj)

    app_native_units = [(index, obj) for index, obj in indexed_objects if str(obj.measurement) == "app_native"]
    if app_native_units:
        with DaemonSession.start(daemon_binary) as daemon_session:
            for loader_label, indexed_group in app_native_groups:
                try:
                    group_results, batch_summary = _run_app_native_loader_instance(
                        indexed_group,
                        loader_label=loader_label,
                        daemon_session=daemon_session,
                        workload_seconds=max(1.0, float(args.workload_seconds)),
                    )
                except Exception as exc:
                    batch_summary = {
                        "repo": indexed_group[0][1].repo,
                        "loader_instance": loader_label,
                        "measurement": "app_native",
                        "status": "error",
                        "error": str(exc),
                        "objects": [obj.object_path for _, obj in indexed_group],
                    }
                    group_results = [
                        (
                            index,
                            {
                                "object": obj.object_path,
                                "repo": obj.repo,
                                "loader_instance": loader_label,
                                "measurement": "app_native",
                                "status": "error",
                                "error": str(exc),
                            },
                        )
                        for index, obj in indexed_group
                    ]
                loader_batches.append(batch_summary)
                for index, result in group_results:
                    indexed_results[index] = result
                daemon_error = _daemon_exit_error(daemon_session)
                if daemon_error is not None:
                    fatal_error = daemon_error
                    break

            if fatal_error:
                for index, obj in indexed_objects:
                    if index in indexed_results:
                        continue
                    indexed_results[index] = {
                        "object": obj.object_path,
                        "repo": obj.repo,
                        "measurement": obj.measurement,
                        "status": "error",
                        "error": fatal_error,
                    }

            daemon_socket = str(daemon_session.socket_path)
    else:
        daemon_socket = None

    results = [indexed_results[index] for index, _obj in indexed_objects if index in indexed_results]
    status_counts = Counter(str(result.get("status") or "error") for result in results)
    measurement_counts = Counter(program.measurement for obj in execution_units for program in obj.programs)
    payload = {
        "generated_at": datetime.now(timezone.utc).isoformat(),
        "manifest": str(manifest_path),
        "daemon": str(daemon_binary),
        "daemon_socket": daemon_socket,
        "filters": list(args.filters or []),
        "repeat": max(1, repeat),
        "workload_seconds": max(1.0, float(args.workload_seconds)),
        "manifest_summary": manifest_summary,
        "app_native_batches": loader_batches,
        "results": results,
        "summary": {
            "selected_manifest_objects": len(objects),
            "selected_execution_units": len(execution_units),
            "selected_programs": sum(len(obj.programs) for obj in execution_units),
            "measurements": dict(sorted(measurement_counts.items())),
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
