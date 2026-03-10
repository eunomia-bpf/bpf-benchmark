#!/usr/bin/env python3
from __future__ import annotations

import argparse
import json
import math
import os
import statistics
import subprocess
import sys
import time
from collections import Counter
from datetime import datetime, timezone
from pathlib import Path
from typing import Any


ROOT_DIR = Path(__file__).resolve().parent.parent
DEFAULT_OUTPUT_JSON = ROOT_DIR / "docs" / "tmp" / "corpus-v5-recompile-results.json"
DEFAULT_OUTPUT_MD = ROOT_DIR / "docs" / "tmp" / "corpus-v5-recompile-results.md"
DEFAULT_RUNNER = ROOT_DIR / "micro" / "build" / "runner" / "micro_exec"
DEFAULT_BTF_PATH = ROOT_DIR / "vendor" / "linux-framework" / "vmlinux"
DEFAULT_PERF_RESULTS = ROOT_DIR / "docs" / "tmp" / "corpus-perf-results.json"
DEFAULT_TRACING_RESULTS = ROOT_DIR / "docs" / "tmp" / "corpus-tracing-results.json"
DEFAULT_PACKET_PATH = ROOT_DIR / "micro" / "generated-inputs" / "corpus_dummy_packet_64.bin"
DEFAULT_CONTEXT_PATH = ROOT_DIR / "micro" / "generated-inputs" / "corpus_dummy_context_64.bin"
DEFAULT_REPEAT = 5
DEFAULT_TIMEOUT_SECONDS = 120


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description=(
            "Run the 40-program directive-bearing corpus union on the framework kernel "
            "with baseline and v5 recompile, using compile-only probes for all targets "
            "and timed runs for the bpf_prog_test_run-capable subset."
        )
    )
    parser.add_argument(
        "--output-json",
        default=str(DEFAULT_OUTPUT_JSON),
        help="Path for structured JSON output.",
    )
    parser.add_argument(
        "--output-md",
        default=str(DEFAULT_OUTPUT_MD),
        help="Path for markdown output.",
    )
    parser.add_argument(
        "--runner",
        default=str(DEFAULT_RUNNER),
        help="Path to the micro_exec runner.",
    )
    parser.add_argument(
        "--btf-custom-path",
        default=str(DEFAULT_BTF_PATH),
        help="Path to the framework-kernel vmlinux BTF file.",
    )
    parser.add_argument(
        "--perf-results-json",
        default=str(DEFAULT_PERF_RESULTS),
        help="Existing corpus perf JSON used to derive the 40-program union.",
    )
    parser.add_argument(
        "--tracing-results-json",
        default=str(DEFAULT_TRACING_RESULTS),
        help="Existing corpus tracing JSON used to derive the 40-program union.",
    )
    parser.add_argument(
        "--repeat",
        type=int,
        default=DEFAULT_REPEAT,
        help="Repeat count for measured runs.",
    )
    parser.add_argument(
        "--timeout",
        type=int,
        default=DEFAULT_TIMEOUT_SECONDS,
        help="Per-invocation timeout in seconds.",
    )
    parser.add_argument(
        "--max-programs",
        type=int,
        help="Optional cap for smoke testing.",
    )
    parser.add_argument(
        "--filter",
        action="append",
        dest="filters",
        help="Only include target programs whose object path or name contains this substring. Repeatable.",
    )
    return parser.parse_args()


def ensure_parent(path: Path) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)


def maybe_sudo_prefix() -> list[str]:
    return [] if os.geteuid() == 0 else ["sudo", "-n"]


