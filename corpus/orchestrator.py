#!/usr/bin/env python3
from __future__ import annotations

import argparse
import json
import os
import subprocess
import sys
from collections import Counter
from datetime import datetime, timezone
from pathlib import Path
from typing import Any, Mapping

import yaml

REPO_ROOT = Path(__file__).resolve().parents[1]
if str(REPO_ROOT) not in sys.path:
    sys.path.insert(0, str(REPO_ROOT))

from runner.libs import ROOT_DIR, ensure_parent, resolve_bpftool_binary, run_command, run_json_command, write_json
from runner.libs.app_runners import get_app_runner
from runner.libs.bpf_stats import enable_bpf_stats, read_program_stats
from runner.libs.corpus import load_targets_from_yaml, materialize_dummy_packet
from runner.libs.rejit import (
    _start_daemon_server,
    _stop_daemon_server,
    apply_daemon_rejit,
    benchmark_rejit_enabled_passes,
)


DEFAULT_MACRO_CORPUS_YAML = ROOT_DIR / "corpus" / "config" / "macro_corpus.yaml"
DEFAULT_DAEMON = ROOT_DIR / "daemon" / "target" / "release" / "bpfrejit-daemon"
DEFAULT_RUNNER = ROOT_DIR / "runner" / "build" / "micro_exec"
DEFAULT_OUTPUT_JSON = ROOT_DIR / "corpus" / "results" / "vm_corpus_new.json"
DEFAULT_BTF_PATH = Path("/sys/kernel/btf/vmlinux")
NETWORK_TEST_RUN_TYPES = {"xdp", "sched_cls", "sched_act", "cgroup_skb", "socket_filter"}
SECTION_TYPE_PREFIXES = {
    "xdp": "xdp",
    "tc": "sched_cls",
    "classifier": "sched_cls",
    "cgroup_skb": "cgroup_skb",
    "socket": "socket_filter",
}


def _sanitize_pin_component(value: str) -> str:
    sanitized = "".join(char if (char.isalnum() or char in {"_", "-"}) else "_" for char in str(value))
    sanitized = sanitized.strip("_-")
    return sanitized or "prog"


def parse_args(argv: list[str] | None = None) -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="Run the new Python-only corpus orchestrator.")
    parser.add_argument("--suite", default=str(DEFAULT_MACRO_CORPUS_YAML))
    parser.add_argument("--daemon", default=str(DEFAULT_DAEMON))
    parser.add_argument("--runner", default=str(DEFAULT_RUNNER))
    parser.add_argument("--bpftool", default="", help="Explicit bpftool binary.")
    parser.add_argument("--btf-custom-path", default=str(DEFAULT_BTF_PATH))
    parser.add_argument("--repeat", type=int, default=0)
    parser.add_argument("--workload-seconds", type=float, default=10.0)
    parser.add_argument("--output-json", default=str(DEFAULT_OUTPUT_JSON))
    parser.add_argument("--filter", action="append", dest="filters")
    parser.add_argument("--max-programs", type=int)
    return parser.parse_args(argv)


def ensure_bpffs_mounted() -> None:
    if subprocess.run(["mountpoint", "-q", "/sys/fs/bpf"], check=False).returncode == 0:
        return
    run_command(["mount", "-t", "bpf", "bpf", "/sys/fs/bpf"])


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


def _bpftool_prog_show_pinned(bpftool_binary: str, pin_path: Path) -> dict[str, Any]:
    payload = run_json_command([bpftool_binary, "-j", "-p", "prog", "show", "pinned", str(pin_path)], timeout=30)
    if isinstance(payload, list):
        if len(payload) != 1:
            raise RuntimeError(f"unexpected pinned prog payload for {pin_path}")
        payload = payload[0]
    if not isinstance(payload, Mapping):
        raise RuntimeError(f"unexpected pinned prog payload for {pin_path}")
    return dict(payload)


def _build_prog_run_command(
    bpftool_binary: str,
    pin_path: Path,
    program: Any,
    *,
    repeat: int,
) -> list[str]:
    command = [bpftool_binary, "-j", "-p", "prog", "run", "pinned", str(pin_path)]
    if _infer_prog_type_name(program) in NETWORK_TEST_RUN_TYPES:
        packet_path = materialize_dummy_packet(ROOT_DIR / "corpus" / "inputs" / "macro_dummy_packet_64.bin")
        command.extend(["data_in", str(packet_path)])
    command.extend(["repeat", str(max(1, repeat))])
    return command


