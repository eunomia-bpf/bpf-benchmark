#!/usr/bin/env python3
from __future__ import annotations

import argparse
import json
import math
import platform
import statistics
import struct
import subprocess
import time
from collections import Counter
from datetime import datetime, timezone
from pathlib import Path
from typing import Any

from run_real_world_code_size import DEFAULT_RUNNER, ensure_runner_binary
try:
    from results_layout import authoritative_output_path, latest_output_path, maybe_refresh_latest_alias, smoke_output_path
except ImportError:
    from corpus.results_layout import authoritative_output_path, latest_output_path, maybe_refresh_latest_alias, smoke_output_path


ROOT = Path(__file__).resolve().parent
DEFAULT_INPUT = latest_output_path(ROOT / "results", "real_world_code_size")
DEFAULT_OUTPUT = authoritative_output_path(ROOT / "results", "real_world_exec_time")
DEFAULT_REPORT = ROOT / "results" / "real_world_exec_time.md"
DEFAULT_REPEAT = 1000
DEFAULT_ITERATIONS = 10
DEFAULT_TIMEOUT_SECONDS = 60
DEFAULT_CONTEXT_SIZE = 256

PACKET_CONTEXT_PROG_TYPES = {
    3,  # BPF_PROG_TYPE_SCHED_CLS
    4,  # BPF_PROG_TYPE_SCHED_ACT
    6,  # BPF_PROG_TYPE_XDP
    8,  # BPF_PROG_TYPE_CGROUP_SKB
}
PACKET_CONTEXT_PROG_TYPE_NAMES = {
    "cgroup_skb",
    "sched_act",
    "sched_cls",
    "xdp",
}
PACKET_CONTEXT_SECTION_PREFIXES = (
    "action",
    "cgroup/skb",
    "cgroup_skb",
    "classifier",
    "tc",
    "xdp",
)
KERNEL_UNSUPPORTED_ERROR_SNIPPETS = (
    "Unknown error 524",
    "Operation not supported",
    "Not supported",
    "requires an XDP or skb packet context",
)


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description="Compare exec_ns across llvmbpf and kernel for real-world BPF programs."
    )
    parser.add_argument("--input", default=str(DEFAULT_INPUT), help="Path to real_world_code_size.latest.json.")
    parser.add_argument("--output", default=str(DEFAULT_OUTPUT), help="Path to output JSON payload.")
    parser.add_argument("--report", default=str(DEFAULT_REPORT), help="Path to Markdown report.")
    parser.add_argument("--runner", default=str(DEFAULT_RUNNER), help="Path to micro/build/runner/micro_exec.")
    parser.add_argument("--repeat", type=int, default=DEFAULT_REPEAT, help="Inner runner repeat count.")
    parser.add_argument("--iterations", type=int, default=DEFAULT_ITERATIONS, help="Runner invocations per program.")
    parser.add_argument(
        "--timeout-seconds",
        type=int,
        default=DEFAULT_TIMEOUT_SECONDS,
        help="Per-invocation timeout in seconds.",
    )
    parser.add_argument(
        "--context-size",
        type=int,
        default=DEFAULT_CONTEXT_SIZE,
        help="Zero-filled context input size to materialize for io-mode=context.",
    )
    parser.add_argument("--max-programs", type=int, help="Limit the number of paired programs processed.")
    return parser.parse_args()


def parse_json_output(stdout: str) -> Any:
    lines = [line for line in stdout.splitlines() if line.strip()]
    if not lines:
        raise ValueError("command produced no stdout")
    return json.loads(lines[-1])


def tail_text(value: str, limit: int = 4000) -> str:
    value = value.strip()
    if len(value) <= limit:
        return value
    return "..." + value[-(limit - 3) :]


def summarize_error(value: str | None) -> str:
    if not value:
        return "unknown error"
    lines = [line.strip() for line in value.splitlines() if line.strip()]
    return lines[-1] if lines else "unknown error"