def materialize_dummy_packet(path: Path) -> Path:
    ensure_parent(path)
    if path.exists() and path.stat().st_size == 64:
        return path

    packet = bytearray(64)
    packet[0:6] = bytes.fromhex("001122334455")
    packet[6:12] = bytes.fromhex("66778899aabb")
    packet[12:14] = bytes.fromhex("0800")
    packet[14] = 0x45
    packet[15] = 0x00
    packet[16:18] = (50).to_bytes(2, "big")
    packet[18:20] = (0).to_bytes(2, "big")
    packet[20:22] = (0x4000).to_bytes(2, "big")
    packet[22] = 64
    packet[23] = 6
    packet[24:26] = (0).to_bytes(2, "big")
    packet[26:30] = bytes([192, 0, 2, 1])
    packet[30:34] = bytes([198, 51, 100, 2])
    packet[34:36] = (12345).to_bytes(2, "big")
    packet[36:38] = (80).to_bytes(2, "big")
    packet[38:42] = (1).to_bytes(4, "big")
    packet[42:46] = (0).to_bytes(4, "big")
    packet[46] = 0x50
    packet[47] = 0x02
    packet[48:50] = (8192).to_bytes(2, "big")
    packet[50:52] = (0).to_bytes(2, "big")
    packet[52:54] = (0).to_bytes(2, "big")
    path.write_bytes(packet)
    return path


def materialize_dummy_context(path: Path, size: int = 64) -> Path:
    ensure_parent(path)
    if path.exists() and path.stat().st_size == size:
        return path
    path.write_bytes(bytes(size))
    return path


def normalize_section_root(section_name: str) -> str:
    if not section_name:
        return "unknown"
    root = section_name.split("/", 1)[0]
    if root.startswith("kprobe"):
        return "kprobe"
    if root.startswith("kretprobe"):
        return "kretprobe"
    if root.startswith("raw_tp"):
        return "raw_tp"
    return root


def execution_plan(section_name: str, packet_path: Path, context_path: Path) -> dict[str, Any]:
    root = normalize_section_root(section_name)
    if root in {"xdp", "socket", "classifier", "tc", "flow_dissector", "sk_skb", "sk_msg"}:
        return {
            "io_mode": "packet",
            "memory_path": packet_path,
            "input_size": 64,
        }
    if root in {"raw_tracepoint", "raw_tp"}:
        return {
            "io_mode": "context",
            "memory_path": context_path,
            "input_size": 64,
        }
    return {
        "io_mode": "context",
        "memory_path": None,
        "input_size": 0,
    }


def parse_runner_json(stdout: str) -> dict[str, Any]:
    lines = [line.strip() for line in stdout.splitlines() if line.strip()]
    if not lines:
        raise RuntimeError("runner produced no JSON output")
    return json.loads(lines[-1])


def extract_error(stderr: str, stdout: str, returncode: int | None) -> str:
    for text in (stderr, stdout):
        lines = [line.strip() for line in text.splitlines() if line.strip()]
        if lines:
            return f"{lines[-1]} (exit={returncode})"
    return f"command failed (exit={returncode})"


def summarize_stderr(stderr: str, max_lines: int = 20, max_chars: int = 4000) -> str:
    lines = [line.rstrip() for line in stderr.splitlines() if line.strip()]
    if len(lines) > max_lines:
        lines = lines[-max_lines:]
    summary = "\n".join(lines)
    if len(summary) > max_chars:
        summary = summary[-max_chars:]
    return summary


def run_command(command: list[str], timeout_seconds: int) -> dict[str, Any]:
    start = time.monotonic()
    try:
        completed = subprocess.run(
            command,
            cwd=ROOT_DIR,
            capture_output=True,
            text=True,
            timeout=timeout_seconds,
        )
    except subprocess.TimeoutExpired as exc:
        duration_seconds = time.monotonic() - start
        return {
            "ok": False,
            "command": command,
            "returncode": None,
            "timed_out": True,
            "duration_seconds": duration_seconds,
            "stdout": exc.stdout or "",
            "stderr": exc.stderr or "",
            "sample": None,
            "error": f"timeout after {timeout_seconds}s",
        }

    duration_seconds = time.monotonic() - start
    stdout = completed.stdout or ""
    stderr = completed.stderr or ""
    sample = None
    parse_error = None
    if completed.returncode == 0:
        try:
            sample = parse_runner_json(stdout)
        except Exception as exc:
            parse_error = str(exc)

    ok = completed.returncode == 0 and sample is not None
    error = parse_error if parse_error is not None else None
    if not ok and error is None:
        error = extract_error(stderr, stdout, completed.returncode)

    return {
        "ok": ok,
        "command": command,
        "returncode": completed.returncode,
        "timed_out": False,
        "duration_seconds": duration_seconds,
        "stdout": stdout,
        "stderr": stderr,
        "sample": sample,
        "error": error,
    }


