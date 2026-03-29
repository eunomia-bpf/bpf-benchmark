#!/usr/bin/env python3
from __future__ import annotations

import argparse
import json
import os
import shutil
import subprocess
import sys
from datetime import datetime, timezone
from pathlib import Path
from typing import Any

SCRIPT_DIR = Path(__file__).resolve().parent
REPO_ROOT = SCRIPT_DIR.parent
for candidate in (REPO_ROOT, SCRIPT_DIR, REPO_ROOT / "micro", REPO_ROOT / "corpus"):
    candidate_str = str(candidate)
    if candidate_str not in sys.path:
        sys.path.insert(0, candidate_str)

from runner.libs import authoritative_output_path, latest_output_path, smoke_output_path
from runner.libs.machines import resolve_machine
from runner.libs.rejit import (
    benchmark_config_repeat,
    benchmark_config_warmups,
    load_benchmark_config,
)
from runner.libs.results import summarize_corpus_batch_results
from runner.libs.vm import (
    DEFAULT_VM_TARGET,
    run_corpus_targets_in_guest_batch,
)

from runner.libs.run_artifacts import (
    ArtifactSession,
    derive_run_type,
    repo_relative_path,
)

from runner.libs.corpus import (
    add_filter_argument,
    add_max_programs_argument,
    add_output_json_argument,
    add_output_md_argument,
    add_repeat_argument,
    add_runner_argument,
    add_daemon_argument,
    add_timeout_argument,
    attach_trigger_unsupported_reason,
    build_test_run_batch_job,
    find_program_in_object,
    format_ns,
    format_ratio,
    load_corpus_build_report,
    load_guest_batch_targets,
    load_targets_from_yaml,
    markdown_table,
    ResolvedObject,
    ResolvedProgram,
    require_minimum,
    resolve_manifest_object,
    run_objects_locally_batch,
    sanitize_guest_batch_record,
    summarize_failure_reason,
    write_guest_batch_records,
    summarize_text,
)

ROOT_DIR = Path(__file__).resolve().parent.parent
DRIVER_RELATIVE = Path(__file__).with_name("driver.py").resolve().relative_to(ROOT_DIR)
DEFAULT_MACRO_CORPUS_YAML = ROOT_DIR / "corpus" / "config" / "macro_corpus.yaml"
FALLBACK_OUTPUT_JSON = authoritative_output_path(ROOT_DIR / "corpus" / "results", "corpus_vm_batch")
FALLBACK_OUTPUT_MD = ROOT_DIR / "docs" / "tmp" / "corpus-batch-rejit-results.md"
DEFAULT_RUNNER = ROOT_DIR / "runner" / "build" / "micro_exec"
DEFAULT_DAEMON = ROOT_DIR / "daemon" / "target" / "release" / "bpfrejit-daemon"
DEFAULT_KERNEL_TREE = ROOT_DIR / "vendor" / "linux-framework"
DEFAULT_KERNEL_IMAGE = DEFAULT_KERNEL_TREE / "arch" / "x86" / "boot" / "bzImage"
DEFAULT_BTF_PATH = DEFAULT_KERNEL_TREE / "vmlinux"
DEFAULT_CORPUS_BUILD_REPORT = latest_output_path(ROOT_DIR / "corpus" / "results", "expanded_corpus_build")
DEFAULT_VNG_MACHINE = resolve_machine(target=DEFAULT_VM_TARGET, action="vm-corpus")
DEFAULT_VNG = str(Path(DEFAULT_VNG_MACHINE.executable))
DEFAULT_TIMEOUT_SECONDS = 240
DEFAULT_BATCH_SIZE = 100


def snapshot_guest_input(source: Path, snapshot_dir: Path) -> Path:
    snapshot_dir.mkdir(parents=True, exist_ok=True)
    destination = snapshot_dir / source.name
    shutil.copy2(source, destination)
    return destination


def snapshot_guest_tree(source: Path, destination: Path) -> Path:
    if destination.exists():
        shutil.rmtree(destination)
    shutil.copytree(source, destination)
    return destination

