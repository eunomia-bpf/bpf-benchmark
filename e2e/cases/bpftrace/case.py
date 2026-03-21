#!/usr/bin/env python3
from __future__ import annotations

import argparse
import os
import platform
import re
import statistics
import sys
import threading
import time
from dataclasses import dataclass
from datetime import datetime, timezone
from pathlib import Path
from typing import Any, Mapping, Sequence

if __package__ in {None, ""}:
    sys.path.insert(0, str(Path(__file__).resolve().parents[3]))

from runner.libs import (  # noqa: E402
    RESULTS_DIR,
    ROOT_DIR,
    authoritative_output_path,
    ensure_root,
    run_command,
    smoke_output_path,
    tail_text,
    which,
    write_json,
    write_text,
)
from runner.libs.agent import find_bpf_programs, start_agent, stop_agent  # noqa: E402
from runner.libs.metrics import (  # noqa: E402
    compute_delta,
    enable_bpf_stats,
    sample_bpf_stats,
    sample_cpu_usage,
    sample_total_cpu_usage,
)
from runner.libs.recompile import PolicyTarget, apply_recompile, resolve_policy_files, scan_programs  # noqa: E402
from runner.libs.workload import (  # noqa: E402
    WorkloadResult,
    run_dd_read_load,
    run_exec_storm,
    run_file_open_load,
    run_scheduler_load,
    run_tcp_connect_load,
)


DEFAULT_SCRIPT_DIR = Path(__file__).with_name("scripts")
DEFAULT_OUTPUT_JSON = authoritative_output_path(RESULTS_DIR, "bpftrace")
DEFAULT_OUTPUT_MD = ROOT_DIR / "e2e" / "results" / "bpftrace-real-e2e.md"
DEFAULT_REPORT_MD = ROOT_DIR / "docs" / "tmp" / "bpftrace-real-e2e-report.md"
DEFAULT_RUNNER = ROOT_DIR / "runner" / "build" / "micro_exec"
DEFAULT_DAEMON = ROOT_DIR / "daemon" / "build" / "bpfrejit-daemon"
DEFAULT_DURATION_S = 30
BPFTRACE_POLICY_OBJECT_DIR = ROOT_DIR / "corpus" / "build" / "bpftrace"
MIN_BPFTRACE_VERSION = (0, 16, 0)


@dataclass(frozen=True, slots=True)
class ScriptSpec:
    name: str
    script_path: Path
    description: str
    expected_programs: int
    workload_kind: str


SCRIPTS: tuple[ScriptSpec, ...] = (
    ScriptSpec(
        name="open_latency",
        script_path=DEFAULT_SCRIPT_DIR / "open_latency.bt",
        description="kprobe do_sys_openat2 latency histogram",
        expected_programs=2,
        workload_kind="open_latency",
    ),
    ScriptSpec(
        name="exec_trace",
        script_path=DEFAULT_SCRIPT_DIR / "exec_trace.bt",
        description="tracepoint sched_process_exec counter",
        expected_programs=1,
        workload_kind="exec_trace",
    ),
    ScriptSpec(
        name="scheduler_latency",
        script_path=DEFAULT_SCRIPT_DIR / "scheduler_latency.bt",
        description="tracepoint wakeup/switch run queue latency histogram",
        expected_programs=2,
        workload_kind="scheduler_latency",
    ),
    ScriptSpec(
        name="vfs_read_count",
        script_path=DEFAULT_SCRIPT_DIR / "vfs_read_count.bt",
        description="kprobe vfs_read counter by comm",
        expected_programs=1,
        workload_kind="vfs_read_count",
    ),
    ScriptSpec(
        name="tcp_connect",
        script_path=DEFAULT_SCRIPT_DIR / "tcp_connect.bt",
        description="kprobe tcp_v4_connect counter",
        expected_programs=1,
        workload_kind="tcp_connect",
    ),
)


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="Run the real end-to-end bpftrace benchmark case.")
    parser.add_argument("--output-json", default=str(DEFAULT_OUTPUT_JSON))
    parser.add_argument("--output-md", default=str(DEFAULT_OUTPUT_MD))
    parser.add_argument("--report-md", default=str(DEFAULT_REPORT_MD))
    parser.add_argument("--runner", default=str(DEFAULT_RUNNER))
    parser.add_argument("--scanner", default=str(DEFAULT_DAEMON))
    parser.add_argument("--duration", type=int, default=30)
    parser.add_argument("--smoke-duration", type=int, default=5)
    parser.add_argument("--attach-timeout", type=int, default=20)
    parser.add_argument("--script", action="append", dest="scripts")
    parser.add_argument("--smoke", action="store_true")
    parser.add_argument("--skip-build", action="store_true")
    return parser.parse_args()


