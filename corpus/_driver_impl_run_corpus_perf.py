#!/usr/bin/env python3
from __future__ import annotations

import argparse
import json
import statistics
import subprocess
import sys
from collections import Counter
from datetime import datetime, timezone
from pathlib import Path
from typing import Any

SCRIPT_DIR = Path(__file__).resolve().parent
REPO_ROOT = SCRIPT_DIR.parent
for candidate in (REPO_ROOT, SCRIPT_DIR, REPO_ROOT / "micro", REPO_ROOT / "corpus"):
    candidate_str = str(candidate)
    if candidate_str not in sys.path:
        sys.path.insert(0, candidate_str)

from benchmark_catalog import ROOT_DIR, load_suite
try:
    from orchestrator.corpus import (
        build_kernel_command as orchestrator_build_kernel_command,
        directive_scan_from_record as orchestrator_directive_scan_from_record,
        ensure_parent as orchestrator_ensure_parent,
        execution_plan as orchestrator_execution_plan,
        format_ns as orchestrator_format_ns,
        infer_program_kind as orchestrator_infer_program_kind,
        invocation_summary as orchestrator_invocation_summary,
        markdown_table as orchestrator_markdown_table,
        materialize_dummy_context as orchestrator_materialize_dummy_context,
        materialize_dummy_packet as orchestrator_materialize_dummy_packet,
        normalize_section_root as orchestrator_normalize_section_root,
        relpath as orchestrator_relpath,
        run_command as orchestrator_run_command,
        summarize_failure_reason as orchestrator_summarize_failure_reason,
        summarize_stderr as orchestrator_summarize_stderr,
    )
    from orchestrator.inventory import discover_corpus_objects, discover_object_programs
    from orchestrator.results import parse_runner_sample
except ImportError:
    from micro.orchestrator.corpus import (
        build_kernel_command as orchestrator_build_kernel_command,
        directive_scan_from_record as orchestrator_directive_scan_from_record,
        ensure_parent as orchestrator_ensure_parent,
        execution_plan as orchestrator_execution_plan,
        format_ns as orchestrator_format_ns,
        infer_program_kind as orchestrator_infer_program_kind,
        invocation_summary as orchestrator_invocation_summary,
        markdown_table as orchestrator_markdown_table,
        materialize_dummy_context as orchestrator_materialize_dummy_context,
        materialize_dummy_packet as orchestrator_materialize_dummy_packet,
        normalize_section_root as orchestrator_normalize_section_root,
        relpath as orchestrator_relpath,
        run_command as orchestrator_run_command,
        summarize_failure_reason as orchestrator_summarize_failure_reason,
        summarize_stderr as orchestrator_summarize_stderr,
    )
    from micro.orchestrator.inventory import discover_corpus_objects, discover_object_programs
    from micro.orchestrator.results import parse_runner_sample
try:
    from common import (
        add_corpus_build_report_argument,
        add_filter_argument,
        add_max_programs_argument,
        add_output_json_argument,
        add_output_md_argument,
        add_repeat_argument,
        add_runner_argument,
        add_timeout_argument,
        format_ratio,
        geomean,
        require_minimum,
    )
except ImportError:
    from corpus.common import (
        add_corpus_build_report_argument,
        add_filter_argument,
        add_max_programs_argument,
        add_output_json_argument,
        add_output_md_argument,
        add_repeat_argument,
        add_runner_argument,
        add_timeout_argument,
        format_ratio,
        geomean,
        require_minimum,
    )


