#!/usr/bin/env python3
"""Parse raw workload stdout/stderr from corpus per-app result JSONs.

The benchmark framework stores every workload's verbatim stdout/stderr without
parsing. This script is the offline parser: walks `details/apps/<app>.json`
files, dispatches by `workload_name` (and falls back to detecting
`config.tool`), and emits a normalized record per workload sample.

Output: JSON list, one entry per sample with raw fields exposed per tool. No
ratios, geomeans, or comparisons — that lives in `corpus_analyze.py` for BPF
data and in the user's own follow-up scripts for app-throughput delta.

Usage:
    python analysis/extract_workload_metrics.py <result_dir>
    python analysis/extract_workload_metrics.py <result_dir> --app katran
    python analysis/extract_workload_metrics.py <result_dir> --tool wrk
"""
from __future__ import annotations

import argparse
import json
import re
import sys
from pathlib import Path
from typing import Any, Mapping, Sequence


_FLOAT = r"[-+]?(?:\d+(?:\.\d*)?|\.\d+)(?:[eE][-+]?\d+)?"


def _scaled_number(value: str) -> float:
    """wrk uses k/M/G suffixes for Req/Sec; convert to plain count."""
    text = str(value or "").strip()
    m = re.fullmatch(rf"({_FLOAT})([kKmMgG]?)", text)
    if not m:
        return float("nan")
    n = float(m.group(1))
    return n * {"": 1.0, "k": 1e3, "m": 1e6, "g": 1e9}[m.group(2).lower()]


def _wrk_latency_ms(value: str) -> float:
    text = str(value or "").strip()
    m = re.fullmatch(rf"({_FLOAT})(us|ms|s)", text)
    if not m:
        return float("nan")
    n = float(m.group(1))
    return {"us": n / 1000.0, "ms": n, "s": n * 1000.0}[m.group(2)]


def _wrk_bytes(value: str) -> float:
    text = str(value or "").strip()
    m = re.fullmatch(rf"({_FLOAT})([KMG]?i?B|B)", text)
    if not m:
        return float("nan")
    n = float(m.group(1))
    scale = {"B": 1.0, "KB": 1024.0, "KiB": 1024.0,
             "MB": 1024.0**2, "MiB": 1024.0**2,
             "GB": 1024.0**3, "GiB": 1024.0**3}
    return n * scale[m.group(2)]


def parse_wrk(stdout: str) -> dict[str, Any]:
    """Extract metrics from wrk's text report.

    Wrk emits lines like:
        Latency     1.23ms   456us   12.3ms   90.12%
        Latency Distribution
           50%    1.20ms
           99%    3.40ms
        12345 requests in 5.00s, 1.23MB read
        Requests/sec:   2469.00
        Transfer/sec:    251.49KB
        Socket errors: connect 0, read 0, write 0, timeout 0
    """
    metrics: dict[str, Any] = {}
    latency_ms: dict[str, float] = {}
    in_lat_dist = False
    for line in stdout.splitlines():
        s = line.strip()
        if s == "Latency Distribution":
            in_lat_dist = True
            continue
        if s.startswith("Latency "):
            parts = s.split()
            if len(parts) >= 4:
                latency_ms["avg"] = _wrk_latency_ms(parts[1])
                latency_ms["stdev"] = _wrk_latency_ms(parts[2])
                latency_ms["max"] = _wrk_latency_ms(parts[3])
            continue
        if s.startswith("Req/Sec"):
            parts = s.split()
            if len(parts) >= 4:
                metrics["req_per_sec_thread"] = {
                    "avg": _scaled_number(parts[1]),
                    "stdev": _scaled_number(parts[2]),
                    "max": _scaled_number(parts[3]),
                }
            continue
        if in_lat_dist:
            m = re.match(rf"(50|75|90|99)%\s+(\S+)", s)
            if m:
                latency_ms[f"p{m.group(1)}"] = _wrk_latency_ms(m.group(2))
                continue
            if s and not re.match(rf"\d+%", s):
                in_lat_dist = False
        m = re.search(rf"([0-9]+)\s+requests in\s+\S+,\s+(\S+)\s+read", s)
        if m:
            metrics["request_count"] = int(m.group(1))
            metrics["bytes_total"] = _wrk_bytes(m.group(2))
            continue
        m = re.match(rf"Requests/sec:\s+(\S+)", s)
        if m:
            metrics["requests_per_sec"] = _scaled_number(m.group(1))
            continue
        m = re.match(rf"Transfer/sec:\s+(\S+)", s)
        if m:
            metrics["bytes_per_sec"] = _wrk_bytes(m.group(1))
            continue
        if s.startswith("Socket errors:"):
            errors = {}
            for k, v in re.findall(rf"(connect|read|write|timeout)\s+([0-9]+)", s):
                errors[k] = int(v)
            metrics["socket_errors"] = errors
    if latency_ms:
        metrics["latency_ms"] = latency_ms
    return metrics