def prepend_guest_tools_to_path() -> None:
    preferred = "/usr/local/sbin"
    current = os.environ.get("PATH", "")
    parts = [part for part in current.split(os.pathsep) if part]
    if preferred not in parts:
        os.environ["PATH"] = preferred + (os.pathsep + current if current else "")


def parse_version(text: str) -> tuple[int, int, int] | None:
    match = re.search(r"(\d+)\.(\d+)(?:\.(\d+))?", text)
    if not match:
        return None
    major, minor, patch = match.groups()
    return int(major), int(minor), int(patch or 0)


def version_at_least(version: tuple[int, int, int] | None, minimum: tuple[int, int, int]) -> bool:
    return version is not None and version >= minimum


def git_sha() -> str:
    try:
        return run_command(["git", "rev-parse", "HEAD"], timeout=15).stdout.strip()
    except Exception:
        return "unknown"


def host_metadata() -> dict[str, object]:
    return {
        "hostname": platform.node(),
        "platform": platform.platform(),
        "kernel": platform.release(),
        "python": sys.version.split()[0],
        "git_sha": git_sha(),
    }


def ensure_artifacts(runner_binary: Path, scanner_binary: Path, *, skip_build: bool) -> None:
    if not skip_build or not runner_binary.exists():
        run_command(["make", "runner"], timeout=1800)
    if not scanner_binary.exists():
        run_command(
            ["cmake", "-S", "daemon", "-B", "daemon/build", "-DCMAKE_BUILD_TYPE=Release"],
            timeout=600,
        )
        run_command(
            ["cmake", "--build", "daemon/build", "--target", "bpfrejit-daemon", "-j"],
            timeout=1800,
        )
    if not runner_binary.exists():
        raise RuntimeError(f"micro_exec not found: {runner_binary}")
    if not scanner_binary.exists():
        raise RuntimeError(f"bpfrejit-daemon not found: {scanner_binary}")


def ensure_required_tools() -> dict[str, object]:
    bpftrace_path = which("bpftrace")
    bpftool_path = which("bpftool")
    if bpftrace_path is None:
        raise RuntimeError("bpftrace is required but not present in PATH")
    if bpftool_path is None:
        raise RuntimeError("bpftool is required but not present in PATH")

    version_result = run_command(["bpftrace", "--version"], timeout=30)
    version_text = (version_result.stdout or version_result.stderr).strip()
    version = parse_version(version_text)
    if not version_at_least(version, MIN_BPFTRACE_VERSION):
        raise RuntimeError(
            f"bpftrace {version_text or 'unknown'} does not meet the required >= "
            f"{MIN_BPFTRACE_VERSION[0]}.{MIN_BPFTRACE_VERSION[1]}"
        )

    bpftool_version = run_command(["bpftool", "version"], timeout=30)
    return {
        "bpftrace_path": bpftrace_path,
        "bpftrace_version_text": version_text,
        "bpftrace_version": version,
        "bpftool_path": bpftool_path,
        "bpftool_version_text": tail_text(bpftool_version.stdout or bpftool_version.stderr, max_lines=3),
        "stress_ng_path": which("stress-ng"),
        "fio_path": which("fio"),
        "curl_path": which("curl"),
    }


def selected_scripts(args: argparse.Namespace) -> list[ScriptSpec]:
    if args.smoke:
        return [next(spec for spec in SCRIPTS if spec.name == "exec_trace")]
    if not args.scripts:
        return list(SCRIPTS)
    wanted = {name.strip() for name in args.scripts if name and name.strip()}
    return [spec for spec in SCRIPTS if spec.name in wanted]