DEFAULT_REPEAT = 200
DEFAULT_TIMEOUT_SECONDS = 120
DEFAULT_OUTPUT_JSON = ROOT_DIR / "docs" / "tmp" / "corpus-perf-results.json"
DEFAULT_OUTPUT_MD = ROOT_DIR / "docs" / "tmp" / "corpus-perf-results.md"
DEFAULT_PACKET_PATH = ROOT_DIR / "micro" / "generated-inputs" / "corpus_dummy_packet_64.bin"
DEFAULT_CONTEXT_PATH = ROOT_DIR / "micro" / "generated-inputs" / "corpus_dummy_context_64.bin"
FAMILY_FIELDS = (
    ("CMOV", "cmov_sites"),
    ("WIDE", "wide_sites"),
    ("ROTATE", "rotate_sites"),
    ("LEA", "lea_sites"),
    ("EXTRACT", "bitfield_sites"),
    ("ZERO-EXT", "zero_ext_sites"),
    ("ENDIAN", "endian_sites"),
    ("BRANCH-FLIP", "branch_flip_sites"),
)


def parse_args(argv: list[str] | None = None) -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description="Run real-world corpus BPF programs under the kernel runtime and compare stock JIT against JIT recompile."
    )
    add_output_json_argument(parser, DEFAULT_OUTPUT_JSON, help_text="Path for structured JSON results.")
    add_output_md_argument(parser, DEFAULT_OUTPUT_MD, help_text="Path for markdown summary output.")
    add_runner_argument(parser, help_text="Path to the micro_exec runner binary. Defaults to the suite config runner path.")
    add_repeat_argument(parser, DEFAULT_REPEAT, help_text="Repeat count passed to bpf_prog_test_run_opts for measured runs.")
    add_timeout_argument(parser, DEFAULT_TIMEOUT_SECONDS, help_text="Per-invocation timeout in seconds.")
    add_filter_argument(parser, help_text="Only include corpus object paths containing this substring. Repeatable.")
    parser.add_argument(
        "--kind",
        action="append",
        dest="kinds",
        help=(
            "Only include programs of this inferred kind. Repeatable. "
            "Examples: xdp, tc, socket, classifier, tracing."
        ),
    )
    add_corpus_build_report_argument(
        parser,
        help_text=(
            "Optional expanded corpus build JSON report. When omitted, "
            "corpus/directive_census.py will use corpus/results/expanded_corpus_build.latest.json if present."
        ),
    )
    add_max_programs_argument(parser, help_text="Stop after processing this many discovered programs.")
    return parser.parse_args(argv)


def relpath(path: Path) -> str:
    return orchestrator_relpath(path, ROOT_DIR)


def ensure_parent(path: Path) -> None:
    orchestrator_ensure_parent(path)


def materialize_dummy_packet(path: Path) -> Path:
    return orchestrator_materialize_dummy_packet(path)


def materialize_dummy_context(path: Path, size: int = 64) -> Path:
    return orchestrator_materialize_dummy_context(path, size)


def run_command(command: list[str], timeout_seconds: int) -> dict[str, Any]:
    return orchestrator_run_command(command, timeout_seconds, cwd=ROOT_DIR)


def parse_runner_json(stdout: str) -> dict[str, Any]:
    return dict(parse_runner_sample(stdout))


def extract_error(stderr: str, stdout: str, returncode: int | None) -> str:
    for text in (stderr, stdout):
        lines = [line.strip() for line in text.splitlines() if line.strip()]
        if lines:
            return f"{lines[-1]} (exit={returncode})"
    return f"command failed (exit={returncode})"


def summarize_stderr(stderr: str, max_lines: int = 20, max_chars: int = 4000) -> str:
    return orchestrator_summarize_stderr(stderr, max_lines=max_lines, max_chars=max_chars)


def runner_binary_from_config() -> Path:
    suite = load_suite()
    return suite.build.runner_binary


