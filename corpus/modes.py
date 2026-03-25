#!/usr/bin/env python3
from __future__ import annotations

import argparse
import json
import math
import os
import selectors
import shlex
import statistics
import subprocess
import sys
import tempfile
import time
import traceback
from collections import Counter, defaultdict
from datetime import datetime, timezone
from pathlib import Path
from typing import Any, Callable, Mapping

SCRIPT_DIR = Path(__file__).resolve().parent
REPO_ROOT = SCRIPT_DIR.parent
for candidate in (REPO_ROOT, SCRIPT_DIR, REPO_ROOT / "micro", REPO_ROOT / "corpus"):
    candidate_str = str(candidate)
    if candidate_str not in sys.path:
        sys.path.insert(0, candidate_str)

from runner.libs import authoritative_output_path, smoke_output_path
from runner.libs.batch_runner import run_batch_runner
from runner.libs.machines import resolve_machine
from runner.libs.vm import DEFAULT_VM_TARGET, build_vng_command as build_runner_vng_command

from runner.libs.inventory import (
    discover_corpus_objects,
    discover_object_programs,
    load_packet_test_run_targets,
)
from runner.libs.run_artifacts import (
    ArtifactSession,
    derive_run_type,
    repo_relative_path,
)

from runner.libs.corpus import (
    add_filter_argument,
    add_max_programs_argument,
    add_corpus_build_report_argument,
    add_output_json_argument,
    add_output_md_argument,
    add_repeat_argument,
    add_runner_argument,
    add_daemon_argument,
    add_timeout_argument,
    directive_scan_from_record,
    ensure_parent,
    execution_plan,
    format_ns,
    format_ratio,
    geomean,
    infer_program_kind,
    markdown_table,
    materialize_dummy_context,
    materialize_dummy_packet,
    normalize_directive_scan as shared_normalize_directive_scan,
    require_minimum,
    summarize_text,
    write_json_output,
    write_text_output,
    extract_error,
)


ROOT_DIR = Path(__file__).resolve().parent.parent
DRIVER_RELATIVE = Path(__file__).with_name("driver.py").resolve().relative_to(ROOT_DIR)
DEFAULT_INVENTORY_JSON = ROOT_DIR / "docs" / "tmp" / "corpus-runnability-results.json"
DEFAULT_OUTPUT_JSON = authoritative_output_path(ROOT_DIR / "corpus" / "results", "corpus_vm_batch")
DEFAULT_OUTPUT_MD = ROOT_DIR / "docs" / "tmp" / "corpus-batch-rejit-results.md"
DEFAULT_RUNNER = ROOT_DIR / "runner" / "build" / "micro_exec"
DEFAULT_DAEMON = ROOT_DIR / "daemon" / "target" / "release" / "bpfrejit-daemon"
DEFAULT_KERNEL_TREE = ROOT_DIR / "vendor" / "linux-framework"
DEFAULT_KERNEL_IMAGE = DEFAULT_KERNEL_TREE / "arch" / "x86" / "boot" / "bzImage"
DEFAULT_BTF_PATH = DEFAULT_KERNEL_TREE / "vmlinux"
DEFAULT_HOST_BTF_PATH = Path("/sys/kernel/btf/vmlinux")
DEFAULT_VNG_MACHINE = resolve_machine(target=DEFAULT_VM_TARGET, action="vm-corpus")
DEFAULT_VNG = str(Path(DEFAULT_VNG_MACHINE.executable))
DEFAULT_VNG_MEMORY = DEFAULT_VNG_MACHINE.memory or "4G"
DEFAULT_VNG_CPUS = str(DEFAULT_VNG_MACHINE.cpus or 2)
DEFAULT_REPEAT = 200
DEFAULT_TIMEOUT_SECONDS = 240


DEFAULT_PERF_OUTPUT_JSON = authoritative_output_path(ROOT_DIR / "corpus" / "results", "corpus_perf")
DEFAULT_PERF_OUTPUT_MD = ROOT_DIR / "docs" / "tmp" / "corpus-perf-results.md"
DEFAULT_TRACING_OUTPUT_JSON = authoritative_output_path(ROOT_DIR / "corpus" / "results", "corpus_tracing")
DEFAULT_TRACING_OUTPUT_MD = ROOT_DIR / "docs" / "tmp" / "corpus-tracing-results.md"
DEFAULT_CODE_SIZE_OUTPUT_JSON = authoritative_output_path(ROOT_DIR / "corpus" / "results", "corpus_code_size")
DEFAULT_CODE_SIZE_OUTPUT_MD = ROOT_DIR / "docs" / "tmp" / "corpus-code-size-results.md"
FAMILY_FIELDS = (
    ("cmov", "cmov_sites"),
    ("wide", "wide_sites"),
    ("rotate", "rotate_sites"),
    ("lea", "lea_sites"),
    ("extract", "bitfield_sites"),
    ("endian", "endian_sites"),
    ("branch-flip", "branch_flip_sites"),
)
FAMILY_DISPLAY_NAMES = {
    "cmov": "CMOV",
    "wide": "WIDE",
    "rotate": "ROTATE",
    "lea": "LEA",
    "extract": "EXTRACT",
    "endian": "ENDIAN",
    "branch-flip": "BRANCH-FLIP",
}


def parse_packet_args(argv: list[str] | None = None) -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description=(
            "Run the inventory-derived packet-test-run corpus REJIT batch on "
            "the framework kernel guest."
        )
    )
    parser.add_argument(
        "--inventory-json",
        default=str(DEFAULT_INVENTORY_JSON),
        help="Inventory JSON used to select the paired packet-test-run targets.",
    )
    add_output_json_argument(parser, DEFAULT_OUTPUT_JSON)
    add_output_md_argument(parser, DEFAULT_OUTPUT_MD)
    add_runner_argument(parser, DEFAULT_RUNNER, help_text="Path to micro_exec.")
    add_daemon_argument(parser, DEFAULT_DAEMON, help_text="Path to bpfrejit-daemon.")
    parser.add_argument(
        "--kernel-tree",
        default=str(DEFAULT_KERNEL_TREE),
        help="Framework kernel tree recorded in result metadata.",
    )
    parser.add_argument(
        "--kernel-image",
        default=str(DEFAULT_KERNEL_IMAGE),
        help="Kernel image passed to vng --run.",
    )
    parser.add_argument(
        "--btf-custom-path",
        default=str(DEFAULT_BTF_PATH),
        help="BTF path passed to guest micro_exec invocations.",
    )
    parser.add_argument(
        "--vng",
        default=DEFAULT_VNG,
        help="vng executable to use for strict guest runs.",
    )
    add_repeat_argument(parser, DEFAULT_REPEAT, help_text="Repeat count passed to each micro_exec invocation.")
    add_timeout_argument(parser, DEFAULT_TIMEOUT_SECONDS, help_text="Per-target timeout in seconds.")
    add_filter_argument(
        parser,
        help_text="Only include targets whose object path, program name, or source contains this substring. Repeatable.",
    )
    add_max_programs_argument(parser, help_text="Optional cap for smoke testing.")
    parser.add_argument(
        "--skip-families",
        action="append",
        help="Comma-separated REJIT families to exclude from daemon apply. Supported: cmov, wide, rotate, lea, extract, endian, branch-flip.",
    )
    parser.add_argument(
        "--blind-apply",
        action="store_true",
        help="Ignore per-program policies and force blind all-apply auto-scan REJIT for debugging.",
    )
    parser.add_argument(
        "--guest-info",
        action="store_true",
        help=argparse.SUPPRESS,
    )
    parser.add_argument(
        "--guest-target-json",
        help=argparse.SUPPRESS,
    )
    parser.add_argument(
        "--guest-result-json",
        help=argparse.SUPPRESS,
    )
    return parser.parse_args(argv)


def build_corpus_artifact_metadata(
    *,
    generated_at: str,
    run_type: str,
    mode_name: str,
    output_json: Path,
    output_md: Path,
    summary: dict[str, Any],
    progress: dict[str, Any],
    extra_fields: dict[str, Any],
) -> dict[str, Any]:
    metadata = {
        "generated_at": generated_at,
        "suite": "corpus",
        "mode": mode_name,
        "run_type": run_type,
        "output_hint_json": repo_relative_path(output_json),
        "output_hint_md": repo_relative_path(output_md),
        "summary": summary,
        "paper_summary": summary,
        "progress": progress,
    }
    metadata.update(extra_fields)
    return metadata


def canonical_family_name(value: str) -> str:
    normalized = value.strip().lower().replace("_", "-")
    mapping = {
        "cmov": "cmov",
        "cond-select": "cmov",
        "wide": "wide",
        "wide-mem": "wide",
        "wide-load": "wide",
        "rotate": "rotate",
        "lea": "lea",
        "addr-calc": "lea",
        "addrcalc": "lea",
        "extract": "extract",
        "bitfield": "extract",
        "bitfield-extract": "extract",
        "bit-extract": "extract",
        "endian": "endian",
        "endian-fusion": "endian",
        "branch-flip": "branch-flip",
        "branchflip": "branch-flip",
        "bflip": "branch-flip",
    }
    if normalized not in mapping:
        raise SystemExit(
            f"unsupported family in --skip-families: {value} "
            "(expected cmov, wide, rotate, lea, extract, endian, or branch-flip)"
        )
    return mapping[normalized]


def normalize_skip_families(values: list[str] | None) -> list[str]:
    normalized: list[str] = []
    seen: set[str] = set()
    for raw in values or []:
        for item in raw.split(","):
            if not item.strip():
                continue
            family = canonical_family_name(item)
            if family not in seen:
                seen.add(family)
                normalized.append(family)
    return normalized


def normalize_scan(scan: dict[str, Any] | None) -> dict[str, int]:
    return shared_normalize_directive_scan(scan)


def families_from_scan(scan: dict[str, Any] | None) -> list[str]:
    normalized = normalize_scan(scan)
    return [name for name, field in FAMILY_FIELDS if normalized[field] > 0]