def wait_for_attached_programs(
    process: Any,
    *,
    expected_count: int,
    timeout_s: int,
) -> list[dict[str, object]]:
    deadline = time.monotonic() + timeout_s
    last_nonempty: list[dict[str, object]] = []
    stable_ids: tuple[int, ...] | None = None
    stable_rounds = 0
    while time.monotonic() < deadline:
        matches = find_bpf_programs(int(process.pid or 0))
        if matches:
            last_nonempty = matches
            ids = tuple(int(item.get("id", 0)) for item in matches)
            if ids == stable_ids:
                stable_rounds += 1
            else:
                stable_ids = ids
                stable_rounds = 1
            if len(matches) >= expected_count and stable_rounds >= 2:
                return matches
        elif process.poll() is not None and not last_nonempty:
            break
        time.sleep(0.5)
    return last_nonempty


def aggregate_site_totals(records: Mapping[int, Mapping[str, object]]) -> dict[str, int]:
    totals = {
        "total_sites": 0,
        "cmov_sites": 0,
        "wide_sites": 0,
        "rotate_sites": 0,
        "lea_sites": 0,
    }
    for record in records.values():
        counts = record.get("sites") or record.get("counts") or {}
        for field in totals:
            totals[field] += int(counts.get(field, 0) or 0)
    return totals


def resolve_bpftrace_policy_files(
    spec: ScriptSpec,
    programs: Sequence[Mapping[str, object]],
) -> dict[int, str]:
    object_hint = BPFTRACE_POLICY_OBJECT_DIR / f"{spec.name}.bpf.o"
    targets = [
        PolicyTarget(
            prog_id=int(program.get("id", 0)),
            object_path=object_hint,
            program_name=str(program.get("name", "")).strip() or None,
        )
        for program in programs
        if int(program.get("id", 0) or 0) > 0
    ]
    resolved = resolve_policy_files(targets)
    unresolved = [
        program
        for program in programs
        if int(program.get("id", 0) or 0) > 0 and int(program.get("id", 0)) not in resolved
    ]
    if not unresolved:
        return resolved

    from runner.libs.policy import parse_policy_v3, program_policy_dir

    policy_dir = program_policy_dir(object_hint)
    if not policy_dir.exists():
        return resolved

    candidates: list[tuple[Path, str | None]] = []
    for candidate in sorted(policy_dir.glob("*.policy.yaml")):
        try:
            document = parse_policy_v3(candidate)
        except Exception:
            continue
        candidates.append((candidate.resolve(), document.program))
    if not candidates:
        return resolved

    if len(candidates) == 1:
        only_policy = str(candidates[0][0])
        for program in unresolved:
            prog_id = int(program.get("id", 0) or 0)
            if prog_id > 0:
                resolved[prog_id] = only_policy
        return resolved

    for program in unresolved:
        prog_id = int(program.get("id", 0) or 0)
        if prog_id <= 0:
            continue
        live_name = str(program.get("name", "")).strip()
        if not live_name:
            continue
        matches = sorted(
            {
                str(candidate_path)
                for candidate_path, candidate_program in candidates
                if candidate_program and candidate_program.rsplit(":", 1)[-1] == live_name
            }
        )
        if len(matches) == 1:
            resolved[prog_id] = matches[0]
    return resolved


def run_named_workload(kind: str, duration_s: int) -> WorkloadResult:
    if kind == "open_latency":
        return run_file_open_load(duration_s)
    if kind == "exec_trace":
        return run_exec_storm(duration_s, rate=2)
    if kind == "scheduler_latency":
        return run_scheduler_load(duration_s)
    if kind == "vfs_read_count":
        return run_dd_read_load(duration_s)
    if kind == "tcp_connect":
        return run_tcp_connect_load(duration_s)
    raise RuntimeError(f"unsupported workload kind: {kind}")