def parse_stress_ng(stdout: str, stderr: str) -> dict[str, Any]:
    """Extract per-stressor bogo-ops from stress-ng --metrics-brief output.

    Lines look like:
        stress-ng: metrc: [PID] stressor   bogo-ops  real-time  usr-time  sys-time  bogo-ops/s(real)  bogo-ops/s(usr+sys)
    """
    text = (stdout or "") + "\n" + (stderr or "")
    pattern = re.compile(
        rf"stress-ng:\s+metrc:\s+\[\d+\]\s+(\S+)\s+"
        rf"({_FLOAT})\s+({_FLOAT})\s+({_FLOAT})\s+({_FLOAT})\s+"
        rf"({_FLOAT})\s+({_FLOAT})\b"
    )
    rows: list[dict[str, Any]] = []
    bogo_ops_total = 0.0
    for line in text.splitlines():
        if "stress-ng: metrc:" not in line:
            continue
        m = pattern.search(line)
        if not m:
            continue
        stressor, bogo_ops, real_t, usr_t, sys_t, ops_real, ops_usrsys = m.groups()
        rows.append({
            "stressor": stressor,
            "bogo_ops": float(bogo_ops),
            "real_time_s": float(real_t),
            "usr_time_s": float(usr_t),
            "sys_time_s": float(sys_t),
            "bogo_ops_per_sec_real_time": float(ops_real),
            "bogo_ops_per_sec_usr_sys_time": float(ops_usrsys),
        })
        bogo_ops_total += float(bogo_ops)
    return {"per_stressor": rows, "bogo_ops_total": bogo_ops_total}


def parse_fio(stdout: str) -> dict[str, Any]:
    """fio --output-format=json: top-level dict with .jobs[].read/write."""
    try:
        payload = json.loads(stdout)
    except json.JSONDecodeError:
        return {}
    if not isinstance(payload, Mapping):
        return {}
    jobs = payload.get("jobs") or []
    if not isinstance(jobs, list):
        return {}
    total_ios = 0.0
    total_bw_bytes_per_sec = 0.0
    per_job: list[dict[str, Any]] = []
    for j in jobs:
        if not isinstance(j, Mapping):
            continue
        read = j.get("read") or {}
        write = j.get("write") or {}
        if isinstance(read, Mapping) and isinstance(write, Mapping):
            r_ios = float(read.get("total_ios", 0) or 0)
            w_ios = float(write.get("total_ios", 0) or 0)
            r_bw = float(read.get("bw_bytes", 0) or 0)
            w_bw = float(write.get("bw_bytes", 0) or 0)
            total_ios += r_ios + w_ios
            total_bw_bytes_per_sec += r_bw + w_bw
            per_job.append({
                "jobname": j.get("jobname"),
                "read_total_ios": r_ios,
                "write_total_ios": w_ios,
                "read_bw_bytes_per_sec": r_bw,
                "write_bw_bytes_per_sec": w_bw,
            })
    return {"per_job": per_job, "total_ios": total_ios,
            "bw_bytes_per_sec": total_bw_bytes_per_sec}


def parse_katran_parallel_http(stdout: str) -> dict[str, Any]:
    """Katran parallel HTTP client emits a single JSON line at end of stdout."""
    last_brace = stdout.rfind("{")
    if last_brace < 0:
        return {}
    try:
        payload = json.loads(stdout[last_brace:])
    except json.JSONDecodeError:
        return {}
    if not isinstance(payload, Mapping):
        return {}
    out = {k: payload.get(k) for k in (
        "request_count", "success_count", "error_count",
        "duration_s", "bytes_total", "concurrency",
    )}
    lat = payload.get("latencies_ms") or []
    if isinstance(lat, list) and lat:
        ordered = sorted(float(x) for x in lat)
        n = len(ordered)
        out["latency_ms"] = {
            "count": n,
            "min": ordered[0],
            "max": ordered[-1],
            "p50": ordered[max(0, int(0.50 * (n - 1)))],
            "p90": ordered[max(0, int(0.90 * (n - 1)))],
            "p99": ordered[max(0, int(0.99 * (n - 1)))],
        }
    if out.get("duration_s") and out.get("success_count") is not None:
        try:
            out["ops_per_sec"] = float(out["success_count"]) / float(out["duration_s"])
        except (TypeError, ValueError, ZeroDivisionError):
            pass
    return out


