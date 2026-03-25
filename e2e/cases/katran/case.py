#!/usr/bin/env python3
from __future__ import annotations

import argparse
import ctypes
import ctypes.util
import errno
import json
import os
import re
import shutil
import socket
import struct
import subprocess
import sys
import tempfile
import threading
import time
from dataclasses import dataclass
from datetime import datetime, timezone
from pathlib import Path
from typing import Mapping, Sequence

if __package__ in {None, ""}:
    sys.path.insert(0, str(Path(__file__).resolve().parents[3]))

from runner.libs import (  # noqa: E402
    RESULTS_DIR,
    ROOT_DIR,
    authoritative_output_path,
    resolve_bpftool_binary,
    run_command,
    run_json_command,
    smoke_output_path,
    tail_text,
    which,
)
from runner.libs.corpus import materialize_katran_packet  # noqa: E402
from runner.libs.metrics import compute_delta, enable_bpf_stats, sample_bpf_stats, sample_total_cpu_usage  # noqa: E402
from runner.libs.rejit import apply_daemon_rejit, scan_programs  # noqa: E402

from e2e.case_common import (  # noqa: E402
    git_sha,
    host_metadata,
    relpath,
    summarize_numbers,
    percent_delta,
    percentile,
    speedup_ratio,
    persist_results,
)

try:  # noqa: E402
    from runner.libs.inventory import discover_object_programs
except ModuleNotFoundError:  # noqa: E402
    sys.path.insert(0, str(ROOT_DIR / "micro"))
    from runner.libs.inventory import discover_object_programs


DEFAULT_SETUP_SCRIPT = Path(__file__).with_name("setup.sh")
DEFAULT_OUTPUT_JSON = authoritative_output_path(RESULTS_DIR, "katran")
DEFAULT_OUTPUT_MD = ROOT_DIR / "e2e" / "results" / "katran-e2e-real.md"
DEFAULT_KATRAN_OBJECT = ROOT_DIR / "corpus" / "build" / "katran" / "balancer.bpf.o"
DEFAULT_RUNNER = ROOT_DIR / "runner" / "build" / "micro_exec"
DEFAULT_DAEMON = ROOT_DIR / "daemon" / "target" / "release" / "bpfrejit-daemon"
DEFAULT_KATRAN_TEST_PACKET = ROOT_DIR / "corpus" / "inputs" / "katran_vip_packet_64.bin"
DEFAULT_KERNEL_CONFIG = ROOT_DIR / "vendor" / "linux-framework" / ".config"
DEFAULT_PROGRAM_NAME = "balancer_ingress"
DEFAULT_INTERFACE = "katran0"
DEFAULT_IP_CANDIDATES = (
    "/usr/local/sbin/ip",
    "/usr/local/bin/ip",
    "/usr/sbin/ip",
    "/usr/bin/ip",
    "/sbin/ip",
    "/bin/ip",
)
DEFAULT_DURATION_S = 10
DEFAULT_SMOKE_DURATION_S = 3
DEFAULT_WRK_CONNECTIONS = 32
DEFAULT_SMOKE_WRK_CONNECTIONS = 8
DEFAULT_WRK_THREADS = 1
DEFAULT_SMOKE_WRK_THREADS = 1
DEFAULT_PACKET_REPEAT = 4
DEFAULT_SMOKE_PACKET_REPEAT = 2
DEFAULT_SAMPLE_COUNT = 3
DEFAULT_SMOKE_SAMPLE_COUNT = 1
DEFAULT_WARMUP_DURATION_S = 2
DEFAULT_SMOKE_WARMUP_DURATION_S = 1
DEFAULT_WARMUP_PACKET_COUNT = 100
DEFAULT_SMOKE_WARMUP_PACKET_COUNT = 100
DEFAULT_MIN_MEASUREMENT_REQUESTS = 1000
DEFAULT_SMOKE_MIN_MEASUREMENT_REQUESTS = 100
REQUEST_FAILURE_PREVIEW_LIMIT = 5
WARMUP_MAX_ATTEMPT_FACTOR = 3
WRK_OUTPUT_PREVIEW_LINES = 40
WRK_SOCKET_ERRORS_RE = re.compile(
    r"Socket errors:\s*connect\s+(\d+),\s*read\s+(\d+),\s*write\s+(\d+),\s*timeout\s+(\d+)",
    re.IGNORECASE,
)
WRK_REQUESTS_RE = re.compile(r"(\d+)\s+requests in\s+([0-9.]+)([a-zA-Z]+)", re.IGNORECASE)
WRK_REQUESTS_PER_SEC_RE = re.compile(r"Requests/sec:\s*([0-9.]+)", re.IGNORECASE)
WRK_TRANSFER_PER_SEC_RE = re.compile(r"Transfer/sec:\s*([0-9.]+[A-Za-z/]+)", re.IGNORECASE)
WRK_NON_2XX_RE = re.compile(r"Non-2xx or 3xx responses:\s*(\d+)", re.IGNORECASE)
WRK_LATENCY_AVG_RE = re.compile(
    r"Latency\s+([0-9.]+(?:us|ms|s))\s+([0-9.]+(?:us|ms|s))\s+([0-9.]+(?:us|ms|s))",
    re.IGNORECASE,
)
WRK_LATENCY_DIST_RE = re.compile(r"(50|75|90|99)%\s+([0-9.]+(?:us|ms|s))", re.IGNORECASE)

TCP_PROTO = socket.IPPROTO_TCP
XDP_PASS = 2
XDP_TX = 3
F_LRU_BYPASS = 1 << 1
CH_RING_SIZE = 65537
VIP_NUM = 0
REAL_NUM = 1

ROUTER_NS = "katran-router"
CLIENT_NS = "katran-client"
REAL_NS = "katran-real"
ROUTER_LB_IFACE = "rtlb0"
ROUTER_CLIENT_IFACE = "rtcl0"
CLIENT_IFACE = "client0"
ROUTER_REAL_IFACE = "rtreal0"
REAL_IFACE = "real0"

LB_IP = "192.0.2.2"
ROUTER_LB_IP = "192.0.2.1"
CLIENT_IP = "10.0.0.2"
ROUTER_CLIENT_IP = "10.0.0.1"
REAL_IP = "10.200.0.2"
ROUTER_REAL_IP = "10.200.0.1"
VIP_IP = "10.100.1.1"
VIP_PORT = 8080
IPIP_DUMMY_IP = "127.0.0.42"

LB_MAC = "02:00:00:00:00:0a"
ROUTER_LB_MAC = "02:00:00:00:00:0b"
ROUTER_CLIENT_MAC = "02:00:00:00:00:1b"
CLIENT_MAC = "02:00:00:00:00:1c"
ROUTER_REAL_MAC = "02:00:00:00:00:2b"
REAL_MAC = "02:00:00:00:00:2c"

HTTP_RESPONSE_SNIPPET = 200
HTTP_TIMEOUT_S = 5.0
SERVER_START_TIMEOUT_S = 15.0
TOPOLOGY_SETTLE_S = 2.0

HTTP_PAYLOAD = b"GET / HTTP/1.0\r\nHost: katran\r\nConnection: close\r\n\r\n"

STATE_RESET_MAPS = (
    "fallback_cache",
    "reals_stats",
    "lru_miss_stats",
    "vip_miss_stats",
    "stats",
    "quic_stats_map",
    "stable_rt_stats",
    "decap_vip_stats",
    "tpr_stats_map",
    "server_id_stats",
    "vip_to_down_reals_map",
)

PERCPU_MAP_TYPES = {
    "percpu_array",
    "percpu_hash",
    "lru_percpu_hash",
}

ARRAY_MAP_TYPES = {
    "array",
    "percpu_array",
}

HASH_LIKE_MAP_TYPES = {
    "hash",
    "lru_hash",
    "percpu_hash",
    "lru_percpu_hash",
    "lpm_trie",
    "hash_of_maps",
}


@dataclass(frozen=True, slots=True)
class PhaseSample:
    index: int
    phase: str
    driver: str
    measurement_duration_s: float
    measurement_batches: int
    warmup_request_count: int
    warmup_duration_s: float
    request_latencies_ms: list[float]
    request_failure_preview: list[dict[str, object]]
    request_summary: dict[str, object]
    http_request_count: int
    http_success_count: int
    ipip_rx_packets_delta: int
    ipip_rx_bytes_delta: int
    system_cpu: dict[str, object]
    bpf: dict[str, object]
    state_reset: dict[str, object]



def extract_request_latencies(sample: Mapping[str, object]) -> list[float]:
    latencies = sample.get("request_latencies_ms")
    if isinstance(latencies, list):
        return [float(value) for value in latencies if value is not None]
    extracted: list[float] = []
    for request in sample.get("requests") or []:
        if not isinstance(request, Mapping):
            continue
        latency = request.get("latency_ms")
        if latency is not None:
            extracted.append(float(latency))
    return extracted


def summarize_request_records(records: Sequence[Mapping[str, object]]) -> dict[str, object]:
    latencies: list[float] = []
    failures: list[dict[str, object]] = []
    success_count = 0
    for record in records:
        if bool(record.get("ok")):
            success_count += 1
        latency = record.get("latency_ms")
        if latency is not None:
            latencies.append(float(latency))
        if len(failures) >= REQUEST_FAILURE_PREVIEW_LIMIT:
            continue
        if bool(record.get("ok")) and not record.get("error"):
            continue
        failures.append(
            {
                "index": int(record.get("index", -1) or -1),
                "error": str(record.get("error") or ""),
                "snippet": str(record.get("snippet") or "")[:200],
            }
        )
    return {
        "request_count": len(records),
        "success_count": success_count,
        "ops_per_sec": None,
        "latency_ms": {
            **summarize_numbers(latencies),
            "p50": percentile(latencies, 50.0),
            "p90": percentile(latencies, 90.0),
            "p99": percentile(latencies, 99.0),
        },
        "latencies_ms": latencies,
        "failure_preview": failures,
    }


def wrk_binary() -> str | None:
    return which("wrk")


def parse_wrk_duration(value: str) -> float:
    text = value.strip().lower()
    if text.endswith("us"):
        return float(text[:-2]) / 1_000_000.0
    if text.endswith("ms"):
        return float(text[:-2]) / 1_000.0
    if text.endswith("s"):
        return float(text[:-1])
    raise ValueError(f"unsupported wrk duration token: {value}")


def parse_wrk_latency_ms(value: str) -> float:
    text = value.strip().lower()
    if text.endswith("us"):
        return float(text[:-2]) / 1000.0
    if text.endswith("ms"):
        return float(text[:-2])
    if text.endswith("s"):
        return float(text[:-1]) * 1000.0
    raise ValueError(f"unsupported wrk latency token: {value}")