def invocation_summary(result: dict[str, Any] | None) -> dict[str, Any] | None:
    if result is None:
        return None
    return {
        "ok": result["ok"],
        "returncode": result["returncode"],
        "timed_out": result["timed_out"],
        "duration_seconds": result["duration_seconds"],
        "error": result["error"],
        "stderr_tail": summarize_stderr(result["stderr"]),
        "sample": result["sample"],
    }


def directive_scan_from_record(record: dict[str, Any] | None) -> dict[str, int]:
    if not record or not record.get("ok") or not record.get("sample"):
        return {
            "cmov_sites": 0,
            "wide_sites": 0,
            "rotate_sites": 0,
            "lea_sites": 0,
            "total_sites": 0,
        }
    scan = record["sample"].get("directive_scan") or {}
    return {
        "cmov_sites": int(scan.get("cmov_sites", 0) or 0),
        "wide_sites": int(scan.get("wide_sites", 0) or 0),
        "rotate_sites": int(scan.get("rotate_sites", 0) or 0),
        "lea_sites": int(scan.get("lea_sites", 0) or 0),
        "total_sites": int(scan.get("total_sites", 0) or 0),
    }


def format_ratio(value: float | None) -> str:
    if value is None:
        return "n/a"
    return f"{value:.3f}x"


def format_pct(value: float | None) -> str:
    if value is None:
        return "n/a"
    return f"{value:+.1f}%"


def format_ns(value: Any) -> str:
    if value is None:
        return "n/a"
    return str(int(value))


def markdown_table(headers: list[str], rows: list[list[Any]]) -> list[str]:
    lines = [
        "| " + " | ".join(headers) + " |",
        "| " + " | ".join("---" for _ in headers) + " |",
    ]
    for row in rows:
        lines.append("| " + " | ".join(str(cell) for cell in row) + " |")
    return lines


def geomean(values: list[float]) -> float | None:
    positive = [value for value in values if value > 0]
    if not positive:
        return None
    return math.exp(statistics.mean(math.log(value) for value in positive))


def json_load(path: Path) -> dict[str, Any]:
    return json.loads(path.read_text())


def target_key(record: dict[str, Any]) -> tuple[str, str]:
    return (str(record["object_path"]), str(record["program_name"]))


def family_counts(record: dict[str, Any]) -> dict[str, int]:
    scan = record.get("directive_scan") or {}
    return {
        "cmov_sites": int(scan.get("cmov_sites", 0) or 0),
        "wide_sites": int(scan.get("wide_sites", 0) or 0),
        "rotate_sites": int(scan.get("rotate_sites", 0) or 0),
        "lea_sites": int(scan.get("lea_sites", 0) or 0),
        "total_sites": int(scan.get("total_sites", 0) or 0),
    }


def build_target_union(
    perf_results_path: Path,
    tracing_results_path: Path,
) -> list[dict[str, Any]]:
    perf_data = json_load(perf_results_path)
    tracing_data = json_load(tracing_results_path)

    perf_targets: dict[tuple[str, str], dict[str, Any]] = {}
    tracing_targets: dict[tuple[str, str], dict[str, Any]] = {}

    for record in perf_data.get("programs", []):
        if family_counts(record)["total_sites"] <= 0:
            continue
        baseline_ok = bool((record.get("baseline_run") or {}).get("ok"))
        recompile_ok = bool((record.get("recompile_run") or {}).get("ok"))
        if not (baseline_ok and recompile_ok):
            continue
        key = target_key(record)
        perf_targets[key] = {
            "object_path": str(record["object_path"]),
            "program_name": str(record["program_name"]),
            "section_name": str(record["section_name"]),
            "host_directive_scan": family_counts(record),
        }

    for record in tracing_data.get("programs", []):
        measurement = record.get("measurement") or {}
        if family_counts(record)["total_sites"] <= 0:
            continue
        if not (measurement.get("ok") and int(measurement.get("run_cnt_delta", 0) or 0) > 0):
            continue
        key = target_key(record)
        tracing_targets[key] = {
            "object_path": str(record["object_path"]),
            "program_name": str(record["program_name"]),
            "section_name": str(record["section_name"]),
            "host_directive_scan": family_counts(record),
        }

    union: dict[tuple[str, str], dict[str, Any]] = {}
    for key, record in perf_targets.items():
        union[key] = {
            **record,
            "perf_capable": True,
            "tracing_measured": key in tracing_targets,
        }
    for key, record in tracing_targets.items():
        if key not in union:
            union[key] = {
                **record,
                "perf_capable": False,
                "tracing_measured": True,
            }
        else:
            union[key]["tracing_measured"] = True

    targets = sorted(
        union.values(),
        key=lambda item: (item["object_path"], item["program_name"]),
    )
    if len(targets) != 40:
        raise SystemExit(
            f"expected 40 target programs from the existing perf+tracing union, found {len(targets)}"
        )
    for record in targets:
        record["section_root"] = normalize_section_root(record["section_name"])
    return targets