def invoke_command(command: list[str], timeout_seconds: int) -> dict[str, Any]:
    started_ns = time.perf_counter_ns()
    try:
        completed = subprocess.run(command, capture_output=True, text=True, timeout=timeout_seconds)
    except subprocess.TimeoutExpired as error:
        return {
            "status": "timeout",
            "returncode": None,
            "wall_time_ns": time.perf_counter_ns() - started_ns,
            "stdout": error.stdout or "",
            "stderr": error.stderr or "",
            "error": f"timed out after {timeout_seconds} seconds",
        }
    except OSError as error:
        return {
            "status": "error",
            "returncode": None,
            "wall_time_ns": time.perf_counter_ns() - started_ns,
            "stdout": "",
            "stderr": "",
            "error": str(error),
        }

    stdout = completed.stdout or ""
    stderr = completed.stderr or ""
    error_text = summarize_error(stderr) or summarize_error(stdout)
    if completed.returncode != 0:
        if completed.returncode < 0:
            fallback_error = f"terminated by signal {-completed.returncode}"
        else:
            fallback_error = f"command failed with return code {completed.returncode}"
        effective_error = error_text if error_text != "unknown error" else fallback_error
        return {
            "status": "error",
            "returncode": completed.returncode,
            "wall_time_ns": time.perf_counter_ns() - started_ns,
            "stdout": stdout,
            "stderr": stderr,
            "error": effective_error,
        }

    return {
        "status": "ok",
        "returncode": completed.returncode,
        "wall_time_ns": time.perf_counter_ns() - started_ns,
        "stdout": stdout,
        "stderr": stderr,
        "error": None,
    }


def geomean(values: list[float]) -> float | None:
    positives = [value for value in values if value > 0.0]
    if not positives:
        return None
    return math.exp(sum(math.log(value) for value in positives) / len(positives))


def generate_valid_packet() -> bytes:
    """Generate a minimal valid Ethernet + IPv4 + TCP packet."""
    dst_mac = b"\x00\x00\x00\x00\x00\x00"
    src_mac = b"\x00\x00\x00\x00\x00\x00"
    ethertype = struct.pack("!H", 0x0800)
    eth_header = dst_mac + src_mac + ethertype

    version_ihl = 0x45
    tos = 0
    total_length = 40
    identification = 0
    flags_fragment = 0
    ttl = 64
    protocol = 6
    src_ip = struct.pack("!I", 0x0A000001)
    dst_ip = struct.pack("!I", 0x0A000002)
    ip_header_no_checksum = (
        struct.pack("!BBHHHBBH", version_ihl, tos, total_length, identification, flags_fragment, ttl, protocol, 0)
        + src_ip
        + dst_ip
    )

    words = struct.unpack("!10H", ip_header_no_checksum)
    checksum_sum = sum(words)
    checksum_sum = (checksum_sum >> 16) + (checksum_sum & 0xFFFF)
    checksum_sum += checksum_sum >> 16
    checksum = ~checksum_sum & 0xFFFF
    ip_header = (
        struct.pack(
            "!BBHHHBBH", version_ihl, tos, total_length, identification, flags_fragment, ttl, protocol, checksum
        )
        + src_ip
        + dst_ip
    )

    src_port = 12345
    dst_port = 80
    seq = 0
    ack = 0
    data_offset_flags = 0x5002
    window = 65535
    tcp_checksum = 0
    urgent = 0
    tcp_header = (
        struct.pack("!HHIIHHH", src_port, dst_port, seq, ack, data_offset_flags, window, tcp_checksum)
        + struct.pack("!H", urgent)
    )

    return eth_header + ip_header + tcp_header


def build_command(
    runtime: str,
    runner: Path,
    object_path: Path,
    program_name: str,
    repeat: int,
    io_mode: str,
    input_file: Path | None = None,
) -> list[str]:
    command = [
        str(runner),
        "run-llvmbpf" if runtime == "llvmbpf" else "run-kernel",
        "--program",
        str(object_path),
        "--program-name",
        program_name,
        "--repeat",
        str(repeat),
        "--io-mode",
        io_mode,
    ]
    if io_mode == "packet":
        command.append("--raw-packet")
    if input_file is not None:
        command.extend(["--memory", str(input_file)])
    elif io_mode == "packet":
        command.extend(["--input-size", "64"])
    return ["sudo", "-n", *command] if runtime == "kernel" else command