def parse_packet_args(argv: list[str] | None = None) -> argparse.Namespace:
    argv = list(sys.argv[1:] if argv is None else argv)
    pre_parser = argparse.ArgumentParser(add_help=False)
    pre_parser.add_argument("--profile")
    pre_args, _ = pre_parser.parse_known_args(argv)
    benchmark_config = load_benchmark_config(pre_args.profile)
    default_output_json = str(benchmark_config.get("output_json") or FALLBACK_OUTPUT_JSON)
    default_output_md = str(benchmark_config.get("output_md") or FALLBACK_OUTPUT_MD)
    profile_names = benchmark_config.get("available_profiles") or []
    profile_help = "Benchmark profile from benchmark_config.yaml."
    if profile_names:
        profile_help += f" Available: {', '.join(profile_names)}."

    parser = argparse.ArgumentParser(
        description=(
            "Run the macro_corpus.yaml-driven corpus REJIT batch on "
            "the framework kernel guest."
        )
    )
    parser.add_argument(
        "--macro-corpus-yaml",
        default=str(DEFAULT_MACRO_CORPUS_YAML),
        help="Macro corpus YAML manifest used to select the corpus targets.",
    )
    parser.add_argument("--profile", default=benchmark_config.get("profile"), help=profile_help)
    add_output_json_argument(parser, default_output_json)
    add_output_md_argument(parser, default_output_md)
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
        "--corpus-build-report",
        default=str(DEFAULT_CORPUS_BUILD_REPORT),
        help="Strict corpus object availability report emitted by build_corpus_objects.py.",
    )
    parser.add_argument(
        "--vng",
        default=DEFAULT_VNG,
        help="vng executable to use for strict guest runs.",
    )
    add_repeat_argument(
        parser,
        benchmark_config_repeat(benchmark_config),
        help_text="Repeat count passed to each micro_exec invocation.",
    )
    parser.add_argument(
        "--warmups",
        type=int,
        default=benchmark_config_warmups(benchmark_config),
        help="Warmup repeat count passed to each micro_exec invocation.",
    )
    parser.add_argument(
        "--batch-size",
        type=int,
        default=int(benchmark_config.get("corpus_batch_size") or DEFAULT_BATCH_SIZE),
        help="Maximum objects to keep loaded per corpus batch before cleanup.",
    )
    add_timeout_argument(parser, DEFAULT_TIMEOUT_SECONDS, help_text="Per-target timeout in seconds.")
    add_filter_argument(
        parser,
        help_text="Only include targets whose canonical name, object path, program name, or source contains this substring. Repeatable.",
    )
    add_max_programs_argument(parser, help_text="Optional cap for smoke testing.")
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
    args = parser.parse_args(argv)
    args.benchmark_config = load_benchmark_config(args.profile)
    args.default_output_json = str(args.benchmark_config.get("output_json") or FALLBACK_OUTPUT_JSON)
    args.default_output_md = str(args.benchmark_config.get("output_md") or FALLBACK_OUTPUT_MD)
    return args


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
        "progress": progress,
    }
    metadata.update(extra_fields)
    return metadata

def batch_text_invocation_summary(result: dict[str, Any] | None) -> dict[str, Any] | None:
    if result is None:
        return None
    summary = {
        "ok": result["ok"],
        "returncode": result["returncode"],
        "timed_out": result["timed_out"],
        "duration_seconds": result["duration_seconds"],
        "error": result["error"],
        "stderr_tail": summarize_text(result["stderr"]),
        "stdout_tail": summarize_text(result.get("diagnostic_stdout", result["stdout"])),
    }
    command = result.get("command")
    if isinstance(command, str):
        summary["command"] = command
    elif isinstance(command, list):
        summary["command"] = [str(part) for part in command]
    debug_artifacts = result.get("debug_artifacts")
    if isinstance(debug_artifacts, dict) and debug_artifacts:
        summary["debug_artifacts"] = {
            str(key): str(value)
            for key, value in debug_artifacts.items()
            if str(value)
        }
    return summary


def emit_guest_event(kind: str, **payload: Any) -> None:
    print(json.dumps({"kind": kind, **payload}, sort_keys=True), flush=True)


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