def _run_app_native_entry(
    obj: Any,
    *,
    daemon_socket_path: Path,
    workload_seconds: float,
) -> dict[str, object]:
    runner = get_app_runner(
        obj.repo,
        object_path=obj.object_abs_path,
        expected_program_names=[program.program_name for program in obj.programs],
    )
    result: dict[str, object]
    try:
        prog_ids = list(runner.start())
        actual_programs = {
            str(program.get("name") or ""): int(program.get("id", 0) or 0)
            for program in getattr(runner, "programs", [])
            if str(program.get("name") or "").strip() and int(program.get("id", 0) or 0) > 0
        }
        with enable_bpf_stats():
            runner.run_workload(workload_seconds)
            baseline_snapshot = read_program_stats(prog_ids)
            apply_result = apply_daemon_rejit(
                prog_ids,
                enabled_passes=benchmark_rejit_enabled_passes(),
                daemon_socket_path=daemon_socket_path,
            )
            rejit_snapshot: Mapping[int, Mapping[str, object]] = {}
            if bool(apply_result.get("applied")):
                runner.run_workload(workload_seconds)
                rejit_snapshot = read_program_stats(prog_ids)
        baseline_phase = _program_phase_stats(baseline_snapshot)
        rejit_phase = _program_phase_stats(rejit_snapshot, baseline_snapshot) if rejit_snapshot else {}
        baseline_by_name = _program_stats_by_name(baseline_phase, actual_programs)
        rejit_by_name = _program_stats_by_name(rejit_phase, actual_programs)
        status = "ok" if apply_result.get("applied") else "error"
        error = str(apply_result.get("error") or "").strip()
        result = {
            "object": obj.object_path,
            "repo": obj.repo,
            "measurement": "app_native",
            "status": status,
            "error": error,
            "runner": {
                "type": type(runner).__name__,
                "tool_name": getattr(runner, "tool_name", ""),
                "tool_binary": str(getattr(runner, "tool_binary", "") or ""),
            },
            "prog_ids": prog_ids,
            "programs": [dict(program) for program in getattr(runner, "programs", [])],
            "baseline": {
                "programs": baseline_by_name,
                "exec_ns_mean": _mean_exec_ns(baseline_by_name),
            },
            "rejit_apply": dict(apply_result),
            "rejit": {
                "programs": rejit_by_name,
                "exec_ns_mean": _mean_exec_ns(rejit_by_name),
            } if rejit_by_name else None,
        }
    finally:
        runner.stop()
    result["process"] = dict(getattr(runner, "process_output", {}))
    return result