def list_object_programs(runner: Path, object_path: Path, timeout_seconds: int) -> dict[str, Any]:
    command = [
        str(runner),
        "list-programs",
        "--program",
        str(object_path),
    ]
    outcome = invoke_command(command, timeout_seconds)
    if outcome["status"] != "ok":
        return {"command": command, "programs": [], **outcome}
    try:
        programs = parse_json_output(outcome["stdout"])
    except Exception as error:  # noqa: BLE001
        return {
            "command": command,
            "programs": [],
            "status": "error",
            "returncode": 0,
            "wall_time_ns": outcome["wall_time_ns"],
            "stdout": outcome["stdout"],
            "stderr": outcome["stderr"],
            "error": f"failed to parse list-programs output: {error}",
        }
    return {"command": command, "programs": programs, **outcome}


def load_paired_programs(payload: dict[str, Any], max_programs: int | None) -> list[dict[str, Any]]:
    programs: list[dict[str, Any]] = []
    for source in payload.get("sources", []):
        object_path = source.get("build", {}).get("object_path")
        if not object_path:
            continue
        for program in source.get("programs", []):
            runs = {run["runtime"]: run for run in program.get("runs", [])}
            if runs.get("llvmbpf", {}).get("status") != "ok" or runs.get("kernel", {}).get("status") != "ok":
                continue
            programs.append(
                {
                    "repo": source["repo"],
                    "selection": source.get("selection"),
                    "artifact_kind": source.get("artifact_kind"),
                    "relative_path": source["relative_path"],
                    "object_path": object_path,
                    "program_name": program["name"],
                    "section_name": program["section_name"],
                    "insn_count": program["insn_count"],
                    "prog_type": int(program.get("prog_type", 0)),
                    "expected_attach_type": int(program.get("expected_attach_type", 0)),
                    "prog_type_name": str(program.get("prog_type_name", "")),
                    "attach_type_name": str(program.get("attach_type_name", "")),
                    "code_size": {
                        "llvmbpf_native_code_bytes": runs["llvmbpf"]["sample"]["code_size"]["native_code_bytes"],
                        "kernel_native_code_bytes": runs["kernel"]["sample"]["code_size"]["native_code_bytes"],
                    },
                }
            )
    programs.sort(key=lambda row: (row["repo"], row["relative_path"], row["program_name"]))
    return programs if max_programs is None else programs[:max_programs]


def build_program_inventory_cache(
    programs: list[dict[str, Any]],
    runner: Path,
    timeout_seconds: int,
) -> dict[str, dict[str, dict[str, Any]]]:
    inventory_cache: dict[str, dict[str, dict[str, Any]]] = {}
    object_paths = sorted({str(Path(program["object_path"]).resolve()) for program in programs})
    for object_path in object_paths:
        inventory = list_object_programs(runner, Path(object_path), timeout_seconds)
        entries: dict[str, dict[str, Any]] = {}
        if inventory["status"] == "ok":
            for program in inventory["programs"]:
                entries[str(program["name"])] = program
        inventory_cache[object_path] = entries
    return inventory_cache


def enrich_program_metadata(
    program: dict[str, Any],
    inventory_cache: dict[str, dict[str, dict[str, Any]]],
) -> dict[str, Any]:
    if program.get("prog_type"):
        return program

    object_key = str(Path(program["object_path"]).resolve())
    inventory_program = inventory_cache.get(object_key, {}).get(program["program_name"])
    if inventory_program is None:
        return program

    enriched = dict(program)
    enriched["prog_type"] = int(inventory_program.get("prog_type", 0))
    enriched["expected_attach_type"] = int(inventory_program.get("expected_attach_type", 0))
    enriched["prog_type_name"] = str(inventory_program.get("prog_type_name", ""))
    enriched["attach_type_name"] = str(inventory_program.get("attach_type_name", ""))
    return enriched


def resolve_exec_io_mode(program: dict[str, Any]) -> str:
    prog_type = int(program.get("prog_type", 0) or 0)
    if prog_type in PACKET_CONTEXT_PROG_TYPES:
        return "packet"

    prog_type_name = str(program.get("prog_type_name", "")).strip().lower()
    if prog_type_name in PACKET_CONTEXT_PROG_TYPE_NAMES:
        return "packet"

    section_name = str(program.get("section_name", "")).strip().lower()
    if any(section_name.startswith(prefix) for prefix in PACKET_CONTEXT_SECTION_PREFIXES):
        return "packet"

    return "context"


