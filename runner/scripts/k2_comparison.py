#!/usr/bin/env python3
from __future__ import annotations

import argparse
import json
import math
import os
import sys
import traceback
from collections import Counter
from dataclasses import replace
from datetime import datetime, timezone
from pathlib import Path
from typing import Any, Mapping

if __package__ in {None, ""}:
    sys.path.insert(0, str(Path(__file__).resolve().parents[2]))

from runner.libs import ROOT_DIR, docs_tmp_dir, scratch_date_stamp, tail_text, write_json, write_text  # noqa: E402
from runner.libs.batch_runner import run_batch_runner  # noqa: E402
from runner.libs.corpus import (  # noqa: E402
    ResolvedObject,
    ResolvedProgram,
    batch_job_invocation_summary,
    batch_job_result_map,
    build_test_run_batch_job,
    deserialize_resolved_object,
    format_ns,
    format_ratio,
    load_corpus_build_report,
    load_targets_from_yaml,
    markdown_table,
    packet_batch_timeout_seconds,
    program_load_names,
    relpath,
    runtime_for_program,
    sanitize_guest_batch_record,
    serialize_resolved_object,
)
from runner.libs.k2 import optimize_program_with_k2, resolve_k2_toolchain  # noqa: E402
from runner.libs.machines import resolve_machine_executable  # noqa: E402
from runner.libs.rejit import (  # noqa: E402
    _start_daemon_server,
    _stop_daemon_server,
    benchmark_config_enabled_passes,
    benchmark_config_repeat,
    benchmark_config_warmups,
    load_benchmark_config,
)
from runner.libs.vm import DEFAULT_VM_TARGET, build_guest_exec, run_in_vm, write_guest_script  # noqa: E402


SCRIPT_PATH = Path(__file__).resolve()
DEFAULT_MACRO_CORPUS_YAML = ROOT_DIR / "corpus" / "config" / "macro_corpus.yaml"
DEFAULT_CORPUS_BUILD_REPORT = ROOT_DIR / "corpus" / "results" / "expanded_corpus_build.latest.json"
DEFAULT_RUNNER = ROOT_DIR / "runner" / "build" / "micro_exec"
DEFAULT_DAEMON = ROOT_DIR / "daemon" / "target" / "release" / "bpfrejit-daemon"
DEFAULT_KERNEL_TREE = ROOT_DIR / "vendor" / "linux-framework"
DEFAULT_KERNEL_IMAGE = DEFAULT_KERNEL_TREE / "arch" / "x86" / "boot" / "bzImage"
DEFAULT_BTF_PATH = DEFAULT_KERNEL_TREE / "vmlinux"
DEFAULT_VNG = str(resolve_machine_executable(target=DEFAULT_VM_TARGET, action="vm-corpus"))
DEFAULT_TIMEOUT_SECONDS = 240


def _output_defaults(stamp: str) -> tuple[Path, Path]:
    base_dir = docs_tmp_dir(stamp=stamp)
    return (
        base_dir / f"k2_comparison_results_{stamp}.json",
        base_dir / f"k2_comparison_results_{stamp}.md",
    )


def parse_args(argv: list[str] | None = None) -> argparse.Namespace:
    argv = list(sys.argv[1:] if argv is None else argv)
    stamp = scratch_date_stamp()
    pre_parser = argparse.ArgumentParser(add_help=False)
    pre_parser.add_argument("--profile")
    pre_args, _ = pre_parser.parse_known_args(argv)
    benchmark_config = load_benchmark_config(pre_args.profile)
    default_output_json, default_output_md = _output_defaults(stamp)

    parser = argparse.ArgumentParser(description="Compare K2 and BpfReJIT on the same corpus programs.")
    parser.add_argument("--macro-corpus-yaml", default=str(DEFAULT_MACRO_CORPUS_YAML))
    parser.add_argument("--corpus-build-report", default=str(DEFAULT_CORPUS_BUILD_REPORT))
    parser.add_argument("--runner", default=str(DEFAULT_RUNNER))
    parser.add_argument("--daemon", default=str(DEFAULT_DAEMON))
    parser.add_argument("--kernel-image", default=str(DEFAULT_KERNEL_IMAGE))
    parser.add_argument("--btf-custom-path", default=str(DEFAULT_BTF_PATH))
    parser.add_argument("--target", default=DEFAULT_VM_TARGET)
    parser.add_argument("--vng", default=DEFAULT_VNG)
    parser.add_argument("--profile", default=benchmark_config.get("profile"))
    parser.add_argument("--repeat", type=int, default=benchmark_config_repeat(benchmark_config))
    parser.add_argument("--warmup-repeat", type=int, default=benchmark_config_warmups(benchmark_config))
    parser.add_argument("--timeout-seconds", type=int, default=DEFAULT_TIMEOUT_SECONDS)
    parser.add_argument("--vm-timeout-seconds", type=int)
    parser.add_argument("--filter", action="append", default=[])
    parser.add_argument("--max-programs", type=int)
    parser.add_argument("--skip-vm", action="store_true", help="Only run host-side K2 optimization and skip guest measurement.")
    parser.add_argument("--output-json", default=str(default_output_json))
    parser.add_argument("--output-md", default=str(default_output_md))
    parser.add_argument("--k2-root", default=str(ROOT_DIR / ".cache" / "k2"))
    parser.add_argument("--k2-iterations", type=int, default=5000)
    parser.add_argument("--k2-max-pkt-sz", type=int, default=256)
    parser.add_argument("--k2-timeout-seconds", type=int, default=600)
    parser.add_argument("--guest-target-json", help=argparse.SUPPRESS)
    parser.add_argument("--guest-result-json", help=argparse.SUPPRESS)
    args = parser.parse_args(argv)
    args.benchmark_config = load_benchmark_config(args.profile)
    return args