def batch_text_invocation_summary(result: dict[str, Any] | None) -> dict[str, Any] | None:
    if result is None:
        return None
    return {
        "ok": result["ok"],
        "returncode": result["returncode"],
        "timed_out": result["timed_out"],
        "duration_seconds": result["duration_seconds"],
        "error": result["error"],
        "stderr_tail": summarize_text(result["stderr"]),
        "stdout_tail": summarize_text(result.get("diagnostic_stdout", result["stdout"])),
    }


def start_daemon_server(daemon: Path, daemon_socket: str) -> subprocess.Popen[str]:
    socket_path = Path(daemon_socket)
    socket_path.unlink(missing_ok=True)
    daemon_proc: subprocess.Popen[str] = subprocess.Popen(
        [str(daemon), "--pgo", "serve", "--socket", daemon_socket],
        stdout=subprocess.DEVNULL,
        stderr=subprocess.DEVNULL,
        text=True,
    )
    time.sleep(0.5)
    return daemon_proc


def stop_daemon_server(daemon_proc: subprocess.Popen[str] | None, daemon_socket: str | None) -> None:
    if daemon_proc is not None:
        daemon_proc.terminate()
        try:
            daemon_proc.wait(timeout=5)
        except subprocess.TimeoutExpired:
            daemon_proc.kill()
            daemon_proc.wait()
    if daemon_socket:
        Path(daemon_socket).unlink(missing_ok=True)


def emit_guest_event(kind: str, **payload: Any) -> None:
    print(json.dumps({"kind": kind, **payload}, sort_keys=True), flush=True)


def parse_guest_event(line: str) -> dict[str, Any] | None:
    text = line.strip()
    if not text or not text.startswith("{"):
        return None
    try:
        payload = json.loads(text)
    except json.JSONDecodeError:
        return None
    if not isinstance(payload, dict) or not isinstance(payload.get("kind"), str):
        return None
    return payload


def packet_batch_timeout_seconds(target_count: int, per_target_timeout: int) -> int:
    return max(1, target_count) * max(1, per_target_timeout) * 4 + 120


def size_ratio(
    baseline_record: dict[str, Any] | None,
    rejit_record: dict[str, Any] | None,
) -> float | None:
    if not baseline_record or not rejit_record:
        return None
    if not baseline_record.get("ok") or not rejit_record.get("ok"):
        return None
    baseline_len = ((baseline_record.get("sample") or {}).get("jited_prog_len"))
    rejit_len = ((rejit_record.get("sample") or {}).get("jited_prog_len"))
    if not baseline_len or not rejit_len:
        return None
    return float(baseline_len) / float(rejit_len)


def size_delta_pct(
    baseline_record: dict[str, Any] | None,
    rejit_record: dict[str, Any] | None,
) -> float | None:
    ratio = size_ratio(baseline_record, rejit_record)
    if ratio is None:
        return None
    baseline_len = ((baseline_record.get("sample") or {}).get("jited_prog_len"))
    rejit_len = ((rejit_record.get("sample") or {}).get("jited_prog_len"))
    if baseline_len in (None, 0) or rejit_len is None:
        return None
    return (float(rejit_len) - float(baseline_len)) * 100.0 / float(baseline_len)


def speedup_ratio(
    baseline_record: dict[str, Any] | None,
    rejit_record: dict[str, Any] | None,
) -> float | None:
    if not baseline_record or not rejit_record:
        return None
    if not baseline_record.get("ok") or not rejit_record.get("ok"):
        return None
    baseline_ns = ((baseline_record.get("sample") or {}).get("exec_ns"))
    rejit_ns = ((rejit_record.get("sample") or {}).get("exec_ns"))
    if not baseline_ns or not rejit_ns:
        return None
    return float(baseline_ns) / float(rejit_ns)


def summarize_failure_reason(record: dict[str, Any] | None) -> str:
    if not record:
        return "n/a"
    error = record.get("error")
    if error:
        return str(error)
    sample = record.get("sample") or {}
    rejit = sample.get("rejit") or {}
    if rejit.get("error"):
        return str(rejit["error"])
    return "unknown"


def program_label(record: dict[str, Any]) -> str:
    return f"{record['object_path']}:{record['program_name']}"


def rejit_metadata(record: dict[str, Any] | None) -> dict[str, Any]:
    if not record or not record.get("ok"):
        return {}
    return (record.get("sample") or {}).get("rejit") or {}


def effective_applied_families(
    requested_families: list[str],
    eligible_families: list[str],
    applied: bool,
) -> list[str]:
    if not applied:
        return []
    if not requested_families:
        return list(eligible_families)
    eligible_set = set(eligible_families)
    return [family for family in requested_families if family in eligible_set]


def build_empty_record(target: dict[str, Any], execution_mode: str) -> dict[str, Any]:
    return {
        **target,
        "execution_mode": execution_mode,
        "policy_path": target.get("policy_path"),
        "policy_mode": str(target.get("policy_mode", "stock")),
        "scan_source": "inventory",
        "daemon_counts": normalize_scan(target.get("inventory_scan")),
        "daemon_cli": None,
        "baseline_compile": None,
        "rejit_compile": None,
        "baseline_run": None,
        "rejit_run": None,
        "rejit_compile_applied": False,
        "rejit_run_applied": False,
        "eligible_families": families_from_scan(target.get("inventory_scan")),
        "requested_families_compile": [],
        "requested_families_run": [],
        "applied_families_compile": [],
        "applied_families_run": [],
        "size_ratio": None,
        "size_delta_pct": None,
        "speedup_ratio": None,
        "record_error": None,
        "guest_invocation": None,
    }


def corpus_batch_parallel_jobs() -> int:
    return max(1, int(math.floor((os.cpu_count() or 1) * 0.8)))


def build_test_run_batch_job(
    *,
    job_id: str,
    execution: str,
    runtime: str,
    object_path: Path,
    program_name: str,
    io_mode: str,
    memory_path: Path | None,
    input_size: int,
    repeat: int,
    btf_custom_path: Path | None,
    compile_only: bool,
    daemon_socket: str | None = None,
    prepared_key: str | None = None,
    prepared_ref: str | None = None,
    prepared_group: str | None = None,
) -> dict[str, Any]:
    job: dict[str, Any] = {
        "id": job_id,
        "type": "test_run",
        "execution": execution,
        "runtime": runtime,
        "program": str(object_path),
        "program_name": program_name,
        "io_mode": io_mode,
        "repeat": max(1, repeat),
        "compile_only": compile_only,
    }
    if memory_path is not None:
        job["memory"] = str(memory_path)
    if input_size > 0:
        job["input_size"] = int(input_size)
    if btf_custom_path is not None:
        job["btf_custom_path"] = str(btf_custom_path)
    if daemon_socket is not None:
        job["daemon_socket"] = daemon_socket
    if prepared_key is not None:
        job["prepared_key"] = prepared_key
    if prepared_ref is not None:
        job["prepared_ref"] = prepared_ref
    if prepared_group is not None:
        job["prepared_group"] = prepared_group
    return job


def batch_job_invocation_summary(job_result: Mapping[str, Any] | None) -> dict[str, Any] | None:
    if not isinstance(job_result, Mapping):
        return None
    samples = job_result.get("samples")
    last_sample = None
    if isinstance(samples, list) and samples:
        candidate = samples[-1]
        if isinstance(candidate, dict):
            last_sample = dict(candidate)
    ok = bool(job_result.get("ok"))
    error = str(job_result.get("error") or "") or None
    return {
        "ok": ok,
        "returncode": 0 if ok else 2,
        "timed_out": False,
        "duration_seconds": float(job_result.get("wall_time_ns", 0) or 0) / 1_000_000_000.0,
        "error": error,
        "stderr_tail": summarize_text(error or ""),
        "stdout_tail": "",
        "sample": last_sample,
    }


def batch_job_result_map(batch_payload: Mapping[str, Any] | None) -> dict[str, dict[str, Any]]:
    if not isinstance(batch_payload, Mapping):
        return {}
    jobs = batch_payload.get("jobs")
    if not isinstance(jobs, list):
        return {}
    mapped: dict[str, dict[str, Any]] = {}
    for item in jobs:
        if not isinstance(item, dict):
            continue
        job_id = item.get("id")
        if isinstance(job_id, str) and job_id:
            mapped[job_id] = dict(item)
    return mapped