def program_type_label(program: dict[str, Any]) -> str:
    prog_type_name = str(program.get("prog_type_name", "")).strip()
    if prog_type_name:
        return prog_type_name
    prog_type = int(program.get("prog_type", 0) or 0)
    return f"prog_type={prog_type}" if prog_type else "unknown"


def run_runtime(
    runtime: str,
    runner: Path,
    object_path: Path,
    program_name: str,
    repeat: int,
    iterations: int,
    timeout_seconds: int,
    io_mode: str,
    input_file: Path | None = None,
) -> dict[str, Any]:
    command = build_command(runtime, runner, object_path, program_name, repeat, io_mode, input_file=input_file)
    exec_samples: list[int] = []
    timing_source: str | None = None

    for _ in range(iterations):
        outcome = invoke_command(command, timeout_seconds)
        if outcome["status"] != "ok":
            return {
                "runtime": runtime,
                "command": command,
                "status": outcome["status"],
                "repeat": repeat,
                "iterations_requested": iterations,
                "iterations_completed": len(exec_samples),
                "io_mode": io_mode,
                "input_path": str(input_file) if input_file is not None else None,
                "timing_source": timing_source,
                "exec_ns_samples": exec_samples,
                "median_exec_ns": statistics.median(exec_samples) if exec_samples else None,
                "error": outcome["error"],
                "stdout_excerpt": tail_text(outcome["stdout"]),
                "stderr_excerpt": tail_text(outcome["stderr"]),
            }
        try:
            sample = parse_json_output(outcome["stdout"])
        except Exception as error:  # noqa: BLE001
            return {
                "runtime": runtime,
                "command": command,
                "status": "error",
                "repeat": repeat,
                "iterations_requested": iterations,
                "iterations_completed": len(exec_samples),
                "io_mode": io_mode,
                "input_path": str(input_file) if input_file is not None else None,
                "timing_source": timing_source,
                "exec_ns_samples": exec_samples,
                "median_exec_ns": statistics.median(exec_samples) if exec_samples else None,
                "error": f"failed to parse runtime output: {error}",
                "stdout_excerpt": tail_text(outcome["stdout"]),
                "stderr_excerpt": tail_text(outcome["stderr"]),
            }
        exec_samples.append(int(sample["exec_ns"]))
        timing_source = str(sample.get("timing_source", "")) or timing_source

    return {
        "runtime": runtime,
        "command": command,
        "status": "ok",
        "repeat": repeat,
        "iterations_requested": iterations,
        "iterations_completed": iterations,
        "io_mode": io_mode,
        "input_path": str(input_file) if input_file is not None else None,
        "timing_source": timing_source,
        "exec_ns_samples": exec_samples,
        "median_exec_ns": statistics.median(exec_samples),
        "error": None,
        "stdout_excerpt": "",
        "stderr_excerpt": "",
    }


def maybe_retry_llvmbpf_timeout(
    run: dict[str, Any],
    runner: Path,
    object_path: Path,
    program_name: str,
    repeat: int,
    iterations: int,
    timeout_seconds: int,
    io_mode: str,
    input_file: Path | None = None,
) -> dict[str, Any]:
    if run["runtime"] != "llvmbpf":
        return run
    if run["status"] != "timeout" or io_mode != "context" or repeat <= 1:
        return run

    retry_run = run_runtime(
        "llvmbpf",
        runner,
        object_path,
        program_name,
        1,
        iterations,
        timeout_seconds,
        io_mode,
        input_file=input_file,
    )
    retry_run["retry_after_timeout"] = {"initial_repeat": repeat, "retry_repeat": 1}
    return retry_run


def maybe_reclassify_kernel_run(program: dict[str, Any], run: dict[str, Any]) -> dict[str, Any]:
    if run["runtime"] != "kernel" or run["status"] != "error":
        return run

    error_text = str(run.get("error", ""))
    if any(snippet in error_text for snippet in KERNEL_UNSUPPORTED_ERROR_SNIPPETS):
        reclassified = dict(run)
        reclassified["status"] = "skipped"
        reclassified["error"] = (
            f"kernel test_run unsupported for {program_type_label(program)} with io-mode {run['io_mode']}: "
            f"{error_text}"
        )
        return reclassified

    if program_type_label(program) == "socket_filter" and "Invalid argument" in error_text:
        reclassified = dict(run)
        reclassified["status"] = "skipped"
        reclassified["error"] = (
            f"kernel test_run unsupported for socket_filter with io-mode {run['io_mode']}: "
            f"{error_text}"
        )
        return reclassified

    return run