def list_programs(runner: Path, object_path: Path, timeout_seconds: int) -> dict[str, Any]:
    try:
        inventory = [
            {
                "name": entry.name,
                "section_name": entry.section_name,
                "insn_count": entry.insn_count,
                "prog_type": entry.prog_type,
                "expected_attach_type": entry.expected_attach_type,
                "prog_type_name": entry.prog_type_name,
                "attach_type_name": entry.attach_type_name,
            }
            for entry in discover_object_programs(runner, object_path, timeout_seconds=timeout_seconds)
        ]
        return {
            "ok": True,
            "command": [str(runner), "list-programs", "--program", str(object_path)],
            "returncode": 0,
            "timed_out": False,
            "duration_seconds": 0.0,
            "stdout": "",
            "stderr": "",
            "sample": None,
            "error": None,
            "inventory": inventory,
        }
    except Exception as exc:
        return {
            "ok": False,
            "command": [str(runner), "list-programs", "--program", str(object_path)],
            "returncode": None,
            "timed_out": False,
            "duration_seconds": 0.0,
            "stdout": "",
            "stderr": "",
            "sample": None,
            "error": str(exc),
            "inventory": [],
        }


def normalize_section_root(section_name: str) -> str:
    return orchestrator_normalize_section_root(section_name)


def infer_program_kind(section_name: str) -> str:
    return orchestrator_infer_program_kind(section_name)


def program_label(program: dict[str, Any]) -> str:
    return f"{program['object_path']}:{program['program_name']}"


def build_kernel_command(
    runner: Path,
    object_path: Path,
    program_name: str,
    io_mode: str,
    memory_path: Path | None,
    input_size: int,
    repeat: int,
    *,
    compile_only: bool,
    recompile_all: bool,
) -> list[str]:
    return orchestrator_build_kernel_command(
        runner,
        object_path,
        program_name,
        io_mode,
        memory_path,
        input_size,
        repeat,
        compile_only=compile_only,
        recompile_all=recompile_all,
    )


def invocation_summary(result: dict[str, Any]) -> dict[str, Any]:
    return dict(orchestrator_invocation_summary(result) or {})


def directive_scan_from_record(record: dict[str, Any] | None) -> dict[str, int]:
    return orchestrator_directive_scan_from_record(record)


def compute_correctness(
    baseline_record: dict[str, Any] | None,
    recompile_record: dict[str, Any] | None,
) -> dict[str, Any]:
    if not baseline_record or not recompile_record:
        return {"comparable": False, "matches": None}
    if not baseline_record.get("ok") or not recompile_record.get("ok"):
        return {"comparable": False, "matches": None}

    baseline_sample = baseline_record["sample"]
    recompile_sample = recompile_record["sample"]
    matches = (
        baseline_sample.get("result") == recompile_sample.get("result")
        and baseline_sample.get("retval") == recompile_sample.get("retval")
    )
    return {
        "comparable": True,
        "matches": matches,
        "baseline_result": baseline_sample.get("result"),
        "baseline_retval": baseline_sample.get("retval"),
        "recompile_result": recompile_sample.get("result"),
        "recompile_retval": recompile_sample.get("retval"),
    }


def compute_speedup_ratio(
    baseline_record: dict[str, Any] | None,
    recompile_record: dict[str, Any] | None,
) -> float | None:
    if not baseline_record or not recompile_record:
        return None
    if not baseline_record.get("ok") or not recompile_record.get("ok"):
        return None
    baseline_exec_ns = baseline_record["sample"].get("exec_ns")
    recompile_exec_ns = recompile_record["sample"].get("exec_ns")
    if not baseline_exec_ns or not recompile_exec_ns:
        return None
    return float(baseline_exec_ns) / float(recompile_exec_ns)


def format_ns(value: Any) -> str:
    return orchestrator_format_ns(value)


def markdown_table(headers: list[str], rows: list[list[Any]]) -> list[str]:
    return orchestrator_markdown_table(headers, rows)


def summarize_failure_reason(record: dict[str, Any] | None) -> str:
    return orchestrator_summarize_failure_reason(record)