def build_target_batch_plan(
    *,
    targets: list[dict[str, Any]],
    repeat: int,
    btf_custom_path: Path | None,
    enable_recompile: bool,
    enable_exec: bool,
    daemon_socket: str | None,
) -> tuple[dict[str, Any], list[dict[str, str]]]:
    jobs: list[dict[str, Any]] = []
    job_refs: list[dict[str, str]] = []
    target_entries: list[dict[str, Any]] = []
    parallel_jobs = corpus_batch_parallel_jobs()

    for index, target in enumerate(targets, start=1):
        object_path = ROOT_DIR / target["object_path"]
        memory_path = Path(target["memory_path"]) if target.get("memory_path") else None
        prefix = f"target-{index:04d}"
        refs: dict[str, str] = {}
        job_refs.append(refs)
        target_entries.append(
            {
                "target": target,
                "object_path": object_path,
                "memory_path": memory_path,
                "prefix": prefix,
                "refs": refs,
                "baseline_prepared_key": f"{prefix}:baseline-prepared",
                "rejit_prepared_key": f"{prefix}:rejit-prepared",
            }
        )

    for chunk_start in range(0, len(target_entries), parallel_jobs):
        chunk = target_entries[chunk_start : chunk_start + parallel_jobs]
        baseline_group = f"chunk-{chunk_start // parallel_jobs:04d}:baseline"
        rejit_group = f"chunk-{chunk_start // parallel_jobs:04d}:rejit"

        for entry in chunk:
            target = entry["target"]
            refs = entry["refs"]
            refs["baseline_compile"] = f"{entry['prefix']}:baseline-compile"
            jobs.append(
                build_test_run_batch_job(
                    job_id=refs["baseline_compile"],
                    execution="parallel",
                    runtime="kernel",
                    object_path=entry["object_path"],
                    program_name=target["program_name"],
                    io_mode=target["io_mode"],
                    memory_path=entry["memory_path"],
                    input_size=int(target["input_size"]),
                    repeat=repeat,
                    btf_custom_path=btf_custom_path,
                    compile_only=True,
                    prepared_key=(
                        entry["baseline_prepared_key"]
                        if enable_exec and target.get("can_test_run")
                        else None
                    ),
                    prepared_group=(
                        baseline_group
                        if enable_exec and target.get("can_test_run")
                        else None
                    ),
                )
            )

        if enable_exec:
            for entry in chunk:
                target = entry["target"]
                refs = entry["refs"]
                if not target.get("can_test_run"):
                    continue
                refs["baseline_run"] = f"{entry['prefix']}:baseline-run"
                jobs.append(
                    build_test_run_batch_job(
                        job_id=refs["baseline_run"],
                        execution="serial",
                        runtime="kernel",
                        object_path=entry["object_path"],
                        program_name=target["program_name"],
                        io_mode=target["io_mode"],
                        memory_path=entry["memory_path"],
                        input_size=int(target["input_size"]),
                        repeat=repeat,
                        btf_custom_path=btf_custom_path,
                        compile_only=False,
                        prepared_ref=entry["baseline_prepared_key"],
                        prepared_group=baseline_group,
                    )
                )

        if enable_recompile and enable_exec:
            for entry in chunk:
                target = entry["target"]
                refs = entry["refs"]
                if not target.get("can_test_run"):
                    continue
                refs["pgo_warmup"] = f"{entry['prefix']}:pgo-warmup"
                jobs.append(
                    build_test_run_batch_job(
                        job_id=refs["pgo_warmup"],
                        execution="serial",
                        runtime="kernel",
                        object_path=entry["object_path"],
                        program_name=target["program_name"],
                        io_mode=target["io_mode"],
                        memory_path=entry["memory_path"],
                        input_size=int(target["input_size"]),
                        repeat=10,
                        btf_custom_path=btf_custom_path,
                        compile_only=False,
                    )
                )

        if enable_recompile:
            for entry in chunk:
                target = entry["target"]
                refs = entry["refs"]
                refs["rejit_compile"] = f"{entry['prefix']}:rejit-compile"
                jobs.append(
                    build_test_run_batch_job(
                        job_id=refs["rejit_compile"],
                        execution="parallel",
                        runtime="kernel-rejit",
                        object_path=entry["object_path"],
                        program_name=target["program_name"],
                        io_mode=target["io_mode"],
                        memory_path=entry["memory_path"],
                        input_size=int(target["input_size"]),
                        repeat=repeat,
                        btf_custom_path=btf_custom_path,
                        compile_only=True,
                        daemon_socket=daemon_socket,
                        prepared_key=(
                            entry["rejit_prepared_key"]
                            if enable_exec and target.get("can_test_run")
                            else None
                        ),
                        prepared_group=(
                            rejit_group
                            if enable_exec and target.get("can_test_run")
                            else None
                        ),
                    )
                )

        if enable_recompile and enable_exec:
            for entry in chunk:
                target = entry["target"]
                refs = entry["refs"]
                if not target.get("can_test_run"):
                    continue
                refs["rejit_run"] = f"{entry['prefix']}:rejit-run"
                jobs.append(
                    build_test_run_batch_job(
                        job_id=refs["rejit_run"],
                        execution="serial",
                        runtime="kernel-rejit",
                        object_path=entry["object_path"],
                        program_name=target["program_name"],
                        io_mode=target["io_mode"],
                        memory_path=entry["memory_path"],
                        input_size=int(target["input_size"]),
                        repeat=repeat,
                        btf_custom_path=btf_custom_path,
                        compile_only=False,
                        daemon_socket=daemon_socket,
                        prepared_ref=entry["rejit_prepared_key"],
                        prepared_group=rejit_group,
                    )
                )

    return {
        "schema_version": 1,
        "scheduler": {
            "max_parallel_jobs": parallel_jobs,
        },
        "jobs": jobs,
    }, job_refs


def build_record_from_batch_results(
    *,
    target: dict[str, Any],
    execution_mode: str,
    enable_recompile: bool,
    enable_exec: bool,
    skip_families: list[str],
    blind_apply: bool,
    job_refs: Mapping[str, str],
    results_by_id: Mapping[str, dict[str, Any]],
    ) -> dict[str, Any]:
    record = build_empty_record(target, execution_mode)
    policy_mode = "blind-apply-rejit" if blind_apply else "daemon-auto"
    inventory_scan = normalize_scan(target.get("inventory_scan"))
    scan_source = "inventory"
    daemon_counts = inventory_scan

    baseline_compile_raw = batch_job_invocation_summary(results_by_id.get(job_refs.get("baseline_compile", "")))
    baseline_run_raw = batch_job_invocation_summary(results_by_id.get(job_refs.get("baseline_run", "")))
    rejit_compile_raw = batch_job_invocation_summary(results_by_id.get(job_refs.get("rejit_compile", "")))
    rejit_run_raw = batch_job_invocation_summary(results_by_id.get(job_refs.get("rejit_run", "")))

    if baseline_compile_raw and baseline_compile_raw.get("ok"):
        baseline_scan = directive_scan_from_record(baseline_compile_raw)
        if baseline_scan["total_sites"] > 0:
            daemon_counts = baseline_scan
            scan_source = f"{execution_mode}_runner_scan"

    record["daemon_cli"] = None
    record["policy_path"] = None
    record["policy_mode"] = policy_mode
    record["scan_source"] = scan_source
    record["daemon_counts"] = daemon_counts
    record["eligible_families"] = families_from_scan(daemon_counts)
    record["baseline_compile"] = baseline_compile_raw
    record["rejit_compile"] = rejit_compile_raw
    record["rejit_run"] = rejit_run_raw
    record["baseline_run"] = baseline_run_raw

    if (
        enable_exec
        and enable_recompile
        and target.get("can_test_run")
        and rejit_run_raw
        and rejit_run_raw.get("ok")
        and record["baseline_run"] is None
    ):
        record["record_error"] = "stock phase missing from batch runner output"
    record["rejit_compile_applied"] = bool((((record["rejit_compile"] or {}).get("sample") or {}).get("rejit") or {}).get("applied"))
    record["rejit_run_applied"] = bool((((record["rejit_run"] or {}).get("sample") or {}).get("rejit") or {}).get("applied"))
    record["requested_families_compile"] = list(rejit_metadata(record["rejit_compile"]).get("requested_families") or [])
    record["requested_families_run"] = list(rejit_metadata(record["rejit_run"]).get("requested_families") or [])
    record["applied_families_compile"] = effective_applied_families(
        record["requested_families_compile"],
        record["eligible_families"],
        record["rejit_compile_applied"],
    )
    record["applied_families_run"] = effective_applied_families(
        record["requested_families_run"],
        record["eligible_families"],
        record["rejit_run_applied"],
    )
    record["size_ratio"] = size_ratio(record["baseline_compile"], record["rejit_compile"])
    record["size_delta_pct"] = size_delta_pct(record["baseline_compile"], record["rejit_compile"])
    record["speedup_ratio"] = speedup_ratio(record["baseline_run"], record["rejit_run"])
    return record


def run_targets_locally_batch(
    *,
    targets: list[dict[str, Any]],
    runner: Path,
    daemon: Path,
    repeat: int,
    timeout_seconds: int,
    execution_mode: str,
    btf_custom_path: Path | None,
    enable_recompile: bool,
    enable_exec: bool,
    skip_families: list[str],
    blind_apply: bool,
    daemon_socket: str | None = None,
) -> tuple[list[dict[str, Any]], dict[str, Any]]:
    active_daemon_socket = daemon_socket
    daemon_proc = None
    if enable_recompile and active_daemon_socket is None:
        active_daemon_socket = f"/tmp/bpfrejit-{os.getpid()}.sock"
        daemon_proc = start_daemon_server(daemon, active_daemon_socket)

    try:
        spec_payload, job_refs = build_target_batch_plan(
            targets=targets,
            repeat=repeat,
            btf_custom_path=btf_custom_path,
            enable_recompile=enable_recompile,
            enable_exec=enable_exec,
            daemon_socket=active_daemon_socket,
        )
        batch_result = run_batch_runner(
            runner,
            spec_payload=spec_payload,
            timeout_seconds=packet_batch_timeout_seconds(len(targets), timeout_seconds),
            cwd=ROOT_DIR,
        )
    finally:
        stop_daemon_server(daemon_proc, active_daemon_socket if daemon_proc is not None else None)

    results_by_id = batch_job_result_map(batch_result.get("result"))
    records = [
        build_record_from_batch_results(
            target=target,
            execution_mode=execution_mode,
            enable_recompile=enable_recompile,
            enable_exec=enable_exec,
            skip_families=skip_families,
            blind_apply=blind_apply,
            job_refs=refs,
            results_by_id=results_by_id,
        )
        for target, refs in zip(targets, job_refs, strict=True)
    ]
    return records, batch_result


def guest_info_payload() -> dict[str, Any]:
    return {
        "kind": "guest_info",
        "kernel_release": subprocess.run(
            ["uname", "-r"],
            cwd=ROOT_DIR,
            capture_output=True,
            text=True,
            check=False,
        ).stdout.strip(),
        "cwd": str(Path.cwd()),
        "runner_exists": DEFAULT_RUNNER.exists(),
        "btf_exists": DEFAULT_BTF_PATH.exists(),
        "uid": os.geteuid(),
    }


def run_guest_info_mode() -> int:
    print(json.dumps(guest_info_payload(), sort_keys=True))
    return 0