def compute_summary(program_records: list[dict[str, Any]]) -> dict[str, Any]:
    runtime_status = {"kernel": Counter(), "llvmbpf": Counter()}
    failure_breakdown = {"kernel": Counter(), "llvmbpf": Counter()}
    skip_breakdown = {"kernel": Counter(), "llvmbpf": Counter()}
    ratios: list[float] = []
    any_runtime_exec_ok = 0

    for record in program_records:
        runs = {run["runtime"]: run for run in record["runs"]}
        for runtime, run in runs.items():
            runtime_status[runtime][run["status"]] += 1
            if run["status"] in {"error", "timeout"}:
                failure_breakdown[runtime][summarize_error(run["error"])] += 1
            if run["status"] == "skipped":
                skip_breakdown[runtime][summarize_error(run["error"])] += 1
        if any(run["status"] == "ok" for run in runs.values()):
            any_runtime_exec_ok += 1
        kernel_run = runs["kernel"]
        llvmbpf_run = runs["llvmbpf"]
        if (
            kernel_run["status"] == "ok"
            and llvmbpf_run["status"] == "ok"
            and float(kernel_run["median_exec_ns"]) > 0.0
        ):
            ratios.append(float(llvmbpf_run["median_exec_ns"]) / float(kernel_run["median_exec_ns"]))

    median_ratio = statistics.median(ratios) if ratios else None
    return {
        "programs": {
            "paired_from_code_size": len(program_records),
            "kernel_test_run_ok": runtime_status["kernel"].get("ok", 0),
            "llvmbpf_run_ok": runtime_status["llvmbpf"].get("ok", 0),
            "any_runtime_exec_ok": any_runtime_exec_ok,
            "paired_exec_ok": len(ratios),
        },
        "runtime_status": {runtime: dict(counter) for runtime, counter in runtime_status.items()},
        "runtime_failure_breakdown": {runtime: dict(counter) for runtime, counter in failure_breakdown.items()},
        "runtime_skip_breakdown": {runtime: dict(counter) for runtime, counter in skip_breakdown.items()},
        "llvmbpf_over_kernel_exec_ratio": {
            "paired_programs": len(ratios),
            "geomean": geomean(ratios),
            "min": min(ratios) if ratios else None,
            "median": median_ratio,
            "max": max(ratios) if ratios else None,
        },
    }


def format_float(value: float | None, suffix: str = "") -> str:
    if value is None:
        return "-"
    return f"{value:.3f}{suffix}"