def measure_workload(
    workload_kind: str,
    duration_s: int,
    prog_ids: Sequence[int],
    *,
    agent_pid: int,
    initial_stats: Mapping[int, Mapping[str, object]] | None = None,
) -> dict[str, object]:
    before_bpf = {int(key): dict(value) for key, value in (initial_stats or sample_bpf_stats(list(prog_ids))).items()}
    cpu_holder: dict[int, dict[str, float]] = {}
    system_cpu_holder: dict[str, float] = {}
    threads: list[threading.Thread] = []

    cpu_thread = threading.Thread(
        target=lambda: cpu_holder.update(sample_cpu_usage([agent_pid], duration_s)),
        daemon=True,
    )
    cpu_thread.start()
    threads.append(cpu_thread)

    system_thread = threading.Thread(
        target=lambda: system_cpu_holder.update(sample_total_cpu_usage(duration_s)),
        daemon=True,
    )
    system_thread.start()
    threads.append(system_thread)

    try:
        workload_result = run_named_workload(workload_kind, duration_s)
    finally:
        for thread in threads:
            thread.join()

    after_bpf = sample_bpf_stats(list(prog_ids))
    bpf_delta = compute_delta(before_bpf, after_bpf)
    agent_cpu = cpu_holder.get(agent_pid, {})
    total_pct = None
    if agent_cpu:
        total_pct = float(agent_cpu.get("user_pct", 0.0)) + float(agent_cpu.get("sys_pct", 0.0))

    return {
        "workload": workload_result.to_dict(),
        "initial_stats": {str(key): value for key, value in before_bpf.items()},
        "final_stats": {str(key): value for key, value in after_bpf.items()},
        "bpf": bpf_delta,
        "agent_cpu": {
            "user_pct": agent_cpu.get("user_pct"),
            "sys_pct": agent_cpu.get("sys_pct"),
            "total_pct": total_pct,
        },
        "system_cpu": system_cpu_holder,
    }


def percent_delta(before: object, after: object) -> float | None:
    if before in (None, 0) or after is None:
        return None
    return ((float(after) - float(before)) / float(before)) * 100.0


def finalize_process_output(process: Any) -> dict[str, object]:
    stdout = ""
    stderr = ""
    try:
        stdout, stderr = process.communicate(timeout=1)
    except Exception:
        if process.stdout is not None:
            try:
                stdout = process.stdout.read()
            except Exception:
                stdout = ""
        if process.stderr is not None:
            try:
                stderr = process.stderr.read()
            except Exception:
                stderr = ""
    return {
        "returncode": process.returncode,
        "stdout_tail": tail_text(stdout, max_lines=40, max_chars=8000),
        "stderr_tail": tail_text(stderr, max_lines=40, max_chars=8000),
    }


