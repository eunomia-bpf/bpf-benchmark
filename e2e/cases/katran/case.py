#!/usr/bin/env python3
from __future__ import annotations

import argparse
import ctypes
import ctypes.util
import errno
import json
import os
import platform
import shutil
import socket
import statistics
import struct
import subprocess
import sys
import tempfile
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
    chown_to_invoking_user,
    ensure_root,
    resolve_bpftool_binary,
    run_command,
    run_json_command,
    smoke_output_path,
    tail_text,
    which,
    write_json,
    write_text,
)
from runner.libs.metrics import compute_delta, enable_bpf_stats, sample_bpf_stats  # noqa: E402
from runner.libs.recompile import PolicyTarget, apply_recompile, resolve_policy_files, scan_programs  # noqa: E402

try:  # noqa: E402
    from runner.libs.inventory import discover_object_programs
except ModuleNotFoundError:  # noqa: E402
    sys.path.insert(0, str(ROOT_DIR / "micro"))
    from runner.libs.inventory import discover_object_programs


DEFAULT_SETUP_SCRIPT = Path(__file__).with_name("setup.sh")
DEFAULT_OUTPUT_JSON = authoritative_output_path(RESULTS_DIR, "katran")
DEFAULT_OUTPUT_MD = ROOT_DIR / "e2e" / "results" / "katran-e2e-real.md"
DEFAULT_KATRAN_OBJECT = ROOT_DIR / "corpus" / "build" / "katran" / "balancer.bpf.o"
DEFAULT_POLICY_FILE = Path(__file__).with_name("balancer_ingress.e2e.policy.yaml")
DEFAULT_RUNNER = ROOT_DIR / "runner" / "build" / "micro_exec"
DEFAULT_SCANNER = ROOT_DIR / "scanner" / "build" / "bpf-jit-scanner"
DEFAULT_KERNEL_CONFIG = ROOT_DIR / "vendor" / "linux-framework" / ".config"
DEFAULT_PROGRAM_NAME = "balancer_ingress"
DEFAULT_INTERFACE = "katran0"
DEFAULT_DURATION_S = 10
DEFAULT_SMOKE_DURATION_S = 3
DEFAULT_PACKET_REPEAT = 25
DEFAULT_SMOKE_PACKET_REPEAT = 25
DEFAULT_SAMPLE_COUNT = 3
DEFAULT_SMOKE_SAMPLE_COUNT = 1
DEFAULT_WARMUP_PACKET_COUNT = 100
DEFAULT_SMOKE_WARMUP_PACKET_COUNT = 100
DEFAULT_MIN_MEASUREMENT_REQUESTS = 1000
DEFAULT_SMOKE_MIN_MEASUREMENT_REQUESTS = 100
REQUEST_FAILURE_PREVIEW_LIMIT = 5
WARMUP_MAX_ATTEMPT_FACTOR = 3

TCP_PROTO = socket.IPPROTO_TCP
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
HTTP_TIMEOUT_S = 3.0
SERVER_START_TIMEOUT_S = 10.0
TOPOLOGY_SETTLE_S = 1.0

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
    measurement_duration_s: float
    measurement_batches: int
    warmup_request_count: int
    request_latencies_ms: list[float]
    request_failure_preview: list[dict[str, object]]
    request_summary: dict[str, object]
    http_request_count: int
    http_success_count: int
    ipip_rx_packets_delta: int
    ipip_rx_bytes_delta: int
    bpf: dict[str, object]
    state_reset: dict[str, object]


def relpath(path: Path) -> str:
    try:
        return path.resolve().relative_to(ROOT_DIR).as_posix()
    except ValueError:
        return str(path.resolve())


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


def summarize_numbers(values: Sequence[float | int | None]) -> dict[str, float | int | None]:
    filtered = [float(value) for value in values if value is not None]
    if not filtered:
        return {
            "count": 0,
            "mean": None,
            "median": None,
            "min": None,
            "max": None,
        }
    return {
        "count": len(filtered),
        "mean": statistics.mean(filtered),
        "median": statistics.median(filtered),
        "min": min(filtered),
        "max": max(filtered),
    }