def render_report(payload: dict[str, Any]) -> str:
    summary = payload["summary"]
    ratio = summary["llvmbpf_over_kernel_exec_ratio"]
    lines = [
        "# Real-World Execution-Time Validation",
        "",
        f"- Generated at: `{payload['generated_at']}`",
        f"- Input: `{payload['code_size_input']}`",
        f"- Runner: `{payload['runner_binary']}`",
        f"- Iterations per program: `{payload['iterations']}`",
        f"- Repeat count per invocation: `{payload['repeat']}`",
        f"- I/O mode strategy: `{payload['io_mode_strategy']}`",
        f"- Packet input: `{payload['packet_input']}`",
        f"- Context input: `{payload['context_input']}` (`{payload['context_size']}` bytes, zero-filled)",
        "",
        "## Summary",
        "",
        "| Metric | Value |",
        "| --- | ---: |",
        f"| Programs paired in code-size input | {summary['programs']['paired_from_code_size']} |",
        f"| Kernel `BPF_PROG_TEST_RUN` succeeded | {summary['programs']['kernel_test_run_ok']} |",
        f"| llvmbpf runs completed | {summary['programs']['llvmbpf_run_ok']} |",
        f"| Programs with any runtime exec data | {summary['programs']['any_runtime_exec_ok']} |",
        f"| Programs with both runtimes ok | {summary['programs']['paired_exec_ok']} |",
        f"| Geomean exec ratio (llvmbpf/kernel) | {format_float(ratio['geomean'], 'x')} |",
        "",
        "## Runtime Status",
        "",
        "| Runtime | ok | error | timeout | skipped |",
        "| --- | ---: | ---: | ---: | ---: |",
    ]
    for runtime in ("kernel", "llvmbpf"):
        counter = summary["runtime_status"].get(runtime, {})
        lines.append(
            f"| {runtime} | {counter.get('ok', 0)} | {counter.get('error', 0)} | "
            f"{counter.get('timeout', 0)} | {counter.get('skipped', 0)} |"
        )

    for runtime in ("kernel", "llvmbpf"):
        failures = summary["runtime_failure_breakdown"].get(runtime, {})
        if not failures:
            continue
        lines.extend(
            [
                "",
                f"## {runtime} Failures",
                "",
                "| Error summary | Count |",
                "| --- | ---: |",
            ]
        )
        for error, count in sorted(failures.items(), key=lambda item: (-item[1], item[0])):
            lines.append(f"| {error} | {count} |")

    for runtime in ("kernel", "llvmbpf"):
        skips = summary["runtime_skip_breakdown"].get(runtime, {})
        if not skips:
            continue
        lines.extend(
            [
                "",
                f"## {runtime} Skips",
                "",
                "| Skip reason | Count |",
                "| --- | ---: |",
            ]
        )
        for reason, count in sorted(skips.items(), key=lambda item: (-item[1], item[0])):
            lines.append(f"| {reason} | {count} |")

    coverage_rows = []
    for record in payload["programs"]:
        runs = {run["runtime"]: run for run in record["runs"]}
        coverage_rows.append(
            {
                "repo": record["repo"],
                "artifact": record["relative_path"],
                "program": record["program_name"],
                "section": record["section_name"],
                "prog_type": program_type_label(record),
                "io_mode": record["exec_io_mode"],
                "kernel_status": runs["kernel"]["status"],
                "llvmbpf_status": runs["llvmbpf"]["status"],
            }
        )
    coverage_rows.sort(key=lambda row: (row["repo"], row["artifact"], row["program"]))
    if coverage_rows:
        lines.extend(
            [
                "",
                "## Program Coverage",
                "",
                "| Repo | Artifact | Program | Section | Type | I/O mode | kernel | llvmbpf |",
                "| --- | --- | --- | --- | --- | --- | --- | --- |",
            ]
        )
        for row in coverage_rows:
            lines.append(
                f"| {row['repo']} | `{row['artifact']}` | `{row['program']}` | `{row['section']}` | "
                f"`{row['prog_type']}` | `{row['io_mode']}` | `{row['kernel_status']}` | `{row['llvmbpf_status']}` |"
            )

    paired_rows = []
    for record in payload["programs"]:
        runs = {run["runtime"]: run for run in record["runs"]}
        if (
            runs["kernel"]["status"] != "ok"
            or runs["llvmbpf"]["status"] != "ok"
            or float(runs["kernel"]["median_exec_ns"]) <= 0.0
        ):
            continue
        paired_rows.append(
            {
                "repo": record["repo"],
                "artifact": record["relative_path"],
                "program": record["program_name"],
                "section": record["section_name"],
                "prog_type": program_type_label(record),
                "io_mode": record["exec_io_mode"],
                "llvmbpf": runs["llvmbpf"]["median_exec_ns"],
                "kernel": runs["kernel"]["median_exec_ns"],
                "ratio": float(runs["llvmbpf"]["median_exec_ns"]) / float(runs["kernel"]["median_exec_ns"]),
            }
        )
    paired_rows.sort(key=lambda row: (row["ratio"], row["repo"], row["artifact"], row["program"]))
    if paired_rows:
        lines.extend(
            [
                "",
                "## Program-Level Results",
                "",
                "| Repo | Artifact | Program | Section | Type | I/O mode | llvmbpf median ns | kernel median ns | L/K ratio |",
                "| --- | --- | --- | --- | --- | --- | ---: | ---: | ---: |",
            ]
        )
        for row in paired_rows:
            lines.append(
                f"| {row['repo']} | `{row['artifact']}` | `{row['program']}` | `{row['section']}` | "
                f"`{row['prog_type']}` | `{row['io_mode']}` | "
                f"{row['llvmbpf']:.1f} | {row['kernel']:.1f} | {row['ratio']:.3f}x |"
            )

    lines.extend(
        [
            "",
            "## Notes",
            "",
            "- Inputs come from the subset of programs that already compiled successfully on both runtimes in `real_world_code_size.latest.json`.",
            "- Packet mode is used only for XDP and skb-backed program types; all other program types use `io-mode=context` with a zero-filled context buffer.",
            "- Kernel and llvmbpf exec runs are attempted independently so kernel `ENOTSUP` does not suppress userspace exec-time coverage.",
            "- Kernel `BPF_PROG_TEST_RUN` cases that report `ENOTSUP` are recorded as `skipped` instead of hard failures.",
            "- `--program-name` uses the libbpf program name stored in the code-size results; section names are reported alongside the measurements.",
        ]
    )
    return "\n".join(lines) + "\n"