def run_phase(
    spec: ScriptSpec,
    *,
    duration_s: int,
    attach_timeout: int,
    scanner_binary: Path,
    apply_rejit: bool,
) -> dict[str, object]:
    process = start_agent("bpftrace", ["-q", str(spec.script_path)])
    result: dict[str, object] = {
        "phase": "rejit" if apply_rejit else "baseline",
        "status": "error",
        "reason": "",
        "programs": [],
        "prog_ids": [],
        "scan_results": {},
        "policy_matches": {},
        "policy_summary": {
            "configured_programs": 0,
            "fallback_programs": 0,
        },
        "site_totals": {
            "total_sites": 0,
            "cmov_sites": 0,
            "wide_sites": 0,
            "rotate_sites": 0,
            "lea_sites": 0,
        },
        "recompile_results": {},
        "recompile_summary": {
            "eligible_programs": 0,
            "applied_programs": 0,
            "noop_programs": 0,
            "errors": [],
        },
        "measurement": None,
        "process": {},
    }
    try:
        programs = wait_for_attached_programs(process, expected_count=spec.expected_programs, timeout_s=attach_timeout)
        if not programs:
            result["status"] = "skipped"
            result["reason"] = "bpftrace did not attach any programs"
            return result

        prog_ids = [int(program["id"]) for program in programs]
        result["programs"] = programs
        result["prog_ids"] = prog_ids
        scan_results = scan_programs(prog_ids, scanner_binary)
        result["scan_results"] = {str(key): value for key, value in scan_results.items()}
        result["site_totals"] = aggregate_site_totals(scan_results)
        eligible_prog_ids = [
            int(prog_id)
            for prog_id, record in scan_results.items()
            if int((record.get("sites") or {}).get("total_sites", 0) or 0) > 0
        ]
        eligible_programs = [
            program
            for program in programs
            if int(program.get("id", 0) or 0) in set(eligible_prog_ids)
        ]
        policy_files = resolve_bpftrace_policy_files(spec, eligible_programs)
        result["policy_matches"] = {str(prog_id): path for prog_id, path in policy_files.items()}
        result["policy_summary"] = {
            "configured_programs": len(policy_files),
            "fallback_programs": max(0, len(eligible_prog_ids) - len(policy_files)),
        }

        if apply_rejit:
            result["recompile_summary"]["eligible_programs"] = len(eligible_prog_ids)
            if not eligible_prog_ids:
                result["status"] = "skipped"
                result["reason"] = "no eligible directive sites"
                return result

            recompile_results = apply_recompile(
                eligible_prog_ids,
                scanner_binary,
                policy_files=policy_files,
            )
            applied_programs = sum(1 for record in recompile_results.values() if record.get("applied"))
            noop_programs = sum(1 for record in recompile_results.values() if record.get("noop"))
            errors = sorted({str(record.get("error", "")).strip() for record in recompile_results.values() if record.get("error")})
            result["recompile_results"] = {str(key): value for key, value in recompile_results.items()}
            result["recompile_summary"] = {
                "eligible_programs": len(eligible_prog_ids),
                "applied_programs": applied_programs,
                "noop_programs": noop_programs,
                "errors": errors,
            }
            if applied_programs <= 0:
                result["status"] = "skipped"
                result["reason"] = (
                    "policy filtered all live sites"
                    if noop_programs == len(eligible_prog_ids)
                    else "BPF_PROG_JIT_RECOMPILE did not apply"
                )
                return result
            time.sleep(0.5)

        measurement = measure_workload(
            spec.workload_kind,
            duration_s,
            prog_ids,
            agent_pid=int(process.pid or 0),
            initial_stats=sample_bpf_stats(prog_ids),
        )
        result["measurement"] = measurement
        result["status"] = "ok"
        return result
    except Exception as exc:
        result["status"] = "error"
        result["reason"] = str(exc)
        return result
    finally:
        stop_agent(process, timeout=8)
        result["process"] = finalize_process_output(process)
        if result["status"] != "ok" and not result["reason"]:
            stderr_tail = str(result["process"].get("stderr_tail") or "")
            stdout_tail = str(result["process"].get("stdout_tail") or "")
            result["reason"] = stderr_tail or stdout_tail or "unknown failure"


def summarize_script(spec: ScriptSpec, baseline: Mapping[str, object], rejit: Mapping[str, object] | None) -> dict[str, object]:
    baseline_measurement = baseline.get("measurement") or {}
    rejit_measurement = (rejit or {}).get("measurement") or {}
    stock_avg_ns = ((baseline_measurement.get("bpf") or {}).get("summary", {}) or {}).get("avg_ns_per_run")
    rejit_avg_ns = ((rejit_measurement.get("bpf") or {}).get("summary", {}) or {}).get("avg_ns_per_run")
    workload_ops_baseline = ((baseline_measurement.get("workload") or {}).get("ops_per_sec"))
    workload_ops_rejit = ((rejit_measurement.get("workload") or {}).get("ops_per_sec"))
    cpu_baseline = ((baseline_measurement.get("agent_cpu") or {}).get("total_pct"))
    cpu_rejit = ((rejit_measurement.get("agent_cpu") or {}).get("total_pct"))
    sites = int(((rejit or {}).get("site_totals") or baseline.get("site_totals") or {}).get("total_sites", 0) or 0)
    speedup = None
    if stock_avg_ns not in (None, 0) and rejit_avg_ns not in (None, 0):
        speedup = float(stock_avg_ns) / float(rejit_avg_ns)

    note = ""
    if baseline.get("status") != "ok":
        note = str(baseline.get("reason") or "")
    elif rejit and rejit.get("status") != "ok":
        note = str(rejit.get("reason") or "")

    return {
        "name": spec.name,
        "sites": sites,
        "stock_avg_ns": stock_avg_ns,
        "rejit_avg_ns": rejit_avg_ns,
        "speedup": speedup,
        "workload_ops_baseline": workload_ops_baseline,
        "workload_ops_rejit": workload_ops_rejit,
        "cpu_baseline": cpu_baseline,
        "cpu_rejit": cpu_rejit,
        "avg_ns_delta_pct": percent_delta(stock_avg_ns, rejit_avg_ns),
        "workload_ops_delta_pct": percent_delta(workload_ops_baseline, workload_ops_rejit),
        "cpu_delta_pct": percent_delta(cpu_baseline, cpu_rejit),
        "baseline_status": baseline.get("status"),
        "rejit_status": None if rejit is None else rejit.get("status"),
        "note": note,
    }


