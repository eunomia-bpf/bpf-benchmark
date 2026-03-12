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
        return {
            "status": "error",
            "returncode": completed.returncode,
            "wall_time_ns": time.perf_counter_ns() - started_ns,
            "stdout": stdout,
            "stderr": stderr,
            "error": error_text or f"command failed with return code {completed.returncode}",
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
    runtime: str, runner: Path, object_path: Path, program_name: str, repeat: int, packet_file: Path | None = None
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
        "packet",
        "--raw-packet",
    ]
    if packet_file is not None:
        command.extend(["--memory", str(packet_file)])
    else:
        command.extend(["--input-size", "64"])
    return ["sudo", "-n", *command] if runtime == "kernel" else command


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
                    "code_size": {
                        "llvmbpf_native_code_bytes": runs["llvmbpf"]["sample"]["code_size"]["native_code_bytes"],
                        "kernel_native_code_bytes": runs["kernel"]["sample"]["code_size"]["native_code_bytes"],
                    },
                }
            )
    programs.sort(key=lambda row: (row["repo"], row["relative_path"], row["program_name"]))
    return programs if max_programs is None else programs[:max_programs]


def run_runtime(
    runtime: str,
    runner: Path,
    object_path: Path,
    program_name: str,
    repeat: int,
    iterations: int,
    timeout_seconds: int,
    packet_file: Path | None = None,
) -> dict[str, Any]:
    command = build_command(runtime, runner, object_path, program_name, repeat, packet_file=packet_file)
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
        "timing_source": timing_source,
        "exec_ns_samples": exec_samples,
        "median_exec_ns": statistics.median(exec_samples),
        "error": None,
        "stdout_excerpt": "",
        "stderr_excerpt": "",
    }


def compute_summary(program_records: list[dict[str, Any]]) -> dict[str, Any]:
    runtime_status = {"kernel": Counter(), "llvmbpf": Counter()}
    failure_breakdown = {"kernel": Counter(), "llvmbpf": Counter()}
    ratios: list[float] = []

    for record in program_records:
        runs = {run["runtime"]: run for run in record["runs"]}
        for runtime, run in runs.items():
            runtime_status[runtime][run["status"]] += 1
            if run["status"] in {"error", "timeout"}:
                failure_breakdown[runtime][summarize_error(run["error"])] += 1
        kernel_run = runs["kernel"]
        llvmbpf_run = runs["llvmbpf"]
        if kernel_run["status"] == "ok" and llvmbpf_run["status"] == "ok":
            ratios.append(float(llvmbpf_run["median_exec_ns"]) / float(kernel_run["median_exec_ns"]))

    median_ratio = statistics.median(ratios) if ratios else None
    return {
        "programs": {
            "paired_from_code_size": len(program_records),
            "kernel_test_run_ok": runtime_status["kernel"].get("ok", 0),
            "llvmbpf_run_ok": runtime_status["llvmbpf"].get("ok", 0),
            "paired_exec_ok": len(ratios),
        },
        "runtime_status": {runtime: dict(counter) for runtime, counter in runtime_status.items()},
        "runtime_failure_breakdown": {runtime: dict(counter) for runtime, counter in failure_breakdown.items()},
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
        f"- I/O mode: `{payload['io_mode']}`",
        "",
        "## Summary",
        "",
        "| Metric | Value |",
        "| --- | ---: |",
        f"| Programs paired in code-size input | {summary['programs']['paired_from_code_size']} |",
        f"| Kernel `BPF_PROG_TEST_RUN` succeeded | {summary['programs']['kernel_test_run_ok']} |",
        f"| llvmbpf runs completed | {summary['programs']['llvmbpf_run_ok']} |",
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

    paired_rows = []
    for record in payload["programs"]:
        runs = {run["runtime"]: run for run in record["runs"]}
        if runs["kernel"]["status"] != "ok" or runs["llvmbpf"]["status"] != "ok":
            continue
        paired_rows.append(
            {
                "repo": record["repo"],
                "artifact": record["relative_path"],
                "program": record["program_name"],
                "section": record["section_name"],
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
                "| Repo | Artifact | Program | Section | llvmbpf median ns | kernel median ns | L/K ratio |",
                "| --- | --- | --- | --- | ---: | ---: | ---: |",
            ]
        )
        for row in paired_rows:
            lines.append(
                f"| {row['repo']} | `{row['artifact']}` | `{row['program']}` | `{row['section']}` | "
                f"{row['llvmbpf']:.1f} | {row['kernel']:.1f} | {row['ratio']:.3f}x |"
            )

    lines.extend(
        [
            "",
            "## Notes",
            "",
            "- Inputs come from the subset of programs that already compiled successfully on both runtimes in `real_world_code_size.latest.json`.",
            f"- Each median is computed across separate `micro_exec` invocations; each invocation uses packet mode with a generated valid raw packet input from `{payload['packet_input']}`.",
            "- Kernel runs are attempted first; if `run-kernel` fails, the program is recorded as unsupported for exec-time comparison and llvmbpf is marked `skipped`.",
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
    packet_file = output_path.parent / "valid_packet.bin"
    packet_file.parent.mkdir(parents=True, exist_ok=True)
    packet_file.write_bytes(generate_valid_packet())

    code_size_payload = json.loads(input_path.read_text())
    paired_programs = load_paired_programs(code_size_payload, args.max_programs)
    program_records: list[dict[str, Any]] = []

    for program in paired_programs:
        object_path = Path(program["object_path"])
        kernel_run = run_runtime(
            "kernel",
            runner_path,
            object_path,
            program["program_name"],
            args.repeat,
            args.iterations,
            args.timeout_seconds,
            packet_file=packet_file,
        )
        llvmbpf_run = (
            {
                "runtime": "llvmbpf",
                "command": build_command(
                    "llvmbpf", runner_path, object_path, program["program_name"], args.repeat, packet_file=packet_file
                ),
                "status": "skipped",
                "repeat": args.repeat,
                "iterations_requested": args.iterations,
                "iterations_completed": 0,
                "timing_source": None,
                "exec_ns_samples": [],
                "median_exec_ns": None,
                "error": "skipped because kernel run did not succeed",
                "stdout_excerpt": "",
                "stderr_excerpt": "",
            }
            if kernel_run["status"] != "ok"
            else run_runtime(
                "llvmbpf",
                runner_path,
                object_path,
                program["program_name"],
                args.repeat,
                args.iterations,
                args.timeout_seconds,
                packet_file=packet_file,
            )
        )
        program_records.append({**program, "runs": [kernel_run, llvmbpf_run]})

    payload = {
        "dataset": "real_world_exec_time",
        "generated_at": datetime.now(timezone.utc).isoformat(),
        "code_size_input": str(input_path),
        "runner_binary": str(runner_path),
        "repeat": args.repeat,
        "iterations": args.iterations,
        "io_mode": "packet",
        "packet_input": str(packet_file),
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