def _resolve_path(path_text: str) -> Path:
    candidate = Path(path_text)
    return candidate if candidate.is_absolute() else (ROOT_DIR / candidate)


def _optional_path(path_text: str | None) -> Path | None:
    if not path_text:
        return None
    return _resolve_path(path_text)


def _single_program_object(obj: ResolvedObject, program: ResolvedProgram) -> ResolvedObject:
    return replace(obj, programs=(program,))


def _variant_object(
    obj: ResolvedObject,
    program: ResolvedProgram,
    *,
    object_path: Path,
    variant_prefix: str,
) -> ResolvedObject:
    resolved_object_path = object_path.resolve()
    object_text = relpath(resolved_object_path, ROOT_DIR)
    variant_program = replace(
        program,
        source=object_text,
        object_path=object_text,
        object_abs_path=str(resolved_object_path),
        object_relpath=object_text,
        canonical_object_name=f"{variant_prefix}:{program.canonical_object_name}",
        object_basename=resolved_object_path.name,
        short_name=f"{variant_prefix}:{program.short_name}",
        canonical_name=f"{variant_prefix}:{program.canonical_name}",
    )
    return replace(
        obj,
        source=object_text,
        object_path=object_text,
        object_abs_path=str(resolved_object_path),
        object_relpath=object_text,
        canonical_name=f"{variant_prefix}:{obj.canonical_name}",
        object_basename=resolved_object_path.name,
        short_name=f"{variant_prefix}:{obj.short_name}",
        programs=(variant_program,),
    )


def _sample(summary: Mapping[str, Any] | None) -> Mapping[str, Any]:
    if not isinstance(summary, Mapping):
        return {}
    sample = summary.get("sample")
    return sample if isinstance(sample, Mapping) else {}


def _sample_int(summary: Mapping[str, Any] | None, field_name: str) -> int | None:
    sample = _sample(summary)
    value = sample.get(field_name)
    if value is None:
        return None
    try:
        return int(value)
    except (TypeError, ValueError):
        return None


def _speedup_ratio(baseline_ns: int | None, candidate_ns: int | None) -> float | None:
    if baseline_ns is None or candidate_ns is None or baseline_ns <= 0 or candidate_ns <= 0:
        return None
    return float(baseline_ns) / float(candidate_ns)


def _geomean(values: list[float | None]) -> float | None:
    filtered = [float(value) for value in values if value is not None and float(value) > 0.0]
    if not filtered:
        return None
    return math.exp(sum(math.log(value) for value in filtered) / len(filtered))


def _rejit_summary(summary: Mapping[str, Any] | None) -> Mapping[str, Any]:
    sample = _sample(summary)
    rejit = sample.get("rejit")
    return rejit if isinstance(rejit, Mapping) else {}