# Maps workload_name (or config.tool) to parser. Preference order: workload_name first.
TOOL_PARSERS = {
    "wrk": lambda r: parse_wrk(r.get("stdout", "")),
    "stress-ng": lambda r: parse_stress_ng(r.get("stdout", ""), r.get("stderr", "")),
    "fio": lambda r: parse_fio(r.get("stdout", "")),
    "python_parallel": lambda r: parse_katran_parallel_http(r.get("stdout", "")),
    "python-udp-client": lambda r: {},  # raw stdout; analysis tbd
}


def parse_workload(record: Mapping[str, Any]) -> dict[str, Any]:
    """Dispatch by config.tool first, fall back to workload_name."""
    config = record.get("config") or {}
    tool = ""
    if isinstance(config, Mapping):
        tool = str(config.get("tool") or "").strip()
    name = str(record.get("workload_name") or "").strip()
    parser = TOOL_PARSERS.get(tool)
    if parser is None:
        # Light fallback: stress_ng_* workloads always use stress-ng
        if name.startswith("stress_ng_"):
            parser = TOOL_PARSERS["stress-ng"]
        elif "wrk" in name or name in {"xdp_traffic", "tcp_connect"} or name.startswith("network_"):
            parser = TOOL_PARSERS["wrk"]
        elif name == "katran_parallel_http":
            parser = TOOL_PARSERS["python_parallel"]
        elif name == "file_io":
            parser = TOOL_PARSERS["fio"]
    metrics = parser(record) if parser else {}
    out = {
        "workload_name": name,
        "duration_s": record.get("duration_s"),
        "returncode": record.get("returncode"),
        "tool": tool,
        "metrics": metrics,
    }
    if record.get("components"):
        out["components"] = [parse_workload(c) for c in record["components"]]
    return out


def walk_app_json(app_payload: Mapping[str, Any], app_name: str) -> list[dict[str, Any]]:
    """Per-app json contains baseline.workloads[] and post_rejit.workloads[] arrays."""
    out: list[dict[str, Any]] = []
    for phase in ("baseline", "post_rejit"):
        phase_data = app_payload.get(phase) or {}
        if not isinstance(phase_data, Mapping):
            continue
        for idx, w in enumerate(phase_data.get("workloads") or []):
            if not isinstance(w, Mapping):
                continue
            parsed = parse_workload(w)
            parsed["app"] = app_name
            parsed["phase"] = phase
            parsed["sample_index"] = idx
            out.append(parsed)
    return out


def collect_corpus_run(run_dir: Path, app_filter: str | None = None,
                      tool_filter: str | None = None) -> list[dict[str, Any]]:
    apps_dir = run_dir / "details" / "apps"
    if not apps_dir.is_dir():
        raise FileNotFoundError(f"{apps_dir} not found")
    out: list[dict[str, Any]] = []
    for app_path in sorted(apps_dir.glob("*.json")):
        app_name = app_path.stem.replace("__", "/")
        if app_filter and app_name != app_filter and app_path.stem != app_filter:
            continue
        try:
            payload = json.loads(app_path.read_text())
        except (OSError, json.JSONDecodeError):
            continue
        if not isinstance(payload, Mapping):
            continue
        if payload.get("status") != "ok":
            continue
        out.extend(walk_app_json(payload, app_name))
    if tool_filter:
        out = [r for r in out if r.get("tool") == tool_filter
               or r.get("workload_name") == tool_filter]
    return out


def main(argv: Sequence[str] | None = None) -> int:
    p = argparse.ArgumentParser()
    p.add_argument("run_dir", type=Path,
                   help="corpus result run directory (contains details/apps/)")
    p.add_argument("--app", default=None, help="filter to a single app (e.g. katran)")
    p.add_argument("--tool", default=None, help="filter by workload tool/name (e.g. wrk)")
    p.add_argument("--summary", action="store_true",
                   help="print one row per (app, phase) instead of per-sample")
    args = p.parse_args(argv)

    rows = collect_corpus_run(args.run_dir, app_filter=args.app, tool_filter=args.tool)
    if not args.summary:
        json.dump(rows, sys.stdout, indent=2, default=str)
        sys.stdout.write("\n")
        return 0

    # Aggregate per (app, phase)
    from collections import defaultdict
    grouped: dict[tuple[str, str], list[dict[str, Any]]] = defaultdict(list)
    for r in rows:
        grouped[(r["app"], r["phase"])].append(r)
    summary = []
    for (app, phase), items in sorted(grouped.items()):
        durations = [float(i["duration_s"]) for i in items if i.get("duration_s") is not None]
        summary.append({
            "app": app, "phase": phase, "samples": len(items),
            "tool_set": sorted({i.get("tool") or i.get("workload_name") for i in items}),
            "duration_s_total": sum(durations),
            "metrics_per_sample": [i["metrics"] for i in items],
        })
    json.dump(summary, sys.stdout, indent=2, default=str)
    sys.stdout.write("\n")
    return 0


if __name__ == "__main__":
    sys.exit(main())