def parse_wrk_output(stdout: str, stderr: str) -> dict[str, object]:
    requests = 0
    duration_s = 0.0
    match = WRK_REQUESTS_RE.search(stdout)
    if match:
        requests = int(match.group(1))
        duration_s = parse_wrk_duration(match.group(2) + match.group(3))

    requests_per_sec = None
    match = WRK_REQUESTS_PER_SEC_RE.search(stdout)
    if match:
        requests_per_sec = float(match.group(1))

    transfer_per_sec = None
    match = WRK_TRANSFER_PER_SEC_RE.search(stdout)
    if match:
        transfer_per_sec = match.group(1)

    latency: dict[str, float | None] = {
        "mean": None,
        "stdev": None,
        "max": None,
        "p50": None,
        "p75": None,
        "p90": None,
        "p99": None,
    }
    match = WRK_LATENCY_AVG_RE.search(stdout)
    if match:
        latency["mean"] = parse_wrk_latency_ms(match.group(1))
        latency["stdev"] = parse_wrk_latency_ms(match.group(2))
        latency["max"] = parse_wrk_latency_ms(match.group(3))
    for pct_match in WRK_LATENCY_DIST_RE.finditer(stdout):
        key = f"p{pct_match.group(1)}"
        latency[key] = parse_wrk_latency_ms(pct_match.group(2))

    socket_errors = {"connect": 0, "read": 0, "write": 0, "timeout": 0}
    match = WRK_SOCKET_ERRORS_RE.search(stdout)
    if match:
        socket_errors = {
            "connect": int(match.group(1)),
            "read": int(match.group(2)),
            "write": int(match.group(3)),
            "timeout": int(match.group(4)),
        }
    non2xx = 0
    match = WRK_NON_2XX_RE.search(stdout)
    if match:
        non2xx = int(match.group(1))

    total_failures = int(non2xx) + sum(socket_errors.values())
    success_count = max(0, requests - total_failures)
    failure_preview: list[dict[str, object]] = []
    if non2xx > 0:
        failure_preview.append({"kind": "non_2xx", "count": non2xx})
    if sum(socket_errors.values()) > 0:
        failure_preview.append({"kind": "socket_errors", **socket_errors})

    return {
        "driver": "wrk",
        "request_count": requests,
        "success_count": success_count,
        "ops_per_sec": requests_per_sec,
        "duration_s": duration_s,
        "latency_ms": latency,
        "socket_errors": socket_errors,
        "non_2xx": non2xx,
        "transfer_per_sec": transfer_per_sec,
        "failure_preview": failure_preview[:REQUEST_FAILURE_PREVIEW_LIMIT],
        "stdout_tail": tail_text(stdout, max_lines=WRK_OUTPUT_PREVIEW_LINES, max_chars=8000),
        "stderr_tail": tail_text(stderr, max_lines=WRK_OUTPUT_PREVIEW_LINES, max_chars=8000),
    }


def format_wrk_duration_arg(duration_s: int | float) -> str:
    value = max(1.0, float(duration_s))
    if value.is_integer():
        return f"{int(value)}s"
    return f"{str(value).rstrip('0').rstrip('.')}s"


def run_wrk(
    *,
    namespace: str,
    duration_s: int | float,
    connections: int,
    threads: int,
) -> dict[str, object]:
    binary = wrk_binary()
    if binary is None:
        raise RuntimeError("wrk is not installed")
    command = [
        "ip",
        "netns",
        "exec",
        namespace,
        binary,
        f"-t{max(1, int(threads))}",
        f"-c{max(1, int(connections))}",
        f"-d{format_wrk_duration_arg(duration_s)}",
        "--latency",
        "--timeout",
        format_wrk_duration_arg(HTTP_TIMEOUT_S),
        f"http://{VIP_IP}:{VIP_PORT}/",
    ]
    completed = run_command(
        command,
        check=False,
        timeout=max(30, int(float(duration_s) * 4) + 10),
    )
    parsed = parse_wrk_output(completed.stdout or "", completed.stderr or "")
    parsed["returncode"] = completed.returncode
    if completed.returncode != 0:
        detail = parsed.get("stderr_tail") or parsed.get("stdout_tail") or "wrk failed"
        raise RuntimeError(str(detail))
    return parsed


def build_phase_summary(samples: Sequence[Mapping[str, object]]) -> dict[str, object]:
    total_requests = sum(int(sample.get("http_request_count", 0) or 0) for sample in samples)
    total_successes = sum(int(sample.get("http_success_count", 0) or 0) for sample in samples)
    packet_pps = []
    event_rates = []
    for sample in samples:
        duration = float(sample.get("measurement_duration_s", 0.0) or 0.0)
        if duration > 0:
            packet_pps.append(float(sample.get("ipip_rx_packets_delta", 0) or 0) / duration)
            event_rates.append(
                float(((sample.get("bpf") or {}).get("summary", {}).get("total_events", 0) or 0)) / duration
            )
    return {
        "http_requests": total_requests,
        "http_successes": total_successes,
        "http_all_succeeded": total_requests > 0 and total_requests == total_successes,
        "app_throughput_rps": summarize_numbers(
            [((sample.get("request_summary") or {}).get("ops_per_sec")) for sample in samples]
        ),
        "latency_ms_p50": summarize_numbers(
            [(((sample.get("request_summary") or {}).get("latency_ms") or {}).get("p50")) for sample in samples]
        ),
        "latency_ms_p90": summarize_numbers(
            [(((sample.get("request_summary") or {}).get("latency_ms") or {}).get("p90")) for sample in samples]
        ),
        "latency_ms_p99": summarize_numbers(
            [(((sample.get("request_summary") or {}).get("latency_ms") or {}).get("p99")) for sample in samples]
        ),
        "latency_ms_mean": summarize_numbers(
            [(((sample.get("request_summary") or {}).get("latency_ms") or {}).get("mean")) for sample in samples]
        ),
        "measurement_duration_s": summarize_numbers([sample.get("measurement_duration_s") for sample in samples]),
        "measurement_batches": summarize_numbers([sample.get("measurement_batches") for sample in samples]),
        "warmup_http_requests": summarize_numbers([sample.get("warmup_request_count") for sample in samples]),
        "warmup_duration_s": summarize_numbers([sample.get("warmup_duration_s") for sample in samples]),
        "ipip_rx_packets_delta": summarize_numbers(
            [sample.get("ipip_rx_packets_delta") for sample in samples]
        ),
        "packet_pps": summarize_numbers(packet_pps),
        "bpf_avg_ns_per_run": summarize_numbers(
            [((sample.get("bpf") or {}).get("summary", {}).get("avg_ns_per_run")) for sample in samples]
        ),
        "events": summarize_numbers(
            [((sample.get("bpf") or {}).get("summary", {}).get("total_events")) for sample in samples]
        ),
        "events_per_sec": summarize_numbers(event_rates),
        "system_cpu_busy_pct": summarize_numbers(
            [((sample.get("system_cpu") or {}).get("busy_pct")) for sample in samples]
        ),
    }


def compare_phase_summaries(
    baseline_summary: Mapping[str, object],
    post_summary: Mapping[str, object] | None,
) -> dict[str, object]:
    if not post_summary:
        return {"comparable": False, "reason": "rejit did not apply successfully"}
    baseline_throughput = (baseline_summary.get("app_throughput_rps") or {}).get("median")
    post_throughput = (post_summary.get("app_throughput_rps") or {}).get("median")
    baseline_p99 = (baseline_summary.get("latency_ms_p99") or {}).get("median")
    post_p99 = (post_summary.get("latency_ms_p99") or {}).get("median")
    baseline_pps = (baseline_summary.get("packet_pps") or {}).get("median")
    post_pps = (post_summary.get("packet_pps") or {}).get("median")
    baseline_cpu = (baseline_summary.get("system_cpu_busy_pct") or {}).get("median")
    post_cpu = (post_summary.get("system_cpu_busy_pct") or {}).get("median")
    baseline_bpf = (baseline_summary.get("bpf_avg_ns_per_run") or {}).get("median")
    post_bpf = (post_summary.get("bpf_avg_ns_per_run") or {}).get("median")
    baseline_events = (baseline_summary.get("events") or {}).get("median")
    post_events = (post_summary.get("events") or {}).get("median")
    return {
        "comparable": True,
        "aggregation": "paired_cycle_median",
        "app_throughput_rps_delta_pct": percent_delta(baseline_throughput, post_throughput),
        "latency_ms_p99_delta_pct": percent_delta(baseline_p99, post_p99),
        "packet_pps_delta_pct": percent_delta(baseline_pps, post_pps),
        "system_cpu_busy_pct_delta_pct": percent_delta(baseline_cpu, post_cpu),
        "http_successes_delta_pct": percent_delta(
            baseline_summary.get("http_successes"),
            post_summary.get("http_successes"),
        ),
        "bpf_avg_ns_per_run_delta_pct": percent_delta(baseline_bpf, post_bpf),
        "bpf_speedup_ratio": speedup_ratio(baseline_bpf, post_bpf),
        "events_delta_pct": percent_delta(baseline_events, post_events),
    }


def compare_phases(baseline: Mapping[str, object], post: Mapping[str, object] | None) -> dict[str, object]:
    if not post:
        return {"comparable": False, "reason": "rejit did not apply successfully"}
    return compare_phase_summaries(baseline.get("summary") or {}, post.get("summary") or {})


def build_markdown(payload: Mapping[str, object]) -> str:
    lines = [
        "# Katran Real End-to-End Benchmark",
        "",
        f"- Generated: {payload['generated_at']}",
        f"- Mode: `{payload['mode']}`",
        f"- Smoke: `{payload['smoke']}`",
        f"- Paired cycles: `{payload['sample_count']}`",
        f"- Timed duration per phase: `{payload['duration_s']}s`",
        f"- Traffic driver: `{payload.get('traffic_driver')}`",
        f"- Workload model: `{payload.get('workload_model')}`",
        f"- Client concurrency: `{payload.get('client_concurrency')}`",
        f"- wrk threads: `{payload.get('wrk_threads')}`",
        f"- wrk connections: `{payload.get('wrk_connections')}`",
        f"- Warmup duration per phase: `{payload.get('warmup_duration_s')}`",
        f"- Control plane: `{payload.get('control_plane_mode')}`",
        f"- Interface: `{((payload.get('live_program') or {}).get('iface'))}`",
        f"- Attach mode: `{((payload.get('live_program') or {}).get('attach_mode'))}`",
        "",
        "## Kernel",
        "",
        f"- CONFIG_NET_IPIP: `{((payload.get('kernel_config') or {}).get('net_ipip_enabled'))}`",
        f"- CONFIG_DUMMY: `{((payload.get('kernel_config') or {}).get('dummy_enabled'))}`",
        f"- CONFIG_VETH: `{((payload.get('kernel_config') or {}).get('veth_enabled'))}`",
        "",
        "## Baseline",
        "",
        f"- HTTP successes: `{((payload['baseline'].get('summary') or {}).get('http_successes'))}` / `{((payload['baseline'].get('summary') or {}).get('http_requests'))}`",
        f"- App throughput median req/s: `{(((payload['baseline'].get('summary') or {}).get('app_throughput_rps') or {}).get('median'))}`",
        f"- Packet PPS median: `{(((payload['baseline'].get('summary') or {}).get('packet_pps') or {}).get('median'))}`",
        f"- Latency p99 median (ms): `{(((payload['baseline'].get('summary') or {}).get('latency_ms_p99') or {}).get('median'))}`",
        f"- System CPU busy median (%): `{(((payload['baseline'].get('summary') or {}).get('system_cpu_busy_pct') or {}).get('median'))}`",
        f"- bpf avg ns/run: `{((payload['baseline'].get('summary') or {}).get('bpf_avg_ns_per_run'))}`",
        f"- total events: `{((payload['baseline'].get('summary') or {}).get('events'))}`",
        "",
    ]
    if payload.get("post_rejit"):
        lines.extend(
            [
                "",
                "## Post-ReJIT",
                "",
                f"- HTTP successes: `{((payload['post_rejit'].get('summary') or {}).get('http_successes'))}` / `{((payload['post_rejit'].get('summary') or {}).get('http_requests'))}`",
                f"- App throughput median req/s: `{(((payload['post_rejit'].get('summary') or {}).get('app_throughput_rps') or {}).get('median'))}`",
                f"- Packet PPS median: `{(((payload['post_rejit'].get('summary') or {}).get('packet_pps') or {}).get('median'))}`",
                f"- Latency p99 median (ms): `{(((payload['post_rejit'].get('summary') or {}).get('latency_ms_p99') or {}).get('median'))}`",
                f"- System CPU busy median (%): `{(((payload['post_rejit'].get('summary') or {}).get('system_cpu_busy_pct') or {}).get('median'))}`",
                f"- bpf avg ns/run: `{((payload['post_rejit'].get('summary') or {}).get('bpf_avg_ns_per_run'))}`",
                f"- total events: `{((payload['post_rejit'].get('summary') or {}).get('events'))}`",
            ]
        )
    if payload.get("comparison", {}).get("comparable"):
        lines.extend(
            [
                "",
                "## Comparison",
                "",
                f"- Median throughput delta: `{payload['comparison'].get('app_throughput_rps_delta_pct')}`",
                f"- Median latency p99 delta: `{payload['comparison'].get('latency_ms_p99_delta_pct')}`",
                f"- Median packet PPS delta: `{payload['comparison'].get('packet_pps_delta_pct')}`",
                f"- Median system CPU delta: `{payload['comparison'].get('system_cpu_busy_pct_delta_pct')}`",
                f"- Median BPF delta: `{payload['comparison'].get('bpf_avg_ns_per_run_delta_pct')}`",
                f"- Median BPF speedup ratio (stock/reJIT): `{payload['comparison'].get('bpf_speedup_ratio')}`",
            ]
        )
    if payload.get("limitations"):
        lines.extend(["", "## Limitations", ""])
        for item in payload.get("limitations") or []:
            lines.append(f"- {item}")
    return "\n".join(lines) + "\n"