def _build_guest_jobs_for_case(
    *,
    case_index: int,
    case_id: str,
    original_obj: ResolvedObject,
    k2_obj: ResolvedObject | None,
    repeat: int,
    warmup_repeat: int,
    btf_custom_path: Path,
    daemon_socket: str,
    enabled_passes: list[str],
) -> tuple[list[dict[str, Any]], dict[str, str]]:
    program = original_obj.programs[0]
    fixture_path = _optional_path(program.fixture_path) or _optional_path(original_obj.fixture_path)
    memory_path = _optional_path(program.memory_path)
    load_names = program_load_names(program)
    refs = {
        "stock_compile": f"case-{case_index:04d}:stock-compile",
        "stock_run": f"case-{case_index:04d}:stock-run",
        "rejit_compile": f"case-{case_index:04d}:rejit-compile",
        "rejit_run": f"case-{case_index:04d}:rejit-run",
        "k2_compile": f"case-{case_index:04d}:k2-compile",
        "k2_run": f"case-{case_index:04d}:k2-run",
    }
    jobs = [
        build_test_run_batch_job(
            job_id=refs["stock_compile"],
            execution="serial",
            runtime=runtime_for_program(program, rejit=False),
            object_path=Path(original_obj.object_abs_path),
            program_name=program.program_name,
            attach_program_name=program.attach_group,
            io_mode=program.io_mode,
            raw_packet=program.raw_packet,
            memory_path=memory_path,
            input_size=program.input_size,
            repeat=repeat,
            warmup_repeat=warmup_repeat,
            btf_custom_path=btf_custom_path,
            compile_only=True,
            load_program_names=load_names,
            fixture_path=fixture_path,
            trigger_command=program.trigger,
            trigger_timeout_seconds=program.trigger_timeout_seconds,
        ),
        build_test_run_batch_job(
            job_id=refs["stock_run"],
            execution="serial",
            runtime=runtime_for_program(program, rejit=False),
            object_path=Path(original_obj.object_abs_path),
            program_name=program.program_name,
            attach_program_name=program.attach_group,
            io_mode=program.io_mode,
            raw_packet=program.raw_packet,
            memory_path=memory_path,
            input_size=program.input_size,
            repeat=repeat,
            warmup_repeat=warmup_repeat,
            btf_custom_path=btf_custom_path,
            compile_only=False,
            load_program_names=load_names,
            fixture_path=fixture_path,
            trigger_command=program.trigger,
            trigger_timeout_seconds=program.trigger_timeout_seconds,
        ),
        build_test_run_batch_job(
            job_id=refs["rejit_compile"],
            execution="serial",
            runtime=runtime_for_program(program, rejit=True),
            object_path=Path(original_obj.object_abs_path),
            program_name=program.program_name,
            attach_program_name=program.attach_group,
            io_mode=program.io_mode,
            raw_packet=program.raw_packet,
            memory_path=memory_path,
            input_size=program.input_size,
            repeat=repeat,
            warmup_repeat=warmup_repeat,
            btf_custom_path=btf_custom_path,
            compile_only=True,
            daemon_socket=daemon_socket,
            enabled_passes=enabled_passes,
            load_program_names=load_names,
            fixture_path=fixture_path,
            trigger_command=program.trigger,
            trigger_timeout_seconds=program.trigger_timeout_seconds,
        ),
        build_test_run_batch_job(
            job_id=refs["rejit_run"],
            execution="serial",
            runtime=runtime_for_program(program, rejit=True),
            object_path=Path(original_obj.object_abs_path),
            program_name=program.program_name,
            attach_program_name=program.attach_group,
            io_mode=program.io_mode,
            raw_packet=program.raw_packet,
            memory_path=memory_path,
            input_size=program.input_size,
            repeat=repeat,
            warmup_repeat=warmup_repeat,
            btf_custom_path=btf_custom_path,
            compile_only=False,
            daemon_socket=daemon_socket,
            enabled_passes=enabled_passes,
            load_program_names=load_names,
            fixture_path=fixture_path,
            trigger_command=program.trigger,
            trigger_timeout_seconds=program.trigger_timeout_seconds,
        ),
    ]
    if k2_obj is not None:
        k2_program = k2_obj.programs[0]
        jobs.extend(
            [
                build_test_run_batch_job(
                    job_id=refs["k2_compile"],
                    execution="serial",
                    runtime=runtime_for_program(k2_program, rejit=False),
                    object_path=Path(k2_obj.object_abs_path),
                    program_name=k2_program.program_name,
                    attach_program_name=k2_program.attach_group,
                    io_mode=k2_program.io_mode,
                    raw_packet=k2_program.raw_packet,
                    memory_path=memory_path,
                    input_size=k2_program.input_size,
                    repeat=repeat,
                    warmup_repeat=warmup_repeat,
                    btf_custom_path=btf_custom_path,
                    compile_only=True,
                    load_program_names=load_names,
                    fixture_path=fixture_path,
                    trigger_command=k2_program.trigger,
                    trigger_timeout_seconds=k2_program.trigger_timeout_seconds,
                ),
                build_test_run_batch_job(
                    job_id=refs["k2_run"],
                    execution="serial",
                    runtime=runtime_for_program(k2_program, rejit=False),
                    object_path=Path(k2_obj.object_abs_path),
                    program_name=k2_program.program_name,
                    attach_program_name=k2_program.attach_group,
                    io_mode=k2_program.io_mode,
                    raw_packet=k2_program.raw_packet,
                    memory_path=memory_path,
                    input_size=k2_program.input_size,
                    repeat=repeat,
                    warmup_repeat=warmup_repeat,
                    btf_custom_path=btf_custom_path,
                    compile_only=False,
                    load_program_names=load_names,
                    fixture_path=fixture_path,
                    trigger_command=k2_program.trigger,
                    trigger_timeout_seconds=k2_program.trigger_timeout_seconds,
                ),
            ]
        )
    return jobs, refs