def format_float(value: object, digits: int = 2) -> str:
    if value is None:
        return "n/a"
    return f"{float(value):.{digits}f}"


def format_ratio(value: object) -> str:
    if value is None:
        return "n/a"
    return f"{float(value):.3f}x"


def markdown_table(headers: Sequence[str], rows: Sequence[Sequence[object]]) -> list[str]:
    lines = [
        "| " + " | ".join(headers) + " |",
        "| " + " | ".join("---" for _ in headers) + " |",
    ]
    for row in rows:
        lines.append("| " + " | ".join(str(cell) for cell in row) + " |")
    return lines


def geomean(values: Sequence[object]) -> float | None:
    positive = [float(value) for value in values if isinstance(value, (int, float)) and float(value) > 0]
    if not positive:
        return None
    return statistics.geometric_mean(positive)


def build_markdown(payload: Mapping[str, object]) -> str:
    lines = [
        "# bpftrace Real End-to-End Benchmark",
        "",
        f"- Generated: `{payload['generated_at']}`",
        f"- Mode: `{'smoke' if payload['smoke'] else 'full'}`",
        f"- Duration per phase: `{payload['duration_s']}s`",
        f"- Host kernel: `{payload['host']['kernel']}`",
        f"- bpftrace: `{payload['tool_versions']['bpftrace_version_text']}`",
        f"- bpftool: `{payload['tool_versions']['bpftool_version_text']}`",
        f"- Scanner: `{payload['scanner']}`",
        "",
        "## Summary",
        "",
        f"- Scripts selected: `{len(payload['selected_scripts'])}`",
        f"- Baseline successes: `{payload['summary']['baseline_successes']}`",
        f"- ReJIT successes: `{payload['summary']['rejit_successes']}`",
        f"- Eligible-site scripts: `{payload['summary']['scripts_with_sites']}`",
        f"- Aggregate sites: `{payload['summary']['site_totals']['total_sites']}` "
        f"(cmov={payload['summary']['site_totals']['cmov_sites']}, "
        f"wide={payload['summary']['site_totals']['wide_sites']}, "
        f"rotate={payload['summary']['site_totals']['rotate_sites']}, "
        f"lea={payload['summary']['site_totals']['lea_sites']})",
        f"- Geomean speedup: `{format_ratio(payload['summary']['speedup_geomean'])}`",
        "",
        "## Per-Script",
        "",
    ]

    rows = []
    for record in payload["records"]:
        summary = record["summary"]
        rows.append(
            [
                summary["name"],
                summary["sites"],
                format_float(summary["stock_avg_ns"]),
                format_float(summary["rejit_avg_ns"]),
                format_ratio(summary["speedup"]),
                format_float(summary["workload_ops_baseline"]),
                format_float(summary["workload_ops_rejit"]),
                format_float(summary["cpu_baseline"]),
                format_float(summary["cpu_rejit"]),
                summary["note"] or "ok",
            ]
        )
    lines.extend(
        markdown_table(
            [
                "Script",
                "Sites",
                "Stock ns",
                "ReJIT ns",
                "Speedup",
                "Ops/s Stock",
                "Ops/s ReJIT",
                "CPU% Stock",
                "CPU% ReJIT",
                "Notes",
            ],
            rows,
        )
    )
    lines.extend(["", "## Comparison", ""])
    for record in payload["records"]:
        summary = record["summary"]
        lines.append(
            f"- {summary['name']}: avg_ns_delta={format_float(summary['avg_ns_delta_pct'])}%, "
            f"ops_delta={format_float(summary['workload_ops_delta_pct'])}%, "
            f"cpu_delta={format_float(summary['cpu_delta_pct'])}%"
        )
    lines.extend(
        [
            "",
            "## Notes",
            "",
            "- `Stock ns` and `ReJIT ns` are weighted averages of `delta(run_time_ns) / delta(run_cnt)` across the attached bpftrace-owned programs.",
            "- `Ops/s` is application throughput while the bpftrace script is attached; `CPU%` is bpftrace process CPU from `/proc/<pid>/stat` over the same interval.",
            "- Scripts that fail to attach or have no eligible directive sites are marked with `n/a` ReJIT fields instead of a fake comparison.",
            "",
        ]
    )
    return "\n".join(lines)