def ensure_artifacts(runner_binary: Path, daemon_binary: Path) -> None:
    if not runner_binary.exists():
        raise RuntimeError(f"micro_exec not found: {runner_binary}")
    if not daemon_binary.exists():
        raise RuntimeError(f"bpfrejit-daemon not found: {daemon_binary}")


def run_setup_script(setup_script: Path) -> dict[str, object]:
    completed = run_command(["bash", str(setup_script)], check=False, timeout=300)
    server_binary = ""
    for line in (completed.stdout or "").splitlines():
        if line.startswith("KATRAN_SERVER_BINARY="):
            server_binary = line.split("=", 1)[1].strip()
            break
    return {
        "returncode": completed.returncode,
        "katran_server_binary": server_binary or None,
        "stdout_tail": tail_text(completed.stdout or "", max_lines=40, max_chars=8000),
        "stderr_tail": tail_text(completed.stderr or "", max_lines=40, max_chars=8000),
    }


def katran_server_candidates() -> tuple[Path, ...]:
    return (
        ROOT_DIR / "e2e" / "cases" / "katran" / "bin" / "katran_server_grpc",
        Path("/usr/local/bin/katran_server_grpc"),
        Path("/usr/local/sbin/katran_server_grpc"),
        Path("/opt/katran/bin/katran_server_grpc"),
        ROOT_DIR / "third_party" / "katran-src" / "build" / "example_grpc" / "katran_server_grpc",
        ROOT_DIR / "tmp" / "katran-src" / "build" / "example_grpc" / "katran_server_grpc",
    )


def resolve_katran_server_binary(explicit: str | None, setup_result: Mapping[str, object]) -> str | None:
    if explicit:
        candidate = Path(explicit).expanduser().resolve()
        if candidate.exists():
            return str(candidate)
    scripted = str(setup_result.get("katran_server_binary") or "").strip()
    if scripted and Path(scripted).exists():
        return scripted
    for candidate in katran_server_candidates():
        if candidate.is_file() and os.access(candidate, os.X_OK):
            return str(candidate.resolve())
    for candidate in ("katran_server_grpc", "katran_server"):
        resolved = which(candidate)
        if resolved:
            return resolved
    return None


def read_kernel_config(path: Path) -> dict[str, object]:
    status = {
        "path": str(path.resolve()),
        "exists": path.exists(),
        "net_ipip_enabled": False,
        "net_ipgre_enabled": False,
        "dummy_enabled": False,
        "veth_enabled": False,
        "raw_matches": [],
    }
    if not path.exists():
        return status
    matches: list[str] = []
    for line in path.read_text().splitlines():
        if not any(token in line for token in ("CONFIG_NET_IPIP", "CONFIG_NET_IPGRE", "CONFIG_DUMMY", "CONFIG_VETH")):
            continue
        matches.append(line.strip())
        stripped = line.strip()
        if stripped in ("CONFIG_NET_IPIP=y", "CONFIG_NET_IPIP=m"):
            status["net_ipip_enabled"] = True
        if stripped in ("CONFIG_NET_IPGRE=y", "CONFIG_NET_IPGRE=m"):
            status["net_ipgre_enabled"] = True
        if stripped in ("CONFIG_DUMMY=y", "CONFIG_DUMMY=m"):
            status["dummy_enabled"] = True
        if stripped in ("CONFIG_VETH=y", "CONFIG_VETH=m"):
            status["veth_enabled"] = True
    status["raw_matches"] = matches
    return status


def inspect_object_program(
    runner_binary: Path,
    object_path: Path,
    program_name: str,
) -> dict[str, object]:
    result: dict[str, object] = {
        "object_path": relpath(object_path),
        "runner_binary": relpath(runner_binary),
        "program_name": program_name,
        "available_programs": [],
        "selected_program": None,
        "error": "",
    }
    try:
        inventory = discover_object_programs(runner_binary, object_path)
    except Exception as exc:
        result["error"] = str(exc)
        return result
    result["available_programs"] = [
        {
            "name": entry.name,
            "section_name": entry.section_name,
            "prog_type_name": entry.prog_type_name,
            "attach_type_name": entry.attach_type_name,
            "insn_count": entry.insn_count,
        }
        for entry in inventory
    ]
    for entry in inventory:
        if entry.name != program_name:
            continue
        result["selected_program"] = {
            "name": entry.name,
            "section_name": entry.section_name,
            "prog_type_name": entry.prog_type_name,
            "attach_type_name": entry.attach_type_name,
            "insn_count": entry.insn_count,
        }
        break
    return result


def bpftool_binary() -> str:
    try:
        return resolve_bpftool_binary()
    except RuntimeError:
        return "bpftool"


def ip_binary() -> str:
    for candidate in DEFAULT_IP_CANDIDATES:
        path = Path(candidate)
        if path.is_file() and os.access(path, os.X_OK):
            return str(path)
    resolved = which("ip")
    if resolved:
        return resolved
    raise RuntimeError("ip is required for the katran case")


def _normalize_ip_command(command: Sequence[str]) -> list[str]:
    args = [str(part) for part in command]
    if args and args[0] == "ip":
        return args[1:]
    return args


def _normalize_exec_command(command: Sequence[str]) -> list[str]:
    return [str(part) for part in command]


def ip_command(
    command: Sequence[str],
    *,
    check: bool = True,
    timeout: int | float | None = 30,
) -> subprocess.CompletedProcess[str]:
    return run_command([ip_binary(), *_normalize_ip_command(command)], check=check, timeout=timeout)


def ip_json_command(
    command: Sequence[str],
    *,
    timeout: int | float | None = 30,
) -> object:
    return run_json_command([ip_binary(), *_normalize_ip_command(command)], timeout=timeout)


def link_exists(name: str) -> bool:
    return Path("/sys/class/net").joinpath(name).exists()


def module_loaded(name: str) -> bool:
    return Path("/sys/module").joinpath(name).exists()


MODULE_FALLBACK_CANDIDATES: dict[str, tuple[Path, ...]] = {
    "veth": (ROOT_DIR / "vendor" / "linux-framework" / "drivers" / "net" / "veth.ko",),
    "tunnel4": (ROOT_DIR / "vendor" / "linux-framework" / "net" / "ipv4" / "tunnel4.ko",),
    "ip_tunnel": (ROOT_DIR / "vendor" / "linux-framework" / "net" / "ipv4" / "ip_tunnel.ko",),
    "ipip": (ROOT_DIR / "vendor" / "linux-framework" / "net" / "ipv4" / "ipip.ko",),
}


def ensure_kernel_module_loaded(name: str) -> None:
    if module_loaded(name):
        return

    attempts: list[str] = []
    repo_candidates = MODULE_FALLBACK_CANDIDATES.get(name, ())
    if repo_candidates:
        attempts.append(
            "repo_candidates="
            + ",".join(f"{candidate}:{candidate.exists()}" for candidate in repo_candidates)
        )
    modprobe = run_command(["modprobe", name], check=False, timeout=15)
    if modprobe.returncode == 0 and module_loaded(name):
        return
    detail = (modprobe.stderr or modprobe.stdout).strip()
    attempts.append(f"modprobe rc={modprobe.returncode}: {detail or 'no output'}")

    candidates: list[Path] = []
    for candidate in MODULE_FALLBACK_CANDIDATES.get(name, ()):
        if candidate.exists():
            candidates.append(candidate)
    for module_root in (
        Path("/lib/modules"),
        ROOT_DIR / "vendor" / "linux-framework" / ".virtme_mods" / "lib" / "modules",
    ):
        if not module_root.exists():
            continue
        candidates.extend(sorted(module_root.glob(f"**/{name}.ko")))
    candidates = list(dict.fromkeys(candidates))
    for candidate in candidates:
        insmod = run_command(["insmod", str(candidate)], check=False, timeout=15)
        if insmod.returncode == 0 and module_loaded(name):
            return
        detail = (insmod.stderr or insmod.stdout).strip()
        attempts.append(f"insmod {candidate} rc={insmod.returncode}: {detail or 'no output'}")

    raise RuntimeError(
        f"failed to load kernel module {name}: "
        + "; ".join(attempts or ["no module candidate under /lib/modules"])
    )


def ns_exec_command(
    namespace: str,
    command: Sequence[str],
    *,
    check: bool = True,
    timeout: int | float | None = 30,
) -> subprocess.CompletedProcess[str]:
    return run_command(
        [ip_binary(), "netns", "exec", namespace, *_normalize_exec_command(command)],
        check=check,
        timeout=timeout,
    )


def ns_ip_command(
    namespace: str,
    command: Sequence[str],
    *,
    check: bool = True,
    timeout: int | float | None = 30,
) -> subprocess.CompletedProcess[str]:
    return ns_exec_command(
        namespace,
        [ip_binary(), *_normalize_ip_command(command)],
        check=check,
        timeout=timeout,
    )


def set_ns_sysctl(namespace: str, key: str, value: int) -> None:
    completed = ns_exec_command(
        namespace,
        ["sysctl", "-q", "-w", f"{key}={value}"],
        check=False,
        timeout=15,
    )
    if completed.returncode == 0:
        return
    proc_key = key.replace(".", "/")
    ns_exec_command(
        namespace,
        ["sh", "-c", f"printf '%s' '{value}' > /proc/sys/{proc_key}"],
        timeout=15,
    )


def set_link_mac(namespace: str | None, iface: str, mac: str) -> None:
    if namespace is None:
        ip_command(["link", "set", "dev", iface, "address", mac], timeout=15)
        return
    ns_ip_command(namespace, ["link", "set", "dev", iface, "address", mac], timeout=15)


def get_link_json(namespace: str | None, iface: str) -> dict[str, object]:
    command = ["-j", "-details", "-s", "link", "show", "dev", iface]
    if namespace is not None:
        payload = run_json_command(
            [ip_binary(), "netns", "exec", namespace, ip_binary(), *command],
            timeout=30,
        )
    else:
        payload = ip_json_command(command, timeout=30)
    if not isinstance(payload, list) or not payload:
        raise RuntimeError(f"unexpected ip -j link payload for {iface}")
    return dict(payload[0])


def link_stats(namespace: str | None, iface: str) -> dict[str, int]:
    payload = get_link_json(namespace, iface)
    stats = payload.get("stats64") or payload.get("stats") or {}
    rx = stats.get("rx") if isinstance(stats, Mapping) else {}
    tx = stats.get("tx") if isinstance(stats, Mapping) else {}
    return {
        "rx_packets": int((rx or {}).get("packets", 0) or 0),
        "rx_bytes": int((rx or {}).get("bytes", 0) or 0),
        "tx_packets": int((tx or {}).get("packets", 0) or 0),
        "tx_bytes": int((tx or {}).get("bytes", 0) or 0),
    }


