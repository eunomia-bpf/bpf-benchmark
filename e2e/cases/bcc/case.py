#!/usr/bin/env python3
"""BCC libbpf-tools E2E benchmark case.

Each tool from runner/repos/bcc/libbpf-tools/ is started as a real userspace
binary that loads BPF programs into the kernel.  The benchmark follows the same
baseline → daemon-apply → post-rejit pattern used by the bpftrace case.
"""
from __future__ import annotations

import argparse
import os
import statistics
import subprocess
import sys
import threading
import time
from dataclasses import dataclass
from datetime import datetime, timezone
from pathlib import Path
from typing import Any, Mapping, Sequence

import yaml

if __package__ in {None, ""}:
    sys.path.insert(0, str(Path(__file__).resolve().parents[3]))

from runner.libs import (  # noqa: E402
    RESULTS_DIR,
    ROOT_DIR,
    authoritative_output_path,
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
from runner.libs.recompile import apply_daemon_rejit, scan_programs  # noqa: E402
from runner.libs.workload import (  # noqa: E402
    WorkloadResult,
    run_dd_read_load,
    run_exec_storm,
    run_file_open_load,
    run_scheduler_load,
    run_tcp_connect_load,
)
from e2e.case_common import (  # noqa: E402
    git_sha,
    host_metadata,
    percent_delta,
)


DEFAULT_CONFIG = Path(__file__).with_name("config.yaml")
DEFAULT_SETUP_SCRIPT = Path(__file__).with_name("setup.sh")
DEFAULT_OUTPUT_JSON = authoritative_output_path(RESULTS_DIR, "bcc")
DEFAULT_OUTPUT_MD = ROOT_DIR / "e2e" / "results" / "bcc-e2e.md"
DEFAULT_REPORT_MD = ROOT_DIR / "docs" / "tmp" / "bcc-e2e-report.md"
DEFAULT_DAEMON = ROOT_DIR / "daemon" / "target" / "release" / "bpfrejit-daemon"
# libbpf-tools src dir; setup.sh may override this via BCC_TOOLS_DIR env var
DEFAULT_TOOLS_DIR = ROOT_DIR / "runner" / "repos" / "bcc" / "libbpf-tools"


# ---------------------------------------------------------------------------
# Config dataclasses
# ---------------------------------------------------------------------------

@dataclass(frozen=True, slots=True)
class ToolSpec:
    name: str
    description: str
    expected_programs: int
    workload_kind: str
    spawn_timeout_s: int


@dataclass(frozen=True, slots=True)
class SuiteConfig:
    tools: tuple[ToolSpec, ...]
    measurement_duration_s: int
    smoke_duration_s: int
    attach_timeout_s: int


def load_config(path: Path) -> SuiteConfig:
    raw = yaml.safe_load(path.read_text())
    tools = tuple(
        ToolSpec(
            name=entry["name"],
            description=entry.get("description", ""),
            expected_programs=int(entry.get("expected_programs", 1)),
            workload_kind=entry["workload_kind"],
            spawn_timeout_s=int(entry.get("spawn_timeout_s", 20)),
        )
        for entry in raw.get("tools", [])
    )
    return SuiteConfig(
        tools=tools,
        measurement_duration_s=int(raw.get("measurement_duration_s", 30)),
        smoke_duration_s=int(raw.get("smoke_duration_s", 10)),
        attach_timeout_s=int(raw.get("attach_timeout_s", 20)),
    )


# ---------------------------------------------------------------------------
# Tool binary resolution
# ---------------------------------------------------------------------------

def resolve_tools_dir(explicit: str | None) -> Path:
    """Return the directory containing compiled libbpf-tools binaries."""
    # Priority: explicit CLI arg > BCC_TOOLS_DIR env var > setup.sh output > default src dir
    if explicit:
        candidate = Path(explicit)
        if candidate.is_dir():
            return candidate
    env_dir = os.environ.get("BCC_TOOLS_DIR", "").strip()
    if env_dir:
        candidate = Path(env_dir)
        if candidate.is_dir():
            return candidate
    # Check .output subdirectory (standard libbpf-tools build output)
    output_subdir = DEFAULT_TOOLS_DIR / ".output"
    if output_subdir.is_dir() and (output_subdir / "tcplife").exists():
        return output_subdir
    return DEFAULT_TOOLS_DIR


def find_tool_binary(tools_dir: Path, name: str) -> Path | None:
    """Return the path to a compiled libbpf-tools binary, or None."""
    candidate = tools_dir / name
    if candidate.is_file() and os.access(candidate, os.X_OK):
        return candidate
    # Some builds place binaries in parent directory
    candidate2 = tools_dir.parent / name
    if candidate2.is_file() and os.access(candidate2, os.X_OK):
        return candidate2
    return None


# ---------------------------------------------------------------------------
# Workload dispatch
# ---------------------------------------------------------------------------

def run_named_workload(kind: str, duration_s: int) -> WorkloadResult:
    if kind == "tcp_connect":
        return run_tcp_connect_load(duration_s)
    if kind == "dd_read":
        return run_dd_read_load(duration_s)
    if kind == "scheduler":
        return run_scheduler_load(duration_s)
    if kind == "exec_storm":
        return run_exec_storm(duration_s, rate=2)
    if kind == "file_open":
        return run_file_open_load(duration_s)
    raise RuntimeError(f"unsupported workload kind: {kind!r}")


# ---------------------------------------------------------------------------
# BPF program discovery
# ---------------------------------------------------------------------------

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


# ---------------------------------------------------------------------------
# Site aggregation
# ---------------------------------------------------------------------------

def aggregate_site_totals(records: Mapping[int, Mapping[str, object]]) -> dict[str, int]:
    totals: dict[str, int] = {
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


# ---------------------------------------------------------------------------
# Measurement
# ---------------------------------------------------------------------------

def measure_workload(
    workload_kind: str,
    duration_s: int,
    prog_ids: Sequence[int],
    *,
    agent_pid: int,
    initial_stats: Mapping[int, Mapping[str, object]] | None = None,
) -> dict[str, object]:
    before_bpf = {int(k): dict(v) for k, v in (initial_stats or sample_bpf_stats(list(prog_ids))).items()}
    cpu_holder: dict[int, dict[str, float]] = {}
    system_cpu_holder: dict[str, float] = {}

    cpu_thread = threading.Thread(
        target=lambda: cpu_holder.update(sample_cpu_usage([agent_pid], duration_s)),
        daemon=True,
    )
    cpu_thread.start()

    system_thread = threading.Thread(
        target=lambda: system_cpu_holder.update(sample_total_cpu_usage(duration_s)),
        daemon=True,
    )
    system_thread.start()

    try:
        workload_result = run_named_workload(workload_kind, duration_s)
    finally:
        cpu_thread.join()
        system_thread.join()

    after_bpf = sample_bpf_stats(list(prog_ids))
    bpf_delta = compute_delta(before_bpf, after_bpf)
    agent_cpu = cpu_holder.get(agent_pid, {})
    total_pct: float | None = None
    if agent_cpu:
        total_pct = float(agent_cpu.get("user_pct", 0.0)) + float(agent_cpu.get("sys_pct", 0.0))

    return {
        "workload": workload_result.to_dict(),
        "initial_stats": {str(k): v for k, v in before_bpf.items()},
        "final_stats": {str(k): v for k, v in after_bpf.items()},
        "bpf": bpf_delta,
        "agent_cpu": {
            "user_pct": agent_cpu.get("user_pct"),
            "sys_pct": agent_cpu.get("sys_pct"),
            "total_pct": total_pct,
        },
        "system_cpu": system_cpu_holder,
    }


# ---------------------------------------------------------------------------
# Per-tool phase runner
# ---------------------------------------------------------------------------

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
                pass
        if process.stderr is not None:
            try:
                stderr = process.stderr.read()
            except Exception:
                pass
    return {
        "returncode": process.returncode,
        "stdout_tail": tail_text(stdout, max_lines=40, max_chars=8000),
        "stderr_tail": tail_text(stderr, max_lines=40, max_chars=8000),
    }


def run_phase(
    spec: ToolSpec,
    tool_binary: Path,
    *,
    duration_s: int,
    attach_timeout: int,
    daemon_binary: Path,
) -> tuple[dict[str, object], dict[str, object] | None]:
    """Run baseline then daemon-apply then post-rejit measurement for one tool.

    Returns (baseline, rejit) where rejit is None if apply failed or was skipped.
    """
    # Most libbpf-tools write to stdout; -T adds timestamps for biosnoop etc.
    # Run without extra flags to keep the tool's default output mode.
    process = start_agent(str(tool_binary), [])

    baseline: dict[str, object] = {
        "phase": "baseline",
        "status": "error",
        "reason": "",
        "programs": [],
        "prog_ids": [],
        "scan_results": {},
        "site_totals": {
            "total_sites": 0,
            "cmov_sites": 0,
            "wide_sites": 0,
            "rotate_sites": 0,
            "lea_sites": 0,
        },
        "measurement": None,
        "process": {},
    }
    rejit: dict[str, object] | None = None
    try:
        programs = wait_for_attached_programs(
            process,
            expected_count=spec.expected_programs,
            timeout_s=attach_timeout,
        )
        if not programs:
            baseline["status"] = "skipped"
            baseline["reason"] = f"{spec.name} did not attach any BPF programs within {attach_timeout}s"
            return baseline, None

        prog_ids = [int(program["id"]) for program in programs]
        baseline["programs"] = programs
        baseline["prog_ids"] = prog_ids
        scan_results = scan_programs(prog_ids, daemon_binary)
        baseline["scan_results"] = {str(k): v for k, v in scan_results.items()}
        baseline["site_totals"] = aggregate_site_totals(scan_results)

        measurement = measure_workload(
            spec.workload_kind,
            duration_s,
            prog_ids,
            agent_pid=int(process.pid or 0),
            initial_stats=sample_bpf_stats(prog_ids),
        )
        baseline["measurement"] = measurement
        baseline["status"] = "ok"

        rejit_apply = apply_daemon_rejit(daemon_binary, prog_ids)
        if rejit_apply["applied"]:
            rejit = {
                "phase": "post_rejit",
                "status": "ok",
                "reason": "",
                "programs": programs,
                "prog_ids": prog_ids,
                "scan_results": baseline["scan_results"],
                "site_totals": baseline["site_totals"],
                "rejit_result": rejit_apply,
                "measurement": measure_workload(
                    spec.workload_kind,
                    duration_s,
                    prog_ids,
                    agent_pid=int(process.pid or 0),
                    initial_stats=sample_bpf_stats(prog_ids),
                ),
                "process": {},
            }

        return baseline, rejit
    except Exception as exc:
        baseline["status"] = "error"
        baseline["reason"] = str(exc)
        return baseline, rejit
    finally:
        stop_agent(process, timeout=8)
        process_output = finalize_process_output(process)
        baseline["process"] = process_output
        if rejit is not None:
            rejit["process"] = process_output
        if baseline["status"] not in ("ok", "skipped") and not baseline["reason"]:
            stderr_tail = str(process_output.get("stderr_tail") or "")
            stdout_tail = str(process_output.get("stdout_tail") or "")
            baseline["reason"] = stderr_tail or stdout_tail or "unknown failure"


# ---------------------------------------------------------------------------
# Summary helpers
# ---------------------------------------------------------------------------

def summarize_tool(
    spec: ToolSpec,
    baseline: Mapping[str, object],
    rejit: Mapping[str, object] | None,
) -> dict[str, object]:
    baseline_measurement = baseline.get("measurement") or {}
    rejit_measurement = (rejit or {}).get("measurement") or {}
    stock_avg_ns = ((baseline_measurement.get("bpf") or {}).get("summary", {}) or {}).get("avg_ns_per_run")
    rejit_avg_ns = ((rejit_measurement.get("bpf") or {}).get("summary", {}) or {}).get("avg_ns_per_run")
    workload_ops_baseline = (baseline_measurement.get("workload") or {}).get("ops_per_sec")
    workload_ops_rejit = (rejit_measurement.get("workload") or {}).get("ops_per_sec")
    cpu_baseline = (baseline_measurement.get("agent_cpu") or {}).get("total_pct")
    cpu_rejit = (rejit_measurement.get("agent_cpu") or {}).get("total_pct")
    sites = int(((rejit or {}).get("site_totals") or baseline.get("site_totals") or {}).get("total_sites", 0) or 0)

    speedup: float | None = None
    if stock_avg_ns not in (None, 0) and rejit_avg_ns not in (None, 0):
        speedup = float(stock_avg_ns) / float(rejit_avg_ns)

    note = ""
    if baseline.get("status") != "ok":
        note = str(baseline.get("reason") or "")
    elif rejit and rejit.get("status") != "ok":
        note = str(rejit.get("reason") or "")

    return {
        "name": spec.name,
        "description": spec.description,
        "workload_kind": spec.workload_kind,
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


def geomean(values: Sequence[object]) -> float | None:
    positive = [float(v) for v in values if isinstance(v, (int, float)) and float(v) > 0]
    if not positive:
        return None
    return statistics.geometric_mean(positive)


# ---------------------------------------------------------------------------
# Markdown / report builders
# ---------------------------------------------------------------------------

def _fmt(value: object, digits: int = 2) -> str:
    if value is None:
        return "n/a"
    return f"{float(value):.{digits}f}"


def _fmt_ratio(value: object) -> str:
    if value is None:
        return "n/a"
    return f"{float(value):.3f}x"


def _markdown_table(headers: Sequence[str], rows: Sequence[Sequence[object]]) -> list[str]:
    lines = [
        "| " + " | ".join(headers) + " |",
        "| " + " | ".join("---" for _ in headers) + " |",
    ]
    for row in rows:
        lines.append("| " + " | ".join(str(cell) for cell in row) + " |")
    return lines


def build_markdown(payload: Mapping[str, object]) -> str:
    lines = [
        "# BCC libbpf-tools Real End-to-End Benchmark",
        "",
        f"- Generated: `{payload['generated_at']}`",
        f"- Mode: `{'smoke' if payload['smoke'] else 'full'}`",
        f"- Duration per phase: `{payload['duration_s']}s`",
        f"- Host kernel: `{payload['host']['kernel']}`",
        f"- Tools dir: `{payload['tools_dir']}`",
        f"- Daemon: `{payload['daemon']}`",
        "",
        "## Summary",
        "",
        f"- Tools selected: `{len(payload['selected_tools'])}`",
        f"- Baseline successes: `{payload['summary']['baseline_successes']}`",
        f"- ReJIT successes: `{payload['summary']['rejit_successes']}`",
        f"- Tools with eligible sites: `{payload['summary']['tools_with_sites']}`",
        f"- Aggregate sites: `{payload['summary']['site_totals']['total_sites']}` "
        f"(cmov={payload['summary']['site_totals']['cmov_sites']}, "
        f"wide={payload['summary']['site_totals']['wide_sites']}, "
        f"rotate={payload['summary']['site_totals']['rotate_sites']}, "
        f"lea={payload['summary']['site_totals']['lea_sites']})",
        f"- Geomean speedup: `{_fmt_ratio(payload['summary']['speedup_geomean'])}`",
        "",
        "## Per-Tool",
        "",
    ]
    rows = []
    for record in payload["records"]:
        summary = record["summary"]
        rows.append([
            summary["name"],
            summary["sites"],
            _fmt(summary["stock_avg_ns"]),
            _fmt(summary["rejit_avg_ns"]),
            _fmt_ratio(summary["speedup"]),
            _fmt(summary["workload_ops_baseline"]),
            _fmt(summary["workload_ops_rejit"]),
            _fmt(summary["cpu_baseline"]),
            _fmt(summary["cpu_rejit"]),
            summary["note"] or "ok",
        ])
    lines.extend(_markdown_table(
        ["Tool", "Sites", "Stock ns", "ReJIT ns", "Speedup",
         "Ops/s Stock", "Ops/s ReJIT", "CPU% Stock", "CPU% ReJIT", "Notes"],
        rows,
    ))
    lines.extend(["", "## Comparison", ""])
    for record in payload["records"]:
        summary = record["summary"]
        lines.append(
            f"- {summary['name']}: avg_ns_delta={_fmt(summary['avg_ns_delta_pct'])}%, "
            f"ops_delta={_fmt(summary['workload_ops_delta_pct'])}%, "
            f"cpu_delta={_fmt(summary['cpu_delta_pct'])}%"
        )
    lines.extend([
        "",
        "## Notes",
        "",
        "- `Stock ns` and `ReJIT ns` are weighted averages of `delta(run_time_ns) / delta(run_cnt)` "
        "across the libbpf-tool-owned BPF programs.",
        "- `Ops/s` is application workload throughput while the tool is tracing; "
        "`CPU%` is the tool process CPU from `/proc/<pid>/stat`.",
        "- Tools that fail to attach or have no eligible directive sites show `n/a` ReJIT columns.",
        "",
    ])
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
        "# BCC libbpf-tools E2E Report",
        "",
        f"- Generated: `{payload['generated_at']}`",
        f"- Run mode: `{'smoke' if payload['smoke'] else 'full'}`",
        f"- Duration per phase: `{payload['duration_s']}s`",
        f"- Guest kernel: `{payload['host']['kernel']}`",
        f"- Tools dir: `{payload['tools_dir']}`",
        "",
        "## Outcome",
        "",
        f"- Tools with detected sites: `{payload['summary']['tools_with_sites']}`; "
        f"aggregate site count: `{payload['summary']['site_totals']['total_sites']}`.",
        f"- Geomean BPF speedup across tools with both baseline and ReJIT data: "
        f"`{_fmt_ratio(payload['summary']['speedup_geomean'])}`.",
        "",
        "## Per-Tool",
        "",
    ]
    for record in payload["records"]:
        summary = record["summary"]
        lines.append(
            f"- `{summary['name']}` ({summary['workload_kind']}): "
            f"sites={summary['sites']}, stock_ns={_fmt(summary['stock_avg_ns'])}, "
            f"rejit_ns={_fmt(summary['rejit_avg_ns'])}, speedup={_fmt_ratio(summary['speedup'])}, "
            f"ops_stock={_fmt(summary['workload_ops_baseline'])}, ops_rejit={_fmt(summary['workload_ops_rejit'])}, "
            f"cpu_stock={_fmt(summary['cpu_baseline'])}, cpu_rejit={_fmt(summary['cpu_rejit'])}"
        )
        if summary["note"]:
            lines.append(f"  - Note: {summary['note']}")
    lines.extend([
        "",
        "## Interpretation",
        "",
        "- BCC libbpf-tools are production observability tools with diverse BPF program shapes, "
        "exercising the full range of kprobes, tracepoints, and helper calls.",
        f"- Tools improved by ReJIT: {improved or ['none']}; regressed: {regressed or ['none']}.",
        f"- Geomean speedup: `{_fmt_ratio(payload['summary']['speedup_geomean'])}`.",
        "- Tools with zero eligible sites are still measured for baseline overhead but "
        "their ReJIT columns remain `n/a`.",
        "",
    ])
    return "\n".join(lines)


# ---------------------------------------------------------------------------
# Top-level entry points
# ---------------------------------------------------------------------------

def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="Run the BCC libbpf-tools end-to-end benchmark case.")
    parser.add_argument("--output-json", default=str(DEFAULT_OUTPUT_JSON))
    parser.add_argument("--output-md", default=str(DEFAULT_OUTPUT_MD))
    parser.add_argument("--report-md", default=str(DEFAULT_REPORT_MD))
    parser.add_argument("--daemon", default=str(DEFAULT_DAEMON))
    parser.add_argument("--tools-dir", default="", help="Directory with compiled libbpf-tools binaries.")
    parser.add_argument("--config", default=str(DEFAULT_CONFIG))
    parser.add_argument("--duration", type=int, default=0)
    parser.add_argument("--smoke-duration", type=int, default=0)
    parser.add_argument("--attach-timeout", type=int, default=0)
    parser.add_argument("--tool", action="append", dest="tools")
    parser.add_argument("--smoke", action="store_true")
    return parser.parse_args()


def run_bcc_case(args: argparse.Namespace) -> dict[str, object]:
    daemon_binary = Path(args.daemon).resolve()
    if not daemon_binary.exists():
        raise RuntimeError(f"bpfrejit-daemon not found: {daemon_binary}")

    suite = load_config(Path(args.config).resolve())
    tools_dir = resolve_tools_dir(getattr(args, "tools_dir", None) or "")

    # Duration resolution: CLI > smoke flag > config
    smoke = bool(args.smoke)
    if getattr(args, "smoke_duration", 0) and smoke:
        duration_s = int(args.smoke_duration)
    elif getattr(args, "duration", 0):
        duration_s = int(args.duration)
    elif smoke:
        duration_s = suite.smoke_duration_s
    else:
        duration_s = suite.measurement_duration_s

    attach_timeout = int(getattr(args, "attach_timeout", 0) or suite.attach_timeout_s)

    # Filter tools if --tool was provided
    selected: list[ToolSpec]
    if smoke:
        # Smoke: run only the fastest attaching tool (capable)
        smoke_candidate = next((t for t in suite.tools if t.name == "capable"), None)
        selected = [smoke_candidate] if smoke_candidate else [suite.tools[0]]
    elif getattr(args, "tools", None):
        wanted = {name.strip() for name in args.tools if name and name.strip()}
        selected = [t for t in suite.tools if t.name in wanted]
    else:
        selected = list(suite.tools)

    if not selected:
        raise RuntimeError("no tools selected")

    records: list[dict[str, object]] = []
    with enable_bpf_stats():
        for spec in selected:
            tool_binary = find_tool_binary(tools_dir, spec.name)
            if tool_binary is None:
                record: dict[str, object] = {
                    "name": spec.name,
                    "description": spec.description,
                    "tool_binary": None,
                    "baseline": {
                        "phase": "baseline",
                        "status": "skipped",
                        "reason": f"binary '{spec.name}' not found in {tools_dir}",
                        "programs": [],
                        "prog_ids": [],
                        "scan_results": {},
                        "site_totals": {
                            "total_sites": 0, "cmov_sites": 0,
                            "wide_sites": 0, "rotate_sites": 0, "lea_sites": 0,
                        },
                        "measurement": None,
                        "process": {},
                    },
                    "rejit": None,
                    "summary": {
                        "name": spec.name,
                        "description": spec.description,
                        "workload_kind": spec.workload_kind,
                        "sites": 0,
                        "stock_avg_ns": None,
                        "rejit_avg_ns": None,
                        "speedup": None,
                        "workload_ops_baseline": None,
                        "workload_ops_rejit": None,
                        "cpu_baseline": None,
                        "cpu_rejit": None,
                        "avg_ns_delta_pct": None,
                        "workload_ops_delta_pct": None,
                        "cpu_delta_pct": None,
                        "baseline_status": "skipped",
                        "rejit_status": None,
                        "note": f"binary not found in {tools_dir}",
                    },
                }
                records.append(record)
                continue

            baseline, rejit = run_phase(
                spec,
                tool_binary,
                duration_s=duration_s,
                attach_timeout=attach_timeout,
                daemon_binary=daemon_binary,
            )
            summary = summarize_tool(spec, baseline, rejit)
            records.append({
                "name": spec.name,
                "description": spec.description,
                "tool_binary": str(tool_binary),
                "baseline": baseline,
                "rejit": rejit,
                "summary": summary,
            })

    # Aggregate
    site_totals: dict[str, int] = {
        "total_sites": 0, "cmov_sites": 0,
        "wide_sites": 0, "rotate_sites": 0, "lea_sites": 0,
    }
    speedups: list[float] = []
    baseline_successes = 0
    rejit_successes = 0
    tools_with_sites = 0
    for record in records:
        bl = record.get("baseline") or {}
        rj = record.get("rejit") or {}
        sm = record.get("summary") or {}
        if bl.get("status") == "ok":
            baseline_successes += 1
        if rj.get("status") == "ok":
            rejit_successes += 1
        if int((sm.get("sites") or 0)) > 0:
            tools_with_sites += 1
        counts = bl.get("site_totals") or rj.get("site_totals") or {}
        for field in site_totals:
            site_totals[field] += int(counts.get(field, 0) or 0)
        speedup = sm.get("speedup")
        if isinstance(speedup, (int, float)) and float(speedup) > 0:
            speedups.append(float(speedup))

    return {
        "generated_at": datetime.now(timezone.utc).isoformat(),
        "smoke": smoke,
        "duration_s": duration_s,
        "selected_tools": [spec.name for spec in selected],
        "tools_dir": str(tools_dir),
        "daemon": str(daemon_binary),
        "host": host_metadata(),
        "records": records,
        "summary": {
            "baseline_successes": baseline_successes,
            "rejit_successes": rejit_successes,
            "tools_with_sites": tools_with_sites,
            "site_totals": site_totals,
            "speedup_geomean": geomean(speedups),
        },
    }


def main() -> None:
    args = parse_args()
    payload = run_bcc_case(args)

    if args.output_json == str(DEFAULT_OUTPUT_JSON) and args.smoke:
        output_json = smoke_output_path(RESULTS_DIR, "bcc")
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