def build_report(payload: Mapping[str, object]) -> str:
    improved = [
        record["summary"]["name"]
        for record in payload["records"]
        if isinstance(record["summary"].get("avg_ns_delta_pct"), (int, float))
        and float(record["summary"]["avg_ns_delta_pct"]) < 0
    ]
    regressed = [
        record["summary"]["name"]
        for record in payload["records"]
        if isinstance(record["summary"].get("avg_ns_delta_pct"), (int, float))
        and float(record["summary"]["avg_ns_delta_pct"]) > 0
    ]
    lines = [
        "# bpftrace Real E2E Report",
        "",
        f"- Generated: `{payload['generated_at']}`",
        f"- Run mode: `{'smoke' if payload['smoke'] else 'full'}`",
        f"- Duration per phase: `{payload['duration_s']}s`",
        f"- Guest kernel: `{payload['host']['kernel']}`",
        f"- bpftrace version: `{payload['tool_versions']['bpftrace_version_text']}`",
        "",
        "## Outcome",
        "",
        "- This benchmark treats `bpftrace` itself as the tracing agent and measures application throughput plus bpftrace CPU while tracing is active.",
        f"- Scripts with detected sites: `{payload['summary']['scripts_with_sites']}`; aggregate site count: `{payload['summary']['site_totals']['total_sites']}`.",
        f"- Geomean BPF speedup across scripts with both baseline and ReJIT data: `{format_ratio(payload['summary']['speedup_geomean'])}`.",
        "",
        "## Per-Script",
        "",
    ]
    for record in payload["records"]:
        summary = record["summary"]
        lines.append(
            f"- `{summary['name']}`: sites={summary['sites']}, stock_ns={format_float(summary['stock_avg_ns'])}, "
            f"rejit_ns={format_float(summary['rejit_avg_ns'])}, speedup={format_ratio(summary['speedup'])}, "
            f"ops_stock={format_float(summary['workload_ops_baseline'])}, ops_rejit={format_float(summary['workload_ops_rejit'])}, "
            f"cpu_stock={format_float(summary['cpu_baseline'])}, cpu_rejit={format_float(summary['cpu_rejit'])}"
        )
        if summary["note"]:
            lines.append(f"- Note: {summary['note']}")
    lines.extend(
        [
            "",
            "## Comparison",
            "",
        ]
    )
    for record in payload["records"]:
        summary = record["summary"]
        lines.append(
            f"- `{summary['name']}` delta: avg_ns={format_float(summary['avg_ns_delta_pct'])}%, "
            f"ops={format_float(summary['workload_ops_delta_pct'])}%, "
            f"cpu={format_float(summary['cpu_delta_pct'])}%"
        )
    lines.extend(
        [
            "",
            "## Interpretation",
            "",
            "- The prior VM-only bpftrace measurements were pure BPF run-time deltas. This case adds application throughput and bpftrace CPU overhead, which makes the policy-sensitive regressions visible as honest end-to-end cost.",
            f"- Eligible CMOV-bearing scripts split by workload: improved={improved or ['none']}, regressed={regressed or ['none']}. The overall geomean across scripts with stock+ReJIT data is `{format_ratio(payload['summary']['speedup_geomean'])}`.",
            "- Scripts with zero eligible sites were still measured for the baseline end-to-end overhead, but their ReJIT columns remain `n/a` to avoid implying a meaningless comparison.",
            "",
        ]
    )
    return "\n".join(lines)