def load_guest_batch_targets(target_path: Path) -> list[dict[str, Any]]:
    payload = json.loads(target_path.read_text())
    if not isinstance(payload, dict):
        raise SystemExit("--guest-target-json payload must be a JSON object")
    targets = payload.get("targets")
    if not isinstance(targets, list):
        raise SystemExit("--guest-target-json payload missing targets list")
    normalized_targets: list[dict[str, Any]] = []
    for index, target in enumerate(targets, start=1):
        if not isinstance(target, dict):
            raise SystemExit(f"--guest-target-json target #{index} must be a JSON object")
        normalized_targets.append(dict(target))
    return normalized_targets


def write_guest_batch_records(result_path: Path, records: list[dict[str, Any]]) -> None:
    payload = {"records": records}
    with tempfile.NamedTemporaryFile(
        mode="w",
        dir=result_path.parent,
        prefix=f"{result_path.name}.",
        suffix=".tmp",
        delete=False,
    ) as handle:
        json.dump(payload, handle)
        handle.write("\n")
        temp_path = Path(handle.name)
    temp_path.replace(result_path)


def _strip_daemon_response(value: Any) -> Any:
    if isinstance(value, dict):
        sanitized: dict[str, Any] = {}
        for key, item in value.items():
            if key == "daemon_response":
                continue
            sanitized[key] = _strip_daemon_response(item)
        return sanitized
    if isinstance(value, list):
        return [_strip_daemon_response(item) for item in value]
    return value


def sanitize_guest_batch_record(record: dict[str, Any]) -> dict[str, Any]:
    return _strip_daemon_response(record)


def run_guest_batch_mode(args: argparse.Namespace) -> int:
    target_path = Path(args.guest_target_json).resolve()
    targets = load_guest_batch_targets(target_path)
    runner = Path(args.runner).resolve()
    daemon = Path(args.daemon).resolve()
    btf_custom_path = Path(args.btf_custom_path).resolve() if args.btf_custom_path else None
    guest_result_path = Path(args.guest_result_json).resolve() if args.guest_result_json else None
    if btf_custom_path is None:
        raise SystemExit("--btf-custom-path is required in guest batch mode")

    emit_guest_event("guest_info", payload=guest_info_payload())
    skip_families = normalize_skip_families(args.skip_families)
    records: list[dict[str, Any]] = []
    if guest_result_path is not None:
        write_guest_batch_records(guest_result_path, records)

    try:
        built_records, _batch_result = run_targets_locally_batch(
            targets=targets,
            runner=runner,
            daemon=daemon,
            repeat=args.repeat,
            timeout_seconds=args.timeout,
            execution_mode="vm",
            btf_custom_path=btf_custom_path,
            enable_recompile=True,
            enable_exec=True,
            skip_families=skip_families,
            blind_apply=args.blind_apply,
        )
    except Exception as exc:
        print(traceback.format_exc(), file=sys.stderr, flush=True)
        built_records = []
        for target in targets:
            record = build_empty_record(target, "vm")
            record["record_error"] = f"guest batch exception: {exc}"
            built_records.append(record)

    for index, record in enumerate(built_records, start=1):
        records.append(sanitize_guest_batch_record(record))
        if guest_result_path is not None:
            write_guest_batch_records(guest_result_path, records)
            emit_guest_event("program_progress", index=index, total=len(targets))
        else:
            emit_guest_event("program_record", index=index, total=len(targets), record=record)
    return 0


def build_vng_command(*, vng_binary: str, kernel_image: Path, guest_exec: str) -> list[str]:
    command = build_runner_vng_command(
        kernel_path=kernel_image,
        guest_exec=guest_exec,
        cpus=int(DEFAULT_VNG_CPUS),
        mem=DEFAULT_VNG_MEMORY,
        target=DEFAULT_VM_TARGET,
        action="vm-corpus",
    )
    if vng_binary == DEFAULT_VNG:
        return command
    inner = command[command.index("--") + 1 :]
    inner[0] = vng_binary
    return command[: command.index("--") + 1] + inner


def build_guest_exec(argv: list[str]) -> str:
    # Load kinsn kernel modules before running the guest command so the daemon
    # can apply platform-specific rewrites (rotate, cond_select, extract).
    load_script = ROOT_DIR / "module" / "load_all.sh"
    kinsn_load = f"{shlex.quote(str(load_script))} 2>/dev/null || true; "
    main_cmd = " ".join(shlex.quote(part) for part in argv)
    return kinsn_load + main_cmd


def load_targets(
    inventory_json: Path,
    filters: list[str] | None,
    max_programs: int | None,
) -> tuple[list[dict[str, Any]], dict[str, Any]]:
    return load_packet_test_run_targets(
        inventory_json,
        filters=filters,
        max_programs=max_programs,
        require_inventory_sites=False,
    )


def run_targets_in_guest_batch(
    *,
    targets: list[dict[str, Any]],
    runner: Path,
    daemon: Path,
    kernel_image: Path,
    btf_custom_path: Path,
    repeat: int,
    timeout_seconds: int,
    vng_binary: str,
    skip_families: list[str],
    blind_apply: bool,
    on_guest_info: Callable[[dict[str, Any]], None] | None = None,
    on_record: Callable[[int, dict[str, Any]], None] | None = None,
) -> dict[str, Any]:
    handle = tempfile.NamedTemporaryFile(
        mode="w",
        prefix="corpus-rejit-vm-batch-",
        suffix=".json",
        dir=ROOT_DIR,
        delete=False,
    )
    result_handle = tempfile.NamedTemporaryFile(
        mode="w",
        prefix="corpus-rejit-vm-batch-result-",
        suffix=".json",
        dir=ROOT_DIR,
        delete=False,
    )
    try:
        guest_target_payload = {
            "targets": [
                {
                    **target,
                    "policy_mode": "blind-apply-rejit" if blind_apply else "daemon-auto",
                    "policy_path": None,
                }
                for target in targets
            ],
        }
        with handle:
            json.dump(guest_target_payload, handle)
            handle.write("\n")
        target_path = Path(handle.name)
        with result_handle:
            json.dump({"records": []}, result_handle)
            result_handle.write("\n")
        result_path = Path(result_handle.name)
        guest_argv = [
            "python3",
            str(DRIVER_RELATIVE),
            "packet",
            "--guest-target-json",
            str(target_path),
            "--guest-result-json",
            str(result_path),
            "--runner",
            str(runner),
            "--daemon",
            str(daemon),
            "--btf-custom-path",
            str(btf_custom_path),
            "--repeat",
            str(repeat),
            "--timeout",
            str(timeout_seconds),
        ]
        if skip_families:
            guest_argv.extend(["--skip-families", ",".join(skip_families)])
        if blind_apply:
            guest_argv.append("--blind-apply")
        guest_exec = build_guest_exec(guest_argv)
        command = build_vng_command(
            vng_binary=vng_binary,
            kernel_image=kernel_image,
            guest_exec=guest_exec,
        )
        timeout_limit = packet_batch_timeout_seconds(len(targets), timeout_seconds)
        start = time.monotonic()
        process = subprocess.Popen(
            command,
            cwd=ROOT_DIR,
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            text=True,
            bufsize=1,
        )
        selector = selectors.DefaultSelector()
        assert process.stdout is not None
        assert process.stderr is not None
        selector.register(process.stdout, selectors.EVENT_READ, data="stdout")
        selector.register(process.stderr, selectors.EVENT_READ, data="stderr")

        stdout_chunks: list[str] = []
        stderr_chunks: list[str] = []
        diagnostic_stdout_chunks: list[str] = []
        guest_info: dict[str, Any] | None = None
        emitted_records = 0
        timed_out = False
        guest_result_mtime_ns: int | None = None

        def sync_guest_records() -> None:
            nonlocal emitted_records, guest_result_mtime_ns
            if not result_path.exists():
                return
            stat = result_path.stat()
            if guest_result_mtime_ns == stat.st_mtime_ns:
                return
            guest_result_mtime_ns = stat.st_mtime_ns
            try:
                payload = json.loads(result_path.read_text())
            except json.JSONDecodeError:
                return
            records_payload = payload.get("records")
            if not isinstance(records_payload, list):
                return
            while emitted_records < len(records_payload):
                record = records_payload[emitted_records]
                emitted_records += 1
                if isinstance(record, dict) and on_record is not None:
                    on_record(emitted_records, record)

        while selector.get_map():
            remaining = timeout_limit - (time.monotonic() - start)
            if remaining <= 0:
                timed_out = True
                process.kill()
                break
            ready = selector.select(timeout=min(1.0, remaining))
            sync_guest_records()
            if not ready:
                continue
            for key, _ in ready:
                stream = key.fileobj
                line = stream.readline()
                if line == "":
                    selector.unregister(stream)
                    continue
                if key.data == "stdout":
                    stdout_chunks.append(line)
                    event = parse_guest_event(line)
                    if event is None:
                        diagnostic_stdout_chunks.append(line)
                        continue
                    if event["kind"] == "guest_info":
                        payload = event.get("payload")
                        if isinstance(payload, dict):
                            guest_info = payload
                            if on_guest_info is not None:
                                on_guest_info(payload)
                        continue
                    if event["kind"] == "program_record":
                        record = event.get("record")
                        if isinstance(record, dict):
                            emitted_records += 1
                            if on_record is not None:
                                on_record(emitted_records, record)
                        continue
                    if event["kind"] == "program_progress":
                        continue
                    diagnostic_stdout_chunks.append(line)
                else:
                    stderr_chunks.append(line)
        selector.close()

        try:
            process.wait(timeout=5)
        except subprocess.TimeoutExpired:
            process.kill()
            process.wait()

        remaining_stdout = process.stdout.read() if process.stdout is not None else ""
        remaining_stderr = process.stderr.read() if process.stderr is not None else ""
        if remaining_stdout:
            for line in remaining_stdout.splitlines(keepends=True):
                stdout_chunks.append(line)
                event = parse_guest_event(line)
                if event is None:
                    diagnostic_stdout_chunks.append(line)
                    continue
                if event["kind"] == "guest_info":
                    payload = event.get("payload")
                    if isinstance(payload, dict):
                        guest_info = payload
                        if on_guest_info is not None:
                            on_guest_info(payload)
                    continue
                if event["kind"] == "program_record":
                    record = event.get("record")
                    if isinstance(record, dict):
                        emitted_records += 1
                        if on_record is not None:
                            on_record(emitted_records, record)
                    continue
                if event["kind"] == "program_progress":
                    continue
                diagnostic_stdout_chunks.append(line)
        if remaining_stderr:
            stderr_chunks.append(remaining_stderr)
        sync_guest_records()

        stdout = "".join(stdout_chunks)
        stderr = "".join(stderr_chunks)
        ok = process.returncode == 0 and not timed_out and guest_info is not None and emitted_records == len(targets)
        error = None
        if timed_out:
            error = f"timeout after {timeout_limit}s"
        elif process.returncode != 0:
            error = extract_error(stderr, stdout, process.returncode)
        elif guest_info is None:
            error = "guest batch missing guest_info"
        elif emitted_records != len(targets):
            error = f"guest batch emitted {emitted_records}/{len(targets)} records"

        return {
            "invocation": {
                "ok": ok,
                "command": command,
                "returncode": process.returncode,
                "timed_out": timed_out,
                "duration_seconds": time.monotonic() - start,
                "stdout": stdout,
                "stderr": stderr,
                "diagnostic_stdout": "".join(diagnostic_stdout_chunks),
                "sample": None,
                "error": error,
            },
            "guest_info": guest_info,
            "records_emitted": emitted_records,
        }
    finally:
        Path(handle.name).unlink(missing_ok=True)
        Path(result_handle.name).unlink(missing_ok=True)