def _build_guest_case_record(
    *,
    case_payload: Mapping[str, Any],
    refs: Mapping[str, str],
    results_by_id: Mapping[str, dict[str, Any]],
) -> dict[str, Any]:
    stock_compile = batch_job_invocation_summary(results_by_id.get(refs["stock_compile"]))
    stock_run = batch_job_invocation_summary(results_by_id.get(refs["stock_run"]))
    rejit_compile = batch_job_invocation_summary(results_by_id.get(refs["rejit_compile"]))
    rejit_run = batch_job_invocation_summary(results_by_id.get(refs["rejit_run"]))
    k2_compile = batch_job_invocation_summary(results_by_id.get(refs["k2_compile"]))
    k2_run = batch_job_invocation_summary(results_by_id.get(refs["k2_run"]))

    stock_bpf_insns = _sample_int(stock_compile, "bpf_insn_count") or _sample_int(stock_run, "bpf_insn_count")
    stock_exec_ns = _sample_int(stock_run, "exec_ns")
    stock_jited_prog_len = _sample_int(stock_compile, "jited_prog_len") or _sample_int(stock_run, "jited_prog_len")
    k2_bpf_insns = _sample_int(k2_compile, "bpf_insn_count") or _sample_int(k2_run, "bpf_insn_count")
    k2_exec_ns = _sample_int(k2_run, "exec_ns")
    k2_jited_prog_len = _sample_int(k2_compile, "jited_prog_len") or _sample_int(k2_run, "jited_prog_len")

    rejit_meta = _rejit_summary(rejit_run if rejit_run else rejit_compile)
    rejit_insn_delta = rejit_meta.get("insn_delta")
    try:
        rejit_insn_delta = int(rejit_insn_delta) if rejit_insn_delta is not None else None
    except (TypeError, ValueError):
        rejit_insn_delta = None
    rejit_bpf_insns = stock_bpf_insns + rejit_insn_delta if stock_bpf_insns is not None and rejit_insn_delta is not None else None
    rejit_exec_ns = _sample_int(rejit_run, "exec_ns")
    rejit_jited_prog_len = _sample_int(rejit_compile, "jited_prog_len") or _sample_int(rejit_run, "jited_prog_len")

    record = {
        "case_id": case_payload["case_id"],
        "canonical_name": case_payload["canonical_name"],
        "repo": case_payload["repo"],
        "object_path": case_payload["object_path"],
        "program_name": case_payload["program_name"],
        "section_name": case_payload["section_name"],
        "prog_type_name": case_payload["prog_type_name"],
        "test_method": case_payload["test_method"],
        "stock_compile": stock_compile,
        "stock_run": stock_run,
        "rejit_compile": rejit_compile,
        "rejit_run": rejit_run,
        "k2_compile": k2_compile,
        "k2_run": k2_run,
        "stock_bpf_insn_count": stock_bpf_insns,
        "k2_bpf_insn_count": k2_bpf_insns,
        "rejit_bpf_insn_count": rejit_bpf_insns,
        "stock_jited_prog_len": stock_jited_prog_len,
        "k2_jited_prog_len": k2_jited_prog_len,
        "rejit_jited_prog_len": rejit_jited_prog_len,
        "stock_exec_ns": stock_exec_ns,
        "k2_exec_ns": k2_exec_ns,
        "rejit_exec_ns": rejit_exec_ns,
        "k2_speedup_vs_stock": _speedup_ratio(stock_exec_ns, k2_exec_ns),
        "rejit_speedup_vs_stock": _speedup_ratio(stock_exec_ns, rejit_exec_ns),
        "rejit_total_sites_applied": rejit_meta.get("total_sites_applied"),
        "rejit_passes_applied": list(rejit_meta.get("passes_applied") or []),
        "rejit_insn_delta": rejit_insn_delta,
    }
    return sanitize_guest_batch_record(record)


