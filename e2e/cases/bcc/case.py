"""BCC libbpf-tools E2E benchmark case.

Each tool from runner/repos/bcc/libbpf-tools/ is started as a real userspace
binary that loads BPF programs into the kernel.  The benchmark follows the same
baseline → daemon-apply → post-rejit pattern used by the bpftrace case.
"""
from __future__ import annotations

import argparse
import statistics
import sys
from dataclasses import dataclass
from datetime import datetime, timezone
from pathlib import Path
from typing import Mapping, Sequence

import yaml

if __package__ in {None, ""}:
    sys.path.insert(0, str(Path(__file__).resolve().parents[3]))

from runner.libs import (  # noqa: E402
    RESULTS_DIR,
    ROOT_DIR,
)
from runner.libs.app_runners.bcc import BCCRunner, find_tool_binary, resolve_tools_dir, run_setup_script  # noqa: E402
from runner.libs.bpf_stats import (  # noqa: E402
    enable_bpf_stats,
)
from runner.libs.rejit import (  # noqa: E402
    applied_site_totals_from_rejit_result,
    benchmark_rejit_enabled_passes,
    collect_effective_enabled_passes,
)
from runner.libs.case_common import (  # noqa: E402
    CaseLifecycleState,
    host_metadata,
    measure_app_runner_workload,
    percent_delta,
    run_app_runner_phase_records,
    zero_site_totals,
)


DEFAULT_CONFIG = Path(__file__).with_name("config.yaml")
DEFAULT_SETUP_SCRIPT = Path(__file__).with_name("setup.sh")
DEFAULT_OUTPUT_JSON = RESULTS_DIR / "bcc.json"
DEFAULT_OUTPUT_MD = ROOT_DIR / "e2e" / "results" / "bcc-e2e.md"
DEFAULT_REPORT_MD = ROOT_DIR / "e2e" / "results" / "bcc-e2e-report.md"


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
    tool_args: tuple[str, ...]


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
            tool_args=tuple(str(arg) for arg in entry.get("tool_args", [])),
        )
        for entry in raw.get("tools", [])
    )
    return SuiteConfig(
        tools=tools,
        measurement_duration_s=int(raw.get("measurement_duration_s", 30)),
        smoke_duration_s=int(raw.get("smoke_duration_s", 10)),
        attach_timeout_s=int(raw.get("attach_timeout_s", 20)),
    )


BCC_SITE_TOTAL_FIELDS = (
    "total_sites",
    "map_inline_sites",
    "const_prop_sites",
    "dce_sites",
    "cmov_sites",
    "wide_sites",
    "rotate_sites",
    "lea_sites",
)

SITE_BREAKDOWN_FIELDS = (
    ("map_inline_sites", "map_inline"),
    ("const_prop_sites", "const_prop"),
    ("dce_sites", "dce"),
    ("cmov_sites", "cond_select"),
    ("wide_sites", "wide_mem"),
    ("rotate_sites", "rotate"),
    ("extract_sites", "extract"),
    ("endian_sites", "endian_fusion"),
    ("bounds_check_merge_sites", "bounds_check_merge"),
    ("skb_load_bytes_spec_sites", "skb_load_bytes_spec"),
    ("bulk_memory_sites", "bulk_memory"),
    ("branch_flip_sites", "branch_flip"),
    ("other_sites", "other"),
)


def format_site_breakdown(site_totals: Mapping[str, object]) -> str:
    parts = [
        f"{label}={int(site_totals.get(field_name, 0) or 0)}"
        for field_name, label in SITE_BREAKDOWN_FIELDS
        if int(site_totals.get(field_name, 0) or 0) > 0
    ]
    return ", ".join(parts) if parts else "none"