def build_summary(records: list[dict[str, Any]]) -> dict[str, Any]:
    compile_pairs = [
        record
        for record in records
        if record.get("baseline_compile") and record["baseline_compile"].get("ok")
        and record.get("rejit_compile") and record["rejit_compile"].get("ok")
    ]
    measured_pairs = [
        record
        for record in records
        if record.get("baseline_run") and record["baseline_run"].get("ok")
        and record.get("rejit_run") and record["rejit_run"].get("ok")
    ]
    applied_programs = [
        record
        for record in records
        if record.get("rejit_compile_applied") or record.get("rejit_run_applied")
    ]
    family_totals = Counter()
    for record in records:
        scan = normalize_scan(record.get("daemon_counts"))
        for _, field in FAMILY_FIELDS:
            family_totals[field] += scan[field]

    failure_reasons = Counter()
    rejit_failures = Counter()
    for record in records:
        if record.get("record_error"):
            failure_reasons[str(record["record_error"])] += 1
            continue
        baseline_compile = record.get("baseline_compile")
        rejit_compile = record.get("rejit_compile")
        baseline_run = record.get("baseline_run")
        rejit_run = record.get("rejit_run")
        if baseline_compile and not baseline_compile.get("ok"):
            failure_reasons[summarize_failure_reason(baseline_compile)] += 1
        if rejit_compile and not rejit_compile.get("ok"):
            failure_reasons[summarize_failure_reason(rejit_compile)] += 1
        if baseline_run and not baseline_run.get("ok"):
            failure_reasons[summarize_failure_reason(baseline_run)] += 1
        if rejit_run and not rejit_run.get("ok"):
            failure_reasons[summarize_failure_reason(rejit_run)] += 1
        if rejit_compile and rejit_compile.get("ok"):
            rejit = ((rejit_compile.get("sample") or {}).get("rejit") or {})
            if rejit.get("requested") and not rejit.get("applied") and rejit.get("error"):
                rejit_failures[str(rejit["error"])] += 1
        if rejit_run and rejit_run.get("ok"):
            rejit = ((rejit_run.get("sample") or {}).get("rejit") or {})
            if rejit.get("requested") and not rejit.get("applied") and rejit.get("error"):
                rejit_failures[str(rejit["error"])] += 1

    size_ratios = [record["size_ratio"] for record in compile_pairs if record.get("size_ratio") is not None]
    exec_ratios = [record["speedup_ratio"] for record in measured_pairs if record.get("speedup_ratio") is not None]
    regressions = [record for record in measured_pairs if (record.get("speedup_ratio") or 0) < 1.0]
    improvements = [record for record in measured_pairs if (record.get("speedup_ratio") or 0) > 1.0]

    by_source: list[dict[str, Any]] = []
    grouped_sources: dict[str, list[dict[str, Any]]] = defaultdict(list)
    for record in records:
        grouped_sources[record["source_name"]].append(record)
    for source_name, items in grouped_sources.items():
        source_compile = [item for item in items if item in compile_pairs]
        source_measured = [item for item in items if item in measured_pairs]
        source_size = [item["size_ratio"] for item in source_compile if item.get("size_ratio") is not None]
        source_exec = [item["speedup_ratio"] for item in source_measured if item.get("speedup_ratio") is not None]
        counts = Counter()
        for item in items:
            scan = normalize_scan(item.get("daemon_counts"))
            for _, field in FAMILY_FIELDS:
                counts[field] += scan[field]
        source_row = {
            "source_name": source_name,
            "programs": len(items),
            "compile_pairs": len(source_compile),
            "measured_pairs": len(source_measured),
            "applied_programs": sum(1 for item in items if item.get("rejit_compile_applied") or item.get("rejit_run_applied")),
            "total_sites": sum(counts[field] for _, field in FAMILY_FIELDS),
            "code_size_ratio_geomean": geomean(source_size),
            "exec_ratio_geomean": geomean(source_exec),
            "wins": sum(1 for item in source_measured if (item.get("speedup_ratio") or 0) > 1.0),
            "regressions": sum(1 for item in source_measured if (item.get("speedup_ratio") or 0) < 1.0),
        }
        for _, field in FAMILY_FIELDS:
            source_row[field] = counts[field]
        by_source.append(source_row)
    by_source.sort(key=lambda item: (-item["programs"], item["source_name"]))

    by_family: list[dict[str, Any]] = []
    for family_name, field in FAMILY_FIELDS:
        items = [record for record in records if normalize_scan(record.get("daemon_counts"))[field] > 0]
        family_compile = [item for item in items if item in compile_pairs]
        family_measured = [item for item in items if item in measured_pairs]
        family_size = [item["size_ratio"] for item in family_compile if item.get("size_ratio") is not None]
        family_exec = [item["speedup_ratio"] for item in family_measured if item.get("speedup_ratio") is not None]
        applied_items = [
            item
            for item in items
            if family_name in item.get("applied_families_compile", [])
            or family_name in item.get("applied_families_run", [])
        ]
        by_family.append(
            {
                "family_name": family_name,
                "programs": len(items),
                "compile_pairs": len(family_compile),
                "measured_pairs": len(family_measured),
                "applied_programs": len(applied_items),
                "total_sites": sum(normalize_scan(item.get("daemon_counts"))[field] for item in items),
                "applied_sites": sum(normalize_scan(item.get("daemon_counts"))[field] for item in applied_items),
                "code_size_ratio_geomean": geomean(family_size),
                "exec_ratio_geomean": geomean(family_exec),
                "wins": sum(1 for item in family_measured if (item.get("speedup_ratio") or 0) > 1.0),
                "regressions": sum(1 for item in family_measured if (item.get("speedup_ratio") or 0) < 1.0),
            }
        )
    by_family.sort(key=lambda item: (-item["total_sites"], item["family_name"]))

    top_speedups = sorted(
        improvements,
        key=lambda item: (-(item.get("speedup_ratio") or 0), item["source_name"], program_label(item)),
    )[:10]
    top_regressions = sorted(
        regressions,
        key=lambda item: ((item.get("speedup_ratio") or math.inf), item["source_name"], program_label(item)),
    )[:10]
    top_code_shrinks = sorted(
        [record for record in compile_pairs if (record.get("size_ratio") or 0) > 1.0],
        key=lambda item: (-(item.get("size_ratio") or 0), item["source_name"], program_label(item)),
    )[:10]

    return {
        "effective_mode": "vm",
        "targets_attempted": len(records),
        "compile_pairs": len(compile_pairs),
        "measured_pairs": len(measured_pairs),
        "applied_programs": len(applied_programs),
        "code_size_ratio_geomean": geomean(size_ratios),
        "code_size_delta_median_pct": statistics.median([record["size_delta_pct"] for record in compile_pairs if record.get("size_delta_pct") is not None]) if compile_pairs else None,
        "exec_ratio_geomean": geomean(exec_ratios),
        "exec_ratio_median": statistics.median(exec_ratios) if exec_ratios else None,
        "exec_ratio_min": min(exec_ratios) if exec_ratios else None,
        "exec_ratio_max": max(exec_ratios) if exec_ratios else None,
        "improvements": len(improvements),
        "regressions": len(regressions),
        "family_totals": dict(family_totals),
        "failure_reasons": dict(failure_reasons.most_common(16)),
        "rejit_failure_reasons": dict(rejit_failures.most_common(16)),
        "by_source": by_source,
        "by_family": by_family,
        "top_speedups": [
            {
                "program": program_label(record),
                "source_name": record["source_name"],
                "prog_type_name": record["prog_type_name"],
                "speedup_ratio": record.get("speedup_ratio"),
                "families": record.get("applied_families_run") or record.get("eligible_families", []),
            }
            for record in top_speedups
        ],
        "top_regressions": [
            {
                "program": program_label(record),
                "source_name": record["source_name"],
                "prog_type_name": record["prog_type_name"],
                "speedup_ratio": record.get("speedup_ratio"),
                "families": record.get("applied_families_run") or record.get("eligible_families", []),
            }
            for record in top_regressions
        ],
        "top_code_shrinks": [
            {
                "program": program_label(record),
                "source_name": record["source_name"],
                "prog_type_name": record["prog_type_name"],
                "size_ratio": record.get("size_ratio"),
                "families": record.get("applied_families_compile") or record.get("eligible_families", []),
            }
            for record in top_code_shrinks
        ],
    }