def build_runner_command(
    runner: Path,
    btf_custom_path: Path | None,
    object_path: Path,
    program_name: str,
    io_mode: str,
    memory_path: Path | None,
    input_size: int,
    repeat: int,
    *,
    compile_only: bool,
    recompile_v5: bool,
) -> list[str]:
    command = maybe_sudo_prefix() + [
        str(runner),
        "run-kernel",
        "--program",
        str(object_path),
        "--program-name",
        program_name,
        "--io-mode",
        io_mode,
        "--repeat",
        str(max(1, repeat)),
    ]
    if io_mode == "packet":
        command.append("--raw-packet")
    if memory_path is not None:
        command.extend(["--memory", str(memory_path)])
    if input_size > 0:
        command.extend(["--input-size", str(input_size)])
    if btf_custom_path is not None:
        command.extend(["--btf-custom-path", str(btf_custom_path)])
    if recompile_v5:
        command.extend(["--recompile-v5", "--recompile-all"])
    if compile_only:
        command.append("--compile-only")
    return command


def size_ratio(baseline_record: dict[str, Any] | None, v5_record: dict[str, Any] | None) -> float | None:
    if not baseline_record or not v5_record:
        return None
    if not baseline_record.get("ok") or not v5_record.get("ok"):
        return None
    baseline_len = (baseline_record.get("sample") or {}).get("jited_prog_len")
    v5_len = (v5_record.get("sample") or {}).get("jited_prog_len")
    if not baseline_len or not v5_len:
        return None
    return float(baseline_len) / float(v5_len)


def size_delta_pct(baseline_record: dict[str, Any] | None, v5_record: dict[str, Any] | None) -> float | None:
    if not baseline_record or not v5_record:
        return None
    if not baseline_record.get("ok") or not v5_record.get("ok"):
        return None
    baseline_len = (baseline_record.get("sample") or {}).get("jited_prog_len")
    v5_len = (v5_record.get("sample") or {}).get("jited_prog_len")
    if baseline_len is None or v5_len is None or baseline_len == 0:
        return None
    return (float(v5_len) - float(baseline_len)) * 100.0 / float(baseline_len)


def speedup_ratio(baseline_record: dict[str, Any] | None, v5_record: dict[str, Any] | None) -> float | None:
    if not baseline_record or not v5_record:
        return None
    if not baseline_record.get("ok") or not v5_record.get("ok"):
        return None
    baseline_ns = (baseline_record.get("sample") or {}).get("exec_ns")
    v5_ns = (v5_record.get("sample") or {}).get("exec_ns")
    if not baseline_ns or not v5_ns:
        return None
    return float(baseline_ns) / float(v5_ns)


def summarize_failure_reason(record: dict[str, Any] | None) -> str:
    if not record:
        return "n/a"
    if record.get("error"):
        return str(record["error"])
    sample = record.get("sample") or {}
    recompile = sample.get("recompile") or {}
    if recompile.get("error"):
        return str(recompile["error"])
    return "unknown"