def run_phase(
    spec: ToolSpec,
    tool_binary: Path,
    *,
    duration_s: int,
    attach_timeout: int,
    enabled_passes: Sequence[str] | None,
    policy_context: Mapping[str, object] | None = None,
    prepared_daemon_session: object,
) -> tuple[dict[str, object], dict[str, object] | None]:
    """Run baseline then daemon-apply then post-rejit measurement for one tool.

    Returns (baseline, rejit) where rejit is None only when ReJIT was not applicable.
    """
    bcc_runner = BCCRunner(
        tool_binary=tool_binary,
        tool_name=spec.name,
        tool_args=spec.tool_args,
        workload_kind=spec.workload_kind,
        expected_programs=spec.expected_programs,
        attach_timeout_s=attach_timeout,
    )
    def workload(lifecycle: object, _phase_name: str) -> dict[str, object]:
        prog_ids = [int(value) for value in (getattr(lifecycle, "target_prog_ids", []) or []) if int(value) > 0]
        if not prog_ids:
            return {"status": "error", "reason": "no BPF programs are attached", "measurement": None}
        process = bcc_runner.session.process if bcc_runner.session is not None else None
        if process is None:
            return {"status": "error", "reason": "bcc runner process is not available", "measurement": None}
        return {
            "status": "ok",
            "reason": "",
            "measurement": measure_app_runner_workload(
                bcc_runner,
                duration_s,
                prog_ids,
                agent_pid=int(process.pid or 0),
            ),
        }

    if prepared_daemon_session is None:
        raise RuntimeError("prepared daemon session is required")

    def build_state(runner: BCCRunner, started_prog_ids: list[int]) -> CaseLifecycleState:
        prog_ids = [int(value) for value in started_prog_ids if int(value) > 0]
        if not prog_ids:
            raise RuntimeError(f"BCC tool {spec.name} did not expose any live prog_ids")
        programs = [dict(program) for program in runner.programs]
        if not programs:
            raise RuntimeError(f"BCC tool {spec.name} did not expose any live programs")
        artifacts: dict[str, object] = {
            "runner_artifacts": dict(runner.artifacts),
            "programs": programs,
            "command_used": [str(item) for item in runner.command_used],
        }
        if isinstance(policy_context, Mapping):
            artifacts["rejit_policy_context"] = {
                str(key): value
                for key, value in policy_context.items()
                if str(key).strip() and str(value).strip()
            }
        return CaseLifecycleState(
            runtime=runner,
            target_prog_ids=list(prog_ids),
            apply_prog_ids=list(prog_ids),
            artifacts=artifacts,
        )

    return run_app_runner_phase_records(
        runner=bcc_runner,
        prepared_daemon_session=prepared_daemon_session,
        measure=workload,
        site_totals_fields=BCC_SITE_TOTAL_FIELDS,
        enabled_passes=(list(enabled_passes) if enabled_passes is not None else None),
        build_state=build_state,
    )


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
    site_totals = applied_site_totals_from_rejit_result((rejit or {}).get("rejit_result"))
    sites = int(site_totals.get("total_sites", 0) or 0)

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
        "site_totals": site_totals,
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


def collect_record_errors(records: Sequence[Mapping[str, object]]) -> list[str]:
    errors: list[str] = []
    for record in records:
        name = str(record.get("name") or "unknown")
        baseline = record.get("baseline") or {}
        if isinstance(baseline, Mapping) and str(baseline.get("status") or "") == "error":
            reason = str(baseline.get("reason") or "unknown failure")
            errors.append(f"{name} baseline failed: {reason}")
        rejit = record.get("rejit") or {}
        if isinstance(rejit, Mapping) and str(rejit.get("status") or "") == "error":
            reason = str(rejit.get("reason") or "unknown failure")
            errors.append(f"{name} rejit failed: {reason}")
    return errors


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
    site_totals = payload["summary"]["site_totals"]
    lines = [
        "# BCC libbpf-tools Real End-to-End Benchmark",
        "",
        f"- Generated: `{payload['generated_at']}`",
        f"- Mode: `{'smoke' if payload['smoke'] else 'full'}`",
        f"- Duration per phase: `{payload['duration_s']}s`",
        f"- Host kernel: `{payload['host']['kernel']}`",
        f"- Tools dir: `{payload['tools_dir']}`",
        f"- Setup rc: `{payload['setup']['returncode']}`",
        f"- Daemon: `{payload['daemon']}`",
        "",
        "## Summary",
        "",
        f"- Tools selected: `{len(payload['selected_tools'])}`",
        f"- Baseline successes: `{payload['summary']['baseline_successes']}`",
        f"- ReJIT successes: `{payload['summary']['rejit_successes']}`",
        f"- Tools with applied sites: `{payload['summary']['tools_with_sites']}`",
        f"- Aggregate applied sites: `{site_totals['total_sites']}` ({format_site_breakdown(site_totals)})",
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
        "- Tools that fail to attach or have no applicable ReJIT passes show `n/a` ReJIT columns.",
        "",
    ])
    return "\n".join(lines)


def build_report(payload: Mapping[str, object]) -> str:
    site_totals = payload["summary"]["site_totals"]
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
        f"- Tools with applied sites: `{payload['summary']['tools_with_sites']}`; "
        f"aggregate applied site count: `{site_totals['total_sites']}` ({format_site_breakdown(site_totals)}).",
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
        "- Tools with zero applied sites are still measured for baseline overhead but "
        "their ReJIT columns remain `n/a`.",
        "",
    ])
    return "\n".join(lines)