def run_case(args: argparse.Namespace) -> dict[str, object]:
    prepend_guest_tools_to_path()
    ensure_root([str(Path(sys.argv[0]).resolve()), *sys.argv[1:]])

    runner_binary = Path(args.runner).resolve()
    scanner_binary = Path(args.scanner).resolve()
    ensure_artifacts(runner_binary, scanner_binary, skip_build=bool(args.skip_build))
    tool_versions = ensure_required_tools()

    scripts = selected_scripts(args)
    if not scripts:
        raise RuntimeError("no scripts selected")

    duration_s = int(args.smoke_duration if args.smoke else (args.duration or DEFAULT_DURATION_S))
    records: list[dict[str, object]] = []
    with enable_bpf_stats():
        for spec in scripts:
            baseline = run_phase(
                spec,
                duration_s=duration_s,
                attach_timeout=int(args.attach_timeout),
                scanner_binary=scanner_binary,
                apply_rejit=False,
            )
            rejit = None
            if baseline.get("status") == "ok":
                rejit = run_phase(
                    spec,
                    duration_s=duration_s,
                    attach_timeout=int(args.attach_timeout),
                    scanner_binary=scanner_binary,
                    apply_rejit=True,
                )
            summary = summarize_script(spec, baseline, rejit)
            records.append(
                {
                    "name": spec.name,
                    "description": spec.description,
                    "script_path": str(spec.script_path),
                    "script_text": spec.script_path.read_text(),
                    "baseline": baseline,
                    "rejit": rejit,
                    "summary": summary,
                }
            )

    site_totals = {
        "total_sites": 0,
        "cmov_sites": 0,
        "wide_sites": 0,
        "rotate_sites": 0,
        "lea_sites": 0,
    }
    speedups: list[float] = []
    baseline_successes = 0
    rejit_successes = 0
    scripts_with_sites = 0
    for record in records:
        baseline = record.get("baseline") or {}
        rejit = record.get("rejit") or {}
        summary = record.get("summary") or {}
        if baseline.get("status") == "ok":
            baseline_successes += 1
        if rejit.get("status") == "ok":
            rejit_successes += 1
        if int((summary.get("sites") or 0)) > 0:
            scripts_with_sites += 1
        counts = baseline.get("site_totals") or rejit.get("site_totals") or {}
        for field in site_totals:
            site_totals[field] += int(counts.get(field, 0) or 0)
        speedup = summary.get("speedup")
        if isinstance(speedup, (int, float)) and float(speedup) > 0:
            speedups.append(float(speedup))

    return {
        "generated_at": datetime.now(timezone.utc).isoformat(),
        "smoke": bool(args.smoke),
        "duration_s": duration_s,
        "selected_scripts": [spec.name for spec in scripts],
        "runner": str(runner_binary),
        "scanner": str(scanner_binary),
        "host": host_metadata(),
        "tool_versions": tool_versions,
        "records": records,
        "summary": {
            "baseline_successes": baseline_successes,
            "rejit_successes": rejit_successes,
            "scripts_with_sites": scripts_with_sites,
            "site_totals": site_totals,
            "speedup_geomean": geomean(speedups),
        },
    }


def main() -> None:
    args = parse_args()
    payload = run_case(args)

    if args.output_json == str(DEFAULT_OUTPUT_JSON) and args.smoke:
        output_json = smoke_output_path(RESULTS_DIR, "bpftrace")
    else:
        output_json = Path(args.output_json).resolve()
    output_md = Path(args.output_md).resolve()
    report_md = Path(args.report_md).resolve()
    write_json(output_json, payload)
    write_text(output_md, build_markdown(payload) + "\n")
    write_text(report_md, build_report(payload) + "\n")
    print(f"[ok] wrote {output_json}")
    print(f"[ok] wrote {output_md}")
    print(f"[ok] wrote {report_md}")


if __name__ == "__main__":
    main()