class BpfTestRunOpts(ctypes.Structure):
    _fields_ = [
        ("sz", ctypes.c_size_t),
        ("data_in", ctypes.c_void_p),
        ("data_out", ctypes.c_void_p),
        ("data_size_in", ctypes.c_uint32),
        ("data_size_out", ctypes.c_uint32),
        ("ctx_in", ctypes.c_void_p),
        ("ctx_out", ctypes.c_void_p),
        ("ctx_size_in", ctypes.c_uint32),
        ("ctx_size_out", ctypes.c_uint32),
        ("retval", ctypes.c_uint32),
        ("repeat", ctypes.c_int),
        ("duration", ctypes.c_uint32),
        ("flags", ctypes.c_uint32),
        ("cpu", ctypes.c_uint32),
        ("batch_size", ctypes.c_uint32),
    ]


class LibbpfMapApi:
    def __init__(self) -> None:
        path = ctypes.util.find_library("bpf") or "libbpf.so.1"
        self.lib = ctypes.CDLL(path, use_errno=True)
        self.lib.bpf_obj_get.argtypes = [ctypes.c_char_p]
        self.lib.bpf_obj_get.restype = ctypes.c_int
        self.lib.bpf_map_update_elem.argtypes = [
            ctypes.c_int,
            ctypes.c_void_p,
            ctypes.c_void_p,
            ctypes.c_uint64,
        ]
        self.lib.bpf_map_update_elem.restype = ctypes.c_int
        self.lib.bpf_map_delete_elem.argtypes = [
            ctypes.c_int,
            ctypes.c_void_p,
        ]
        self.lib.bpf_map_delete_elem.restype = ctypes.c_int
        self.lib.bpf_map_get_next_key.argtypes = [
            ctypes.c_int,
            ctypes.c_void_p,
            ctypes.c_void_p,
        ]
        self.lib.bpf_map_get_next_key.restype = ctypes.c_int
        self.lib.bpf_prog_test_run_opts.argtypes = [ctypes.c_int, ctypes.POINTER(BpfTestRunOpts)]
        self.lib.bpf_prog_test_run_opts.restype = ctypes.c_int

    def obj_get(self, path: Path) -> int:
        fd = int(self.lib.bpf_obj_get(os.fsencode(str(path))))
        if fd >= 0:
            return fd
        err = ctypes.get_errno()
        raise RuntimeError(f"bpf_obj_get failed for {path}: {os.strerror(err)} (errno={err})")

    def update(self, fd: int, key: bytes, value: bytes, flags: int = 0) -> None:
        key_buf = (ctypes.c_ubyte * len(key)).from_buffer_copy(key)
        value_buf = (ctypes.c_ubyte * len(value)).from_buffer_copy(value)
        rc = int(
            self.lib.bpf_map_update_elem(
                int(fd),
                ctypes.byref(key_buf),
                ctypes.byref(value_buf),
                int(flags),
            )
        )
        if rc == 0:
            return
        err = ctypes.get_errno()
        raise RuntimeError(f"bpf_map_update_elem failed: {os.strerror(err)} (errno={err})")

    def delete(self, fd: int, key: bytes) -> None:
        key_buf = (ctypes.c_ubyte * len(key)).from_buffer_copy(key)
        rc = int(self.lib.bpf_map_delete_elem(int(fd), ctypes.byref(key_buf)))
        if rc == 0:
            return
        err = ctypes.get_errno()
        if err == errno.ENOENT:
            return
        raise RuntimeError(f"bpf_map_delete_elem failed: {os.strerror(err)} (errno={err})")

    def next_key(self, fd: int, key: bytes | None, key_size: int) -> bytes | None:
        next_key = (ctypes.c_ubyte * key_size)()
        if key is None:
            current_key_ptr = None
        else:
            current_key = (ctypes.c_ubyte * len(key)).from_buffer_copy(key)
            current_key_ptr = ctypes.byref(current_key)
        rc = int(self.lib.bpf_map_get_next_key(int(fd), current_key_ptr, ctypes.byref(next_key)))
        if rc == 0:
            return bytes(next_key)
        err = ctypes.get_errno()
        if err == errno.ENOENT:
            return None
        raise RuntimeError(f"bpf_map_get_next_key failed: {os.strerror(err)} (errno={err})")

    def prog_test_run(
        self,
        prog_fd: int,
        packet: bytes,
        *,
        repeat: int = 1,
        data_out_size: int | None = None,
    ) -> dict[str, object]:
        in_buf = (ctypes.c_ubyte * len(packet)).from_buffer_copy(packet)
        out_size = max(1, int(data_out_size or len(packet)))
        out_buf = (ctypes.c_ubyte * out_size)()
        opts = BpfTestRunOpts()
        opts.sz = ctypes.sizeof(BpfTestRunOpts)
        opts.data_in = ctypes.cast(in_buf, ctypes.c_void_p)
        opts.data_size_in = len(packet)
        opts.data_out = ctypes.cast(out_buf, ctypes.c_void_p)
        opts.data_size_out = out_size
        opts.repeat = max(1, int(repeat))
        rc = int(self.lib.bpf_prog_test_run_opts(int(prog_fd), ctypes.byref(opts)))
        if rc != 0:
            err = ctypes.get_errno()
            raise RuntimeError(f"bpf_prog_test_run_opts failed: {os.strerror(err)} (errno={err})")
        output_size = max(0, int(opts.data_size_out))
        return {
            "retval": int(opts.retval),
            "duration_ns": int(opts.duration),
            "repeat": int(opts.repeat),
            "data_size_in": len(packet),
            "data_size_out": output_size,
            "data_out_preview_hex": bytes(out_buf[: min(output_size, 32)]).hex(),
        }


def pack_u32(value: int) -> bytes:
    return struct.pack("=I", int(value))


def pack_mac(mac: str) -> bytes:
    return bytes(int(part, 16) for part in mac.split(":"))


def pack_ctl_mac(mac: str) -> bytes:
    return pack_mac(mac) + b"\x00\x00"


def pack_vip_definition(address: str, port: int, proto: int) -> bytes:
    return socket.inet_aton(address) + (b"\x00" * 12) + struct.pack("!HBB", int(port), int(proto), 0)


def pack_vip_meta(flags: int, vip_num: int) -> bytes:
    return struct.pack("=II", int(flags), int(vip_num))


def pack_real_definition(address: str, flags: int = 0) -> bytes:
    return socket.inet_aton(address) + (b"\x00" * 12) + bytes([int(flags) & 0xFF]) + (b"\x00" * 3)


def xdp_action_name(retval: int) -> str:
    return {
        0: "XDP_ABORTED",
        1: "XDP_DROP",
        XDP_PASS: "XDP_PASS",
        XDP_TX: "XDP_TX",
        4: "XDP_REDIRECT",
    }.get(int(retval), f"UNKNOWN({int(retval)})")


def run_katran_prog_test_run(session: KatranDirectSession) -> dict[str, object]:
    if session.pinned_prog is None:
        raise RuntimeError("Katran pinned program path is unavailable")
    api = LibbpfMapApi()
    packet_path = materialize_katran_packet(DEFAULT_KATRAN_TEST_PACKET)
    packet = packet_path.read_bytes()
    prog_fd = api.obj_get(session.pinned_prog)
    try:
        result = api.prog_test_run(
            prog_fd,
            packet,
            data_out_size=max(256, len(packet) + 64),
        )
    finally:
        os.close(prog_fd)
    result.update(
        {
            "packet_path": relpath(packet_path),
            "expected_retval": XDP_TX,
            "expected_action": xdp_action_name(XDP_TX),
            "action": xdp_action_name(int(result["retval"])),
            "ok": int(result["retval"]) == XDP_TX,
        }
    )
    if not bool(result["ok"]):
        raise RuntimeError(
            "Katran BPF_PROG_TEST_RUN expected XDP_TX, "
            f"got {result['action']} ({result['retval']})"
        )
    return result


def possible_cpu_count() -> int:
    possible = Path("/sys/devices/system/cpu/possible")
    if not possible.exists():
        return max(1, os.cpu_count() or 1)
    count = 0
    for chunk in possible.read_text().strip().split(","):
        chunk = chunk.strip()
        if not chunk:
            continue
        if "-" in chunk:
            start_text, end_text = chunk.split("-", 1)
            count += int(end_text) - int(start_text) + 1
        else:
            count += 1
    return max(1, count)