def run_program(
    runner: Path,
    io_mode: str,
    memory_path: Path | None,
    input_size: int,
    object_path: Path,
    program_name: str,
    repeat: int,
    timeout_seconds: int,
) -> dict[str, Any]:
    load_compile = run_command(
        build_kernel_command(
            runner,
            object_path,
            program_name,
            io_mode,
            memory_path,
            input_size,
            1,
            compile_only=True,
            recompile_all=False,
        ),
        timeout_seconds,
    )

    baseline_run: dict[str, Any] | None = None
    recompile_run: dict[str, Any] | None = None
    recompile_compile: dict[str, Any] | None = None

    if load_compile["ok"]:
        baseline_run = run_command(
            build_kernel_command(
                runner,
                object_path,
                program_name,
                io_mode,
                memory_path,
                input_size,
                repeat,
                compile_only=False,
                recompile_all=False,
            ),
            timeout_seconds,
        )

        if baseline_run["ok"]:
            recompile_run = run_command(
                build_kernel_command(
                    runner,
                    object_path,
                    program_name,
                    io_mode,
                    memory_path,
                    input_size,
                    repeat,
                    compile_only=False,
                    recompile_all=True,
                ),
                timeout_seconds,
            )
            if not recompile_run["ok"]:
                recompile_compile = run_command(
                    build_kernel_command(
                        runner,
                        object_path,
                        program_name,
                        io_mode,
                        memory_path,
                        input_size,
                        1,
                        compile_only=True,
                        recompile_all=True,
                    ),
                    timeout_seconds,
                )
        else:
            recompile_compile = run_command(
                build_kernel_command(
                    runner,
                    object_path,
                    program_name,
                    io_mode,
                    memory_path,
                    input_size,
                    1,
                    compile_only=True,
                    recompile_all=True,
                ),
                timeout_seconds,
            )

    metadata_source = None
    if recompile_run and recompile_run.get("ok"):
        metadata_source = recompile_run
    elif recompile_compile and recompile_compile.get("ok"):
        metadata_source = recompile_compile

    correctness = compute_correctness(baseline_run, recompile_run)
    speedup_ratio = compute_speedup_ratio(baseline_run, recompile_run)

    return {
        "load_compile": invocation_summary(load_compile),
        "baseline_run": invocation_summary(baseline_run) if baseline_run else None,
        "recompile_run": invocation_summary(recompile_run) if recompile_run else None,
        "recompile_compile": invocation_summary(recompile_compile) if recompile_compile else None,
        "metadata_source": "recompile_run" if metadata_source is recompile_run else (
            "recompile_compile" if metadata_source is recompile_compile else None
        ),
        "directive_scan": directive_scan_from_record(metadata_source),
        "correctness": correctness,
        "speedup_ratio": speedup_ratio,
    }


def build_summary(records: list[dict[str, Any]]) -> dict[str, Any]:
    loadable = [record for record in records if record["load_compile"]["ok"]]
    baseline_runnable = [record for record in records if record["baseline_run"] and record["baseline_run"]["ok"]]
    recompile_runnable = [record for record in records if record["recompile_run"] and record["recompile_run"]["ok"]]
    paired = [
        record for record in records
        if record["baseline_run"] and record["baseline_run"]["ok"]
        and record["recompile_run"] and record["recompile_run"]["ok"]
    ]
    directive_bearing = [record for record in loadable if record["directive_scan"]["total_sites"] > 0]
    paired_directive_bearing = [record for record in paired if record["directive_scan"]["total_sites"] > 0]

    speedups = [record["speedup_ratio"] for record in paired if record["speedup_ratio"] is not None]
    family_totals = Counter()
    for record in loadable:
        for _, field in FAMILY_FIELDS:
            family_totals[field] += record["directive_scan"].get(field, 0)

    failure_reasons = Counter()
    for record in records:
        if not record["load_compile"]["ok"]:
            failure_reasons[summarize_failure_reason(record["load_compile"])] += 1
        elif record["baseline_run"] and not record["baseline_run"]["ok"]:
            failure_reasons[summarize_failure_reason(record["baseline_run"])] += 1
        elif record["recompile_run"] and not record["recompile_run"]["ok"]:
            failure_reasons[summarize_failure_reason(record["recompile_run"])] += 1

    correctness_mismatches = [
        record for record in paired
        if record["correctness"]["comparable"] and record["correctness"]["matches"] is False
    ]

    return {
        "programs_found": len(records),
        "loadable_programs": len(loadable),
        "baseline_runnable_programs": len(baseline_runnable),
        "recompile_runnable_programs": len(recompile_runnable),
        "paired_measurements": len(paired),
        "directive_bearing_loadable_programs": len(directive_bearing),
        "directive_bearing_paired_programs": len(paired_directive_bearing),
        "correctness_mismatches": len(correctness_mismatches),
        "speedup_geomean": geomean([value for value in speedups if value is not None]),
        "speedup_median": statistics.median(speedups) if speedups else None,
        "speedup_min": min(speedups) if speedups else None,
        "speedup_max": max(speedups) if speedups else None,
        "family_totals": dict(family_totals),
        "failure_reasons": dict(failure_reasons.most_common(10)),
    }