def build_markdown(data: dict[str, Any]) -> str:
    summary = data["summary"]
    records = sorted(data["programs"], key=lambda item: (item["source_name"], item["object_path"], item["program_name"]))
    build_summary_data = data.get("kernel_build") or {}
    guest_info = (data.get("guest_smoke") or {}).get("payload")
    family_headers = [FAMILY_DISPLAY_NAMES[name] for name, _ in FAMILY_FIELDS]
    lines: list[str] = [
        "# Corpus Batch REJIT Results",
        "",
        f"- Generated: {data['generated_at']}",
        f"- Inventory: `{data['inventory_json']}`",
        f"- Runner: `{data['runner_binary']}`",
        f"- Daemon: `{data['daemon_binary']}`",
        "- Requested mode: `strict-vm`",
        f"- Effective mode: `{summary['effective_mode']}`",
        f"- Repeat: {data['repeat']}",
        f"- Skip families: `{', '.join(data.get('skip_families') or []) or 'none'}`",
        f"- Target programs: {summary['targets_attempted']}",
        f"- Compile pairs: {summary['compile_pairs']}",
        f"- Measured pairs: {summary['measured_pairs']}",
        f"- REJIT applied programs: {summary['applied_programs']}",
        f"- Code-size ratio geomean (baseline/rejit): {format_ratio(summary['code_size_ratio_geomean'])}",
        f"- Exec-time ratio geomean (baseline/rejit): {format_ratio(summary['exec_ratio_geomean'])}",
        f"- Total sites: {sum(summary['family_totals'].get(field, 0) for _, field in FAMILY_FIELDS)}",
        *[
            f"- {FAMILY_DISPLAY_NAMES[name]} sites: {summary['family_totals'].get(field, 0)}"
            for name, field in FAMILY_FIELDS
        ],
    ]
    if build_summary_data:
        lines.append(
            f"- Kernel build: {'ok' if build_summary_data.get('ok') else 'failed'} "
            f"({build_summary_data.get('duration_seconds', 0):.2f}s)"
        )
    if guest_info:
        lines.append(f"- Guest kernel: `{guest_info.get('kernel_release', 'unknown')}`")
    lines.append("")

    lines.extend(["## By Project", ""])
    lines.extend(
        markdown_table(
            [
                "Project",
                "Programs",
                "Compile Pairs",
                "Measured Pairs",
                "Applied",
                *family_headers,
                "Code Ratio",
                "Exec Ratio",
                "Regressions",
            ],
            [
                [
                    row["source_name"],
                    row["programs"],
                    row["compile_pairs"],
                    row["measured_pairs"],
                    row["applied_programs"],
                    *[row[field] for _, field in FAMILY_FIELDS],
                    format_ratio(row["code_size_ratio_geomean"]),
                    format_ratio(row["exec_ratio_geomean"]),
                    row["regressions"],
                ]
                for row in summary["by_source"]
            ],
        )
    )
    lines.append("")

    lines.extend(["## By Family", ""])
    lines.extend(
        markdown_table(
            ["Family", "Programs", "Applied", "Sites", "Applied Sites", "Compile Pairs", "Measured Pairs", "Code Ratio", "Exec Ratio", "Regressions"],
            [
                [
                    row["family_name"],
                    row["programs"],
                    row["applied_programs"],
                    row["total_sites"],
                    row["applied_sites"],
                    row["compile_pairs"],
                    row["measured_pairs"],
                    format_ratio(row["code_size_ratio_geomean"]),
                    format_ratio(row["exec_ratio_geomean"]),
                    row["regressions"],
                ]
                for row in summary["by_family"]
            ],
        )
    )
    lines.append("")

    if summary["top_speedups"]:
        lines.extend(["## Top Speedups", ""])
        lines.extend(
            markdown_table(
                ["Program", "Project", "Type", "Exec Ratio", "Families"],
                [
                    [
                        row["program"],
                        row["source_name"],
                        row["prog_type_name"],
                        format_ratio(row["speedup_ratio"]),
                        ", ".join(row["families"]),
                    ]
                    for row in summary["top_speedups"]
                ],
            )
        )
        lines.append("")

    if summary["top_regressions"]:
        lines.extend(["## Regressions", ""])
        lines.extend(
            markdown_table(
                ["Program", "Project", "Type", "Exec Ratio", "Families"],
                [
                    [
                        row["program"],
                        row["source_name"],
                        row["prog_type_name"],
                        format_ratio(row["speedup_ratio"]),
                        ", ".join(row["families"]),
                    ]
                    for row in summary["top_regressions"]
                ],
            )
        )
        lines.append("")

    if summary["top_code_shrinks"]:
        lines.extend(["## Largest Code Shrinks", ""])
        lines.extend(
            markdown_table(
                ["Program", "Project", "Type", "Code Ratio", "Families"],
                [
                    [
                        row["program"],
                        row["source_name"],
                        row["prog_type_name"],
                        format_ratio(row["size_ratio"]),
                        ", ".join(row["families"]),
                    ]
                    for row in summary["top_code_shrinks"]
                ],
            )
        )
        lines.append("")

    lines.extend(["## Per-Program Results", ""])
    lines.extend(
        markdown_table(
            [
                "Program",
                "Project",
                "Type",
                "Sites",
                "Applied Families",
                "Baseline JIT",
                "REJIT JIT",
                "Code Ratio",
                "Baseline ns",
                "REJIT ns",
                "Exec Ratio",
                "Note",
            ],
            [
                [
                    program_label(record),
                    record["source_name"],
                    record["prog_type_name"],
                    normalize_scan(record.get("daemon_counts"))["total_sites"],
                    ", ".join(record.get("applied_families_run") or record.get("applied_families_compile") or []),
                    format_ns(((record.get("baseline_compile") or {}).get("sample") or {}).get("jited_prog_len")),
                    format_ns(((record.get("rejit_compile") or {}).get("sample") or {}).get("jited_prog_len")),
                    format_ratio(record.get("size_ratio")),
                    format_ns(((record.get("baseline_run") or {}).get("sample") or {}).get("exec_ns")),
                    format_ns(((record.get("rejit_run") or {}).get("sample") or {}).get("exec_ns")),
                    format_ratio(record.get("speedup_ratio")),
                    record.get("record_error")
                    or (
                        summarize_failure_reason(record.get("rejit_compile"))
                        if record.get("rejit_compile") and not record["rejit_compile"].get("ok")
                        else ""
                    ),
                ]
                for record in records
            ],
        )
    )

    if summary["failure_reasons"]:
        lines.extend(["", "## Top Failure Reasons", ""])
        lines.extend(
            markdown_table(
                ["Reason", "Count"],
                [[reason, count] for reason, count in summary["failure_reasons"].items()],
            )
        )

    if summary["rejit_failure_reasons"]:
        lines.extend(["", "## REJIT Failures", ""])
        lines.extend(
            markdown_table(
                ["Reason", "Count"],
                [[reason, count] for reason, count in summary["rejit_failure_reasons"].items()],
            )
        )

    lines.extend(
        [
            "",
            "## Notes",
            "",
            "- Target selection comes from the runnability inventory and keeps every packet-test-run target whose baseline run already succeeds; the current daemon pass determines whether REJIT has any eligible families.",
            "- In strict VM mode, the framework REJIT guest boots once, keeps `daemon serve` alive for the full batch, and runs baseline compile-only, REJIT compile-only, baseline test_run, and REJIT test_run for each target in that order.",
            "- Default steady-state semantics: the daemon is always started and tries to optimize each program; programs with no applicable sites stay on stock JIT.",
            "- `--blind-apply` switches from per-program policy mode to unconditional daemon auto-scan REJIT.",
            "- `--skip-families` only applies together with `--blind-apply`; the family columns above report applied families, not just eligible sites.",
            "- The Make-driven `vm-corpus` path is strict VM-only: guest batch failures fail the run instead of falling back to host execution.",
            "- Family summaries are overlap-based: one program can contribute to multiple family rows, so those rows are not isolated causal attributions.",
        ]
    )
    return "\n".join(lines) + "\n"