def percent_delta(before: object, after: object) -> float | None:
    if before in (None, 0) or after is None:
        return None
    return ((float(after) - float(before)) / float(before)) * 100.0


def speedup_ratio(before: object, after: object) -> float | None:
    if before in (None, 0) or after in (None, 0):
        return None
    return float(before) / float(after)


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
        "latency_ms": summarize_numbers(latencies),
        "latencies_ms": latencies,
        "failure_preview": failures,
    }


def build_phase_summary(samples: Sequence[Mapping[str, object]]) -> dict[str, object]:
    latencies: list[float | int | None] = []
    for sample in samples:
        latencies.extend(extract_request_latencies(sample))
    total_requests = sum(int(sample.get("http_request_count", 0) or 0) for sample in samples)
    total_successes = sum(int(sample.get("http_success_count", 0) or 0) for sample in samples)
    return {
        "http_requests": total_requests,
        "http_successes": total_successes,
        "http_all_succeeded": total_requests > 0 and total_requests == total_successes,
        "latency_ms": summarize_numbers(latencies),
        "measurement_duration_s": summarize_numbers([sample.get("measurement_duration_s") for sample in samples]),
        "measurement_batches": summarize_numbers([sample.get("measurement_batches") for sample in samples]),
        "warmup_http_requests": summarize_numbers([sample.get("warmup_request_count") for sample in samples]),
        "ipip_rx_packets_delta": summarize_numbers(
            [sample.get("ipip_rx_packets_delta") for sample in samples]
        ),
        "bpf_avg_ns_per_run": summarize_numbers(
            [((sample.get("bpf") or {}).get("summary", {}).get("avg_ns_per_run")) for sample in samples]
        ),
        "events": summarize_numbers(
            [((sample.get("bpf") or {}).get("summary", {}).get("total_events")) for sample in samples]
        ),
    }


def compare_phase_summaries(
    baseline_summary: Mapping[str, object],
    post_summary: Mapping[str, object] | None,
) -> dict[str, object]:
    if not post_summary:
        return {"comparable": False, "reason": "recompile did not apply successfully"}
    baseline_latency = (baseline_summary.get("latency_ms") or {}).get("median")
    post_latency = (post_summary.get("latency_ms") or {}).get("median")
    baseline_bpf = (baseline_summary.get("bpf_avg_ns_per_run") or {}).get("median")
    post_bpf = (post_summary.get("bpf_avg_ns_per_run") or {}).get("median")
    baseline_events = (baseline_summary.get("events") or {}).get("median")
    post_events = (post_summary.get("events") or {}).get("median")
    return {
        "comparable": True,
        "aggregation": "paired_cycle_median",
        "http_successes_delta_pct": percent_delta(
            baseline_summary.get("http_successes"),
            post_summary.get("http_successes"),
        ),
        "latency_ms_delta_pct": percent_delta(baseline_latency, post_latency),
        "bpf_avg_ns_per_run_delta_pct": percent_delta(baseline_bpf, post_bpf),
        "bpf_speedup_ratio": speedup_ratio(baseline_bpf, post_bpf),
        "events_delta_pct": percent_delta(baseline_events, post_events),
    }