def execution_plan(section_name: str, packet_path: Path, context_path: Path) -> dict[str, Any]:
    return orchestrator_execution_plan(section_name, packet_path, context_path)


def build_markdown(
    data: dict[str, Any],
    objects_found: int,
    skipped_non_bpf: list[str],
) -> str:
    summary = data["summary"]
    records = data["programs"]
    paired = [
        record for record in records
        if record["baseline_run"] and record["baseline_run"]["ok"]
        and record["recompile_run"] and record["recompile_run"]["ok"]
    ]
    paired.sort(key=lambda item: (item["object_path"], item["program_name"]))

    loadable_not_runnable = [
        record for record in records
        if record["load_compile"]["ok"]
        and not (record["baseline_run"] and record["baseline_run"]["ok"])
    ]
    loadable_not_runnable.sort(key=lambda item: (item["object_path"], item["program_name"]))

    load_failures = [
        record for record in records
        if not record["load_compile"]["ok"]
    ]
    load_failures.sort(key=lambda item: (item["object_path"], item["program_name"]))

    lines: list[str] = [
        "# Corpus BPF Runtime Performance Results",
        "",
        f"- Generated: {data['generated_at']}",
        f"- Runner: `{data['runner_binary']}`",
        f"- Dummy packet: `{data['dummy_packet_path']}`",
        f"- Dummy context: `{data['dummy_context_path']}`",
        f"- Corpus source: {data['corpus_source']}",
        f"- Corpus BPF objects discovered: {objects_found}",
        f"- Skipped non-BPF `.bpf.o` artifacts: {len(skipped_non_bpf)}",
        f"- Programs found: {summary['programs_found']}",
        f"- Loadable programs: {summary['loadable_programs']}",
        f"- Baseline-runnable programs: {summary['baseline_runnable_programs']}",
        f"- Recompile-runnable programs: {summary['recompile_runnable_programs']}",
        f"- Paired baseline/recompile measurements: {summary['paired_measurements']}",
        f"- Directive-bearing loadable programs: {summary['directive_bearing_loadable_programs']}",
        f"- Directive-bearing paired programs: {summary['directive_bearing_paired_programs']}",
        f"- Correctness mismatches: {summary['correctness_mismatches']}",
        f"- Speedup geomean (baseline/recompile): {format_ratio(summary['speedup_geomean'])}",
        f"- Speedup median (baseline/recompile): {format_ratio(summary['speedup_median'])}",
        "",
        "## Summary Statistics",
        "",
    ]

    stats_rows = [
        [f"{label} sites", summary["family_totals"].get(field, 0)]
        for label, field in FAMILY_FIELDS
    ]
    stats_rows.extend(
        [
            ["Speedup min", format_ratio(summary["speedup_min"])],
            ["Speedup max", format_ratio(summary["speedup_max"])],
        ]
    )
    lines.extend(markdown_table(["Metric", "Value"], stats_rows))
    lines.append("")

    if paired:
        lines.extend(
            [
                "## Runnable Programs",
                "",
            ]
        )
        paired_rows = []
        for record in paired:
            recompile_sample = record["recompile_run"]["sample"]
            recompile_meta = recompile_sample.get("recompile", {})
            correctness = record["correctness"]
            paired_rows.append(
                [
                    f"{record['object_path']}:{record['program_name']}",
                    record["section_name"],
                    format_ns(record["baseline_run"]["sample"].get("exec_ns")),
                    format_ns(recompile_sample.get("exec_ns")),
                    format_ratio(record["speedup_ratio"]),
                    "yes" if recompile_meta.get("applied") else "no",
                    "match" if correctness.get("matches") else "mismatch",
                    *[record["directive_scan"].get(field, 0) for _, field in FAMILY_FIELDS],
                ]
            )
        lines.extend(
            markdown_table(
                [
                    "Program",
                    "Section",
                    "Baseline ns",
                    "Recompile ns",
                    "Speedup",
                    "Applied",
                    "Correct",
                    *[label for label, _ in FAMILY_FIELDS],
                ],
                paired_rows,
            )
        )
        lines.append("")

    if loadable_not_runnable:
        lines.extend(
            [
                "## Loadable But Not Runnable",
                "",
            ]
        )
        rows = []
        for record in loadable_not_runnable:
            source = record["baseline_run"] or record["load_compile"]
            recompile_source = record["recompile_run"] or record["recompile_compile"]
            recompile_meta = {}
            if recompile_source and recompile_source.get("sample"):
                recompile_meta = recompile_source["sample"].get("recompile", {})
            rows.append(
                [
                    f"{record['object_path']}:{record['program_name']}",
                    record["section_name"],
                    "yes" if recompile_meta.get("applied") else "no",
                    *[record["directive_scan"].get(field, 0) for _, field in FAMILY_FIELDS],
                    summarize_failure_reason(source),
                ]
            )
        lines.extend(
            markdown_table(
                ["Program", "Section", "Applied", *[label for label, _ in FAMILY_FIELDS], "Failure"],
                rows,
            )
        )
        lines.append("")

    if load_failures:
        lines.extend(
            [
                "## Load Failures",
                "",
            ]
        )
        rows = [
            [
                f"{record['object_path']}:{record['program_name']}",
                record["section_name"],
                summarize_failure_reason(record["load_compile"]),
            ]
            for record in load_failures
        ]
        lines.extend(markdown_table(["Program", "Section", "Failure"], rows))
        lines.append("")

    if summary["failure_reasons"]:
        lines.extend(
            [
                "## Top Failure Reasons",
                "",
            ]
        )
        rows = [[reason, count] for reason, count in summary["failure_reasons"].items()]
        lines.extend(markdown_table(["Reason", "Count"], rows))
        lines.append("")

    inventory_failures = data.get("inventory_failures") or []
    if inventory_failures:
        lines.extend(
            [
                "## Inventory Failures",
                "",
            ]
        )
        rows = [
            [
                item["object_path"],
                item["error"],
            ]
            for item in inventory_failures
        ]
        lines.extend(markdown_table(["Object", "Failure"], rows))
        lines.append("")

    if skipped_non_bpf:
        lines.extend(
            [
                "## Skipped Non-BPF Artifacts",
                "",
            ]
        )
        lines.extend(markdown_table(["Path"], [[path] for path in skipped_non_bpf]))
        lines.append("")

    lines.extend(
        [
            "## Notes",
            "",
            "- Discovery reuses `corpus/directive_census.py` filtering, so only `EM_BPF` corpus objects are executed.",
            "- Execution uses the existing `micro_exec run-kernel` path with `bpf_prog_test_run_opts` and scanner-backed `--recompile-all`.",
            "- Non-runnable programs are expected in this corpus. The harness records load-only success separately from full runtime success.",
            "- Packet programs use the synthetic 64-byte Ethernet/IPv4/TCP packet, while non-packet programs use `context` mode with empty or zero-filled `ctx_in`.",
            "",
        ]
    )
    return "\n".join(lines)