def _guest_batch_failure_headline(
    *,
    batch_result: dict[str, Any],
    built_records: list[dict[str, Any]],
) -> str:
    def failure_messages() -> list[str]:
        messages: list[str] = []
        seen: set[str] = set()

        def add(message: str) -> None:
            text = message.strip()
            if not text or text in seen:
                return
            seen.add(text)
            messages.append(text)

        for bundle in built_records:
            object_record = bundle.get("object_record")
            if isinstance(object_record, dict):
                object_name = str(object_record.get("canonical_object_name") or "unknown-object")
                object_error = str(object_record.get("error") or "").strip()
                object_status = str(object_record.get("status") or "").strip()
                if object_error:
                    add(f"{object_name}: {object_error}")
                elif object_status == "error":
                    add(f"{object_name}: object status error")

            program_records = bundle.get("program_records")
            if not isinstance(program_records, list):
                continue
            for program_record in program_records:
                if not isinstance(program_record, dict):
                    continue
                program_name = str(program_record.get("canonical_name") or "unknown-program")
                for field_name in ("baseline_compile", "rejit_compile", "baseline_run", "rejit_run"):
                    invocation = program_record.get(field_name)
                    if isinstance(invocation, dict) and not invocation.get("ok", False):
                        add(f"{program_name} {field_name}: {summarize_failure_reason(invocation)}")
                        break

        return messages

    batch_error = str(batch_result.get("error") or "").strip()
    batch_stderr = str(batch_result.get("stderr") or "").strip()
    record_failures = failure_messages()
    if batch_stderr and (
        not batch_error or batch_error.startswith("batch runner exited with code")
    ):
        if record_failures:
            return record_failures[0]
        stderr_lines = [line.strip() for line in batch_stderr.splitlines() if line.strip()]
        if stderr_lines:
            return stderr_lines[-1]
    if record_failures and (
        not batch_error
        or batch_error.startswith("batch runner exited with code")
        or batch_error.startswith("libbpf:")
    ):
        return record_failures[0]
    if batch_error:
        return batch_error
    if record_failures:
        return record_failures[0]

    return f"batch runner exited with code {batch_result.get('returncode')}"


def run_guest_batch_mode(args: argparse.Namespace) -> int:
    target_path = Path(args.guest_target_json).resolve()
    objects = load_guest_batch_targets(target_path)
    runner = Path(args.runner).resolve()
    daemon = Path(args.daemon).resolve()
    btf_custom_path = Path(args.btf_custom_path).resolve() if args.btf_custom_path else None
    guest_result_path = Path(args.guest_result_json).resolve() if args.guest_result_json else None
    warmup_repeat = int(getattr(args, "warmups", 1) or 1)
    batch_size = int(getattr(args, "batch_size", DEFAULT_BATCH_SIZE) or DEFAULT_BATCH_SIZE)
    if btf_custom_path is None:
        raise SystemExit("--btf-custom-path is required in guest batch mode")

    emit_guest_event("guest_info", payload=guest_info_payload())
    records: list[dict[str, Any]] = []
    if guest_result_path is not None:
        write_guest_batch_records(guest_result_path, records)

    object_records, program_records, batch_result = run_objects_locally_batch(
        objects=objects,
        runner=runner,
        daemon=daemon,
        repeat=args.repeat,
        warmup_repeat=warmup_repeat,
        timeout_seconds=args.timeout,
        execution_mode="vm",
        btf_custom_path=btf_custom_path,
        benchmark_config=args.benchmark_config,
        batch_size=batch_size,
    )
    built_records = []
    for obj in objects:
        object_record = next(
            item for item in object_records if item["canonical_object_name"] == obj.canonical_name
        )
        object_program_records = [
            item for item in program_records if item["canonical_object_name"] == obj.canonical_name
        ]
        built_records.append(
            {
                "object_record": object_record,
                "program_records": object_program_records,
            }
        )

    for index, record in enumerate(built_records, start=1):
        records.append(sanitize_guest_batch_record(record))
        if guest_result_path is not None:
            write_guest_batch_records(guest_result_path, records)
            emit_guest_event("program_progress", index=index, total=len(objects))
        else:
            emit_guest_event("program_record", index=index, total=len(objects), record=record)

    if not batch_result["ok"]:
        raise SystemExit(
            "guest batch failed: "
            + _guest_batch_failure_headline(batch_result=batch_result, built_records=built_records)
        )
    if batch_result["completed_with_job_errors"]:
        raise SystemExit(
            "guest batch completed with job errors: "
            + _guest_batch_failure_headline(batch_result=batch_result, built_records=built_records)
        )
    return 0