def run_guest_mode(args: argparse.Namespace) -> int:
    target_path = Path(args.guest_target_json).resolve()
    result_path = Path(args.guest_result_json).resolve()
    payload = json.loads(target_path.read_text(encoding="utf-8"))
    if not isinstance(payload, Mapping):
        raise SystemExit("guest payload must be a JSON object")
    raw_cases = payload.get("cases")
    if not isinstance(raw_cases, list):
        raise SystemExit("guest payload missing cases")
    enabled_passes = [str(name) for name in payload.get("enabled_passes") or []]
    repeat = int(payload.get("repeat") or args.repeat)
    warmup_repeat = int(payload.get("warmup_repeat") or args.warmup_repeat)
    btf_custom_path = _resolve_path(args.btf_custom_path).resolve()
    daemon = _resolve_path(args.daemon).resolve()
    runner = _resolve_path(args.runner).resolve()

    jobs: list[dict[str, Any]] = []
    case_refs: list[dict[str, Any]] = []

    daemon_server = _start_daemon_server(daemon)
    try:
        for index, raw_case in enumerate(raw_cases, start=1):
            if not isinstance(raw_case, Mapping):
                raise SystemExit(f"guest case #{index} must be a JSON object")
            original_obj = deserialize_resolved_object(raw_case["original_object"])
            k2_obj = (
                deserialize_resolved_object(raw_case["k2_object"])
                if isinstance(raw_case.get("k2_object"), Mapping)
                else None
            )
            case_jobs, refs = _build_guest_jobs_for_case(
                case_index=index,
                case_id=str(raw_case["case_id"]),
                original_obj=original_obj,
                k2_obj=k2_obj,
                repeat=repeat,
                warmup_repeat=warmup_repeat,
                btf_custom_path=btf_custom_path,
                daemon_socket=str(daemon_server[1]),
                enabled_passes=enabled_passes,
            )
            jobs.extend(case_jobs)
            case_refs.append({"payload": dict(raw_case), "refs": refs})

        spec_payload = {
            "schema_version": 1,
            "scheduler": {"max_parallel_jobs": 1},
            "jobs": jobs,
        }
        batch_result = run_batch_runner(
            runner,
            spec_payload=spec_payload,
            timeout_seconds=packet_batch_timeout_seconds(max(1, len(jobs)), args.timeout_seconds),
            cwd=ROOT_DIR,
        )
    finally:
        _stop_daemon_server(daemon_server[0], daemon_server[1], daemon_server[2])

    results_by_id = batch_job_result_map(batch_result.get("result"))
    case_records = [
        _build_guest_case_record(
            case_payload=case_ref["payload"],
            refs=case_ref["refs"],
            results_by_id=results_by_id,
        )
        for case_ref in case_refs
    ]
    guest_payload = {
        "generated_at": datetime.now(timezone.utc).isoformat(),
        "guest": {
            "kernel_release": os.uname().release,
            "enabled_passes": enabled_passes,
            "repeat": repeat,
            "warmup_repeat": warmup_repeat,
        },
        "batch_result": {
            "ok": batch_result["ok"],
            "completed_with_job_errors": batch_result["completed_with_job_errors"],
            "returncode": batch_result["returncode"],
            "timed_out": batch_result["timed_out"],
            "duration_seconds": batch_result["duration_seconds"],
            "error": batch_result["error"],
            "stderr_tail": tail_text(batch_result["stderr"]),
            "stdout_tail": tail_text(batch_result["stdout"]),
        },
        "cases": case_records,
    }
    write_json(result_path, guest_payload)
    return 0 if batch_result["ok"] else 1


def _host_guest_payload(
    *,
    case_id: str,
    obj: ResolvedObject,
    program: ResolvedProgram,
    k2_obj: ResolvedObject | None,
) -> dict[str, Any]:
    single_obj = _single_program_object(obj, program)
    return {
        "case_id": case_id,
        "canonical_name": program.canonical_name,
        "repo": program.repo,
        "object_path": program.object_path,
        "program_name": program.program_name,
        "section_name": program.section_name,
        "prog_type_name": program.prog_type_name,
        "test_method": program.test_method,
        "original_object": serialize_resolved_object(single_obj),
        "k2_object": serialize_resolved_object(k2_obj) if k2_obj is not None else None,
    }


def _host_case_record(
    *,
    case_id: str,
    obj: ResolvedObject,
    program: ResolvedProgram,
    k2_host: Mapping[str, Any],
) -> dict[str, Any]:
    return {
        "case_id": case_id,
        "canonical_name": program.canonical_name,
        "repo": program.repo,
        "object_path": program.object_path,
        "program_name": program.program_name,
        "section_name": program.section_name,
        "prog_type_name": program.prog_type_name,
        "test_method": program.test_method,
        "k2_host": dict(k2_host),
        "guest": None,
        "comparison": None,
    }