def main(argv: list[str] | None = None) -> int:
    args = parse_args(argv)
    require_minimum(args.repeat, 1, "--repeat")

    runner = Path(args.runner).resolve() if args.runner else runner_binary_from_config()
    if not runner.exists():
        raise SystemExit(f"runner binary not found: {runner}")

    sudo_check = subprocess.run(["sudo", "-n", "true"], cwd=ROOT_DIR)
    if sudo_check.returncode != 0:
        raise SystemExit("sudo -n is required for corpus kernel runs")

    packet_path = materialize_dummy_packet(DEFAULT_PACKET_PATH)
    context_path = materialize_dummy_context(DEFAULT_CONTEXT_PATH)
    corpus_build_report = (
        Path(args.corpus_build_report).resolve() if args.corpus_build_report else None
    )

    inputs = discover_corpus_objects(ROOT_DIR, corpus_build_report=corpus_build_report)
    corpus_objects = list(inputs.corpus_paths)
    if args.filters:
        corpus_objects = [
            path for path in corpus_objects
            if any(token in relpath(path) for token in args.filters)
        ]

    program_records: list[dict[str, Any]] = []
    inventory_failures: list[dict[str, Any]] = []

    for object_path in corpus_objects:
        inventory = list_programs(runner, object_path, args.timeout)
        if not inventory["ok"]:
            inventory_failures.append(
                {
                    "object_path": relpath(object_path),
                    "error": inventory["error"],
                    "stderr_tail": summarize_stderr(inventory["stderr"]),
                }
            )
            continue

        for program in inventory.get("inventory", []):
            record = {
                "object_path": relpath(object_path),
                "program_name": str(program.get("name", "")),
                "section_name": str(program.get("section_name", "")),
                "insn_count": int(program.get("insn_count", 0)),
            }
            record["program_kind"] = infer_program_kind(record["section_name"])
            if args.kinds and record["program_kind"] not in set(args.kinds):
                continue
            plan = execution_plan(record["section_name"], packet_path, context_path)
            record["io_mode"] = plan["io_mode"]
            record["input_size"] = plan["input_size"]
            record["memory_path"] = (
                str(plan["memory_path"]) if plan["memory_path"] is not None else None
            )
            record.update(
                run_program(
                    runner,
                    plan["io_mode"],
                    plan["memory_path"],
                    plan["input_size"],
                    object_path,
                    record["program_name"],
                    args.repeat,
                    args.timeout,
                )
            )
            program_records.append(record)

            if args.max_programs is not None and len(program_records) >= args.max_programs:
                break

        if args.max_programs is not None and len(program_records) >= args.max_programs:
            break

    summary = build_summary(program_records)

    output_json = Path(args.output_json).resolve()
    output_md = Path(args.output_md).resolve()
    ensure_parent(output_json)
    ensure_parent(output_md)

    data = {
        "generated_at": datetime.now(timezone.utc).isoformat(),
        "repo_root": str(ROOT_DIR),
        "runner_binary": str(runner),
        "dummy_packet_path": str(packet_path),
        "dummy_context_path": str(context_path),
        "corpus_source": inputs.corpus_source,
        "repeat": args.repeat,
        "objects_found": len(corpus_objects),
        "inventory_failures": inventory_failures,
        "skipped_non_bpf_artifacts": list(inputs.skipped_non_bpf),
        "summary": summary,
        "programs": program_records,
    }

    output_json.write_text(json.dumps(data, indent=2) + "\n")
    output_md.write_text(build_markdown(data, len(corpus_objects), list(inputs.skipped_non_bpf)) + "\n")

    print(f"Wrote {output_json}")
    print(f"Wrote {output_md}")
    print(
        f"Programs found={summary['programs_found']} "
        f"loadable={summary['loadable_programs']} "
        f"paired={summary['paired_measurements']}"
    )
    return 0


if __name__ == "__main__":
    sys.exit(main())