def build_markdown_v2(data: dict[str, Any]) -> str:
    summary = data["summary"]
    records = sorted(data["program_records"], key=lambda item: item["canonical_name"])
    object_records = sorted(data["object_records"], key=lambda item: item["canonical_object_name"])
    corpus_build_summary = data.get("corpus_build_summary") or {}
    guest_info = (data.get("guest_smoke") or {}).get("payload")
    requested_batch_size = int(data.get("batch_size") or DEFAULT_BATCH_SIZE)

    def note_for_record(record: dict[str, Any]) -> str:
        if record.get("record_error"):
            return str(record["record_error"])
        for key in ("baseline_compile", "rejit_compile", "baseline_run", "rejit_run"):
            invocation = record.get(key)
            if invocation and not invocation.get("ok"):
                return summarize_failure_reason(invocation)
        if record.get("comparison_exclusion_reason"):
            return str(record["comparison_exclusion_reason"])
        return ""

    lines: list[str] = [
        "# Corpus Batch REJIT Results",
        "",
        f"- Generated: {data['generated_at']}",
        f"- Corpus manifest: `{data['macro_corpus_yaml']}`",
        f"- Corpus build report: `{data['corpus_build_report']}`",
        f"- Runner: `{data['runner_binary']}`",
        f"- Daemon: `{data['daemon_binary']}`",
        "- Requested mode: `strict-vm`",
        f"- Effective mode: `{summary['effective_mode']}`",
        f"- Benchmark profile: `{data.get('benchmark_profile') or 'default'}`",
        f"- Benchmark config: `{data.get('benchmark_config') or 'fallback-defaults'}`",
        f"- Warmups: {data.get('warmups', 0)}",
        f"- Batch size: {requested_batch_size}",
        f"- Objects: {summary['objects_attempted']}",
        f"- Programs: {summary['targets_attempted']}",
        f"- Compile pairs: {summary['compile_pairs']}",
        f"- Measured pairs: {summary['measured_pairs']}",
        f"- Comparable exec pairs (all): {summary['comparable_pairs']}",
        f"- Comparable exec pairs (applied-only): {summary['applied_comparable_pairs']}",
        f"- REJIT applied programs: {summary['applied_programs']}",
        f"- Code-size ratio geomean (baseline/rejit): {format_ratio(summary['code_size_ratio_geomean'])}",
        (
            "- Exec-time ratio geomean (baseline/rejit, applied comparable): "
            f"{format_ratio(summary['exec_ratio_geomean'])}"
        ),
        (
            "- Exec-time ratio geomean (baseline/rejit, all comparable): "
            f"{format_ratio(summary['all_exec_ratio_geomean'])}"
        ),
    ]
    if corpus_build_summary:
        lines.append(
            f"- Build availability: {corpus_build_summary.get('available_total', 0)} objects "
            f"({corpus_build_summary.get('built_ok', 0)} built, {corpus_build_summary.get('staged_existing', 0)} staged)"
        )
    if guest_info:
        lines.append(f"- Guest kernel: `{guest_info.get('kernel_release', 'unknown')}`")
    lines.append("")

    lines.extend(["## By Repo", ""])
    lines.extend(
        markdown_table(
            [
                "Repo",
                "Programs",
                "Compile Pairs",
                "Measured Pairs",
                "Comparable",
                "Applied Comparable",
                "Applied",
                "Code Ratio",
                "Exec Ratio (Applied)",
                "Exec Ratio (All)",
            ],
            [
                [
                    row["repo"],
                    row["programs"],
                    row["compile_pairs"],
                    row["measured_pairs"],
                    row["comparable_pairs"],
                    row["applied_comparable_pairs"],
                    row["applied_programs"],
                    format_ratio(row["code_size_ratio_geomean"]),
                    format_ratio(row["exec_ratio_geomean"]),
                    format_ratio(row["all_exec_ratio_geomean"]),
                ]
                for row in summary["by_repo"]
            ],
        )
    )
    lines.append("")

    lines.extend(["## By Object", ""])
    lines.extend(
        markdown_table(
            ["Object", "Programs", "Compile", "REJIT Compile", "Status", "Error"],
            [
                [
                    row["canonical_object_name"],
                    row["program_count"],
                    format_ns(((row.get("stock_compile") or {}).get("sample") or {}).get("compile_ns")),
                    format_ns(((row.get("rejit_compile") or {}).get("sample") or {}).get("compile_ns")),
                    row["status"],
                    row.get("error") or "",
                ]
                for row in object_records
            ],
        )
    )
    lines.append("")

    lines.extend(["## Per-Program Results", ""])
    lines.extend(
        markdown_table(
            [
                "Program",
                "Repo",
                "Type",
                "Compile Passes",
                "Run Passes",
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
                    record["canonical_name"],
                    record["repo"],
                    record["prog_type_name"],
                    ", ".join(record.get("compile_passes_applied") or []) or "-",
                    ", ".join(record.get("run_passes_applied") or []) or "-",
                    format_ns(((record.get("baseline_compile") or {}).get("sample") or {}).get("jited_prog_len")),
                    format_ns(((record.get("rejit_compile") or {}).get("sample") or {}).get("jited_prog_len")),
                    format_ratio(record.get("size_ratio")),
                    format_ns(((record.get("baseline_run") or {}).get("sample") or {}).get("exec_ns")),
                    format_ns(((record.get("rejit_run") or {}).get("sample") or {}).get("exec_ns")),
                    format_ratio(record.get("speedup_ratio")),
                    note_for_record(record),
                ]
                for record in records
            ],
        )
    )

    if summary["failure_reasons"]:
        lines.extend(["", "## Top Failure Reasons", ""])
        lines.extend(markdown_table(["Reason", "Count"], [[reason, count] for reason, count in summary["failure_reasons"].items()]))

    if summary["comparison_exclusion_reasons"]:
        lines.extend(["", "## Top Comparison Exclusions", ""])
        lines.extend(
            markdown_table(
                ["Reason", "Count"],
                [[reason, count] for reason, count in summary["comparison_exclusion_reasons"].items()],
            )
        )

    return "\n".join(lines) + "\n"