def _build_comparison(case: Mapping[str, Any]) -> dict[str, Any]:
    guest = case.get("guest") if isinstance(case.get("guest"), Mapping) else {}
    k2_host = case.get("k2_host") if isinstance(case.get("k2_host"), Mapping) else {}
    stock_exec_ns = guest.get("stock_exec_ns")
    k2_exec_ns = guest.get("k2_exec_ns")
    rejit_exec_ns = guest.get("rejit_exec_ns")
    stock_jited = guest.get("stock_jited_prog_len")
    k2_jited = guest.get("k2_jited_prog_len")
    rejit_jited = guest.get("rejit_jited_prog_len")

    def delta_pct(before: Any, after: Any) -> float | None:
        try:
            before_i = int(before)
            after_i = int(after)
        except (TypeError, ValueError):
            return None
        if before_i <= 0:
            return None
        return (float(after_i) - float(before_i)) * 100.0 / float(before_i)

    return {
        "k2_bytecode_insn_delta": k2_host.get("insn_delta"),
        "rejit_bytecode_insn_delta": guest.get("rejit_insn_delta"),
        "k2_speedup_vs_stock": _speedup_ratio(stock_exec_ns, k2_exec_ns),
        "rejit_speedup_vs_stock": _speedup_ratio(stock_exec_ns, rejit_exec_ns),
        "k2_native_size_delta_pct": delta_pct(stock_jited, k2_jited),
        "rejit_native_size_delta_pct": delta_pct(stock_jited, rejit_jited),
    }


def _build_summary(
    *,
    cases: list[dict[str, Any]],
    enabled_passes: list[str],
) -> dict[str, Any]:
    k2_status_counter = Counter(
        str(case.get("k2_host", {}).get("status") or "unknown")
        for case in cases
    )
    k2_reason_counter = Counter(
        str(case.get("k2_host", {}).get("reason") or "")
        for case in cases
        if case.get("k2_host", {}).get("reason")
    )
    k2_speedups = [case.get("comparison", {}).get("k2_speedup_vs_stock") for case in cases]
    rejit_speedups = [case.get("comparison", {}).get("rejit_speedup_vs_stock") for case in cases]
    return {
        "total_cases": len(cases),
        "repos": sorted({str(case["repo"]) for case in cases}),
        "enabled_passes": enabled_passes,
        "k2_status_counts": dict(sorted(k2_status_counter.items())),
        "k2_ok_count": sum(1 for case in cases if case.get("k2_host", {}).get("ok")),
        "k2_warning_count": sum(1 for case in cases if case.get("k2_host", {}).get("warnings")),
        "k2_supported_count": sum(
            1 for case in cases if case.get("k2_host", {}).get("model", {}).get("supported")
        ),
        "k2_perf_improved_count": sum(
            1
            for case in cases
            if (
                case.get("k2_host", {}).get("optimized_perf_cost") is not None
                and case.get("k2_host", {}).get("original_perf_cost") is not None
                and int(case["k2_host"]["optimized_perf_cost"]) < int(case["k2_host"]["original_perf_cost"])
            )
        ),
        "k2_bytecode_changed_count": sum(
            1 for case in cases if (case.get("k2_host", {}).get("insn_delta") or 0) != 0
        ),
        "stock_run_ok_count": sum(1 for case in cases if (case.get("guest") or {}).get("stock_run", {}).get("ok")),
        "k2_run_ok_count": sum(1 for case in cases if (case.get("guest") or {}).get("k2_run", {}).get("ok")),
        "rejit_run_ok_count": sum(1 for case in cases if (case.get("guest") or {}).get("rejit_run", {}).get("ok")),
        "k2_geomean_speedup_vs_stock": _geomean(k2_speedups),
        "rejit_geomean_speedup_vs_stock": _geomean(rejit_speedups),
        "k2_failure_reasons_top": [
            {"reason": reason, "count": count}
            for reason, count in k2_reason_counter.most_common(8)
        ],
    }