def compare_phases(baseline: Mapping[str, object], post: Mapping[str, object] | None) -> dict[str, object]:
    if not post:
        return {"comparable": False, "reason": "recompile did not apply successfully"}
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
        f"- Request batch size: `{payload['packet_repeat']}`",
        f"- Warmup requests per phase: `{payload['warmup_packet_count']}`",
        f"- Minimum requests per phase: `{payload['min_measurement_requests']}`",
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
        f"- ipip rx packets delta: `{((payload['baseline'].get('summary') or {}).get('ipip_rx_packets_delta'))}`",
        f"- bpf avg ns/run: `{((payload['baseline'].get('summary') or {}).get('bpf_avg_ns_per_run'))}`",
        f"- total events: `{((payload['baseline'].get('summary') or {}).get('events'))}`",
        "",
        "## Recompile",
        "",
        f"- Applied cycles: `{payload['recompile_summary']['applied_cycles']}` / `{payload['recompile_summary']['requested_cycles']}`",
        f"- Applied successfully on all cycles: `{payload['recompile_summary']['all_cycles_applied']}`",
    ]
    if payload["recompile_summary"].get("errors"):
        lines.append(f"- Errors: `{payload['recompile_summary']['errors']}`")
    if payload.get("post_rejit"):
        lines.extend(
            [
                "",
                "## Post-ReJIT",
                "",
                f"- HTTP successes: `{((payload['post_rejit'].get('summary') or {}).get('http_successes'))}` / `{((payload['post_rejit'].get('summary') or {}).get('http_requests'))}`",
                f"- ipip rx packets delta: `{((payload['post_rejit'].get('summary') or {}).get('ipip_rx_packets_delta'))}`",
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
                f"- Median BPF delta: `{payload['comparison'].get('bpf_avg_ns_per_run_delta_pct')}`",
                f"- Median BPF speedup ratio (stock/reJIT): `{payload['comparison'].get('bpf_speedup_ratio')}`",
            ]
        )
    if payload.get("limitations"):
        lines.extend(["", "## Limitations", ""])
        for item in payload.get("limitations") or []:
            lines.append(f"- {item}")
    return "\n".join(lines) + "\n"


def persist_results(payload: Mapping[str, object], output_json: Path, output_md: Path) -> None:
    write_json(output_json, payload)
    write_text(output_md, build_markdown(payload))
    chown_to_invoking_user(output_md)


def ensure_artifacts(runner_binary: Path, scanner_binary: Path) -> None:
    if not runner_binary.exists():
        run_command(["make", "runner"], timeout=1800)
    if not scanner_binary.exists():
        run_command(
            ["cmake", "-S", "scanner", "-B", "scanner/build", "-DCMAKE_BUILD_TYPE=Release"],
            timeout=600,
        )
        run_command(
            ["cmake", "--build", "scanner/build", "--target", "bpf-jit-scanner", "-j"],
            timeout=1800,
        )


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
        if stripped == "CONFIG_NET_IPIP=y":
            status["net_ipip_enabled"] = True
        if stripped == "CONFIG_NET_IPGRE=y":
            status["net_ipgre_enabled"] = True
        if stripped == "CONFIG_DUMMY=y":
            status["dummy_enabled"] = True
        if stripped == "CONFIG_VETH=y":
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


def link_exists(name: str) -> bool:
    return Path("/sys/class/net").joinpath(name).exists()


def ns_command(
    namespace: str,
    command: Sequence[str],
    *,
    check: bool = True,
    timeout: int | float | None = 30,
) -> subprocess.CompletedProcess[str]:
    return run_command(["ip", "netns", "exec", namespace, *command], check=check, timeout=timeout)


def set_ns_sysctl(namespace: str, key: str, value: int) -> None:
    completed = ns_command(
        namespace,
        ["sysctl", "-q", "-w", f"{key}={value}"],
        check=False,
        timeout=15,
    )
    if completed.returncode == 0:
        return
    proc_key = key.replace(".", "/")
    ns_command(
        namespace,
        ["sh", "-c", f"printf '%s' '{value}' > /proc/sys/{proc_key}"],
        timeout=15,
    )


def set_link_mac(namespace: str | None, iface: str, mac: str) -> None:
    if namespace is None:
        run_command(["ip", "link", "set", "dev", iface, "address", mac], timeout=15)
        return
    ns_command(namespace, ["ip", "link", "set", "dev", iface, "address", mac], timeout=15)