def packet_main(argv: list[str] | None = None) -> int:
    args = parse_packet_args(argv)
    require_minimum(args.repeat, 1, "--repeat")
    require_minimum(args.warmups, 0, "--warmups")
    require_minimum(args.batch_size, 1, "--batch-size")
    benchmark_config_path = args.benchmark_config.get("config_path")

    if args.guest_info:
        return run_guest_info_mode()
    if args.guest_target_json:
        return run_guest_batch_mode(args)

    macro_corpus_yaml = Path(args.macro_corpus_yaml).resolve()
    if args.output_json == args.default_output_json and args.max_programs is not None:
        output_json = smoke_output_path(ROOT_DIR / "corpus" / "results", "corpus_vm_batch")
    else:
        output_json = Path(args.output_json).resolve()
    output_md = Path(args.output_md).resolve()
    runner = Path(args.runner).resolve()
    daemon = Path(args.daemon).resolve()
    kernel_tree = Path(args.kernel_tree).resolve()
    kernel_image = Path(args.kernel_image).resolve()
    btf_custom_path = Path(args.btf_custom_path).resolve() if args.btf_custom_path else None
    corpus_build_report_path = Path(args.corpus_build_report).resolve()

    if not macro_corpus_yaml.exists():
        raise SystemExit(f"macro corpus YAML not found: {macro_corpus_yaml}")
    if not runner.exists():
        raise SystemExit(f"runner not found: {runner}")
    if not daemon.exists():
        raise SystemExit(f"daemon not found: {daemon}")
    if not corpus_build_report_path.exists():
        raise SystemExit(f"corpus build report not found: {corpus_build_report_path}")

    run_type = derive_run_type(output_json, "corpus_vm_batch")
    started_at = datetime.now(timezone.utc).isoformat()
    corpus_build_report = load_corpus_build_report(corpus_build_report_path)

    objects, yaml_summary = load_targets_from_yaml(
        yaml_path=macro_corpus_yaml,
        corpus_build_report=corpus_build_report,
        filters=args.filters,
        max_programs=args.max_programs,
    )

    if not kernel_image.exists():
        raise SystemExit(f"kernel image missing: {kernel_image}")
    if btf_custom_path is None or not btf_custom_path.exists():
        raise SystemExit(f"btf path missing: {btf_custom_path}")

    guest_smoke: dict[str, Any] = {"invocation": None, "payload": None}
    object_records: list[dict[str, Any]] = []
    program_records: list[dict[str, Any]] = []
    total_programs = sum(len(obj.programs) for obj in objects)
    print(
        "vm-corpus selection "
        f"profile={args.profile or 'default'} "
        f"batch_size={args.batch_size} "
        f"manifest_objects={yaml_summary['total_objects']} "
        f"manifest_programs={yaml_summary['total_programs']} "
        f"selected_objects={yaml_summary['selected_objects']} "
        f"selected_programs={yaml_summary['selected_programs']} "
        f"available_objects={yaml_summary['available_objects']}",
        flush=True,
    )
    result = {
        "generated_at": started_at,
        "repo_root": str(ROOT_DIR),
        "macro_corpus_yaml": str(macro_corpus_yaml),
        "corpus_build_report": str(corpus_build_report_path),
        "corpus_build_summary": corpus_build_report.get("summary") or {},
        "yaml_summary": yaml_summary,
        "benchmark_profile": args.profile,
        "benchmark_config": str(benchmark_config_path) if benchmark_config_path is not None else None,
        "runner_binary": str(runner),
        "daemon_binary": str(daemon),
        "kernel_tree": str(kernel_tree),
        "kernel_image": str(kernel_image),
        "btf_custom_path": str(btf_custom_path) if btf_custom_path is not None else None,
        "vng_binary": args.vng,
        "repeat": args.repeat,
        "warmups": args.warmups,
        "batch_size": args.batch_size,
        "timeout_seconds": args.timeout,
        "guest_smoke": guest_smoke,
        "summary": summarize_corpus_batch_results(program_records, object_records),
        "object_records": object_records,
        "program_records": program_records,
    }
    current_target: dict[str, Any] | None = None
    current_target_index: int | None = None

    def build_artifact_metadata(
        status: str,
        session_started_at: str,
        updated_at: str,
        error_message: str | None,
    ) -> dict[str, Any]:
        result["summary"] = summarize_corpus_batch_results(program_records, object_records)
        progress = {
            "status": status,
            "total_objects": len(objects),
            "completed_objects": len(object_records),
            "total_programs": total_programs,
            "completed_programs": len(program_records),
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
                "macro_corpus_yaml": repo_relative_path(macro_corpus_yaml),
                "corpus_build_report": repo_relative_path(corpus_build_report_path),
                "corpus_build_summary": corpus_build_report.get("summary") or {},
                "yaml_summary": yaml_summary,
                "benchmark_profile": args.profile,
                "benchmark_config": repo_relative_path(benchmark_config_path) if benchmark_config_path is not None else None,
                "runner_binary": repo_relative_path(runner),
                "daemon_binary": repo_relative_path(daemon),
                "kernel_tree": repo_relative_path(kernel_tree),
                "kernel_image": repo_relative_path(kernel_image),
                "btf_custom_path": repo_relative_path(btf_custom_path) if btf_custom_path is not None else None,
                "guest_input_snapshots": {
                    "runner": repo_relative_path(runner_snapshot),
                    "daemon": repo_relative_path(daemon_snapshot),
                    "btf_custom_path": repo_relative_path(btf_snapshot) if btf_snapshot is not None else None,
                    "kinsn_module_dir": repo_relative_path(kinsn_module_snapshot),
                },
                "vng_binary": args.vng,
                "repeat": args.repeat,
                "warmups": args.warmups,
                "batch_size": args.batch_size,
                "timeout_seconds": args.timeout,
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
    snapshot_dir = artifact_dir / "guest-inputs"
    runner_snapshot = snapshot_guest_input(runner, snapshot_dir)
    daemon_snapshot = snapshot_guest_input(daemon, snapshot_dir)
    btf_snapshot = snapshot_guest_input(btf_custom_path, snapshot_dir) if btf_custom_path is not None else None
    kinsn_module_snapshot = snapshot_guest_tree(ROOT_DIR / "module", snapshot_dir / "module")

    def flush_artifact(status: str, *, error_message: str | None = None, include_markdown: bool = False) -> None:
        result["summary"] = summarize_corpus_batch_results(program_records, object_records)
        progress = {
            "status": status,
            "total_objects": len(objects),
            "completed_objects": len(object_records),
            "total_programs": total_programs,
            "completed_programs": len(program_records),
            "current_target_index": current_target_index,
            "current_target": current_target,
        }
        if error_message:
            progress["error_message"] = error_message
        detail_texts = {"result.md": build_markdown_v2(result)} if include_markdown else None
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
            print(
                "vm-corpus guest "
                f"kernel={payload.get('kernel_release', 'unknown')} "
                f"cwd={payload.get('cwd', 'unknown')}",
                flush=True,
            )

        def handle_guest_record(index: int, record: dict[str, Any]) -> None:
            nonlocal current_target_index, current_target
            current_target_index = index
            current_target = (
                {"canonical_object_name": objects[index - 1].canonical_name}
                if index - 1 < len(objects)
                else None
            )
            object_record = record.get("object_record")
            program_bundle = record.get("program_records")
            if isinstance(object_record, dict):
                object_records.append(object_record)
            if isinstance(program_bundle, list):
                for item in program_bundle:
                    if isinstance(item, dict):
                        program_records.append(item)
            flush_artifact("running")
            summary = result["summary"]
            object_name = None
            if isinstance(object_record, dict):
                object_name = object_record.get("canonical_object_name")
            print(
                "vm-corpus progress "
                f"objects={len(object_records)}/{len(objects)} "
                f"programs={len(program_records)}/{total_programs} "
                f"measured={summary['measured_pairs']} "
                f"comparable={summary['comparable_pairs']} "
                f"applied_comparable={summary['applied_comparable_pairs']} "
                f"applied_geomean={format_ratio(summary['exec_ratio_geomean'])} "
                f"object={object_name or 'unknown'}",
                flush=True,
            )

        batch_result = run_corpus_targets_in_guest_batch(
            targets=objects,
            guest_driver=str(DRIVER_RELATIVE),
            runner=runner_snapshot,
            daemon=daemon_snapshot,
            kernel_image=kernel_image,
            btf_custom_path=btf_snapshot,
            profile=args.profile,
            repeat=args.repeat,
            batch_size=args.batch_size,
            timeout_seconds=args.timeout,
            vng_binary=args.vng,
            kinsn_load_script=kinsn_module_snapshot / "load_all.sh",
            on_guest_info=handle_guest_info,
            on_record=handle_guest_record,
        )
        guest_invocation = batch_text_invocation_summary(batch_result["invocation"])
        guest_smoke["invocation"] = guest_invocation
        for record in object_records:
            record["guest_invocation"] = dict(guest_invocation) if guest_invocation is not None else None
        for record in program_records:
            record["guest_invocation"] = dict(guest_invocation) if guest_invocation is not None else None

        guest_batch_warning: str | None = None
        if not guest_smoke.get("payload"):
            smoke_error = (guest_smoke.get("invocation") or {}).get("error") or "guest smoke failed"
            raise RuntimeError(f"vm guest smoke failed: {smoke_error}")
        if not batch_result["invocation"]["ok"]:
            batch_error = batch_result["invocation"]["error"] or "guest batch failed"
            if batch_result.get("records_emitted") == len(objects):
                guest_batch_warning = (
                    "vm guest batch completed with non-zero exit after emitting all records: "
                    f"{batch_error}"
                )
            else:
                raise RuntimeError(f"vm guest batch failed: {batch_error}")

        current_target = None
        current_target_index = None
        flush_artifact(
            "completed_with_errors" if guest_batch_warning else "completed",
            error_message=guest_batch_warning,
            include_markdown=True,
        )
    except Exception as exc:
        flush_artifact("error", error_message=str(exc))
        raise
    summary = dict(result["summary"])
    print(f"Wrote {artifact_dir / 'metadata.json'}")
    print(
        f"mode={summary['effective_mode']} "
        f"objects={summary['objects_attempted']} "
        f"targets={summary['targets_attempted']} "
        f"compile_pairs={summary['compile_pairs']} "
        f"measured_pairs={summary['measured_pairs']} "
        f"comparable={summary['comparable_pairs']} "
        f"applied_comparable={summary['applied_comparable_pairs']} "
        f"applied={summary['applied_programs']}"
    )
    return 0