def run_target(
    runner: Path,
    btf_custom_path: Path | None,
    packet_path: Path,
    context_path: Path,
    target: dict[str, Any],
    repeat: int,
    timeout_seconds: int,
) -> dict[str, Any]:
    object_path = ROOT_DIR / target["object_path"]
    plan = execution_plan(target["section_name"], packet_path, context_path)

    baseline_compile_raw = run_command(
        build_runner_command(
            runner,
            btf_custom_path,
            object_path,
            target["program_name"],
            plan["io_mode"],
            plan["memory_path"],
            plan["input_size"],
            1,
            compile_only=True,
            recompile_v5=False,
        ),
        timeout_seconds,
    )
    v5_compile_raw = run_command(
        build_runner_command(
            runner,
            btf_custom_path,
            object_path,
            target["program_name"],
            plan["io_mode"],
            plan["memory_path"],
            plan["input_size"],
            1,
            compile_only=True,
            recompile_v5=True,
        ),
        timeout_seconds,
    )

    baseline_run_raw: dict[str, Any] | None = None
    v5_run_raw: dict[str, Any] | None = None
    if target["perf_capable"] and baseline_compile_raw["ok"]:
        baseline_run_raw = run_command(
            build_runner_command(
                runner,
                btf_custom_path,
                object_path,
                target["program_name"],
                plan["io_mode"],
                plan["memory_path"],
                plan["input_size"],
                repeat,
                compile_only=False,
                recompile_v5=False,
            ),
            timeout_seconds,
        )
        if baseline_run_raw["ok"]:
            v5_run_raw = run_command(
                build_runner_command(
                    runner,
                    btf_custom_path,
                    object_path,
                    target["program_name"],
                    plan["io_mode"],
                    plan["memory_path"],
                    plan["input_size"],
                    repeat,
                    compile_only=False,
                    recompile_v5=True,
                ),
                timeout_seconds,
            )

    baseline_compile = invocation_summary(baseline_compile_raw)
    v5_compile = invocation_summary(v5_compile_raw)
    baseline_run = invocation_summary(baseline_run_raw)
    v5_run = invocation_summary(v5_run_raw)

    return {
        **target,
        "io_mode": plan["io_mode"],
        "input_size": plan["input_size"],
        "memory_path": str(plan["memory_path"]) if plan["memory_path"] is not None else None,
        "baseline_compile": baseline_compile,
        "v5_compile": v5_compile,
        "baseline_run": baseline_run,
        "v5_run": v5_run,
        "framework_directive_scan": directive_scan_from_record(v5_compile_raw),
        "v5_compile_applied": bool(((v5_compile or {}).get("sample") or {}).get("recompile", {}).get("applied")),
        "v5_run_applied": bool(((v5_run or {}).get("sample") or {}).get("recompile", {}).get("applied")),
        "size_ratio": size_ratio(baseline_compile_raw, v5_compile_raw),
        "size_delta_pct": size_delta_pct(baseline_compile_raw, v5_compile_raw),
        "speedup_ratio": speedup_ratio(baseline_run_raw, v5_run_raw),
    }