def _build_markdown(payload: Mapping[str, Any]) -> str:
    config = payload.get("config") or {}
    summary = payload.get("summary") or {}
    cases = payload.get("cases") or []
    lines: list[str] = [
        "# K2 Comparison Results",
        "",
        f"- Generated: `{payload.get('generated_at', 'n/a')}`",
        f"- Profile: `{config.get('profile') or 'default'}`",
        f"- Repeat: `{config.get('repeat')}`",
        f"- Warmup repeat: `{config.get('warmup_repeat')}`",
        f"- K2 iterations: `{config.get('k2_iterations')}`",
        f"- REJIT passes: `{', '.join(summary.get('enabled_passes') or [])}`",
        "",
        "## Summary",
        "",
        f"- Cases: `{summary.get('total_cases')}`",
        f"- K2 supported: `{summary.get('k2_supported_count')}`",
        f"- K2 optimized successfully: `{summary.get('k2_ok_count')}`",
        f"- K2 emitted warnings: `{summary.get('k2_warning_count')}`",
        f"- K2 improved perf cost: `{summary.get('k2_perf_improved_count')}`",
        f"- K2 changed bytecode insn count: `{summary.get('k2_bytecode_changed_count')}`",
        f"- Stock VM runs OK: `{summary.get('stock_run_ok_count')}`",
        f"- K2 VM runs OK: `{summary.get('k2_run_ok_count')}`",
        f"- REJIT VM runs OK: `{summary.get('rejit_run_ok_count')}`",
        f"- K2 geomean speedup vs stock: `{format_ratio(summary.get('k2_geomean_speedup_vs_stock'))}`",
        f"- REJIT geomean speedup vs stock: `{format_ratio(summary.get('rejit_geomean_speedup_vs_stock'))}`",
        "",
        "## Per-program",
        "",
    ]
    headers = [
        "Program",
        "Type",
        "K2 status",
        "K2 perf cost",
        "K2 delta insn",
        "REJIT delta insn",
        "REJIT sites",
        "Stock ns",
        "K2 ns",
        "REJIT ns",
        "K2 speedup",
        "REJIT speedup",
    ]
    rows: list[list[str]] = []
    for case in cases:
        k2_host = case.get("k2_host") or {}
        guest = case.get("guest") or {}
        comparison = case.get("comparison") or {}
        k2_status = str(k2_host.get("status") or "n/a")
        if k2_status != "ok" and k2_host.get("reason"):
            k2_status = f"{k2_status}: {str(k2_host['reason'])[:60]}"
        rows.append(
            [
                str(case["canonical_name"]),
                str(case["prog_type_name"]),
                k2_status,
                (
                    "n/a"
                    if k2_host.get("original_perf_cost") is None or k2_host.get("optimized_perf_cost") is None
                    else f"{k2_host['original_perf_cost']}->{k2_host['optimized_perf_cost']}"
                ),
                str(comparison.get("k2_bytecode_insn_delta") if comparison.get("k2_bytecode_insn_delta") is not None else "n/a"),
                str(comparison.get("rejit_bytecode_insn_delta") if comparison.get("rejit_bytecode_insn_delta") is not None else "n/a"),
                str(guest.get("rejit_total_sites_applied") if guest.get("rejit_total_sites_applied") is not None else "n/a"),
                format_ns(guest.get("stock_exec_ns")),
                format_ns(guest.get("k2_exec_ns")),
                format_ns(guest.get("rejit_exec_ns")),
                format_ratio(comparison.get("k2_speedup_vs_stock")),
                format_ratio(comparison.get("rejit_speedup_vs_stock")),
            ]
        )
    lines.extend(markdown_table(headers, rows))
    return "\n".join(lines) + "\n"