def packet_main(argv: list[str] | None = None) -> int:
    args = parse_packet_args(argv)
    require_minimum(args.repeat, 1, "--repeat")
    skip_families = normalize_skip_families(args.skip_families)
    if skip_families and not args.blind_apply:
        raise SystemExit("--skip-families requires --blind-apply")

    if args.guest_info:
        return run_guest_info_mode()
    if args.guest_target_json:
        return run_guest_batch_mode(args)

    inventory_json = Path(args.inventory_json).resolve()
    if args.output_json == str(DEFAULT_OUTPUT_JSON) and args.max_programs is not None:
        output_json = smoke_output_path(ROOT_DIR / "corpus" / "results", "corpus_vm_batch")
    else:
        output_json = Path(args.output_json).resolve()
    output_md = Path(args.output_md).resolve()
    runner = Path(args.runner).resolve()
    daemon = Path(args.daemon).resolve()
    kernel_tree = Path(args.kernel_tree).resolve()
    kernel_image = Path(args.kernel_image).resolve()
    btf_custom_path = Path(args.btf_custom_path).resolve() if args.btf_custom_path else None

    if not inventory_json.exists():
        raise SystemExit(f"inventory JSON not found: {inventory_json}")
    if not runner.exists():
        raise SystemExit(f"runner not found: {runner}")
    if not daemon.exists():
        raise SystemExit(f"daemon not found: {daemon}")

    run_type = derive_run_type(output_json, "corpus_vm_batch")
    started_at = datetime.now(timezone.utc).isoformat()

    targets, inventory_summary = load_targets(
        inventory_json=inventory_json,
        filters=args.filters,
        max_programs=args.max_programs,
    )

    if not kernel_image.exists():
        raise SystemExit(f"kernel image missing: {kernel_image}")
    if btf_custom_path is None or not btf_custom_path.exists():
        raise SystemExit(f"btf path missing: {btf_custom_path}")

    guest_smoke: dict[str, Any] = {"invocation": None, "payload": None}
    records: list[dict[str, Any]] = []
    result = {
        "generated_at": started_at,
        "repo_root": str(ROOT_DIR),
        "inventory_json": str(inventory_json),
        "inventory_summary": inventory_summary,
        "runner_binary": str(runner),
        "daemon_binary": str(daemon),
        "kernel_tree": str(kernel_tree),
        "kernel_image": str(kernel_image),
        "btf_custom_path": str(btf_custom_path) if btf_custom_path is not None else None,
        "vng_binary": args.vng,
        "repeat": args.repeat,
        "timeout_seconds": args.timeout,
        "guest_smoke": guest_smoke,
        "skip_families": skip_families,
        "blind_apply": args.blind_apply,
        "summary": build_summary(records),
        "programs": records,
    }
    current_target: dict[str, Any] | None = None
    current_target_index: int | None = None

    def build_artifact_metadata(
        status: str,
        session_started_at: str,
        updated_at: str,
        error_message: str | None,
    ) -> dict[str, Any]:
        result["summary"] = build_summary(records)
        progress = {
            "status": status,
            "total_programs": len(targets),
            "completed_programs": len(records),
            "current_target_index": current_target_index,
            "current_target": current_target,
        }
        if error_message:
            progress["error_message"] = error_message

        metadata = build_corpus_artifact_metadata(
            generated_at=str(result["generated_at"]),
            run_type=run_type,
            mode_name="packet",
            output_json=output_json,
            output_md=output_md,
            summary=dict(result["summary"]),
            progress=progress,
            extra_fields={
                "inventory_json": repo_relative_path(inventory_json),
                "inventory_summary": inventory_summary,
                "runner_binary": repo_relative_path(runner),
                "daemon_binary": repo_relative_path(daemon),
                "kernel_tree": repo_relative_path(kernel_tree),
                "kernel_image": repo_relative_path(kernel_image),
                "btf_custom_path": repo_relative_path(btf_custom_path) if btf_custom_path is not None else None,
                "vng_binary": args.vng,
                "repeat": args.repeat,
                "timeout_seconds": args.timeout,
                "skip_families": skip_families,
                "blind_apply": bool(args.blind_apply),
                "guest_smoke": guest_smoke,
                "started_at": session_started_at,
                "last_updated_at": updated_at,
                "status": status,
            },
        )
        if error_message:
            metadata["error_message"] = error_message
        return metadata

    session = ArtifactSession(
        output_path=output_json,
        run_type=run_type,
        generated_at=started_at,
        metadata_builder=build_artifact_metadata,
    )
    artifact_dir = session.run_dir

    def flush_artifact(status: str, *, error_message: str | None = None, include_markdown: bool = False) -> None:
        result["summary"] = build_summary(records)
        progress = {
            "status": status,
            "total_programs": len(targets),
            "completed_programs": len(records),
            "current_target_index": current_target_index,
            "current_target": current_target,
        }
        if error_message:
            progress["error_message"] = error_message
        detail_texts = {"result.md": build_markdown(result)} if include_markdown else None
        session.write(
            status=status,
            progress_payload=progress,
            result_payload=result,
            detail_texts=detail_texts,
            error_message=error_message,
        )

    flush_artifact("running")
    try:
        def handle_guest_info(payload: dict[str, Any]) -> None:
            guest_smoke["payload"] = payload
            flush_artifact("running")

        def handle_guest_record(index: int, record: dict[str, Any]) -> None:
            nonlocal current_target_index, current_target
            current_target_index = index
            current_target = targets[index - 1] if index - 1 < len(targets) else None
            records.append(record)
            flush_artifact("running")

        batch_result = run_targets_in_guest_batch(
            targets=targets,
            runner=runner,
            daemon=daemon,
            kernel_image=kernel_image,
            btf_custom_path=btf_custom_path,
            repeat=args.repeat,
            timeout_seconds=args.timeout,
            vng_binary=args.vng,
            skip_families=skip_families,
            blind_apply=args.blind_apply,
            on_guest_info=handle_guest_info,
            on_record=handle_guest_record,
        )
        guest_invocation = batch_text_invocation_summary(batch_result["invocation"])
        guest_smoke["invocation"] = guest_invocation
        for record in records:
            record["guest_invocation"] = dict(guest_invocation) if guest_invocation is not None else None

        if not guest_smoke.get("payload"):
            smoke_error = (guest_smoke.get("invocation") or {}).get("error") or "guest smoke failed"
            raise RuntimeError(f"vm guest smoke failed: {smoke_error}")
        if not batch_result["invocation"]["ok"]:
            batch_error = batch_result["invocation"]["error"] or "guest batch failed"
            raise RuntimeError(f"vm guest batch failed: {batch_error}")

        current_target = None
        current_target_index = None
        flush_artifact("completed", include_markdown=True)
    except Exception as exc:
        flush_artifact("error", error_message=str(exc))
        raise
    summary = dict(result["summary"])
    print(f"Wrote {artifact_dir / 'metadata.json'}")
    print(
        f"mode={summary['effective_mode']} "
        f"targets={summary['targets_attempted']} "
        f"compile_pairs={summary['compile_pairs']} "
        f"measured_pairs={summary['measured_pairs']} "
        f"applied={summary['applied_programs']}"
    )
    return 0


def _mode_defaults(mode_name: str) -> tuple[Path, Path]:
    if mode_name == "perf":
        return DEFAULT_PERF_OUTPUT_JSON, DEFAULT_PERF_OUTPUT_MD
    if mode_name == "tracing":
        return DEFAULT_TRACING_OUTPUT_JSON, DEFAULT_TRACING_OUTPUT_MD
    if mode_name == "code-size":
        return DEFAULT_CODE_SIZE_OUTPUT_JSON, DEFAULT_CODE_SIZE_OUTPUT_MD
    raise SystemExit(f"unsupported mode: {mode_name}")


def parse_linear_mode_args(mode_name: str, argv: list[str] | None = None) -> argparse.Namespace:
    default_output_json, default_output_md = _mode_defaults(mode_name)
    description = {
        "perf": "Measure corpus programs locally with stock vs REJIT runs when test_run is supported.",
        "tracing": "Inspect tracing-style corpus programs with stock vs REJIT compile-only passes.",
        "code-size": "Compare stock vs REJIT code size for the discovered corpus programs.",
    }[mode_name]
    parser = argparse.ArgumentParser(description=description)
    add_output_json_argument(parser, default_output_json)
    add_output_md_argument(parser, default_output_md)
    add_runner_argument(parser, DEFAULT_RUNNER, help_text="Path to micro_exec.")
    add_daemon_argument(parser, DEFAULT_DAEMON, help_text="Path to bpfrejit-daemon.")
    add_repeat_argument(parser, DEFAULT_REPEAT, help_text="Repeat count passed to each micro_exec invocation.")
    add_timeout_argument(parser, DEFAULT_TIMEOUT_SECONDS, help_text="Per-target timeout in seconds.")
    add_filter_argument(
        parser,
        help_text="Only include targets whose object path, program name, or section name contains this substring. Repeatable.",
    )
    add_max_programs_argument(parser, help_text="Optional cap for smoke testing.")
    add_corpus_build_report_argument(
        parser,
        help_text="Optional expanded corpus build JSON report used to discover object files.",
    )
    parser.add_argument(
        "--kind",
        action="append",
        dest="kinds",
        help="Restrict processing to inferred program kinds such as xdp, tc, socket, tracing, or perf_event.",
    )
    parser.add_argument(
        "--btf-custom-path",
        default=str(DEFAULT_HOST_BTF_PATH) if DEFAULT_HOST_BTF_PATH.exists() else None,
        help="Host BTF path passed to micro_exec compile/load invocations when available.",
    )
    parser.add_argument(
        "--skip-families",
        action="append",
        help="Comma-separated REJIT families to skip from blind auto-scan apply mode.",
    )
    parser.add_argument(
        "--blind-apply",
        action="store_true",
        help="Ignore per-program policies and force blind all-apply auto-scan REJIT.",
    )
    return parser.parse_args(argv)


def _source_name_for_object(relative_object_path: str) -> str:
    path = Path(relative_object_path)
    parts = path.parts
    if len(parts) >= 3 and parts[0] == "corpus" and parts[1] == "build":
        return parts[2]
    if len(parts) >= 3 and parts[0] == "corpus" and parts[1] in {"repos", "bcf"}:
        return parts[2]
    return path.parent.name or "corpus"


def discover_linear_targets(
    *,
    runner: Path,
    mode_name: str,
    filters: list[str] | None,
    kinds: list[str] | None,
    max_programs: int | None,
    corpus_build_report: Path | None,
) -> tuple[list[dict[str, Any]], dict[str, Any]]:
    packet_path = materialize_dummy_packet(ROOT_DIR / "corpus" / "inputs" / "macro_dummy_packet_64.bin")
    context_path = materialize_dummy_context(ROOT_DIR / "corpus" / "inputs" / "macro_dummy_context_64.bin")
    lowered_filters = [item.lower() for item in filters or []]
    requested_kinds = {item.lower() for item in kinds or []}
    discovery = discover_corpus_objects(ROOT_DIR, corpus_build_report=corpus_build_report)
    targets: list[dict[str, Any]] = []
    inventory_failures: list[dict[str, Any]] = []

    for object_path in discovery.corpus_paths:
        rel_object = object_path.relative_to(ROOT_DIR).as_posix()
        try:
            programs = discover_object_programs(runner, object_path)
        except Exception as exc:
            inventory_failures.append({"object_path": rel_object, "error": str(exc)})
            continue

        for program in programs:
            kind = infer_program_kind(program.section_name)
            if mode_name == "tracing":
                if kind != "tracing":
                    continue
            elif mode_name == "perf" and kind == "tracing":
                continue
            if requested_kinds and kind not in requested_kinds:
                continue
            haystack = " ".join(
                [
                    rel_object.lower(),
                    program.name.lower(),
                    program.section_name.lower(),
                    kind.lower(),
                ]
            )
            if lowered_filters and not any(item in haystack for item in lowered_filters):
                continue

            plan = execution_plan(program.section_name, packet_path, context_path)
            can_test_run = kind not in {"tracing", "perf_event", "iter", "struct_ops", "syscall"}
            targets.append(
                {
                    "object_path": rel_object,
                    "source_name": _source_name_for_object(rel_object),
                    "program_name": program.name,
                    "section_name": program.section_name,
                    "section_root": program.section_name.split("/", 1)[0],
                    "prog_type_name": program.prog_type_name,
                    "io_mode": str(plan["io_mode"]),
                    "input_size": int(plan["input_size"]),
                    "memory_path": str(plan["memory_path"]) if plan["memory_path"] is not None else None,
                    "can_test_run": can_test_run,
                    "inventory_scan": {},
                }
            )
            if max_programs is not None and len(targets) >= max_programs:
                return targets, {
                    "discovery_source": discovery.corpus_source,
                    "inventory_failures": inventory_failures,
                    "skipped_non_bpf": list(discovery.skipped_non_bpf),
                }

    return targets, {
        "discovery_source": discovery.corpus_source,
        "inventory_failures": inventory_failures,
        "skipped_non_bpf": list(discovery.skipped_non_bpf),
    }