def run_bcc_case(args: argparse.Namespace) -> dict[str, object]:
    daemon_binary = Path(args.daemon).resolve()
    if not daemon_binary.exists():
        raise RuntimeError(f"bpfrejit-daemon not found: {daemon_binary}")
    prepared_daemon_session = getattr(args, "_prepared_daemon_session", None)
    if prepared_daemon_session is None:
        raise RuntimeError("prepared daemon session is required")

    setup_result = {
        "returncode": 0,
        "tools_dir": None,
        "stdout_tail": "",
        "stderr_tail": "",
    }
    setup_script = Path(getattr(args, "setup_script", DEFAULT_SETUP_SCRIPT)).resolve()
    setup_result = run_setup_script(setup_script)

    config_path = Path(getattr(args, "config", DEFAULT_CONFIG)).resolve()
    suite = load_config(config_path)
    tools_dir = resolve_tools_dir(getattr(args, "tools_dir", None) or "", setup_result=setup_result)

    # Duration resolution: CLI > smoke flag > config
    smoke = bool(args.smoke)
    smoke_duration_s = int(getattr(args, "smoke_duration", 0) or 0)
    duration_override = int(getattr(args, "duration", 0) or 0)
    if smoke_duration_s and smoke:
        duration_s = smoke_duration_s
    elif duration_override:
        duration_s = duration_override
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
        wanted = {name.strip() for name in getattr(args, "tools", []) if name and name.strip()}
        selected = [t for t in suite.tools if t.name in wanted]
    else:
        selected = list(suite.tools)

    if not selected:
        raise RuntimeError("no tools selected")

    records: list[dict[str, object]] = []
    default_requested_passes = [str(pass_name) for pass_name in benchmark_rejit_enabled_passes()]
    with enable_bpf_stats():
        for spec in selected:
            tool_binary = find_tool_binary(tools_dir, spec.name)
            if tool_binary is None:
                record: dict[str, object] = {
                    "name": spec.name,
                    "description": spec.description,
                    "tool_args": list(spec.tool_args),
                    "tool_binary": None,
                    "baseline": {
                        "phase": "baseline",
                        "status": "error",
                        "reason": f"binary '{spec.name}' not found in {tools_dir}",
                        "programs": [],
                        "prog_ids": [],
                        "scan_results": {},
                        "site_totals": zero_site_totals(BCC_SITE_TOTAL_FIELDS),
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
                        "baseline_status": "error",
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
                enabled_passes=None,
                policy_context={
                    "repo": "bcc",
                    "category": "bcc",
                    "level": "e2e",
                },
                prepared_daemon_session=prepared_daemon_session,
            )
            selected_passes = collect_effective_enabled_passes({"rejit": rejit})
            if not selected_passes:
                selected_passes = list(default_requested_passes)
            summary = summarize_tool(spec, baseline, rejit)
            record = {
                "name": spec.name,
                "description": spec.description,
                "tool_args": list(spec.tool_args),
                "tool_binary": str(tool_binary),
                "baseline": baseline,
                "rejit": rejit,
                "summary": summary,
            }
            records.append(record)

    # Aggregate
    site_totals = applied_site_totals_from_rejit_result(None)
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
        counts = sm.get("site_totals") or {}
        for field in site_totals:
            site_totals[field] += int(counts.get(field, 0) or 0)
        speedup = sm.get("speedup")
        if isinstance(speedup, (int, float)) and float(speedup) > 0:
            speedups.append(float(speedup))

    errors = collect_record_errors(records)
    selected_rejit_passes = collect_effective_enabled_passes(records)
    if not selected_rejit_passes:
        selected_rejit_passes = list(default_requested_passes)

    payload = {
        "generated_at": datetime.now(timezone.utc).isoformat(),
        "status": "error" if errors else "ok",
        "smoke": smoke,
        "duration_s": duration_s,
        "selected_rejit_passes": selected_rejit_passes,
        "selected_tools": [spec.name for spec in selected],
        "tools_dir": str(tools_dir),
        "daemon": str(daemon_binary),
        "setup": dict(setup_result),
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
    if selected_rejit_passes != default_requested_passes:
        payload["requested_rejit_passes"] = list(default_requested_passes)
    if errors:
        payload["error_message"] = "; ".join(errors)
    return payload