def run_host_mode(args: argparse.Namespace) -> int:
    runner = _resolve_path(args.runner).resolve()
    daemon = _resolve_path(args.daemon).resolve()
    kernel_image = _resolve_path(args.kernel_image).resolve()
    btf_custom_path = _resolve_path(args.btf_custom_path).resolve()
    output_json = _resolve_path(args.output_json).resolve()
    output_md = _resolve_path(args.output_md).resolve()
    output_dir = output_json.parent
    output_dir.mkdir(parents=True, exist_ok=True)

    corpus_build_report = load_corpus_build_report(_resolve_path(args.corpus_build_report).resolve())
    objects, selection_summary = load_targets_from_yaml(
        _resolve_path(args.macro_corpus_yaml).resolve(),
        corpus_build_report,
        filters=args.filter,
        max_programs=args.max_programs,
    )
    if not objects:
        raise SystemExit("no corpus programs selected")

    toolchain = resolve_k2_toolchain(_resolve_path(args.k2_root).resolve())
    enabled_passes = benchmark_config_enabled_passes(args.benchmark_config)

    cases: list[dict[str, Any]] = []
    guest_cases: list[dict[str, Any]] = []
    k2_output_root = output_dir / "k2-artifacts"
    k2_output_root.mkdir(parents=True, exist_ok=True)

    case_index = 0
    for obj in objects:
        for program in obj.programs:
            case_index += 1
            case_id = f"case-{case_index:04d}"
            k2_host = optimize_program_with_k2(
                toolchain=toolchain,
                runner_binary=runner,
                obj=obj,
                program=program,
                output_root=k2_output_root,
                iterations=args.k2_iterations,
                max_pkt_sz=args.k2_max_pkt_sz,
                timeout_seconds=args.k2_timeout_seconds,
            )
            k2_obj = None
            if k2_host.get("ok") and k2_host.get("output_object"):
                k2_obj = _variant_object(
                    _single_program_object(obj, program),
                    program,
                    object_path=Path(str(k2_host["output_object"])),
                    variant_prefix="k2",
                )
            guest_cases.append(
                _host_guest_payload(
                    case_id=case_id,
                    obj=obj,
                    program=program,
                    k2_obj=k2_obj,
                )
            )
            cases.append(
                _host_case_record(
                    case_id=case_id,
                    obj=obj,
                    program=program,
                    k2_host=k2_host,
                )
            )

    guest_target_path = output_dir / "k2_comparison_guest_targets.json"
    guest_result_path = output_dir / "k2_comparison_guest_results.json"
    write_json(
        guest_target_path,
        {
            "generated_at": datetime.now(timezone.utc).isoformat(),
            "enabled_passes": enabled_passes,
            "repeat": args.repeat,
            "warmup_repeat": args.warmup_repeat,
            "cases": guest_cases,
        },
    )

    vm_timeout_seconds = (
        int(args.vm_timeout_seconds)
        if args.vm_timeout_seconds
        else max(1800, packet_batch_timeout_seconds(max(1, len(guest_cases) * 3), args.timeout_seconds))
    )
    guest_payload: dict[str, Any]
    completed_returncode = None
    completed_stdout = ""
    completed_stderr = ""
    if args.skip_vm:
        guest_payload = {
            "error": "guest VM phase skipped via --skip-vm",
            "cases": [],
        }
    else:
        guest_argv = [
            "python3",
            str(SCRIPT_PATH),
            "--guest-target-json",
            str(guest_target_path),
            "--guest-result-json",
            str(guest_result_path),
            "--runner",
            str(runner),
            "--daemon",
            str(daemon),
            "--btf-custom-path",
            str(btf_custom_path),
            "--repeat",
            str(args.repeat),
            "--warmup-repeat",
            str(args.warmup_repeat),
            "--timeout-seconds",
            str(args.timeout_seconds),
        ]
        guest_exec = build_guest_exec(guest_argv)
        guest_script = write_guest_script([guest_exec])
        completed = run_in_vm(
            kernel_image,
            guest_script,
            None,
            None,
            vm_timeout_seconds,
            vm_executable=args.vng or None,
            target=args.target,
            action="vm-corpus",
        )
        completed_returncode = completed.returncode
        completed_stdout = completed.stdout or ""
        completed_stderr = completed.stderr or ""

        guest_payload = {
            "error": None,
            "returncode": completed.returncode,
            "stdout_tail": tail_text(completed.stdout or ""),
            "stderr_tail": tail_text(completed.stderr or ""),
            "cases": [],
        }
        if guest_result_path.exists():
            guest_payload = json.loads(guest_result_path.read_text(encoding="utf-8"))
            guest_payload["vm_returncode"] = completed.returncode
            guest_payload["vm_stdout_tail"] = tail_text(completed.stdout or "")
            guest_payload["vm_stderr_tail"] = tail_text(completed.stderr or "")
        else:
            guest_payload["error"] = "guest result payload missing"

    guest_by_case = {
        str(case["case_id"]): case
        for case in guest_payload.get("cases") or []
        if isinstance(case, Mapping)
    }
    for case in cases:
        guest_case = guest_by_case.get(case["case_id"])
        case["guest"] = dict(guest_case) if guest_case else None
        case["comparison"] = _build_comparison(case)

    summary = _build_summary(cases=cases, enabled_passes=enabled_passes)
    payload = {
        "generated_at": datetime.now(timezone.utc).isoformat(),
        "config": {
            "macro_corpus_yaml": relpath(_resolve_path(args.macro_corpus_yaml), ROOT_DIR),
            "corpus_build_report": relpath(_resolve_path(args.corpus_build_report), ROOT_DIR),
            "profile": args.profile,
            "repeat": args.repeat,
            "warmup_repeat": args.warmup_repeat,
            "timeout_seconds": args.timeout_seconds,
            "vm_timeout_seconds": vm_timeout_seconds,
            "target": args.target,
            "skip_vm": bool(args.skip_vm),
            "k2_iterations": args.k2_iterations,
            "k2_max_pkt_sz": args.k2_max_pkt_sz,
            "k2_timeout_seconds": args.k2_timeout_seconds,
            "filters": list(args.filter),
            "max_programs": args.max_programs,
        },
        "selection_summary": selection_summary,
        "toolchain": toolchain.as_dict(),
        "vm": {
            "kernel_image": str(kernel_image),
            "btf_custom_path": str(btf_custom_path),
            "vng": args.vng,
            "guest_result_path": str(guest_result_path),
            "guest_target_path": str(guest_target_path),
            "guest_returncode": completed_returncode,
            "guest_stdout_tail": tail_text(completed_stdout),
            "guest_stderr_tail": tail_text(completed_stderr),
        },
        "guest_payload": guest_payload,
        "summary": summary,
        "cases": cases,
    }
    write_json(output_json, payload)
    write_text(output_md, _build_markdown(payload))
    return 0


def main(argv: list[str] | None = None) -> int:
    args = parse_args(argv)
    try:
        if args.guest_target_json:
            return run_guest_mode(args)
        return run_host_mode(args)
    except Exception as exc:
        traceback.print_exc()
        print(f"k2_comparison.py failed: {exc}", file=sys.stderr)
        return 1


if __name__ == "__main__":
    raise SystemExit(main())