def main() -> int:
    args = parse_args()
    input_path = Path(args.input).resolve()
    if args.output == str(DEFAULT_OUTPUT) and args.max_programs is not None:
        output_path = smoke_output_path(ROOT / "results", "real_world_exec_time")
    else:
        output_path = Path(args.output).resolve()
    report_path = Path(args.report).resolve()
    runner_path = Path(args.runner).resolve()
    ensure_runner_binary(runner_path)
    if args.context_size < 0:
        raise SystemExit("--context-size must be non-negative")
    packet_file = output_path.parent / "valid_packet.bin"
    context_file = output_path.parent / "zero_context.bin"
    packet_file.parent.mkdir(parents=True, exist_ok=True)
    packet_file.write_bytes(generate_valid_packet())
    context_file.write_bytes(b"\x00" * args.context_size)

    code_size_payload = json.loads(input_path.read_text())
    paired_programs = load_paired_programs(code_size_payload, args.max_programs)
    inventory_cache = build_program_inventory_cache(paired_programs, runner_path, args.timeout_seconds)
    program_records: list[dict[str, Any]] = []

    for program in paired_programs:
        program = enrich_program_metadata(program, inventory_cache)
        object_path = Path(program["object_path"])
        io_mode = resolve_exec_io_mode(program)
        input_file = packet_file if io_mode == "packet" else context_file
        kernel_run = maybe_reclassify_kernel_run(
            program,
            run_runtime(
                "kernel",
                runner_path,
                object_path,
                program["program_name"],
                args.repeat,
                args.iterations,
                args.timeout_seconds,
                io_mode,
                input_file=input_file,
            ),
        )
        llvmbpf_run = run_runtime(
            "llvmbpf",
            runner_path,
            object_path,
            program["program_name"],
            args.repeat,
            args.iterations,
            args.timeout_seconds,
            io_mode,
            input_file=input_file,
        )
        llvmbpf_run = maybe_retry_llvmbpf_timeout(
            llvmbpf_run,
            runner_path,
            object_path,
            program["program_name"],
            args.repeat,
            args.iterations,
            args.timeout_seconds,
            io_mode,
            input_file=input_file,
        )
        program_records.append({**program, "exec_io_mode": io_mode, "runs": [kernel_run, llvmbpf_run]})

    payload = {
        "dataset": "real_world_exec_time",
        "generated_at": datetime.now(timezone.utc).isoformat(),
        "code_size_input": str(input_path),
        "runner_binary": str(runner_path),
        "repeat": args.repeat,
        "iterations": args.iterations,
        "io_mode_strategy": "per-program: packet for XDP/skb-backed types, context otherwise",
        "packet_input": str(packet_file),
        "context_input": str(context_file),
        "context_size": args.context_size,
        "host": {"platform": platform.platform(), "python": platform.python_version()},
        "programs": program_records,
    }
    payload["summary"] = compute_summary(program_records)

    output_path.parent.mkdir(parents=True, exist_ok=True)
    output_path.write_text(json.dumps(payload, indent=2) + "\n")
    maybe_refresh_latest_alias(output_path)
    report_path.write_text(render_report(payload))
    print(f"[done] wrote {output_path}")
    print(f"[done] wrote {report_path}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
