from __future__ import annotations

import argparse
import re
import statistics
import sys
from dataclasses import replace
from datetime import datetime, timezone
from pathlib import Path
from typing import Mapping, Sequence

if __package__ in {None, ""}:
    sys.path.insert(0, str(Path(__file__).resolve().parents[3]))

from runner.libs import (  # noqa: E402
    RESULTS_DIR,
    ROOT_DIR,
    run_command,
    tail_text,
    which,
)
from runner.libs.app_runners.bpftrace import BpftraceRunner, SCRIPTS, ScriptSpec  # noqa: E402
from runner.libs.bpf_stats import (  # noqa: E402
    enable_bpf_stats,
)
from runner.libs.rejit import applied_site_totals_from_rejit_result  # noqa: E402
from runner.libs.case_common import (  # noqa: E402
    measure_app_runner_workload,
    host_metadata,
    percent_delta,
    run_app_runner_phase_records,
)


DEFAULT_SCRIPT_DIR = Path(__file__).with_name("scripts")
DEFAULT_OUTPUT_JSON = RESULTS_DIR / "bpftrace.json"
DEFAULT_OUTPUT_MD = ROOT_DIR / "e2e" / "results" / "bpftrace-real-e2e.md"
DEFAULT_REPORT_MD = ROOT_DIR / "e2e" / "results" / "bpftrace-real-e2e-report.md"
DEFAULT_DURATION_S = 30
MIN_BPFTRACE_VERSION = (0, 16, 0)


def parse_version(text: str) -> tuple[int, int, int] | None:
    match = re.search(r"(\d+)\.(\d+)(?:\.(\d+))?", text)
    if not match:
        return None
    major, minor, patch = match.groups()
    return int(major), int(minor), int(patch or 0)


def version_at_least(version: tuple[int, int, int] | None, minimum: tuple[int, int, int]) -> bool:
    return version is not None and version >= minimum


def ensure_artifacts(daemon_binary: Path) -> None:
    if not daemon_binary.exists():
        raise RuntimeError(f"bpfrejit-daemon not found: {daemon_binary}")


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
    workload_overrides = getattr(args, "_suite_workload_overrides", {}) or {}
    if args.smoke:
        selected = [next(spec for spec in SCRIPTS if spec.name == "capable")]
    elif not getattr(args, "scripts", None):
        selected = list(SCRIPTS)
    else:
        wanted = {name.strip() for name in getattr(args, "scripts", []) if name and name.strip()}
        selected = [spec for spec in SCRIPTS if spec.name in wanted]
    return [
        replace(spec, workload_spec={"kind": str(workload_overrides.get(spec.name) or (spec.workload_spec or {}).get("kind") or "")})
        for spec in selected
    ]


BPFTRACE_SITE_TOTAL_FIELDS = (
    "total_sites",
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
    spec: ScriptSpec,
    *,
    duration_s: int,
    attach_timeout: int,
    prepared_daemon_session: object,
) -> tuple[dict[str, object], dict[str, object] | None]:
    """Run baseline then daemon-apply then rejit measurement for one bpftrace script.

    Returns (baseline, rejit) where rejit is None only when ReJIT was not applicable.
    """
    bpftrace_runner = BpftraceRunner(
        script_path=spec.script_path,
        script_name=spec.name,
        workload_spec=spec.workload_spec,
        attach_timeout_s=attach_timeout,
    )
    def workload(lifecycle: object, _phase_name: str) -> dict[str, object]:
        prog_ids = [int(value) for value in (getattr(lifecycle, "prog_ids", []) or []) if int(value) > 0]
        if not prog_ids:
            return {"status": "error", "reason": "no BPF programs are attached", "measurement": None}
        return {
            "status": "ok",
            "reason": "",
            "measurement": measure_app_runner_workload(
                bpftrace_runner,
                duration_s,
                prog_ids,
                agent_pid=int(bpftrace_runner.pid or 0),
            ),
        }

    if prepared_daemon_session is None:
        raise RuntimeError("prepared daemon session is required")
    return run_app_runner_phase_records(
        runner=bpftrace_runner,
        prepared_daemon_session=prepared_daemon_session,
        measure=workload,
        site_totals_fields=BPFTRACE_SITE_TOTAL_FIELDS,
    )