def _run_test_run_entry(
    obj: Any,
    *,
    bpftool_binary: str,
    daemon_socket_path: Path,
    repeat: int,
    btf_path: Path | None,
) -> dict[str, object]:
    ensure_bpffs_mounted()
    object_component = _sanitize_pin_component(Path(obj.object_abs_path).stem)
    pin_root = Path("/sys/fs/bpf") / f"corpus-orch-{object_component}-{os.getpid()}"
    pin_dir = pin_root / "progs"
    map_dir = pin_root / "maps"
    load_command = [bpftool_binary, "prog", "loadall", obj.object_abs_path, str(pin_dir)]
    inferred_type = _infer_prog_type_name(obj.programs[0]) if obj.programs else "unspec"
    if btf_path is not None and btf_path.exists():
        load_command.extend(["kernel_btf", str(btf_path)])
    if inferred_type and inferred_type != "unspec":
        load_command.extend(["type", inferred_type])
    load_command.extend(["pinmaps", str(map_dir)])
    run_command(["rm", "-rf", str(pin_root)], check=False)
    run_command(["mkdir", "-p", str(pin_dir), str(map_dir)])

    try:
        run_command(load_command, timeout=180)
        records: list[dict[str, object]] = []
        record_errors: list[str] = []
        for program in obj.programs:
            try:
                pin_path = pin_dir / program.program_name
                prog_show = _bpftool_prog_show_pinned(bpftool_binary, pin_path)
                prog_id = int(prog_show.get("id", 0) or 0)
                if prog_id <= 0:
                    raise RuntimeError(f"{program.program_name}: failed to resolve pinned prog id")
                baseline_run = run_json_command(
                    _build_prog_run_command(bpftool_binary, pin_path, program, repeat=repeat),
                    timeout=120,
                )
                if not isinstance(baseline_run, Mapping):
                    raise RuntimeError(f"{program.program_name}: unexpected bpftool baseline payload")
                apply_result = apply_daemon_rejit(
                    [prog_id],
                    enabled_passes=benchmark_rejit_enabled_passes(),
                    daemon_socket_path=daemon_socket_path,
                )
                rejit_run: Mapping[str, object] | None = None
                if bool(apply_result.get("applied")):
                    rejit_run = run_json_command(
                        _build_prog_run_command(bpftool_binary, pin_path, program, repeat=repeat),
                        timeout=120,
                    )
                    if not isinstance(rejit_run, Mapping):
                        raise RuntimeError(f"{program.program_name}: unexpected bpftool rejit payload")
                baseline: dict[str, object] = {
                    "source": "bpftool",
                    "exec_ns": int(baseline_run.get("duration", 0) or 0),
                    "retval": int(baseline_run.get("retval", 0) or 0),
                    "prog_id": prog_id,
                    "jited_bytes": int(prog_show.get("bytes_jited", 0) or 0),
                    "bytes_xlated": int(prog_show.get("bytes_xlated", 0) or 0),
                    "xlated_insns": int(int(prog_show.get("bytes_xlated", 0) or 0) / 8),
                    "raw": dict(baseline_run),
                }
                rejit: dict[str, object] | None = None
                if rejit_run is not None:
                    post_show = _bpftool_prog_show_pinned(bpftool_binary, pin_path)
                    rejit = {
                        "source": "bpftool",
                        "exec_ns": int(rejit_run.get("duration", 0) or 0),
                        "retval": int(rejit_run.get("retval", 0) or 0),
                        "prog_id": prog_id,
                        "jited_bytes": int(post_show.get("bytes_jited", 0) or 0),
                        "bytes_xlated": int(post_show.get("bytes_xlated", 0) or 0),
                        "xlated_insns": int(int(post_show.get("bytes_xlated", 0) or 0) / 8),
                        "raw": dict(rejit_run),
                    }
                record_status = "ok"
                record_error = ""
                if not bool(apply_result.get("applied")):
                    record_status = "error"
                    record_error = str(apply_result.get("error") or "").strip() or (
                        f"{program.program_name}: daemon REJIT apply returned applied=false"
                    )
            except Exception as exc:
                pin_path = pin_dir / program.program_name
                prog_id = 0
                baseline = {}
                rejit = None
                apply_result = {}
                record_status = "error"
                record_error = str(exc)
            if record_error:
                record_errors.append(record_error)
            records.append(
                {
                    "program_name": program.program_name,
                    "status": record_status,
                    "pin_path": str(pin_path),
                    "prog_id": prog_id,
                    "baseline": baseline,
                    "rejit_apply": dict(apply_result),
                    "rejit": rejit,
                    "error": record_error,
                }
            )
        statuses = Counter(str(record.get("status") or "error") for record in records)
        return {
            "object": obj.object_path,
            "repo": obj.repo,
            "measurement": "test_run",
            "status": "ok" if statuses.get("error", 0) == 0 else "error",
            "error": "; ".join(record_errors),
            "records": records,
            "summary": {
                "records": len(records),
                "statuses": dict(sorted(statuses.items())),
            },
        }
    finally:
        run_command(["rm", "-rf", str(pin_root)], check=False)


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
    runner_binary = Path(args.runner).resolve() if str(args.runner).strip() else None
    btf_path = Path(args.btf_custom_path).resolve() if str(args.btf_custom_path).strip() else None
    bpftool_binary = str(Path(args.bpftool).resolve()) if str(args.bpftool).strip() else resolve_bpftool_binary()

    if not daemon_binary.exists():
        raise RuntimeError(f"daemon binary not found: {daemon_binary}")

    daemon_proc, daemon_socket_path, daemon_socket_dir, daemon_stdout_path, daemon_stderr_path = _start_daemon_server(
        daemon_binary
    )
    try:
        results: list[dict[str, object]] = []
        for obj in objects:
            try:
                if obj.measurement == "app_native":
                    result = _run_app_native_entry(
                        obj,
                        daemon_socket_path=daemon_socket_path,
                        workload_seconds=max(1.0, float(args.workload_seconds)),
                    )
                elif obj.measurement == "test_run":
                    result = _run_test_run_entry(
                        obj,
                        bpftool_binary=bpftool_binary,
                        daemon_socket_path=daemon_socket_path,
                        repeat=max(1, repeat),
                        btf_path=btf_path,
                    )
                else:
                    raise RuntimeError(f"unsupported measurement: {obj.measurement}")
            except NotImplementedError as exc:
                result = {
                    "object": obj.object_path,
                    "repo": obj.repo,
                    "measurement": obj.measurement,
                    "status": "unsupported",
                    "error": str(exc),
                }
            except Exception as exc:
                result = {
                    "object": obj.object_path,
                    "repo": obj.repo,
                    "measurement": obj.measurement,
                    "status": "error",
                    "error": str(exc),
                }
            results.append(result)

        status_counts = Counter(str(result.get("status") or "error") for result in results)
        measurement_counts = Counter(str(result.get("measurement") or "") for result in results)
        return {
            "generated_at": datetime.now(timezone.utc).isoformat(),
            "manifest": str(manifest_path),
            "daemon": str(daemon_binary),
            "daemon_socket": str(daemon_socket_path),
            "bpftool": bpftool_binary,
            "runner": str(runner_binary) if runner_binary is not None else None,
            "btf_custom_path": str(btf_path) if btf_path is not None else None,
            "filters": list(args.filters or []),
            "repeat": max(1, repeat),
            "workload_seconds": max(1.0, float(args.workload_seconds)),
            "manifest_summary": manifest_summary,
            "results": results,
            "summary": {
                "selected_objects": len(objects),
                "selected_programs": sum(len(obj.programs) for obj in objects),
                "measurements": dict(sorted(measurement_counts.items())),
                "statuses": dict(sorted(status_counts.items())),
            },
            "status": "ok" if status_counts.get("error", 0) == 0 else "error",
        }
    finally:
        _stop_daemon_server(daemon_proc, daemon_socket_path, daemon_socket_dir)


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