def build_summary(records: list[dict[str, Any]]) -> dict[str, Any]:
    compile_pairs = [
        record
        for record in records
        if record["baseline_compile"] and record["baseline_compile"]["ok"]
        and record["v5_compile"] and record["v5_compile"]["ok"]
    ]
    measured_pairs = [
        record
        for record in records
        if record["baseline_run"] and record["baseline_run"]["ok"]
        and record["v5_run"] and record["v5_run"]["ok"]
    ]
    framework_detected = [
        record for record in records if record["framework_directive_scan"]["total_sites"] > 0
    ]
    recompile_applied = [
        record for record in records if record["v5_compile_applied"] or record["v5_run_applied"]
    ]

    speedups = [record["speedup_ratio"] for record in measured_pairs if record["speedup_ratio"] is not None]
    size_ratios = [record["size_ratio"] for record in compile_pairs if record["size_ratio"] is not None]
    size_deltas = [record["size_delta_pct"] for record in compile_pairs if record["size_delta_pct"] is not None]

    family_totals = Counter()
    for record in framework_detected:
        family_totals["cmov_sites"] += record["framework_directive_scan"]["cmov_sites"]
        family_totals["wide_sites"] += record["framework_directive_scan"]["wide_sites"]
        family_totals["rotate_sites"] += record["framework_directive_scan"]["rotate_sites"]
        family_totals["lea_sites"] += record["framework_directive_scan"]["lea_sites"]

    failure_reasons = Counter()
    for record in records:
        if not (record["baseline_compile"] and record["baseline_compile"]["ok"]):
            failure_reasons[summarize_failure_reason(record["baseline_compile"])] += 1
            continue
        if not (record["v5_compile"] and record["v5_compile"]["ok"]):
            failure_reasons[summarize_failure_reason(record["v5_compile"])] += 1
            continue
        if record["perf_capable"] and record["baseline_run"] and not record["baseline_run"]["ok"]:
            failure_reasons[summarize_failure_reason(record["baseline_run"])] += 1
            continue
        if record["perf_capable"] and record["v5_run"] and not record["v5_run"]["ok"]:
            failure_reasons[summarize_failure_reason(record["v5_run"])] += 1

    return {
        "programs_attempted": len(records),
        "perf_capable_targets": sum(1 for record in records if record["perf_capable"]),
        "tracing_only_targets": sum(1 for record in records if not record["perf_capable"]),
        "baseline_compile_successes": sum(1 for record in records if record["baseline_compile"] and record["baseline_compile"]["ok"]),
        "v5_compile_successes": sum(1 for record in records if record["v5_compile"] and record["v5_compile"]["ok"]),
        "framework_detected_programs": len(framework_detected),
        "framework_recompile_applied_programs": len(recompile_applied),
        "compile_pairs": len(compile_pairs),
        "measured_pairs": len(measured_pairs),
        "speedup_geomean": geomean([value for value in speedups if value is not None]),
        "speedup_median": statistics.median(speedups) if speedups else None,
        "speedup_min": min(speedups) if speedups else None,
        "speedup_max": max(speedups) if speedups else None,
        "code_size_ratio_geomean": geomean([value for value in size_ratios if value is not None]),
        "code_size_delta_median_pct": statistics.median(size_deltas) if size_deltas else None,
        "code_size_delta_min_pct": min(size_deltas) if size_deltas else None,
        "code_size_delta_max_pct": max(size_deltas) if size_deltas else None,
        "family_totals": dict(family_totals),
        "failure_reasons": dict(failure_reasons.most_common(12)),
    }