def summarize_script(spec: ScriptSpec, baseline: Mapping[str, object], rejit: Mapping[str, object] | None) -> dict[str, object]:
    baseline_measurement = baseline.get("measurement") or {}
    rejit_measurement = (rejit or {}).get("measurement") or {}
    stock_avg_ns = ((baseline_measurement.get("bpf") or {}).get("summary", {}) or {}).get("avg_ns_per_run")
    rejit_avg_ns = ((rejit_measurement.get("bpf") or {}).get("summary", {}) or {}).get("avg_ns_per_run")
    workload_ops_baseline = ((baseline_measurement.get("workload") or {}).get("ops_per_sec"))
    workload_ops_rejit = ((rejit_measurement.get("workload") or {}).get("ops_per_sec"))
    cpu_baseline = ((baseline_measurement.get("agent_cpu") or {}).get("total_pct"))
    cpu_rejit = ((rejit_measurement.get("agent_cpu") or {}).get("total_pct"))
    site_totals = applied_site_totals_from_rejit_result((rejit or {}).get("rejit_result"))
    sites = int(site_totals.get("total_sites", 0) or 0)
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
        f"- Daemon: `{payload['daemon']}`",
        "",
        "## Summary",
        "",
        f"- Scripts selected: `{len(payload['selected_scripts'])}`",
        f"- Baseline successes: `{payload['summary']['baseline_successes']}`",
        f"- ReJIT successes: `{payload['summary']['rejit_successes']}`",
        f"- Scripts with applied sites: `{payload['summary']['scripts_with_sites']}`",
        f"- Aggregate applied sites: `{payload['summary']['site_totals']['total_sites']}` "
        f"({format_site_breakdown(payload['summary']['site_totals'])})",
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
            "- Scripts that fail to attach or have no applicable ReJIT passes are marked with `n/a` ReJIT fields instead of a fake comparison.",
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
        f"- Scripts with applied sites: `{payload['summary']['scripts_with_sites']}`; aggregate applied site count: `{payload['summary']['site_totals']['total_sites']}` ({format_site_breakdown(payload['summary']['site_totals'])}).",
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
            f"- Scripts improved after applied ReJIT: {improved or ['none']}; regressed: {regressed or ['none']}. The overall geomean across scripts with stock+ReJIT data is `{format_ratio(payload['summary']['speedup_geomean'])}`.",
            "- Scripts with zero applied sites were still measured for the baseline end-to-end overhead, but their ReJIT columns remain `n/a` to avoid implying a meaningless comparison.",
            "",
        ]
    )
    return "\n".join(lines)


def run_bpftrace_case(args: argparse.Namespace) -> dict[str, object]:
    prepared_daemon_session = getattr(args, "_prepared_daemon_session", None)
    if prepared_daemon_session is None:
        raise RuntimeError("prepared daemon session is required")

    daemon_binary = Path(args.daemon).resolve()
    ensure_artifacts(daemon_binary)
    tool_versions = ensure_required_tools()

    scripts = selected_scripts(args)
    if not scripts:
        raise RuntimeError("no scripts selected")

    duration_override = int(getattr(args, "duration", 0) or 0)
    duration_s = int(5 if args.smoke else (duration_override or DEFAULT_DURATION_S))
    attach_timeout_s = 20
    records: list[dict[str, object]] = []
    with enable_bpf_stats():
        for spec in scripts:
            baseline, rejit = run_phase(
                spec,
                duration_s=duration_s,
                attach_timeout=attach_timeout_s,
                prepared_daemon_session=prepared_daemon_session,
            )
            summary = summarize_script(spec, baseline, rejit)
            records.append(
                {
                    "name": spec.name,
                    "script_path": str(spec.script_path),
                    "script_text": spec.script_path.read_text(),
                    "baseline": baseline,
                    "rejit": rejit,
                    "summary": summary,
                }
            )

    site_totals = applied_site_totals_from_rejit_result(None)
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
        counts = summary.get("site_totals") or {}
        for field in site_totals:
            site_totals[field] += int(counts.get(field, 0) or 0)
        speedup = summary.get("speedup")
        if isinstance(speedup, (int, float)) and float(speedup) > 0:
            speedups.append(float(speedup))

    errors = collect_record_errors(records)

    payload = {
        "generated_at": datetime.now(timezone.utc).isoformat(),
        "status": "error" if errors else "ok",
        "smoke": bool(args.smoke),
        "duration_s": duration_s,
        "selected_scripts": [spec.name for spec in scripts],
        "daemon": str(daemon_binary),
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
    if errors:
        payload["error_message"] = "; ".join(errors)
    return payload