def get_link_json(namespace: str | None, iface: str) -> dict[str, object]:
    command = ["ip", "-j", "-details", "-s", "link", "show", "dev", iface]
    if namespace is not None:
        payload = run_json_command(["ip", "netns", "exec", namespace, *command], timeout=30)
    else:
        payload = run_json_command(command, timeout=30)
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
        for namespace in (ROUTER_NS, CLIENT_NS, REAL_NS):
            run_command(["ip", "netns", "add", namespace], timeout=15)

        if self.router_peer_iface is None:
            run_command(["ip", "link", "add", self.iface, "type", "veth", "peer", "name", ROUTER_LB_IFACE], timeout=15)
            run_command(["ip", "link", "set", ROUTER_LB_IFACE, "netns", ROUTER_NS], timeout=15)
        else:
            if self.router_peer_iface == self.iface:
                raise RuntimeError("router peer iface must differ from Katran ingress iface")
            if not link_exists(self.iface):
                raise RuntimeError(f"network interface does not exist: {self.iface}")
            if not link_exists(self.router_peer_iface):
                raise RuntimeError(f"router peer interface does not exist: {self.router_peer_iface}")
            run_command(["ip", "link", "set", self.router_peer_iface, "netns", ROUTER_NS], timeout=15)
            ns_command(ROUTER_NS, ["ip", "link", "set", "dev", self.router_peer_iface, "name", ROUTER_LB_IFACE], timeout=15)

        run_command(["ip", "link", "add", ROUTER_CLIENT_IFACE, "type", "veth", "peer", "name", CLIENT_IFACE], timeout=15)
        run_command(["ip", "link", "set", ROUTER_CLIENT_IFACE, "netns", ROUTER_NS], timeout=15)
        run_command(["ip", "link", "set", CLIENT_IFACE, "netns", CLIENT_NS], timeout=15)

        run_command(["ip", "link", "add", ROUTER_REAL_IFACE, "type", "veth", "peer", "name", REAL_IFACE], timeout=15)
        run_command(["ip", "link", "set", ROUTER_REAL_IFACE, "netns", ROUTER_NS], timeout=15)
        run_command(["ip", "link", "set", REAL_IFACE, "netns", REAL_NS], timeout=15)

        set_link_mac(None, self.iface, LB_MAC)
        set_link_mac(ROUTER_NS, ROUTER_LB_IFACE, ROUTER_LB_MAC)
        set_link_mac(ROUTER_NS, ROUTER_CLIENT_IFACE, ROUTER_CLIENT_MAC)
        set_link_mac(CLIENT_NS, CLIENT_IFACE, CLIENT_MAC)
        set_link_mac(ROUTER_NS, ROUTER_REAL_IFACE, ROUTER_REAL_MAC)
        set_link_mac(REAL_NS, REAL_IFACE, REAL_MAC)

        for namespace in (ROUTER_NS, CLIENT_NS, REAL_NS):
            ns_command(namespace, ["ip", "link", "set", "lo", "up"], timeout=15)

        run_command(["ip", "addr", "add", f"{LB_IP}/24", "dev", self.iface], timeout=15)
        run_command(["ip", "link", "set", "dev", self.iface, "up"], timeout=15)

        ns_command(ROUTER_NS, ["ip", "addr", "add", f"{ROUTER_LB_IP}/24", "dev", ROUTER_LB_IFACE], timeout=15)
        ns_command(ROUTER_NS, ["ip", "addr", "add", f"{ROUTER_CLIENT_IP}/24", "dev", ROUTER_CLIENT_IFACE], timeout=15)
        ns_command(ROUTER_NS, ["ip", "addr", "add", f"{ROUTER_REAL_IP}/24", "dev", ROUTER_REAL_IFACE], timeout=15)
        ns_command(ROUTER_NS, ["ip", "link", "set", "dev", ROUTER_LB_IFACE, "up"], timeout=15)
        ns_command(ROUTER_NS, ["ip", "link", "set", "dev", ROUTER_CLIENT_IFACE, "up"], timeout=15)
        ns_command(ROUTER_NS, ["ip", "link", "set", "dev", ROUTER_REAL_IFACE, "up"], timeout=15)

        ns_command(CLIENT_NS, ["ip", "addr", "add", f"{CLIENT_IP}/24", "dev", CLIENT_IFACE], timeout=15)
        ns_command(CLIENT_NS, ["ip", "link", "set", "dev", CLIENT_IFACE, "up"], timeout=15)

        ns_command(REAL_NS, ["ip", "addr", "add", f"{REAL_IP}/24", "dev", REAL_IFACE], timeout=15)
        ns_command(REAL_NS, ["ip", "link", "set", "dev", REAL_IFACE, "up"], timeout=15)
        ns_command(REAL_NS, ["ip", "addr", "add", f"{VIP_IP}/32", "dev", "lo"], timeout=15)
        ns_command(REAL_NS, ["ip", "link", "add", "name", "ipip0", "type", "ipip", "external"], timeout=15)
        ns_command(REAL_NS, ["ip", "addr", "add", f"{IPIP_DUMMY_IP}/32", "dev", "ipip0"], timeout=15)
        ns_command(REAL_NS, ["ip", "link", "set", "dev", "ipip0", "up"], timeout=15)

        ns_command(CLIENT_NS, ["ip", "route", "add", "default", "via", ROUTER_CLIENT_IP, "dev", CLIENT_IFACE], timeout=15)
        ns_command(REAL_NS, ["ip", "route", "add", "default", "via", ROUTER_REAL_IP, "dev", REAL_IFACE], timeout=15)
        ns_command(ROUTER_NS, ["ip", "route", "add", f"{VIP_IP}/32", "via", LB_IP, "dev", ROUTER_LB_IFACE], timeout=15)

        ns_command(
            CLIENT_NS,
            ["ip", "neigh", "replace", ROUTER_CLIENT_IP, "lladdr", ROUTER_CLIENT_MAC, "dev", CLIENT_IFACE, "nud", "permanent"],
            timeout=15,
        )
        ns_command(
            ROUTER_NS,
            ["ip", "neigh", "replace", LB_IP, "lladdr", LB_MAC, "dev", ROUTER_LB_IFACE, "nud", "permanent"],
            timeout=15,
        )
        ns_command(
            ROUTER_NS,
            ["ip", "neigh", "replace", REAL_IP, "lladdr", REAL_MAC, "dev", ROUTER_REAL_IFACE, "nud", "permanent"],
            timeout=15,
        )
        ns_command(
            REAL_NS,
            ["ip", "neigh", "replace", ROUTER_REAL_IP, "lladdr", ROUTER_REAL_MAC, "dev", REAL_IFACE, "nud", "permanent"],
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
            run_command(["ip", "link", "del", self.iface], check=False, timeout=15)
        if self.router_peer_iface is not None:
            run_command(
                ["ip", "netns", "exec", ROUTER_NS, "ip", "link", "set", "dev", ROUTER_LB_IFACE, "netns", "1"],
                check=False,
                timeout=15,
            )
        for namespace in (REAL_NS, CLIENT_NS, ROUTER_NS):
            run_command(["ip", "netns", "del", namespace], check=False, timeout=15)
        if self.router_peer_iface is not None and link_exists(ROUTER_LB_IFACE) and not link_exists(self.router_peer_iface):
            run_command(["ip", "link", "set", "dev", ROUTER_LB_IFACE, "name", self.router_peer_iface], check=False, timeout=15)

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
                "ip",
                "netns",
                "exec",
                self.namespace,
                "python3",
                "-u",
                "-m",
                "http.server",
                str(self.port),
                "--bind",
                self.bind_ip,
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
            completed = ns_command(
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
        for mode in ("xdp", "xdpgeneric"):
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


def measure_phase(
    *,
    index: int,
    phase_name: str,
    session: KatranDirectSession,
    traffic_iterations: int,
    duration_s: int,
    minimum_requests: int,
    warmup_request_count: int,
) -> dict[str, object]:
    state_reset = reset_katran_state(session)
    warmup = run_warmup_requests(warmup_request_count, batch_size=traffic_iterations)
    before = sample_bpf_stats([session.prog_id])
    ipip_before = link_stats(REAL_NS, "ipip0")
    requests, measurement_batches, measurement_duration_s = execute_http_measurement_loop(
        batch_size=traffic_iterations,
        duration_s=duration_s,
        minimum_requests=minimum_requests,
    )
    request_summary = summarize_request_records(requests)
    request_latencies = list(request_summary.pop("latencies_ms", []))
    after = sample_bpf_stats([session.prog_id])
    ipip_after = link_stats(REAL_NS, "ipip0")
    sample = PhaseSample(
        index=index,
        phase=phase_name,
        measurement_duration_s=measurement_duration_s,
        measurement_batches=measurement_batches,
        warmup_request_count=warmup_request_count,
        request_latencies_ms=request_latencies,
        request_failure_preview=list(request_summary.get("failure_preview") or []),
        request_summary=request_summary,
        http_request_count=int(request_summary.get("request_count", 0) or 0),
        http_success_count=int(request_summary.get("success_count", 0) or 0),
        ipip_rx_packets_delta=max(0, ipip_after["rx_packets"] - ipip_before["rx_packets"]),
        ipip_rx_bytes_delta=max(0, ipip_after["rx_bytes"] - ipip_before["rx_bytes"]),
        bpf=compute_delta(before, after),
        state_reset=state_reset,
    )
    if sample.http_request_count == 0 or sample.http_success_count != sample.http_request_count:
        raise RuntimeError(f"live DSR request validation failed: {sample.request_failure_preview}")
    if sample.ipip_rx_packets_delta <= 0:
        raise RuntimeError(f"ipip decap path did not receive packets: before={ipip_before} after={ipip_after}")
    if int(sample.bpf.get("summary", {}).get("total_events", 0) or 0) <= 0:
        raise RuntimeError(f"attached XDP program did not record runtime events: {sample.bpf}")
    return {
        "index": sample.index,
        "phase": sample.phase,
        "measurement_duration_s": sample.measurement_duration_s,
        "measurement_batches": sample.measurement_batches,
        "warmup": warmup,
        "warmup_request_count": sample.warmup_request_count,
        "request_summary": sample.request_summary,
        "request_failure_preview": sample.request_failure_preview,
        "request_latencies_ms": sample.request_latencies_ms,
        "http_request_count": sample.http_request_count,
        "http_success_count": sample.http_success_count,
        "ipip_before": ipip_before,
        "ipip_after": ipip_after,
        "ipip_rx_packets_delta": sample.ipip_rx_packets_delta,
        "ipip_rx_bytes_delta": sample.ipip_rx_bytes_delta,
        "bpf": sample.bpf,
        "state_reset": sample.state_reset,
    }


def run_katran_case(args: argparse.Namespace) -> dict[str, object]:
    ensure_root([str(Path(sys.argv[0]).resolve()), *sys.argv[1:]])
    resolved_bpftool = bpftool_binary()
    if Path(resolved_bpftool).exists():
        sys_path = os.environ.get("PATH", "")
        os.environ["PATH"] = f"{Path(resolved_bpftool).parent}:{sys_path}"
        os.environ["BPFTOOL_BIN"] = resolved_bpftool

    if args.katran_skip_attach:
        raise RuntimeError("--katran-skip-attach is incompatible with the live DSR topology case")

    duration_s = int(args.duration or (DEFAULT_SMOKE_DURATION_S if args.smoke else DEFAULT_DURATION_S))
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
    warmup_request_count = DEFAULT_SMOKE_WARMUP_PACKET_COUNT if args.smoke else DEFAULT_WARMUP_PACKET_COUNT
    minimum_requests = max(
        traffic_iterations,
        DEFAULT_SMOKE_MIN_MEASUREMENT_REQUESTS if args.smoke else DEFAULT_MIN_MEASUREMENT_REQUESTS,
    )
    runner_binary = Path(args.runner).resolve()
    scanner_binary = Path(args.scanner).resolve()
    katran_object = Path(args.katran_object).resolve()
    policy_file = Path(args.katran_policy).resolve()
    setup_script = Path(args.setup_script).resolve()

    ensure_artifacts(runner_binary, scanner_binary)
    if not katran_object.exists():
        raise RuntimeError(f"Katran object not found: {katran_object}")
    if not policy_file.exists():
        raise RuntimeError(f"Katran policy not found: {policy_file}")

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
    limitations.append(
        "Phase order remains stock then recompile inside each same-image cycle; reverse-order randomization would require an explicit stock restore path or a second live load."
    )

    with enable_bpf_stats():
        cycle_results: list[dict[str, object]] = []
        session_metadata: dict[str, object] = {}
        topology_metadata: dict[str, object] = {}
        server_metadata: dict[str, object] = {}
        map_config: dict[str, object] = {}
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
                        time.sleep(TOPOLOGY_SETTLE_S)
                        prog_ids = [session.prog_id]
                        policy_files = resolve_policy_files(
                            [
                                PolicyTarget(
                                    prog_id=session.prog_id,
                                    object_path=katran_object,
                                    program_name=DEFAULT_PROGRAM_NAME,
                                    policy_file=policy_file,
                                )
                            ]
                        )
                        baseline_sample = measure_phase(
                            index=cycle_index,
                            phase_name="stock",
                            session=session,
                            traffic_iterations=traffic_iterations,
                            duration_s=duration_s,
                            minimum_requests=minimum_requests,
                            warmup_request_count=warmup_request_count,
                        )
                        baseline_phase = {
                            "samples": [baseline_sample],
                            "summary": build_phase_summary([baseline_sample]),
                        }
                        scan_results = scan_programs(prog_ids, scanner_binary)
                        recompile_results = apply_recompile(
                            prog_ids,
                            scanner_binary,
                            policy_files=policy_files,
                        )
                        applied = sum(1 for record in recompile_results.values() if record.get("applied"))
                        post_sample = (
                            measure_phase(
                                index=cycle_index,
                                phase_name="recompile",
                                session=session,
                                traffic_iterations=traffic_iterations,
                                duration_s=duration_s,
                                minimum_requests=minimum_requests,
                                warmup_request_count=warmup_request_count,
                            )
                            if applied > 0
                            else None
                        )
                        post_phase = (
                            {
                                "samples": [post_sample],
                                "summary": build_phase_summary([post_sample]),
                            }
                            if post_sample is not None
                            else None
                        )
                        cycle_results.append(
                            {
                                "cycle_index": cycle_index,
                                "topology": topology.metadata(),
                                "http_server": http_server.metadata(),
                                "live_program": session.metadata(),
                                "policy_matches": {str(key): value for key, value in policy_files.items()},
                                "scan_results": {str(key): value for key, value in scan_results.items()},
                                "recompile_results": {str(key): value for key, value in recompile_results.items()},
                                "recompile_summary": {
                                    "requested_programs": 1,
                                    "applied_programs": applied,
                                    "applied": applied > 0,
                                    "errors": sorted(
                                        {
                                            record.get("error", "")
                                            for record in recompile_results.values()
                                            if record.get("error")
                                        }
                                    ),
                                },
                                "baseline": baseline_phase,
                                "post_rejit": post_phase,
                                "comparison": compare_phases(baseline_phase, post_phase),
                            }
                        )
                        if not session_metadata:
                            session_metadata = session.metadata()
                        if not topology_metadata:
                            topology_metadata = topology.metadata()
                        if not server_metadata:
                            server_metadata = http_server.metadata()

    baseline_samples = [
        sample
        for cycle in cycle_results
        for sample in (cycle.get("baseline") or {}).get("samples") or []
    ]
    post_samples = [
        sample
        for cycle in cycle_results
        for sample in (cycle.get("post_rejit") or {}).get("samples") or []
    ]
    baseline = {
        "samples": baseline_samples,
        "summary": build_phase_summary(baseline_samples),
    }
    post = (
        {
            "samples": post_samples,
            "summary": build_phase_summary(post_samples),
        }
        if post_samples
        else None
    )
    applied_cycles = sum(1 for cycle in cycle_results if (cycle.get("recompile_summary") or {}).get("applied"))
    if applied_cycles == 0:
        limitations.append(
            "BPF_PROG_JIT_RECOMPILE did not apply on this kernel for balancer_ingress; post-ReJIT measurement was skipped."
        )
    elif applied_cycles != sample_count:
        limitations.append(
            f"BPF_PROG_JIT_RECOMPILE applied on {applied_cycles}/{sample_count} cycles; top-level post-ReJIT summary includes only successful cycles."
        )

    payload = {
        "generated_at": datetime.now(timezone.utc).isoformat(),
        "mode": "katran_dsr_direct_map_emulation_same_image_paired",
        "control_plane_mode": "bpftool_direct_map",
        "smoke": bool(args.smoke),
        "duration_s": duration_s,
        "packet_repeat": traffic_iterations,
        "sample_count": sample_count,
        "warmup_packet_count": warmup_request_count,
        "min_measurement_requests": minimum_requests,
        "same_image_measurement": True,
        "state_reset_strategy": "reset mutable stats/fallback maps before each phase warmup",
        "katran_object": relpath(katran_object),
        "katran_policy": relpath(policy_file),
        "katran_server_binary": server_binary,
        "setup": setup_result,
        "host": host_metadata(),
        "kernel_config": kernel_config,
        "object_inventory": object_inventory,
        "topology": topology_metadata,
        "map_configuration": map_config,
        "live_program": session_metadata,
        "http_server": server_metadata,
        "baseline": baseline,
        "paired_cycles": cycle_results,
        "policy_matches": {str(cycle["cycle_index"]): cycle["policy_matches"] for cycle in cycle_results},
        "scan_results": {str(cycle["cycle_index"]): cycle["scan_results"] for cycle in cycle_results},
        "recompile_results": {str(cycle["cycle_index"]): cycle["recompile_results"] for cycle in cycle_results},
        "recompile_summary": {
            "requested_programs_per_cycle": 1,
            "requested_cycles": sample_count,
            "applied_cycles": applied_cycles,
            "applied": applied_cycles > 0,
            "all_cycles_applied": applied_cycles == sample_count,
            "errors": sorted(
                {
                    error
                    for cycle in cycle_results
                    for error in ((cycle.get("recompile_summary") or {}).get("errors") or [])
                    if error
                }
            ),
        },
        "post_rejit": post,
        "comparison": compare_phases(baseline, post),
        "limitations": limitations,
    }
    return payload


def build_case_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(description="Run the Katran DSR end-to-end benchmark.")
    parser.add_argument("--setup-script", default=str(DEFAULT_SETUP_SCRIPT))
    parser.add_argument("--output-json", default=str(DEFAULT_OUTPUT_JSON))
    parser.add_argument("--output-md", default=str(DEFAULT_OUTPUT_MD))
    parser.add_argument("--katran-object", default=str(DEFAULT_KATRAN_OBJECT))
    parser.add_argument("--katran-policy", default=str(DEFAULT_POLICY_FILE))
    parser.add_argument("--katran-server-binary")
    parser.add_argument("--katran-iface", default=DEFAULT_INTERFACE)
    parser.add_argument("--katran-router-peer-iface")
    parser.add_argument("--katran-packet-repeat", type=int)
    parser.add_argument("--katran-samples", type=int)
    parser.add_argument("--katran-skip-attach", action="store_true")
    parser.add_argument("--kernel-config", default=str(DEFAULT_KERNEL_CONFIG))
    parser.add_argument("--runner", default=str(DEFAULT_RUNNER))
    parser.add_argument("--scanner", default=str(DEFAULT_SCANNER))
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
    persist_results(payload, output_json, Path(args.output_md).resolve())
    print(json.dumps(payload, indent=2, sort_keys=True))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