def build_markdown(data: dict[str, Any]) -> str:
    summary = data["summary"]
    records = data["programs"]
    compile_rows = sorted(records, key=lambda item: (item["object_path"], item["program_name"]))
    measured_rows = [
        record
        for record in compile_rows
        if record["baseline_run"] and record["baseline_run"]["ok"]
        and record["v5_run"] and record["v5_run"]["ok"]
    ]
    measured_rows.sort(key=lambda item: (item["object_path"], item["program_name"]))

    lines: list[str] = [
        "# Framework-Kernel Corpus v5 Recompile Results",
        "",
        f"- Generated: {data['generated_at']}",
        f"- Repo root: `{data['repo_root']}`",
        f"- Runner: `{data['runner_binary']}`",
        f"- BTF path: `{data['btf_custom_path']}`",
        f"- Repeat: {data['repeat']}",
        f"- Programs attempted: {summary['programs_attempted']}",
        f"- Perf-capable targets: {summary['perf_capable_targets']}",
        f"- Tracing-only compile targets: {summary['tracing_only_targets']}",
        "",
        "## Summary",
        "",
    ]
    lines.extend(
        markdown_table(
            ["Metric", "Value"],
            [
                ["Baseline compile successes", summary["baseline_compile_successes"]],
                ["v5 compile successes", summary["v5_compile_successes"]],
                ["Programs with framework-detected sites", summary["framework_detected_programs"]],
                ["Programs with recompile applied", summary["framework_recompile_applied_programs"]],
                ["Compile-only size pairs", summary["compile_pairs"]],
                ["Measured runtime pairs", summary["measured_pairs"]],
                ["Speedup geomean", format_ratio(summary["speedup_geomean"])],
                ["Speedup median", format_ratio(summary["speedup_median"])],
                ["Speedup min", format_ratio(summary["speedup_min"])],
                ["Speedup max", format_ratio(summary["speedup_max"])],
                ["Code-size ratio geomean (baseline/v5)", format_ratio(summary["code_size_ratio_geomean"])],
                ["Code-size median delta", format_pct(summary["code_size_delta_median_pct"])],
                ["Code-size min delta", format_pct(summary["code_size_delta_min_pct"])],
                ["Code-size max delta", format_pct(summary["code_size_delta_max_pct"])],
                ["Framework CMOV sites", summary["family_totals"].get("cmov_sites", 0)],
                ["Framework WIDE sites", summary["family_totals"].get("wide_sites", 0)],
                ["Framework ROTATE sites", summary["family_totals"].get("rotate_sites", 0)],
                ["Framework LEA sites", summary["family_totals"].get("lea_sites", 0)],
            ],
        )
    )
    lines.extend(
        [
            "",
            "## Target Programs",
            "",
        ]
    )
    target_rows = [
        [
            f"{record['object_path']}:{record['program_name']}",
            record["section_name"],
            "yes" if record["perf_capable"] else "no",
            "yes" if record["tracing_measured"] else "no",
            record["host_directive_scan"]["cmov_sites"],
            record["host_directive_scan"]["wide_sites"],
            record["host_directive_scan"]["rotate_sites"],
            record["host_directive_scan"]["lea_sites"],
        ]
        for record in compile_rows
    ]
    lines.extend(
        markdown_table(
            ["Program", "Section", "Perf-capable", "Tracing-measured", "CMOV", "WIDE", "ROTATE", "LEA"],
            target_rows,
        )
    )
    lines.extend(
        [
            "",
            "## Compile-Only Results",
            "",
        ]
    )
    compile_table_rows = []
    for record in compile_rows:
        baseline_sample = (record["baseline_compile"] or {}).get("sample") or {}
        v5_sample = (record["v5_compile"] or {}).get("sample") or {}
        compile_table_rows.append(
            [
                f"{record['object_path']}:{record['program_name']}",
                record["section_name"],
                "yes" if (record["baseline_compile"] and record["baseline_compile"]["ok"]) else "no",
                "yes" if (record["v5_compile"] and record["v5_compile"]["ok"]) else "no",
                record["framework_directive_scan"]["total_sites"],
                "yes" if record["v5_compile_applied"] else "no",
                format_ns(baseline_sample.get("jited_prog_len")),
                format_ns(v5_sample.get("jited_prog_len")),
                format_pct(record["size_delta_pct"]),
                summarize_failure_reason(record["v5_compile"]) if not record["v5_compile_applied"] else "",
            ]
        )
    lines.extend(
        markdown_table(
            [
                "Program",
                "Section",
                "Baseline Load",
                "v5 Load",
                "v5 Sites",
                "Applied",
                "Baseline JIT Bytes",
                "v5 JIT Bytes",
                "Delta",
                "Note",
            ],
            compile_table_rows,
        )
    )

    if measured_rows:
        lines.extend(
            [
                "",
                "## Measured Runtime Results",
                "",
            ]
        )
        measured_table_rows = []
        for record in measured_rows:
            baseline_sample = (record["baseline_run"] or {}).get("sample") or {}
            v5_sample = (record["v5_run"] or {}).get("sample") or {}
            measured_table_rows.append(
                [
                    f"{record['object_path']}:{record['program_name']}",
                    record["section_name"],
                    format_ns(baseline_sample.get("exec_ns")),
                    format_ns(v5_sample.get("exec_ns")),
                    format_ratio(record["speedup_ratio"]),
                    "yes" if record["v5_run_applied"] else "no",
                    format_ns((record["baseline_compile"] or {}).get("sample", {}).get("jited_prog_len")),
                    format_ns((record["v5_compile"] or {}).get("sample", {}).get("jited_prog_len")),
                ]
            )
        lines.extend(
            markdown_table(
                [
                    "Program",
                    "Section",
                    "Baseline ns",
                    "v5 ns",
                    "Speedup",
                    "Applied",
                    "Baseline JIT Bytes",
                    "v5 JIT Bytes",
                ],
                measured_table_rows,
            )
        )

    if summary["failure_reasons"]:
        lines.extend(
            [
                "",
                "## Top Failure Reasons",
                "",
            ]
        )
        lines.extend(
            markdown_table(
                ["Reason", "Count"],
                [[reason, count] for reason, count in summary["failure_reasons"].items()],
            )
        )

    lines.extend(
        [
            "",
            "## Notes",
            "",
            "- The 40 target programs are the union of the previously measured directive-bearing perf and tracing results from the expanded corpus.",
            "- Baseline and v5 compile-only probes were attempted for all 40 targets on the framework kernel.",
            "- Timed runs were attempted only for the 29 targets that were previously runnable through `bpf_prog_test_run`.",
            "- Guest CO-RE loading uses `--btf-custom-path` pointing at the framework build-tree `vmlinux`, because the guest kernel does not expose `/sys/kernel/btf/vmlinux`.",
            "",
        ]
    )
    return "\n".join(lines)