def zero_map_value_bytes(map_type: str, value_size: int) -> bytes:
    if map_type in PERCPU_MAP_TYPES:
        stride = ((int(value_size) + 7) // 8) * 8
        return bytes(stride * possible_cpu_count())
    return bytes(max(0, int(value_size)))


def map_info_from_path(path: Path) -> dict[str, object]:
    payload = run_json_command([bpftool_binary(), "-j", "map", "show", "pinned", str(path)], timeout=30)
    if isinstance(payload, list):
        if not payload:
            raise RuntimeError(f"bpftool map show pinned returned no records for {path}")
        payload = payload[0]
    if not isinstance(payload, Mapping):
        raise RuntimeError(f"unexpected map payload for {path}: {type(payload)}")
    return dict(payload)


def int_field(payload: Mapping[str, object], *names: str) -> int:
    for name in names:
        value = payload.get(name)
        if value is None:
            continue
        if isinstance(value, int):
            return int(value)
        if isinstance(value, str) and value.isdigit():
            return int(value)
    return 0


def reset_katran_state(session: KatranDirectSession) -> dict[str, object]:
    api = LibbpfMapApi()
    reset_records: list[dict[str, object]] = []
    for map_name in STATE_RESET_MAPS:
        map_path = session.map_path(map_name)
        if not map_path.exists():
            continue
        info = map_info_from_path(map_path)
        map_type = str(info.get("type") or "").lower()
        key_size = int_field(info, "bytes_key", "key_size", "key")
        value_size = int_field(info, "bytes_value", "value_size", "value")
        max_entries = int_field(info, "max_entries")
        cleared_entries = 0
        action = "noop"
        fd = api.obj_get(map_path)
        try:
            if map_type in ARRAY_MAP_TYPES:
                zero_value = zero_map_value_bytes(map_type, value_size)
                if key_size != 4:
                    raise RuntimeError(f"unsupported array key size for {map_name}: {key_size}")
                for entry_index in range(max_entries):
                    api.update(fd, pack_u32(entry_index), zero_value)
                    cleared_entries += 1
                action = "zero-array"
            elif map_type in HASH_LIKE_MAP_TYPES:
                key = api.next_key(fd, None, key_size)
                while key is not None:
                    next_key = api.next_key(fd, key, key_size)
                    api.delete(fd, key)
                    cleared_entries += 1
                    key = next_key
                action = "clear-keys"
            else:
                action = f"skipped-{map_type or 'unknown'}"
        finally:
            os.close(fd)
        reset_records.append(
            {
                "name": map_name,
                "type": map_type,
                "max_entries": max_entries,
                "cleared_entries": cleared_entries,
                "action": action,
            }
        )
    return {
        "strategy": "reset mutable stats/fallback maps before each phase",
        "map_count": len(reset_records),
        "maps": reset_records,
    }


class KatranDsrTopology:
    def __init__(self, iface: str, *, router_peer_iface: str | None = None) -> None:
        self.iface = iface
        self.router_peer_iface = router_peer_iface or None
        self.lb_ifindex = 0

    def __enter__(self) -> "KatranDsrTopology":
        self.cleanup()
        # Ensure required kernel modules are loaded and usable in the guest.
        for mod in ("veth", "tunnel4", "ip_tunnel", "ipip"):
            ensure_kernel_module_loaded(mod)
        for namespace in (ROUTER_NS, CLIENT_NS, REAL_NS):
            ip_command(["netns", "add", namespace], timeout=15)

        if self.router_peer_iface is None:
            ip_command(["link", "add", self.iface, "type", "veth", "peer", "name", ROUTER_LB_IFACE], timeout=15)
            ip_command(["link", "set", ROUTER_LB_IFACE, "netns", ROUTER_NS], timeout=15)
        else:
            if self.router_peer_iface == self.iface:
                raise RuntimeError("router peer iface must differ from Katran ingress iface")
            if not link_exists(self.iface):
                raise RuntimeError(f"network interface does not exist: {self.iface}")
            if not link_exists(self.router_peer_iface):
                raise RuntimeError(f"router peer interface does not exist: {self.router_peer_iface}")
            ip_command(["link", "set", self.router_peer_iface, "netns", ROUTER_NS], timeout=15)
            ns_ip_command(ROUTER_NS, ["link", "set", "dev", self.router_peer_iface, "name", ROUTER_LB_IFACE], timeout=15)

        ip_command(["link", "add", ROUTER_CLIENT_IFACE, "type", "veth", "peer", "name", CLIENT_IFACE], timeout=15)
        ip_command(["link", "set", ROUTER_CLIENT_IFACE, "netns", ROUTER_NS], timeout=15)
        ip_command(["link", "set", CLIENT_IFACE, "netns", CLIENT_NS], timeout=15)

        ip_command(["link", "add", ROUTER_REAL_IFACE, "type", "veth", "peer", "name", REAL_IFACE], timeout=15)
        ip_command(["link", "set", ROUTER_REAL_IFACE, "netns", ROUTER_NS], timeout=15)
        ip_command(["link", "set", REAL_IFACE, "netns", REAL_NS], timeout=15)

        set_link_mac(None, self.iface, LB_MAC)
        set_link_mac(ROUTER_NS, ROUTER_LB_IFACE, ROUTER_LB_MAC)
        set_link_mac(ROUTER_NS, ROUTER_CLIENT_IFACE, ROUTER_CLIENT_MAC)
        set_link_mac(CLIENT_NS, CLIENT_IFACE, CLIENT_MAC)
        set_link_mac(ROUTER_NS, ROUTER_REAL_IFACE, ROUTER_REAL_MAC)
        set_link_mac(REAL_NS, REAL_IFACE, REAL_MAC)

        for namespace in (ROUTER_NS, CLIENT_NS, REAL_NS):
            ns_ip_command(namespace, ["link", "set", "lo", "up"], timeout=15)

        ip_command(["addr", "replace", f"{LB_IP}/24", "dev", self.iface], timeout=15)
        ip_command(["link", "set", "dev", self.iface, "up"], timeout=15)

        ns_ip_command(ROUTER_NS, ["addr", "add", f"{ROUTER_LB_IP}/24", "dev", ROUTER_LB_IFACE], timeout=15)
        ns_ip_command(ROUTER_NS, ["addr", "add", f"{ROUTER_CLIENT_IP}/24", "dev", ROUTER_CLIENT_IFACE], timeout=15)
        ns_ip_command(ROUTER_NS, ["addr", "add", f"{ROUTER_REAL_IP}/24", "dev", ROUTER_REAL_IFACE], timeout=15)
        ns_ip_command(ROUTER_NS, ["link", "set", "dev", ROUTER_LB_IFACE, "up"], timeout=15)
        ns_ip_command(ROUTER_NS, ["link", "set", "dev", ROUTER_CLIENT_IFACE, "up"], timeout=15)
        ns_ip_command(ROUTER_NS, ["link", "set", "dev", ROUTER_REAL_IFACE, "up"], timeout=15)

        ns_ip_command(CLIENT_NS, ["addr", "add", f"{CLIENT_IP}/24", "dev", CLIENT_IFACE], timeout=15)
        ns_ip_command(CLIENT_NS, ["link", "set", "dev", CLIENT_IFACE, "up"], timeout=15)

        ns_ip_command(REAL_NS, ["addr", "add", f"{REAL_IP}/24", "dev", REAL_IFACE], timeout=15)
        ns_ip_command(REAL_NS, ["link", "set", "dev", REAL_IFACE, "up"], timeout=15)
        ns_ip_command(REAL_NS, ["addr", "add", f"{VIP_IP}/32", "dev", "lo"], timeout=15)
        ns_ip_command(REAL_NS, ["link", "add", "name", "ipip0", "type", "ipip", "external"], timeout=15)
        ns_ip_command(REAL_NS, ["addr", "add", f"{IPIP_DUMMY_IP}/32", "dev", "ipip0"], timeout=15)
        ns_ip_command(REAL_NS, ["link", "set", "dev", "ipip0", "up"], timeout=15)

        ns_ip_command(CLIENT_NS, ["route", "add", "default", "via", ROUTER_CLIENT_IP, "dev", CLIENT_IFACE], timeout=15)
        ns_ip_command(REAL_NS, ["route", "add", "default", "via", ROUTER_REAL_IP, "dev", REAL_IFACE], timeout=15)
        ns_ip_command(ROUTER_NS, ["route", "add", f"{VIP_IP}/32", "via", LB_IP, "dev", ROUTER_LB_IFACE], timeout=15)

        ns_ip_command(
            CLIENT_NS,
            ["neigh", "replace", ROUTER_CLIENT_IP, "lladdr", ROUTER_CLIENT_MAC, "dev", CLIENT_IFACE, "nud", "permanent"],
            timeout=15,
        )
        ns_ip_command(
            ROUTER_NS,
            ["neigh", "replace", LB_IP, "lladdr", LB_MAC, "dev", ROUTER_LB_IFACE, "nud", "permanent"],
            timeout=15,
        )
        ns_ip_command(
            ROUTER_NS,
            ["neigh", "replace", REAL_IP, "lladdr", REAL_MAC, "dev", ROUTER_REAL_IFACE, "nud", "permanent"],
            timeout=15,
        )
        ns_ip_command(
            REAL_NS,
            ["neigh", "replace", ROUTER_REAL_IP, "lladdr", ROUTER_REAL_MAC, "dev", REAL_IFACE, "nud", "permanent"],
            timeout=15,
        )

        set_ns_sysctl(ROUTER_NS, "net.ipv4.ip_forward", 1)
        for namespace, keys in (
            (
                ROUTER_NS,
                (
                    "net.ipv4.conf.all.rp_filter",
                    "net.ipv4.conf.default.rp_filter",
                    f"net.ipv4.conf.{ROUTER_LB_IFACE}.rp_filter",
                    f"net.ipv4.conf.{ROUTER_CLIENT_IFACE}.rp_filter",
                    f"net.ipv4.conf.{ROUTER_REAL_IFACE}.rp_filter",
                ),
            ),
            (
                REAL_NS,
                (
                    "net.ipv4.conf.all.rp_filter",
                    "net.ipv4.conf.default.rp_filter",
                    "net.ipv4.conf.lo.rp_filter",
                    f"net.ipv4.conf.{REAL_IFACE}.rp_filter",
                    "net.ipv4.conf.ipip0.rp_filter",
                ),
            ),
        ):
            for key in keys:
                set_ns_sysctl(namespace, key, 0)

        self.lb_ifindex = int(Path("/sys/class/net").joinpath(self.iface, "ifindex").read_text().strip())
        return self

    def cleanup(self) -> None:
        if self.router_peer_iface is None and link_exists(self.iface):
            ip_command(["link", "del", self.iface], check=False, timeout=15)
        if self.router_peer_iface is not None:
            ns_ip_command(ROUTER_NS, ["link", "set", "dev", ROUTER_LB_IFACE, "netns", "1"], check=False, timeout=15)
        for namespace in (REAL_NS, CLIENT_NS, ROUTER_NS):
            ip_command(["netns", "del", namespace], check=False, timeout=15)
        if self.router_peer_iface is not None and link_exists(ROUTER_LB_IFACE) and not link_exists(self.router_peer_iface):
            ip_command(["link", "set", "dev", ROUTER_LB_IFACE, "name", self.router_peer_iface], check=False, timeout=15)

    def ipip_stats(self) -> dict[str, int]:
        return link_stats(REAL_NS, "ipip0")

    def metadata(self) -> dict[str, object]:
        return {
            "namespaces": {
                "router": ROUTER_NS,
                "client": CLIENT_NS,
                "real": REAL_NS,
            },
            "iface": self.iface,
            "router_peer_iface": self.router_peer_iface,
            "lb_ifindex": self.lb_ifindex,
            "addresses": {
                "lb": LB_IP,
                "router_lb": ROUTER_LB_IP,
                "client": CLIENT_IP,
                "router_client": ROUTER_CLIENT_IP,
                "real": REAL_IP,
                "router_real": ROUTER_REAL_IP,
                "vip": VIP_IP,
            },
            "macs": {
                "lb": LB_MAC,
                "router_lb": ROUTER_LB_MAC,
                "client": CLIENT_MAC,
                "router_client": ROUTER_CLIENT_MAC,
                "real": REAL_MAC,
                "router_real": ROUTER_REAL_MAC,
            },
        }

    def close(self) -> None:
        self.cleanup()

    def __exit__(self, exc_type, exc, tb) -> None:
        self.close()


NAMESPACE_HTTP_SERVER_SCRIPT = """
import http.server
import socketserver
import sys


class Handler(http.server.BaseHTTPRequestHandler):
    protocol_version = "HTTP/1.0"

    def do_GET(self):
        body = b"katran-ok\\n"
        self.send_response(200)
        self.send_header("Content-Type", "text/plain; charset=utf-8")
        self.send_header("Content-Length", str(len(body)))
        self.send_header("Connection", "close")
        self.end_headers()
        try:
            self.wfile.write(body)
            self.wfile.flush()
        except (BrokenPipeError, ConnectionResetError, ConnectionAbortedError, TimeoutError):
            return
        self.close_connection = True

    def log_message(self, fmt, *args):
        pass


class Server(socketserver.ThreadingMixIn, http.server.HTTPServer):
    daemon_threads = True
    allow_reuse_address = True
    request_queue_size = 128


server = Server((sys.argv[1], int(sys.argv[2])), Handler)
server.serve_forever()
"""


class NamespaceHttpServer:
    def __init__(self, namespace: str, bind_ip: str, port: int) -> None:
        self.namespace = namespace
        self.bind_ip = bind_ip
        self.port = int(port)
        self.process: subprocess.Popen[str] | None = None
        self.stdout_tail = ""
        self.stderr_tail = ""

    def __enter__(self) -> "NamespaceHttpServer":
        self.process = subprocess.Popen(
            [
                ip_binary(),
                "netns",
                "exec",
                self.namespace,
                "python3",
                "-u",
                "-c",
                NAMESPACE_HTTP_SERVER_SCRIPT,
                self.bind_ip,
                str(self.port),
            ],
            cwd=ROOT_DIR,
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            text=True,
        )
        try:
            self._wait_until_ready()
        except Exception:
            self.close()
            raise
        return self

    def _wait_until_ready(self) -> None:
        assert self.process is not None
        deadline = time.monotonic() + SERVER_START_TIMEOUT_S
        probe = (
            "import socket, sys; "
            "s = socket.socket(); "
            "s.settimeout(0.2); "
            "rc = s.connect_ex((sys.argv[1], int(sys.argv[2]))); "
            "s.close(); "
            "raise SystemExit(0 if rc == 0 else 1)"
        )
        while time.monotonic() < deadline:
            if self.process.poll() is not None:
                stdout, stderr = self.process.communicate(timeout=5)
                self.stdout_tail = tail_text(stdout or "", max_lines=20, max_chars=4000)
                self.stderr_tail = tail_text(stderr or "", max_lines=20, max_chars=4000)
                raise RuntimeError(f"http server exited early: {self.stderr_tail or self.stdout_tail}")
            completed = ns_exec_command(
                self.namespace,
                ["python3", "-c", probe, self.bind_ip, str(self.port)],
                check=False,
                timeout=5,
            )
            if completed.returncode == 0:
                return
            time.sleep(0.1)
        raise RuntimeError("timed out waiting for namespace http server to start")

    def metadata(self) -> dict[str, object]:
        return {
            "namespace": self.namespace,
            "bind_ip": self.bind_ip,
            "port": self.port,
            "pid": None if self.process is None else self.process.pid,
            "stdout_tail": self.stdout_tail,
            "stderr_tail": self.stderr_tail,
        }

    def close(self) -> None:
        if self.process is None:
            return
        if self.process.poll() is None:
            self.process.terminate()
            try:
                stdout, stderr = self.process.communicate(timeout=10)
            except subprocess.TimeoutExpired:
                self.process.kill()
                stdout, stderr = self.process.communicate(timeout=10)
        else:
            stdout, stderr = self.process.communicate(timeout=10)
        self.stdout_tail = tail_text(stdout or "", max_lines=20, max_chars=4000)
        self.stderr_tail = tail_text(stderr or "", max_lines=20, max_chars=4000)
        self.process = None

    def __exit__(self, exc_type, exc, tb) -> None:
        self.close()


class KatranDirectSession:
    def __init__(
        self,
        *,
        object_path: Path,
        program_name: str,
        iface: str,
        attach: bool,
        bpftool: str,
    ) -> None:
        self.object_path = object_path
        self.program_name = program_name
        self.iface = iface
        self.attach = attach
        self.bpftool = bpftool
        self.bpffs_dir: Path | None = None
        self.prog_dir: Path | None = None
        self.map_dir: Path | None = None
        self.pinned_prog: Path | None = None
        self.program: dict[str, object] = {}
        self.attach_info: dict[str, object] = {}
        self.attach_error: str = ""
        self.attach_mode: str | None = None
        self.ifindex: int = 0

    def __enter__(self) -> "KatranDirectSession":
        if not link_exists(self.iface):
            raise RuntimeError(f"network interface does not exist: {self.iface}")
        self.ifindex = int(Path("/sys/class/net").joinpath(self.iface, "ifindex").read_text().strip())
        self.bpffs_dir = Path(tempfile.mkdtemp(prefix="katrane2e-", dir="/sys/fs/bpf"))
        self.prog_dir = self.bpffs_dir / "progs"
        self.map_dir = self.bpffs_dir / "maps"
        self.prog_dir.mkdir(parents=True, exist_ok=True)
        self.map_dir.mkdir(parents=True, exist_ok=True)
        run_command(
            [
                self.bpftool,
                "prog",
                "loadall",
                str(self.object_path),
                str(self.prog_dir),
                "type",
                "xdp",
                "pinmaps",
                str(self.map_dir),
            ],
            timeout=90,
        )
        self.pinned_prog = self.prog_dir / self.program_name
        if not self.pinned_prog.exists():
            raise RuntimeError(f"pinned program not found after load: {self.pinned_prog}")
        self.program = self._show_program()
        if self.attach:
            self._attempt_attach()
        return self

    @property
    def prog_id(self) -> int:
        return int(self.program.get("id", 0) or 0)

    def map_path(self, name: str) -> Path:
        if self.map_dir is None:
            raise RuntimeError("map directory is not initialized")
        return self.map_dir / name

    def _show_program(self) -> dict[str, object]:
        assert self.pinned_prog is not None
        payload = run_json_command([self.bpftool, "-j", "prog", "show", "pinned", str(self.pinned_prog)], timeout=30)
        if not isinstance(payload, dict):
            raise RuntimeError("bpftool prog show pinned returned unexpected payload")
        return dict(payload)

    def _attempt_attach(self) -> None:
        assert self.pinned_prog is not None
        errors: list[str] = []
        # Prefer xdpgeneric for veth interfaces: native XDP_TX on veth is
        # broken in some kernels (including 7.0-rc2) where XDP_TX'd packets
        # do not reach the peer namespace.  xdpgeneric handles this correctly.
        for mode in ("xdpgeneric", "xdp"):
            try:
                run_command(
                    [
                        self.bpftool,
                        "net",
                        "attach",
                        mode,
                        "pinned",
                        str(self.pinned_prog),
                        "dev",
                        self.iface,
                        "overwrite",
                    ],
                    timeout=30,
                )
                self.attach_mode = mode
                payload = run_json_command([self.bpftool, "-j", "net", "show", "dev", self.iface], timeout=30)
                if isinstance(payload, list):
                    for record in payload:
                        if not isinstance(record, dict):
                            continue
                        if record.get("xdp") or record.get("xdp_attached"):
                            self.attach_info = dict(record)
                            break
                return
            except Exception as exc:
                errors.append(f"{mode}: {exc}")
        self.attach_error = "; ".join(errors)

    def metadata(self) -> dict[str, object]:
        return {
            "program": dict(self.program),
            "iface": self.iface,
            "ifindex": self.ifindex,
            "attached": bool(self.attach and not self.attach_error),
            "attach_mode": self.attach_mode,
            "attach_error": self.attach_error,
            "attach_info": self.attach_info,
            "bpffs_dir": None if self.bpffs_dir is None else str(self.bpffs_dir),
            "pinned_prog": None if self.pinned_prog is None else str(self.pinned_prog),
            "pinned_maps": [] if self.map_dir is None else sorted(path.name for path in self.map_dir.iterdir()),
        }

    def close(self) -> None:
        if self.attach and self.attach_mode:
            run_command([self.bpftool, "net", "detach", self.attach_mode, "dev", self.iface], check=False, timeout=15)
            self.attach_mode = None
        if self.bpffs_dir is not None:
            shutil.rmtree(self.bpffs_dir, ignore_errors=True)
            self.bpffs_dir = None
            self.prog_dir = None
            self.map_dir = None
            self.pinned_prog = None

    def __exit__(self, exc_type, exc, tb) -> None:
        self.close()


def configure_katran_maps(session: KatranDirectSession) -> dict[str, object]:
    api = LibbpfMapApi()
    vip_fd = api.obj_get(session.map_path("vip_map"))
    reals_fd = api.obj_get(session.map_path("reals"))
    rings_fd = api.obj_get(session.map_path("ch_rings"))
    ctl_fd = api.obj_get(session.map_path("ctl_array"))
    try:
        api.update(ctl_fd, pack_u32(0), pack_ctl_mac(ROUTER_LB_MAC))
        api.update(
            vip_fd,
            pack_vip_definition(VIP_IP, VIP_PORT, TCP_PROTO),
            pack_vip_meta(F_LRU_BYPASS, VIP_NUM),
        )
        api.update(reals_fd, pack_u32(REAL_NUM), pack_real_definition(REAL_IP))
        for ring_pos in range(CH_RING_SIZE):
            api.update(rings_fd, pack_u32((VIP_NUM * CH_RING_SIZE) + ring_pos), pack_u32(REAL_NUM))
    finally:
        os.close(vip_fd)
        os.close(reals_fd)
        os.close(rings_fd)
        os.close(ctl_fd)
    return {
        "vip": {
            "address": VIP_IP,
            "port": VIP_PORT,
            "proto": TCP_PROTO,
            "vip_num": VIP_NUM,
            "flags": F_LRU_BYPASS,
        },
        "real": {
            "address": REAL_IP,
            "real_num": REAL_NUM,
        },
        "default_gateway_mac": ROUTER_LB_MAC,
        "ch_ring_size": CH_RING_SIZE,
    }


CLIENT_REQUEST_SCRIPT = """
import json
import socket
import sys
import time

host = sys.argv[1]
port = int(sys.argv[2])
count = int(sys.argv[3])
timeout = float(sys.argv[4])
payload = b"GET / HTTP/1.0\\r\\nHost: katran\\r\\nConnection: close\\r\\n\\r\\n"
results = []
for index in range(count):
    entry = {"index": index, "ok": False, "error": "", "bytes": 0, "latency_ms": None, "snippet": ""}
    started = time.monotonic()
    try:
        with socket.create_connection((host, port), timeout=timeout) as sock:
            sock.settimeout(timeout)
            sock.sendall(payload)
            chunks = []
            while True:
                chunk = sock.recv(4096)
                if not chunk:
                    break
                chunks.append(chunk)
        data = b"".join(chunks)
        text = data.decode("latin1", "replace")
        entry["latency_ms"] = (time.monotonic() - started) * 1000.0
        entry["bytes"] = len(data)
        entry["snippet"] = text[:200]
        entry["ok"] = text.startswith("HTTP/1.0 200 OK") or text.startswith("HTTP/1.1 200 OK")
    except Exception as exc:
        entry["error"] = str(exc)
    results.append(entry)
print(json.dumps(results))
"""

PARALLEL_CLIENT_REQUEST_SCRIPT = """
import json
import socket
import statistics
import sys
import threading
import time

host = sys.argv[1]
port = int(sys.argv[2])
duration_s = float(sys.argv[3])
concurrency = max(1, int(sys.argv[4]))
timeout = float(sys.argv[5])
preview_limit = max(1, int(sys.argv[6]))
payload = b"GET / HTTP/1.0\\r\\nHost: katran\\r\\nConnection: close\\r\\n\\r\\n"

latencies = []
failure_preview = []
request_count = 0
success_count = 0
bytes_total = 0
lock = threading.Lock()

def percentile(values, pct):
    if not values:
        return None
    if len(values) == 1:
        return float(values[0])
    ordered = sorted(float(value) for value in values)
    rank = max(0.0, min(1.0, float(pct) / 100.0)) * (len(ordered) - 1)
    lower = int(rank)
    upper = min(len(ordered) - 1, lower + 1)
    weight = rank - lower
    return ordered[lower] * (1.0 - weight) + ordered[upper] * weight

def worker(worker_id, deadline):
    global request_count, success_count, bytes_total
    local_latencies = []
    local_failures = []
    local_requests = 0
    local_successes = 0
    local_bytes = 0
    while time.monotonic() < deadline:
        started = time.monotonic()
        local_requests += 1
        try:
            with socket.create_connection((host, port), timeout=timeout) as sock:
                sock.settimeout(timeout)
                sock.sendall(payload)
                chunks = []
                while True:
                    chunk = sock.recv(4096)
                    if not chunk:
                        break
                    chunks.append(chunk)
            data = b"".join(chunks)
            text = data.decode("latin1", "replace")
            if text.startswith("HTTP/1.0 200 OK") or text.startswith("HTTP/1.1 200 OK"):
                local_successes += 1
                local_bytes += len(data)
                local_latencies.append((time.monotonic() - started) * 1000.0)
            elif len(local_failures) < preview_limit:
                local_failures.append(
                    {
                        "worker": worker_id,
                        "error": "non-200 response",
                        "snippet": text[:200],
                    }
                )
        except Exception as exc:
            if len(local_failures) < preview_limit:
                local_failures.append(
                    {
                        "worker": worker_id,
                        "error": str(exc),
                        "snippet": "",
                    }
                )
    with lock:
        request_count += local_requests
        success_count += local_successes
        bytes_total += local_bytes
        latencies.extend(local_latencies)
        for item in local_failures:
            if len(failure_preview) >= preview_limit:
                break
            failure_preview.append(item)

started = time.monotonic()
deadline = started + max(0.0, duration_s)
threads = [threading.Thread(target=worker, args=(index, deadline), daemon=True) for index in range(concurrency)]
for thread in threads:
    thread.start()
for thread in threads:
    thread.join()
elapsed = max(0.000001, time.monotonic() - started)
latency_summary = {
    "count": len(latencies),
    "mean": statistics.mean(latencies) if latencies else None,
    "median": statistics.median(latencies) if latencies else None,
    "min": min(latencies) if latencies else None,
    "max": max(latencies) if latencies else None,
    "p50": percentile(latencies, 50.0),
    "p90": percentile(latencies, 90.0),
    "p99": percentile(latencies, 99.0),
}
print(
    json.dumps(
        {
            "driver": "python_parallel",
            "request_count": request_count,
            "success_count": success_count,
            "ops_per_sec": (success_count / elapsed) if elapsed > 0 else None,
            "duration_s": elapsed,
            "bytes_total": bytes_total,
            "latency_ms": latency_summary,
            "failure_preview": failure_preview,
            "concurrency": concurrency,
        }
    )
)
"""


def perform_http_requests(iterations: int) -> list[dict[str, object]]:
    payload = run_json_command(
        [
            "ip",
            "netns",
            "exec",
            CLIENT_NS,
            "python3",
            "-c",
            CLIENT_REQUEST_SCRIPT,
            VIP_IP,
            str(VIP_PORT),
            str(max(1, int(iterations))),
            str(HTTP_TIMEOUT_S),
        ],
        timeout=max(30, int(iterations) * 5),
    )
    if not isinstance(payload, list):
        raise RuntimeError("client request payload is not a JSON list")
    requests: list[dict[str, object]] = []
    for item in payload:
        if isinstance(item, dict):
            requests.append(dict(item))
    return requests


def run_parallel_http_load(
    *,
    duration_s: int | float,
    concurrency: int,
) -> dict[str, object]:
    payload = run_json_command(
        [
            "ip",
            "netns",
            "exec",
            CLIENT_NS,
            "python3",
            "-c",
            PARALLEL_CLIENT_REQUEST_SCRIPT,
            VIP_IP,
            str(VIP_PORT),
            str(max(0.0, float(duration_s))),
            str(max(1, int(concurrency))),
            str(HTTP_TIMEOUT_S),
            str(REQUEST_FAILURE_PREVIEW_LIMIT),
        ],
        timeout=max(30, int(float(duration_s) * 4) + 10),
    )
    if not isinstance(payload, Mapping):
        raise RuntimeError("parallel client payload is not a JSON object")
    return dict(payload)


def run_warmup_requests(iterations: int, *, batch_size: int) -> dict[str, object]:
    if iterations <= 0:
        return {
            "request_count": 0,
            "success_count": 0,
            "latency_ms": summarize_numbers([]),
            "failure_preview": [],
        }
    records: list[dict[str, object]] = []
    requested = max(0, int(iterations))
    success_count = 0
    attempted = 0
    attempt_budget = max(requested, requested * WARMUP_MAX_ATTEMPT_FACTOR)
    while success_count < requested and attempted < attempt_budget:
        current_batch = min(max(1, int(batch_size)), requested - success_count)
        batch_records = perform_http_requests(current_batch)
        records.extend(batch_records)
        attempted += len(batch_records)
        success_count += sum(1 for record in batch_records if bool(record.get("ok")))
        if success_count < requested and any(not bool(record.get("ok")) for record in batch_records):
            time.sleep(0.2)
    summary = summarize_request_records(records)
    summary["requested_request_count"] = requested
    summary["attempted_request_count"] = attempted
    summary["completed_warmup_requests"] = min(requested, int(summary["success_count"] or 0))
    if int(summary["success_count"] or 0) < requested:
        raise RuntimeError(f"Katran warmup validation failed: {summary['failure_preview']}")
    summary.pop("latencies_ms", None)
    return summary


def run_warmup_wrk(
    *,
    duration_s: int | float,
    connections: int,
    threads: int,
) -> dict[str, object]:
    if float(duration_s) <= 0:
        return {
            "driver": "wrk",
            "request_count": 0,
            "success_count": 0,
            "ops_per_sec": None,
            "duration_s": 0.0,
            "latency_ms": {},
            "failure_preview": [],
            "stdout_tail": "",
            "stderr_tail": "",
        }
    summary = run_wrk(
        namespace=CLIENT_NS,
        duration_s=duration_s,
        connections=connections,
        threads=threads,
    )
    if int(summary.get("request_count", 0) or 0) <= 0:
        raise RuntimeError("Katran wrk warmup produced zero requests")
    if int(summary.get("success_count", 0) or 0) != int(summary.get("request_count", 0) or 0):
        raise RuntimeError(f"Katran wrk warmup failed: {summary.get('failure_preview')}")
    return summary


def execute_http_measurement_loop(
    *,
    batch_size: int,
    duration_s: int | float,
    minimum_requests: int,
) -> tuple[list[dict[str, object]], int, float]:
    records: list[dict[str, object]] = []
    batches = 0
    started = time.monotonic()
    requested_duration = max(0.0, float(duration_s))
    request_target = max(1, int(minimum_requests), int(batch_size))
    while True:
        records.extend(perform_http_requests(batch_size))
        batches += 1
        elapsed = time.monotonic() - started
        if elapsed >= requested_duration and len(records) >= request_target:
            return records, batches, elapsed


WARMUP_RETRY_COUNT = 3
WARMUP_RETRY_BACKOFF_S = 2.0
WARMUP_MIN_SUCCESS_RATE = 0.90


def _run_warmup_with_retry(
    *,
    use_wrk_driver: bool,
    warmup_duration_s: int | float,
    wrk_connections: int,
    wrk_threads: int,
    traffic_iterations: int,
) -> dict[str, object]:
    """Run warmup with retries.  Early requests may fail while ARP/routing settles."""
    last_error: str = ""
    for attempt in range(WARMUP_RETRY_COUNT):
        try:
            if use_wrk_driver:
                warmup = run_warmup_wrk(
                    duration_s=warmup_duration_s,
                    connections=wrk_connections,
                    threads=wrk_threads,
                )
            else:
                warmup = run_parallel_http_load(
                    duration_s=warmup_duration_s,
                    concurrency=traffic_iterations,
                )
                request_count = int(warmup.get("request_count", 0) or 0)
                success_count = int(warmup.get("success_count", 0) or 0)
                if request_count <= 0:
                    raise RuntimeError("Katran parallel warmup produced zero requests")
                success_rate = success_count / request_count
                if success_rate < WARMUP_MIN_SUCCESS_RATE:
                    raise RuntimeError(
                        f"Katran parallel warmup below threshold "
                        f"({success_count}/{request_count}={success_rate:.1%} < {WARMUP_MIN_SUCCESS_RATE:.0%}): "
                        f"{warmup.get('failure_preview')}"
                    )
            return warmup
        except RuntimeError as exc:
            last_error = str(exc)
            if attempt < WARMUP_RETRY_COUNT - 1:
                time.sleep(WARMUP_RETRY_BACKOFF_S * (attempt + 1))
    raise RuntimeError(f"Katran warmup failed after {WARMUP_RETRY_COUNT} attempts: {last_error}")


def measure_phase(
    *,
    index: int,
    phase_name: str,
    session: KatranDirectSession,
    traffic_iterations: int,
    duration_s: int,
    minimum_requests: int,
    warmup_request_count: int,
    warmup_duration_s: int | float,
    use_wrk_driver: bool,
    wrk_connections: int,
    wrk_threads: int,
) -> dict[str, object]:
    state_reset = reset_katran_state(session)
    warmup = _run_warmup_with_retry(
        use_wrk_driver=use_wrk_driver,
        warmup_duration_s=warmup_duration_s,
        wrk_connections=wrk_connections,
        wrk_threads=wrk_threads,
        traffic_iterations=traffic_iterations,
    )
    before = sample_bpf_stats([session.prog_id])
    ipip_before = link_stats(REAL_NS, "ipip0")
    system_cpu_holder: dict[str, object] = {}
    cpu_thread = threading.Thread(
        target=lambda: system_cpu_holder.update(sample_total_cpu_usage(duration_s)),
        daemon=True,
    )
    cpu_thread.start()
    request_latencies: list[float] = []
    if use_wrk_driver:
        request_summary = run_wrk(
            namespace=CLIENT_NS,
            duration_s=duration_s,
            connections=wrk_connections,
            threads=wrk_threads,
        )
        measurement_batches = 1
        measurement_duration_s = float(request_summary.get("duration_s") or 0.0)
    else:
        request_summary = run_parallel_http_load(
            duration_s=duration_s,
            concurrency=traffic_iterations,
        )
        measurement_batches = 1
        measurement_duration_s = float(request_summary.get("duration_s") or 0.0)
    cpu_thread.join()
    after = sample_bpf_stats([session.prog_id])
    ipip_after = link_stats(REAL_NS, "ipip0")
    sample = PhaseSample(
        index=index,
        phase=phase_name,
        driver="wrk" if use_wrk_driver else "serial_python",
        measurement_duration_s=measurement_duration_s,
        measurement_batches=measurement_batches,
        warmup_request_count=warmup_request_count,
        warmup_duration_s=float(warmup_duration_s),
        request_latencies_ms=request_latencies,
        request_failure_preview=list(request_summary.get("failure_preview") or []),
        request_summary=request_summary,
        http_request_count=int(request_summary.get("request_count", 0) or 0),
        http_success_count=int(request_summary.get("success_count", 0) or 0),
        ipip_rx_packets_delta=max(0, ipip_after["rx_packets"] - ipip_before["rx_packets"]),
        ipip_rx_bytes_delta=max(0, ipip_after["rx_bytes"] - ipip_before["rx_bytes"]),
        system_cpu=dict(system_cpu_holder),
        bpf=compute_delta(before, after),
        state_reset=state_reset,
    )
    if sample.http_request_count == 0:
        raise RuntimeError(f"live DSR measurement produced zero requests: {sample.request_failure_preview}")
    measurement_success_rate = sample.http_success_count / sample.http_request_count
    if measurement_success_rate < WARMUP_MIN_SUCCESS_RATE:
        raise RuntimeError(
            f"live DSR measurement below threshold "
            f"({sample.http_success_count}/{sample.http_request_count}="
            f"{measurement_success_rate:.1%}): {sample.request_failure_preview}"
        )
    if sample.ipip_rx_packets_delta <= 0:
        raise RuntimeError(f"ipip decap path did not receive packets: before={ipip_before} after={ipip_after}")
    if int(sample.bpf.get("summary", {}).get("total_events", 0) or 0) <= 0:
        raise RuntimeError(f"attached XDP program did not record runtime events: {sample.bpf}")
    return {
        "index": sample.index,
        "phase": sample.phase,
        "driver": sample.driver,
        "measurement_duration_s": sample.measurement_duration_s,
        "measurement_batches": sample.measurement_batches,
        "warmup": warmup,
        "warmup_request_count": sample.warmup_request_count,
        "warmup_duration_s": sample.warmup_duration_s,
        "request_summary": sample.request_summary,
        "request_failure_preview": sample.request_failure_preview,
        "request_latencies_ms": sample.request_latencies_ms,
        "http_request_count": sample.http_request_count,
        "http_success_count": sample.http_success_count,
        "ipip_before": ipip_before,
        "ipip_after": ipip_after,
        "ipip_rx_packets_delta": sample.ipip_rx_packets_delta,
        "ipip_rx_bytes_delta": sample.ipip_rx_bytes_delta,
        "system_cpu": sample.system_cpu,
        "bpf": sample.bpf,
        "state_reset": sample.state_reset,
    }


def run_katran_case(args: argparse.Namespace) -> dict[str, object]:
    resolved_bpftool = bpftool_binary()
    if Path(resolved_bpftool).exists():
        sys_path = os.environ.get("PATH", "")
        os.environ["PATH"] = f"{Path(resolved_bpftool).parent}:{sys_path}"
        os.environ["BPFTOOL_BIN"] = resolved_bpftool

    if args.katran_skip_attach:
        raise RuntimeError("--katran-skip-attach is incompatible with the live DSR topology case")

    duration_s = int(args.duration or (DEFAULT_SMOKE_DURATION_S if args.smoke else DEFAULT_DURATION_S))
    wrk_connections = max(
        1,
        int(
            args.katran_wrk_connections
            or (DEFAULT_SMOKE_WRK_CONNECTIONS if args.smoke else DEFAULT_WRK_CONNECTIONS)
        ),
    )
    wrk_threads = max(
        1,
        int(
            args.katran_wrk_threads
            or (DEFAULT_SMOKE_WRK_THREADS if args.smoke else DEFAULT_WRK_THREADS)
        ),
    )
    warmup_duration_s = float(
        args.katran_warmup_duration
        or (DEFAULT_SMOKE_WARMUP_DURATION_S if args.smoke else DEFAULT_WARMUP_DURATION_S)
    )
    traffic_iterations = max(
        1,
        int(
            args.katran_packet_repeat
            or (DEFAULT_SMOKE_PACKET_REPEAT if args.smoke else DEFAULT_PACKET_REPEAT)
        ),
    )
    sample_count = max(
        1,
        int(args.katran_samples or (DEFAULT_SMOKE_SAMPLE_COUNT if args.smoke else DEFAULT_SAMPLE_COUNT)),
    )
    use_wrk_driver = bool(args.katran_use_wrk and wrk_binary() is not None)
    warmup_request_count = (
        0
        if use_wrk_driver
        else (DEFAULT_SMOKE_WARMUP_PACKET_COUNT if args.smoke else DEFAULT_WARMUP_PACKET_COUNT)
    )
    minimum_requests = (
        0
        if use_wrk_driver
        else max(
            traffic_iterations,
            DEFAULT_SMOKE_MIN_MEASUREMENT_REQUESTS if args.smoke else DEFAULT_MIN_MEASUREMENT_REQUESTS,
        )
    )
    runner_binary = Path(args.runner).resolve()
    daemon_binary = Path(args.daemon).resolve()
    katran_object = Path(args.katran_object).resolve()
    setup_script = Path(args.setup_script).resolve()

    ensure_artifacts(runner_binary, daemon_binary)
    if not katran_object.exists():
        raise RuntimeError(f"Katran object not found: {katran_object}")

    setup_result = {
        "returncode": 0,
        "katran_server_binary": None,
        "stdout_tail": "",
        "stderr_tail": "",
    }
    if not args.skip_setup:
        setup_result = run_setup_script(setup_script)

    server_binary = resolve_katran_server_binary(args.katran_server_binary, setup_result)
    kernel_config = read_kernel_config(Path(args.kernel_config).resolve())
    object_inventory = inspect_object_program(runner_binary, katran_object, DEFAULT_PROGRAM_NAME)

    limitations: list[str] = []
    if setup_result["returncode"] != 0:
        limitations.append("Setup script returned non-zero; case continued because required tools were already available.")
    if object_inventory.get("selected_program") is None:
        limitations.append("Object inventory could not confirm balancer_ingress; continuing with direct load based on the pinned name.")
    if not kernel_config.get("net_ipip_enabled"):
        limitations.append("CONFIG_NET_IPIP is not enabled in vendor/linux-framework/.config.")
    if not kernel_config.get("dummy_enabled"):
        limitations.append("CONFIG_DUMMY is not enabled in vendor/linux-framework/.config.")
    if not kernel_config.get("veth_enabled"):
        limitations.append("CONFIG_VETH is not enabled in vendor/linux-framework/.config.")
    if server_binary is None:
        limitations.append(
            "Katran userspace server binary is not present; this case is running in standalone_direct_map_emulation via bpftool and pinned maps, not the official Katran userspace server path."
        )
    if bool(args.katran_use_wrk) and not use_wrk_driver:
        limitations.append("wrk was requested but is unavailable; falling back to the built-in parallel Python HTTP client.")
    if not use_wrk_driver:
        limitations.append(
            "Traffic generator uses a built-in parallel Python short-flow client, so application throughput includes guest-side client overhead."
        )
    else:
        limitations.append(
            "Traffic generator uses wrk against an HTTP/1.0 server, so the measured req/s is a short-flow connection-churn metric rather than bulk keep-alive throughput."
        )
    limitations.append(
        "Phase order remains stock then rejit inside each same-image cycle; reverse-order randomization would require an explicit stock restore path or a second live load."
    )

    with enable_bpf_stats():
        cycle_results: list[dict[str, object]] = []
        session_metadata: dict[str, object] = {}
        topology_metadata: dict[str, object] = {}
        server_metadata: dict[str, object] = {}
        map_config: dict[str, object] = {}
        test_run_validation: dict[str, object] = {}
        for cycle_index in range(sample_count):
            with KatranDsrTopology(
                args.katran_iface,
                router_peer_iface=args.katran_router_peer_iface,
            ) as topology:
                with NamespaceHttpServer(REAL_NS, VIP_IP, VIP_PORT) as http_server:
                    with KatranDirectSession(
                        object_path=katran_object,
                        program_name=DEFAULT_PROGRAM_NAME,
                        iface=args.katran_iface,
                        attach=True,
                        bpftool=resolved_bpftool,
                    ) as session:
                        if session.attach_error:
                            raise RuntimeError(f"failed to attach Katran XDP program: {session.attach_error}")
                        map_config = configure_katran_maps(session)
                        cycle_test_run = run_katran_prog_test_run(session)
                        time.sleep(TOPOLOGY_SETTLE_S)
                        prog_ids = [session.prog_id]
                        baseline_sample = measure_phase(
                            index=cycle_index,
                            phase_name="stock",
                            session=session,
                            traffic_iterations=traffic_iterations,
                            duration_s=duration_s,
                            minimum_requests=minimum_requests,
                            warmup_request_count=warmup_request_count,
                            warmup_duration_s=warmup_duration_s,
                            use_wrk_driver=use_wrk_driver,
                            wrk_connections=wrk_connections,
                            wrk_threads=wrk_threads,
                        )
                        baseline_phase = {
                            "samples": [baseline_sample],
                            "summary": build_phase_summary([baseline_sample]),
                        }
                        scan_results = scan_programs(prog_ids, daemon_binary)
                        rejit_result = apply_daemon_rejit(daemon_binary, prog_ids)
                        post_rejit_phase: dict[str, object] | None = None
                        if rejit_result["applied"]:
                            try:
                                post_rejit_sample = measure_phase(
                                    index=cycle_index,
                                    phase_name="post_rejit",
                                    session=session,
                                    traffic_iterations=traffic_iterations,
                                    duration_s=duration_s,
                                    minimum_requests=minimum_requests,
                                    warmup_request_count=warmup_request_count,
                                    warmup_duration_s=warmup_duration_s,
                                    use_wrk_driver=use_wrk_driver,
                                    wrk_connections=wrk_connections,
                                    wrk_threads=wrk_threads,
                                )
                                post_rejit_phase = {
                                    "samples": [post_rejit_sample],
                                    "summary": build_phase_summary([post_rejit_sample]),
                                }
                            except RuntimeError as rejit_exc:
                                limitations.append(
                                    f"Post-REJIT measurement failed (cycle {cycle_index}): {rejit_exc}"
                                )
                        cycle_results.append(
                            {
                                "cycle_index": cycle_index,
                                "topology": topology.metadata(),
                                "http_server": http_server.metadata(),
                                "live_program": session.metadata(),
                                "scan_results": {str(key): value for key, value in scan_results.items()},
                                "test_run_validation": cycle_test_run,
                                "baseline": baseline_phase,
                                "rejit_result": rejit_result,
                                "post_rejit": post_rejit_phase,
                                "comparison": compare_phases(baseline_phase, post_rejit_phase),
                            }
                        )
                        if not session_metadata:
                            session_metadata = session.metadata()
                        if not topology_metadata:
                            topology_metadata = topology.metadata()
                        if not server_metadata:
                            server_metadata = http_server.metadata()
                        if not test_run_validation:
                            test_run_validation = cycle_test_run

    baseline_samples = [
        sample
        for cycle in cycle_results
        for sample in (cycle.get("baseline") or {}).get("samples") or []
    ]
    baseline = {
        "samples": baseline_samples,
        "summary": build_phase_summary(baseline_samples),
    }
    post_rejit_samples = [
        sample
        for cycle in cycle_results
        for sample in (cycle.get("post_rejit") or {}).get("samples") or []
    ]
    post_rejit: dict[str, object] | None = None
    if post_rejit_samples:
        post_rejit = {
            "samples": post_rejit_samples,
            "summary": build_phase_summary(post_rejit_samples),
        }

    payload = {
        "generated_at": datetime.now(timezone.utc).isoformat(),
        "mode": "katran_dsr_direct_map_connection_churn_same_image_paired",
        "control_plane_mode": "bpftool_direct_map",
        "traffic_driver": "wrk" if use_wrk_driver else "python_parallel",
        "workload_model": "http_short_flow_connection_churn",
        "smoke": bool(args.smoke),
        "duration_s": duration_s,
        "packet_repeat": traffic_iterations,
        "client_concurrency": traffic_iterations,
        "wrk_connections": wrk_connections if use_wrk_driver else None,
        "wrk_threads": wrk_threads if use_wrk_driver else None,
        "sample_count": sample_count,
        "warmup_packet_count": warmup_request_count,
        "warmup_duration_s": warmup_duration_s,
        "min_measurement_requests": minimum_requests,
        "same_image_measurement": True,
        "state_reset_strategy": "reset mutable stats/fallback maps before each phase warmup",
        "katran_object": relpath(katran_object),
        "katran_server_binary": server_binary,
        "setup": setup_result,
        "host": host_metadata(),
        "kernel_config": kernel_config,
        "object_inventory": object_inventory,
        "topology": topology_metadata,
        "map_configuration": map_config,
        "test_run_validation": test_run_validation,
        "live_program": session_metadata,
        "http_server": server_metadata,
        "baseline": baseline,
        "paired_cycles": cycle_results,
        "scan_results": {str(cycle["cycle_index"]): cycle["scan_results"] for cycle in cycle_results},
        "post_rejit": post_rejit,
        "comparison": compare_phases(baseline, post_rejit),
        "limitations": limitations,
    }
    return payload


def build_case_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(description="Run the Katran DSR end-to-end benchmark.")
    parser.add_argument("--setup-script", default=str(DEFAULT_SETUP_SCRIPT))
    parser.add_argument("--output-json", default=str(DEFAULT_OUTPUT_JSON))
    parser.add_argument("--output-md", default=str(DEFAULT_OUTPUT_MD))
    parser.add_argument("--katran-object", default=str(DEFAULT_KATRAN_OBJECT))
    parser.add_argument("--katran-server-binary")
    parser.add_argument("--katran-iface", default=DEFAULT_INTERFACE)
    parser.add_argument("--katran-router-peer-iface")
    parser.add_argument("--katran-packet-repeat", type=int)
    parser.add_argument("--katran-use-wrk", action="store_true")
    parser.add_argument("--katran-wrk-connections", type=int)
    parser.add_argument("--katran-wrk-threads", type=int)
    parser.add_argument("--katran-warmup-duration", type=float)
    parser.add_argument("--katran-samples", type=int)
    parser.add_argument("--katran-skip-attach", action="store_true")
    parser.add_argument("--kernel-config", default=str(DEFAULT_KERNEL_CONFIG))
    parser.add_argument("--runner", default=str(DEFAULT_RUNNER))
    parser.add_argument("--daemon", default=str(DEFAULT_DAEMON))
    parser.add_argument("--duration", type=int)
    parser.add_argument("--smoke", action="store_true")
    parser.add_argument("--skip-setup", action="store_true")
    return parser


def main(argv: Sequence[str] | None = None) -> int:
    parser = build_case_parser()
    args = parser.parse_args(argv)
    payload = run_katran_case(args)
    if args.output_json == str(DEFAULT_OUTPUT_JSON) and args.smoke:
        output_json = smoke_output_path(RESULTS_DIR, "katran")
    else:
        output_json = Path(args.output_json).resolve()
    persist_results(payload, output_json, Path(args.output_md).resolve(), build_markdown)
    print(json.dumps(payload, indent=2, sort_keys=True))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