def build_linear_summary(
    records: list[dict[str, Any]],
    *,
    mode_name: str,
    enable_exec: bool,
) -> dict[str, Any]:
    compile_pairs = sum(
        1
        for record in records
        if (record.get("baseline_compile") or {}).get("ok")
        and (record.get("rejit_compile") or {}).get("ok")
    )
    measured_pairs = sum(
        1
        for record in records
        if enable_exec
        and (record.get("baseline_run") or {}).get("ok")
        and (record.get("rejit_run") or {}).get("ok")
    )
    applied_programs = sum(
        1 for record in records if record.get("rejit_compile_applied") or record.get("rejit_run_applied")
    )
    size_ratios = [float(record["size_ratio"]) for record in records if record.get("size_ratio")]
    speedup_ratios = [float(record["speedup_ratio"]) for record in records if record.get("speedup_ratio")]
    errors = Counter(
        str(record.get("record_error") or "")
        for record in records
        if record.get("record_error")
    )
    return {
        "mode": mode_name,
        "targets_attempted": len(records),
        "compile_pairs": compile_pairs,
        "measured_pairs": measured_pairs,
        "applied_programs": applied_programs,
        "size_ratio_geomean": geomean(size_ratios),
        "speedup_ratio_geomean": geomean(speedup_ratios) if enable_exec else None,
        "record_errors": dict(errors),
    }


def build_linear_markdown(
    payload: dict[str, Any],
    *,
    mode_name: str,
    enable_exec: bool,
) -> str:
    summary = payload["summary"]
    title = {
        "perf": "Corpus Perf Mode",
        "tracing": "Corpus Tracing Mode",
        "code-size": "Corpus Code-Size Mode",
    }[mode_name]
    lines = [
        f"# {title}",
        "",
        f"- Generated: `{payload['generated_at']}`",
        f"- Runner: `{payload['runner_binary']}`",
        f"- Daemon: `{payload['daemon_binary']}`",
        f"- Targets attempted: `{summary['targets_attempted']}`",
        f"- Compile pairs: `{summary['compile_pairs']}`",
        f"- Measured pairs: `{summary['measured_pairs']}`",
        f"- Applied programs: `{summary['applied_programs']}`",
        f"- Native code size geomean ratio: `{format_ratio(summary['size_ratio_geomean'])}`",
    ]
    if enable_exec:
        lines.append(f"- Exec speedup geomean: `{format_ratio(summary['speedup_ratio_geomean'])}`")
    else:
        lines.append("- Exec speedup geomean: `n/a`")
    if mode_name == "tracing":
        lines.append("- Tracing mode uses compile-only inspection in the consolidated driver.")

    rows = []
    for record in payload["programs"]:
        rows.append(
            [
                record["source_name"],
                record["program_name"],
                record["section_name"],
                format_ratio(record.get("size_ratio")),
                format_ratio(record.get("speedup_ratio")) if enable_exec else "n/a",
                "yes" if record.get("rejit_compile_applied") or record.get("rejit_run_applied") else "no",
                record.get("record_error") or "",
            ]
        )

    if rows:
        lines.extend(
            [
                "",
                "## Records",
                "",
                *markdown_table(
                    ["Source", "Program", "Section", "Size Ratio", "Speedup", "Applied", "Error"],
                    rows,
                ),
            ]
        )

    if summary["record_errors"]:
        lines.extend(["", "## Record Errors", ""])
        lines.extend(
            markdown_table(
                ["Reason", "Count"],
                [[reason, count] for reason, count in summary["record_errors"].items()],
            )
        )

    return "\n".join(lines) + "\n"


def run_linear_mode(mode_name: str, argv: list[str] | None = None) -> int:
    args = parse_linear_mode_args(mode_name, argv)
    require_minimum(args.repeat, 1, "--repeat")
    skip_families = normalize_skip_families(args.skip_families)
    if skip_families and not args.blind_apply:
        raise SystemExit("--skip-families requires --blind-apply")

    runner = Path(args.runner).resolve()
    daemon = Path(args.daemon).resolve()
    if not runner.exists():
        raise SystemExit(f"runner not found: {runner}")
    if not daemon.exists():
        raise SystemExit(f"daemon not found: {daemon}")

    output_json = Path(args.output_json).resolve()
    output_md = Path(args.output_md).resolve()
    run_type = derive_run_type(output_json, mode_name)
    started_at = datetime.now(timezone.utc).isoformat()

    btf_custom_path = Path(args.btf_custom_path).resolve() if args.btf_custom_path else None
    corpus_build_report = Path(args.corpus_build_report).resolve() if args.corpus_build_report else None
    targets, discovery_summary = discover_linear_targets(
        runner=runner,
        mode_name=mode_name,
        filters=args.filters,
        kinds=args.kinds,
        max_programs=args.max_programs,
        corpus_build_report=corpus_build_report,
    )

    enable_exec = mode_name == "perf"
    records: list[dict[str, Any]] = []
    payload = {
        "generated_at": started_at,
        "mode": mode_name,
        "repo_root": str(ROOT_DIR),
        "runner_binary": str(runner),
        "daemon_binary": str(daemon),
        "btf_custom_path": str(btf_custom_path) if btf_custom_path is not None else None,
        "repeat": args.repeat,
        "timeout_seconds": args.timeout,
        "skip_families": skip_families,
        "blind_apply": args.blind_apply,
        "corpus_build_report": str(corpus_build_report) if corpus_build_report is not None else None,
        "discovery": discovery_summary,
        "summary": build_linear_summary(records, mode_name=mode_name, enable_exec=enable_exec),
        "programs": records,
    }
    current_target: dict[str, Any] | None = None
    current_target_index: int | None = None

    def build_artifact_metadata(
        status: str,
        session_started_at: str,
        updated_at: str,
        error_message: str | None,
    ) -> dict[str, Any]:
        payload["summary"] = build_linear_summary(records, mode_name=mode_name, enable_exec=enable_exec)
        progress = {
            "status": status,
            "total_programs": len(targets),
            "completed_programs": len(records),
            "current_target_index": current_target_index,
            "current_target": current_target,
        }
        if error_message:
            progress["error_message"] = error_message

        metadata = build_corpus_artifact_metadata(
            generated_at=str(payload["generated_at"]),
            run_type=run_type,
            mode_name=mode_name,
            output_json=output_json,
            output_md=output_md,
            summary=dict(payload["summary"]),
            progress=progress,
            extra_fields={
                "runner_binary": repo_relative_path(runner),
                "daemon_binary": repo_relative_path(daemon),
                "btf_custom_path": repo_relative_path(btf_custom_path) if btf_custom_path is not None else None,
                "repeat": args.repeat,
                "timeout_seconds": args.timeout,
                "skip_families": skip_families,
                "blind_apply": bool(args.blind_apply),
                "corpus_build_report": repo_relative_path(corpus_build_report) if corpus_build_report is not None else None,
                "discovery": discovery_summary,
                "enable_exec": enable_exec,
                "started_at": session_started_at,
                "last_updated_at": updated_at,
                "status": status,
            },
        )
        if error_message:
            metadata["error_message"] = error_message
        return metadata

    session = ArtifactSession(
        output_path=output_json,
        run_type=run_type,
        generated_at=started_at,
        metadata_builder=build_artifact_metadata,
    )
    artifact_dir = session.run_dir

    def flush_artifact(status: str, *, error_message: str | None = None, include_markdown: bool = False) -> None:
        payload["summary"] = build_linear_summary(records, mode_name=mode_name, enable_exec=enable_exec)
        progress = {
            "status": status,
            "total_programs": len(targets),
            "completed_programs": len(records),
            "current_target_index": current_target_index,
            "current_target": current_target,
        }
        if error_message:
            progress["error_message"] = error_message
        detail_texts = {
            "result.md": build_linear_markdown(payload, mode_name=mode_name, enable_exec=enable_exec)
        } if include_markdown else None
        session.write(
            status=status,
            progress_payload=progress,
            result_payload=payload,
            detail_texts=detail_texts,
            error_message=error_message,
        )

    flush_artifact("running")
    try:
        built_records, batch_invocation = run_targets_locally_batch(
            targets=targets,
            runner=runner,
            daemon=daemon,
            repeat=args.repeat,
            timeout_seconds=args.timeout,
            execution_mode=mode_name,
            btf_custom_path=btf_custom_path,
            enable_recompile=True,
            enable_exec=enable_exec,
            skip_families=skip_families,
            blind_apply=args.blind_apply,
        )
        if not batch_invocation["ok"]:
            raise RuntimeError(batch_invocation["error"] or "corpus batch runner failed")

        for index, (target, record) in enumerate(zip(targets, built_records, strict=True), start=1):
            current_target_index = index
            current_target = target
            records.append(record)
            flush_artifact("running")

        current_target = None
        current_target_index = None
        flush_artifact("completed", include_markdown=True)
    except Exception as exc:
        flush_artifact("error", error_message=str(exc))
        raise

    print(f"Wrote {artifact_dir / 'metadata.json'}")
    return 0