def main() -> int:
    args = parse_args()
    if args.repeat < 1:
        raise SystemExit("--repeat must be >= 1")

    runner = Path(args.runner).resolve()
    if not runner.exists():
        raise SystemExit(f"runner binary not found: {runner}")

    btf_custom_path = Path(args.btf_custom_path).resolve() if args.btf_custom_path else None
    if btf_custom_path is not None and not btf_custom_path.exists():
        raise SystemExit(f"btf custom path not found: {btf_custom_path}")

    perf_results_path = Path(args.perf_results_json).resolve()
    tracing_results_path = Path(args.tracing_results_json).resolve()
    if not perf_results_path.exists():
        raise SystemExit(f"perf results JSON not found: {perf_results_path}")
    if not tracing_results_path.exists():
        raise SystemExit(f"tracing results JSON not found: {tracing_results_path}")

    packet_path = materialize_dummy_packet(DEFAULT_PACKET_PATH)
    context_path = materialize_dummy_context(DEFAULT_CONTEXT_PATH)

    targets = build_target_union(perf_results_path, tracing_results_path)
    if args.filters:
        targets = [
            record
            for record in targets
            if any(
                token in record["object_path"]
                or token in record["program_name"]
                or token in record["section_name"]
                for token in args.filters
            )
        ]
    if args.max_programs is not None:
        targets = targets[:args.max_programs]

    records: list[dict[str, Any]] = []
    for index, target in enumerate(targets, start=1):
        print(
            f"[{index}/{len(targets)}] {target['object_path']}:{target['program_name']} "
            f"({target['section_name']})",
            file=sys.stderr,
            flush=True,
        )
        records.append(
            run_target(
                runner,
                btf_custom_path,
                packet_path,
                context_path,
                target,
                args.repeat,
                args.timeout,
            )
        )

    summary = build_summary(records)

    output_json = Path(args.output_json).resolve()
    output_md = Path(args.output_md).resolve()
    ensure_parent(output_json)
    ensure_parent(output_md)

    data = {
        "generated_at": datetime.now(timezone.utc).isoformat(),
        "repo_root": str(ROOT_DIR),
        "runner_binary": str(runner),
        "btf_custom_path": str(btf_custom_path) if btf_custom_path is not None else None,
        "perf_results_json": str(perf_results_path),
        "tracing_results_json": str(tracing_results_path),
        "repeat": args.repeat,
        "summary": summary,
        "programs": records,
    }

    output_json.write_text(json.dumps(data, indent=2) + "\n")
    output_md.write_text(build_markdown(data) + "\n")

    print(f"Wrote {output_json}")
    print(f"Wrote {output_md}")
    print(
        f"attempted={summary['programs_attempted']} "
        f"compile_ok={summary['baseline_compile_successes']} "
        f"applied={summary['framework_recompile_applied_programs']} "
        f"measured_pairs={summary['measured_pairs']}"
    )
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
