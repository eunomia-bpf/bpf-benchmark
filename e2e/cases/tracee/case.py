from __future__ import annotations

import argparse
import ctypes
import itertools
import json
import math
import os
import random
import re
import shlex
import socket
import statistics
import subprocess
import sys
import tempfile
import threading
import time
import uuid
from collections import Counter, deque
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
    resolve_bpftool_binary,
    run_command,
    smoke_output_path,
    tail_text,
    which,
)
from runner.libs.app_runners.tracee import TraceeRunner  # noqa: E402
from runner.libs.agent import find_bpf_programs, start_agent, stop_agent, wait_healthy  # noqa: E402
from runner.libs.metrics import (  # noqa: E402
    compute_delta,
    enable_bpf_stats,
    sample_bpf_stats,
    sample_cpu_usage,
    sample_total_cpu_usage,
)
from runner.libs.rejit import benchmark_rejit_enabled_passes  # noqa: E402
from runner.libs.workload import (  # noqa: E402
    WorkloadResult,
    run_connect_storm,
    run_dd_read_load,
    run_file_open_load,
    run_network_load,
    run_open_storm,
    run_scheduler_load,
    run_user_exec_loop,
)
from e2e.case_common import (  # noqa: E402
    CaseLifecycleState,
    LifecycleAbort,
    build_map_capture_specs,
    capture_map_state,
    host_metadata,
    percentile,
    summarize_numbers,
    percent_delta,
    persist_results,
    run_case_lifecycle,
)


DEFAULT_CONFIG = Path(__file__).with_name("config.yaml")
DEFAULT_SETUP_SCRIPT = Path(__file__).with_name("setup.sh")
DEFAULT_OUTPUT_JSON = authoritative_output_path(RESULTS_DIR, "tracee")
DEFAULT_OUTPUT_MD = ROOT_DIR / "e2e" / "results" / "tracee-e2e-real.md"
DEFAULT_DAEMON = ROOT_DIR / "daemon" / "target" / "release" / "bpfrejit-daemon"
CACHED_TRACEE_BINARY = ROOT_DIR / "e2e" / "cases" / "tracee" / "bin" / "tracee"
DEFAULT_SAMPLE_COUNT = 5
DEFAULT_SMOKE_SAMPLE_COUNT = 2
DEFAULT_WARMUP_DURATION_S = 5
DEFAULT_SMOKE_WARMUP_DURATION_S = 2
DEFAULT_LATENCY_PROBE_COUNT = 8
DEFAULT_SMOKE_LATENCY_PROBE_COUNT = 3
DEFAULT_LATENCY_PROBE_TIMEOUT_S = 5.0
DEFAULT_BOOTSTRAP_ITERATIONS = 2000
DEFAULT_BOOTSTRAP_SEED = 20260328
FALLBACK_MARKERS = ("fallback=", "fell back")
TRACEE_STATS_PATTERN = re.compile(
    r"EventCount[:=]\s*(?P<events>\d+).*?LostEvCount[:=]\s*(?P<lost>\d+)(?:.*?LostWrCount[:=]\s*(?P<lost_writes>\d+))?",
    re.IGNORECASE,
)
SYS_PIDFD_GETFD = 438


def _dup_fd_from_process(pid: int, target_fd: int) -> int | None:
    try:
        pidfd = os.pidfd_open(int(pid), 0)
    except (AttributeError, OSError):
        pidfd = None
    if pidfd is not None:
        try:
            libc = ctypes.CDLL(None, use_errno=True)
            libc.syscall.restype = ctypes.c_long
            result = int(libc.syscall(SYS_PIDFD_GETFD, int(pidfd), int(target_fd), 0))
            if result >= 0:
                return result
        finally:
            os.close(pidfd)
    try:
        return os.open(f"/proc/{pid}/fd/{target_fd}", os.O_RDONLY | os.O_CLOEXEC)
    except OSError:
        return None


class TraceeOutputCollector:
    def __init__(self) -> None:
        self._lock = threading.Lock()
        self._condition = threading.Condition(self._lock)
        self.stdout_tail: deque[str] = deque(maxlen=200)
        self.stderr_tail: deque[str] = deque(maxlen=200)
        self.event_counts: Counter[str] = Counter()
        self.events: deque[dict[str, object]] = deque(maxlen=4096)
        self.total_events = 0
        self.latest_stats: dict[str, int] = {}

    def consume_stdout(self, pipe: Any) -> None:
        for raw_line in iter(pipe.readline, ""):
            line = raw_line.rstrip()
            with self._lock:
                self.stdout_tail.append(line)
            self._parse_event_line(line)
            self._parse_stats_line(line)
        pipe.close()

    def consume_stderr(self, pipe: Any) -> None:
        for raw_line in iter(pipe.readline, ""):
            line = raw_line.rstrip()
            with self._lock:
                self.stderr_tail.append(line)
            self._parse_stats_line(line)
        pipe.close()

    def _parse_event_line(self, line: str) -> None:
        try:
            payload = json.loads(line)
        except json.JSONDecodeError:
            return
        if not isinstance(payload, Mapping):
            return
        event_name = payload.get("eventName") or payload.get("event_name")
        if not event_name:
            return
        with self._lock:
            normalized_event_name = str(event_name)
            self.event_counts[normalized_event_name] += 1
            self.total_events += 1
            self.events.append(
                {
                    "event_name": normalized_event_name,
                    "line": line,
                    "payload": dict(payload),
                    "observed_monotonic_ns": time.monotonic_ns(),
                }
            )
            self._condition.notify_all()

    def _parse_stats_line(self, line: str) -> None:
        match = TRACEE_STATS_PATTERN.search(line)
        if not match:
            return
        stats = {
            "event_count": int(match.group("events")),
            "lost_event_count": int(match.group("lost")),
            "lost_write_count": int(match.group("lost_writes") or 0),
        }
        with self._lock:
            self.latest_stats = stats

    def snapshot(self) -> dict[str, object]:
        with self._lock:
            return {
                "event_counts": dict(self.event_counts),
                "recent_events": list(self.events),
                "total_events": self.total_events,
                "latest_stats": dict(self.latest_stats),
                "stdout_tail": list(self.stdout_tail),
                "stderr_tail": list(self.stderr_tail),
            }

    def wait_for_event(
        self,
        *,
        event_names: Sequence[str],
        marker_tokens: Sequence[str],
        min_observed_ns: int,
        timeout_s: float,
    ) -> dict[str, object] | None:
        wanted_names = {str(name) for name in event_names if str(name)}
        tokens = [str(token) for token in marker_tokens if str(token)]
        deadline = time.monotonic() + max(0.0, float(timeout_s))

        def find_match() -> dict[str, object] | None:
            for record in reversed(self.events):
                observed_ns = int(record.get("observed_monotonic_ns", 0) or 0)
                if observed_ns < min_observed_ns:
                    break
                event_name = str(record.get("event_name") or "")
                if wanted_names and event_name not in wanted_names:
                    continue
                raw_line = str(record.get("line") or "")
                if tokens and not all(token in raw_line for token in tokens):
                    continue
                return dict(record)
            return None

        with self._condition:
            match = find_match()
            while match is None:
                remaining = deadline - time.monotonic()
                if remaining <= 0:
                    return None
                self._condition.wait(timeout=remaining)
                match = find_match()
            return match


class TraceeAgentSession:
    def __init__(self, commands: Sequence[Sequence[str]], load_timeout: int) -> None:
        self.commands = [list(command) for command in commands]
        self.load_timeout = load_timeout
        self.process: subprocess.Popen[str] | None = None
        self.collector = TraceeOutputCollector()
        self.stdout_thread: threading.Thread | None = None
        self.stderr_thread: threading.Thread | None = None
        self.command_used: list[str] | None = None
        self.programs: list[dict[str, object]] = []
        self.program_fds: dict[int, int] = {}

    def __enter__(self) -> "TraceeAgentSession":
        preexisting = sample_bpf_stats(_current_prog_ids())
        preexisting_ids = set(preexisting)
        failures: list[str] = []
        for command in self.commands:
            self.collector = TraceeOutputCollector()
            proc = start_agent(command[0], command[1:], env={"HOME": os.environ.get("HOME", str(ROOT_DIR))})
            self.process = proc
            self.command_used = command
            assert proc.stdout is not None
            assert proc.stderr is not None
            self.stdout_thread = threading.Thread(target=self.collector.consume_stdout, args=(proc.stdout,), daemon=True)
            self.stderr_thread = threading.Thread(target=self.collector.consume_stderr, args=(proc.stderr,), daemon=True)
            self.stdout_thread.start()
            self.stderr_thread.start()

            healthy = wait_healthy(
                proc,
                self.load_timeout,
                lambda: bool([item for item in find_bpf_programs(proc.pid or 0) if int(item.get("id", -1)) not in preexisting_ids]),
            )
            if healthy:
                programs = [
                    item
                    for item in find_bpf_programs(proc.pid or 0)
                    if int(item.get("id", -1)) not in preexisting_ids
                ]
                if programs:
                    self.programs = programs
                    self.program_fds = {}
                    for program in programs:
                        prog_id = int(program.get("id", -1))
                        for ref in program.get("owner_fds") or []:
                            if int(ref.get("pid", -1)) != (proc.pid or -1):
                                continue
                            dup_fd = _dup_fd_from_process(int(proc.pid or -1), int(ref["fd"]))
                            if dup_fd is None:
                                continue
                            self.program_fds[prog_id] = dup_fd
                            break
                    return self
            snapshot = self.collector.snapshot()
            failures.append(_format_launch_failure(command, proc, snapshot))
            self.close()
        if not failures:
            failures.append("Tracee never became healthy")
        raise RuntimeError(f"failed to launch Tracee: {' | '.join(failures)}")

    @property
    def pid(self) -> int | None:
        return None if self.process is None else self.process.pid

    def collector_snapshot(self) -> dict[str, object]:
        return self.collector.snapshot()

    def close(self) -> None:
        for fd in self.program_fds.values():
            try:
                os.close(fd)
            except OSError:
                pass
        self.program_fds.clear()
        if self.process is not None:
            stop_agent(self.process, timeout=8)
            self.process = None
        if self.stdout_thread is not None:
            self.stdout_thread.join(timeout=2.0)
            self.stdout_thread = None
        if self.stderr_thread is not None:
            self.stderr_thread.join(timeout=2.0)
            self.stderr_thread = None

    def __exit__(self, exc_type, exc, tb) -> None:
        self.close()


def _current_prog_ids() -> list[int]:
    payload = run_command([resolve_bpftool_binary(), "-j", "-p", "prog", "show"], timeout=30).stdout
    parsed = json.loads(payload)
    if not isinstance(parsed, list):
        return []
    return [int(record["id"]) for record in parsed if isinstance(record, dict) and "id" in record]


def ensure_artifacts(daemon_binary: Path) -> None:
    if not daemon_binary.exists():
        raise RuntimeError(f"bpfrejit-daemon not found: {daemon_binary}")


def load_config(path: Path) -> dict[str, object]:
    payload = yaml.safe_load(path.read_text())
    if not isinstance(payload, dict):
        raise RuntimeError(f"invalid config payload in {path}")
    return payload


def run_setup_script(setup_script: Path) -> dict[str, object]:
    completed = run_command(["bash", str(setup_script)], check=False, timeout=1800)
    tracee_binary = ""
    for line in (completed.stdout or "").splitlines():
        if line.startswith("TRACEE_BINARY="):
            tracee_binary = line.split("=", 1)[1].strip()
            break
    return {
        "returncode": completed.returncode,
        "tracee_binary": tracee_binary or None,
        "stdout_tail": tail_text(completed.stdout or "", max_lines=40, max_chars=8000),
        "stderr_tail": tail_text(completed.stderr or "", max_lines=40, max_chars=8000),
    }


def resolve_tracee_binary(explicit: str | None, setup_result: Mapping[str, object]) -> str | None:
    if explicit:
        candidate = Path(explicit).resolve()
        if candidate.exists():
            return str(candidate)
    scripted = str(setup_result.get("tracee_binary") or "").strip()
    if scripted and Path(scripted).exists():
        return scripted
    for candidate in ("tracee", "tracee-ebpf"):
        resolved = which(candidate)
        if resolved:
            return resolved
    # Check the repo-local cached binary (shared into VM via --rwdir)
    if CACHED_TRACEE_BINARY.exists():
        return str(CACHED_TRACEE_BINARY)
    if Path("/tmp/tracee-bin/tracee").exists():
        return "/tmp/tracee-bin/tracee"
    return None


def _ensure_empty_signatures_dir() -> Path:
    """Ensure an empty signatures directory exists so tracee does not error out."""
    sig_dir = ROOT_DIR / "e2e" / "cases" / "tracee" / "bin" / "signatures"
    sig_dir.mkdir(parents=True, exist_ok=True)
    return sig_dir


def build_tracee_commands(binary: str, events: Sequence[str], extra_args: Sequence[str] = ()) -> list[list[str]]:
    event_text = ",".join(str(event) for event in events)
    sig_dir = _ensure_empty_signatures_dir()
    return [[binary, "--events", event_text, "--output", "json", "--signatures-dir", str(sig_dir), *extra_args]]


def _format_launch_failure(command: Sequence[str], proc: subprocess.Popen[str] | None, snapshot: Mapping[str, object]) -> str:
    rendered = " ".join(shlex.quote(part) for part in command)
    combined = "\n".join((snapshot.get("stderr_tail") or []) + (snapshot.get("stdout_tail") or []))
    details = tail_text(combined, max_lines=40, max_chars=8000)
    if proc is not None and proc.poll() is not None:
        reason = f"command exited with code {proc.returncode}"
    else:
        reason = "command did not become healthy"
    if details:
        return f"{rendered}: {reason}: {details}"
    return f"{rendered}: {reason}"


def select_tracee_programs(
    live_programs: Sequence[Mapping[str, object]],
    config: Mapping[str, object],
    *,
    config_key: str = "target_programs",
    allow_all_when_unset: bool = True,
) -> list[dict[str, object]]:
    available_programs = [dict(program) for program in live_programs if isinstance(program, Mapping)]
    requested_names = [
        str(name).strip()
        for name in (config.get(config_key) or [])
        if str(name).strip()
    ]
    if not requested_names:
        return available_programs if allow_all_when_unset else []

    selected: list[dict[str, object]] = []
    missing: list[str] = []
    for requested_name in requested_names:
        matched = False
        for program in live_programs:
            if not isinstance(program, Mapping):
                continue
            live_name = str(program.get("name") or "")
            if live_name == requested_name and dict(program) not in selected:
                selected.append(dict(program))
                matched = True
        if not matched:
            missing.append(requested_name)
    if missing:
        raise RuntimeError(
            f"configured {config_key} not found in live Tracee programs: {', '.join(missing)}"
        )
    return selected


def _filtered_float_values(values: Sequence[float | int | None]) -> list[float]:
    filtered: list[float] = []
    for value in values:
        if value is None:
            continue
        numeric = float(value)
        if math.isnan(numeric):
            continue
        filtered.append(numeric)
    return filtered


def bootstrap_mean_ci(
    values: Sequence[float | int | None],
    *,
    iterations: int,
    seed: int,
) -> dict[str, float] | None:
    filtered = _filtered_float_values(values)
    if not filtered:
        return None
    if len(filtered) == 1:
        return {"low": filtered[0], "high": filtered[0]}
    rng = random.Random(seed)
    samples: list[float] = []
    for _ in range(max(1, int(iterations))):
        resample = [filtered[rng.randrange(len(filtered))] for _ in range(len(filtered))]
        samples.append(float(statistics.mean(resample)))
    samples.sort()
    low = percentile(samples, 2.5)
    high = percentile(samples, 97.5)
    if low is None or high is None:
        return None
    return {"low": float(low), "high": float(high)}


def summarize_numeric_distribution(
    values: Sequence[float | int | None],
    *,
    ci_iterations: int,
    ci_seed: int,
) -> dict[str, float | int | dict[str, float] | None]:
    filtered = _filtered_float_values(values)
    summary = dict(summarize_numbers(filtered))
    summary["stdev"] = statistics.stdev(filtered) if len(filtered) > 1 else (0.0 if filtered else None)
    summary["p95"] = percentile(filtered, 95) if filtered else None
    summary["p99"] = percentile(filtered, 99) if filtered else None
    summary["mean_ci95"] = bootstrap_mean_ci(filtered, iterations=ci_iterations, seed=ci_seed)
    return summary


def exact_paired_permutation_pvalue(before_values: Sequence[float | int | None], after_values: Sequence[float | int | None]) -> float | None:
    deltas = [
        float(after) - float(before)
        for before, after in zip(before_values, after_values)
        if before is not None and after is not None
    ]
    non_zero_deltas = [delta for delta in deltas if abs(delta) > 1e-12]
    if not non_zero_deltas:
        return None

    observed = abs(sum(non_zero_deltas))
    if len(non_zero_deltas) <= 14:
        total = 0
        extreme = 0
        for signs in itertools.product((-1.0, 1.0), repeat=len(non_zero_deltas)):
            total += 1
            candidate = abs(sum(sign * delta for sign, delta in zip(signs, non_zero_deltas)))
            if candidate >= observed - 1e-12:
                extreme += 1
        return extreme / total if total > 0 else None

    rng = random.Random(DEFAULT_BOOTSTRAP_SEED + len(non_zero_deltas))
    total = 20000
    extreme = 0
    for _ in range(total):
        candidate = abs(sum((1.0 if rng.random() >= 0.5 else -1.0) * delta for delta in non_zero_deltas))
        if candidate >= observed - 1e-12:
            extreme += 1
    return extreme / total


def paired_metric_report(
    before_values: Sequence[float | int | None],
    after_values: Sequence[float | int | None],
    *,
    ci_iterations: int,
    ci_seed: int,
) -> dict[str, object]:
    before_filtered = _filtered_float_values(before_values)
    after_filtered = _filtered_float_values(after_values)
    paired = [
        (float(before), float(after))
        for before, after in zip(before_values, after_values)
        if before is not None and after is not None
    ]
    deltas = [after - before for before, after in paired]
    pct_deltas = [((after - before) / before) * 100.0 for before, after in paired if before != 0.0]
    p_value = exact_paired_permutation_pvalue([pair[0] for pair in paired], [pair[1] for pair in paired])
    return {
        "pairs": len(paired),
        "before": summarize_numeric_distribution(before_filtered, ci_iterations=ci_iterations, ci_seed=ci_seed),
        "after": summarize_numeric_distribution(after_filtered, ci_iterations=ci_iterations, ci_seed=ci_seed + 1),
        "delta": summarize_numeric_distribution(deltas, ci_iterations=ci_iterations, ci_seed=ci_seed + 2),
        "pct_delta": summarize_numeric_distribution(pct_deltas, ci_iterations=ci_iterations, ci_seed=ci_seed + 3),
        "p_value": p_value,
        "significant": p_value is not None and p_value <= 0.05,
    }


def summarize_latency_values(
    values: Sequence[float | int | None],
    *,
    ci_iterations: int,
    ci_seed: int,
) -> dict[str, object]:
    summary = summarize_numeric_distribution(values, ci_iterations=ci_iterations, ci_seed=ci_seed)
    summary["p50"] = summary.get("median")
    return summary


def application_overhead_pct(control_value: float | int | None, observed_value: float | int | None) -> float | None:
    if control_value in (None, 0) or observed_value is None:
        return None
    return ((float(control_value) - float(observed_value)) / float(control_value)) * 100.0


def primary_events_for_workload(spec: Mapping[str, object]) -> list[str]:
    configured = [str(value) for value in (spec.get("primary_events") or []) if str(value)]
    if configured:
        return configured
    kind = str(spec.get("kind", spec.get("name", "")))
    if kind == "exec_storm":
        return ["execve", "sched_process_exec"]
    if kind in {"file_io", "file_open", "open_storm"}:
        return ["security_file_open"]
    if kind in {"network", "connect_storm"}:
        return ["security_socket_connect"]
    return []


def latency_probe_kind(spec: Mapping[str, object]) -> str:
    configured = str(spec.get("latency_probe_kind") or "").strip()
    if configured:
        return configured
    kind = str(spec.get("kind", spec.get("name", "")))
    if kind in {"file_io", "file_open", "open_storm"}:
        return "file_open"
    if kind in {"network", "connect_storm"}:
        return "tcp_connect"
    return "exec"


def latency_probe_events(spec: Mapping[str, object]) -> list[str]:
    configured = [str(value) for value in (spec.get("latency_probe_events") or []) if str(value)]
    if configured:
        return configured
    primary = primary_events_for_workload(spec)
    if primary:
        return primary
    probe_kind = latency_probe_kind(spec)
    if probe_kind == "file_open":
        return ["security_file_open"]
    if probe_kind == "tcp_connect":
        return ["security_socket_connect"]
    return ["sched_process_exec", "execve"]


def _ensure_no_workload_fallback(kind: str, result: WorkloadResult) -> None:
    combined = ((result.stdout or "") + "\n" + (result.stderr or "")).lower()
    if any(marker in combined for marker in FALLBACK_MARKERS):
        raise RuntimeError(f"{kind} workload fell back to a degraded generator: {tail_text(combined)}")


def run_workload(spec: Mapping[str, object], duration_s: int) -> WorkloadResult:
    kind = str(spec.get("kind", spec.get("name", "")))
    if kind == "read":
        return run_dd_read_load(duration_s)
    if kind == "exec_storm":
        result = run_user_exec_loop(duration_s, mark_fallback=False)
        _ensure_no_workload_fallback(kind, result)
        return result
    if kind in {"file_io", "file_open"}:
        if which("stress-ng") is None and which("fio") is None:
            raise RuntimeError("fio or stress-ng is required for the Tracee file_open workload")
        return run_file_open_load(duration_s)
    if kind == "open_storm":
        return run_open_storm(duration_s)
    if kind in {"network", "connect_storm"}:
        if kind == "network":
            if which("wrk") is None:
                raise RuntimeError("wrk is required for the Tracee network workload")
            return run_network_load(duration_s)
        return run_connect_storm(duration_s)
    if kind == "scheduler":
        return run_scheduler_load(duration_s)
    raise RuntimeError(f"unsupported workload kind: {kind}")


def warmup_workload(spec: Mapping[str, object], duration_s: int | float) -> dict[str, object] | None:
    if float(duration_s) <= 0.0:
        return None
    result = run_workload(spec, max(1, int(duration_s)))
    return {
        "ops_total": result.ops_total,
        "ops_per_sec": result.ops_per_sec,
        "duration_s": result.duration_s,
        "stdout_tail": result.stdout,
        "stderr_tail": result.stderr,
    }


def _emit_exec_latency_probe() -> dict[str, object]:
    marker = f"tracee-exec-probe-{uuid.uuid4().hex}"
    with tempfile.TemporaryDirectory(prefix=f"{marker}-") as tempdir:
        script_path = Path(tempdir) / marker
        script_path.write_text("#!/bin/sh\nexit 0\n")
        script_path.chmod(0o755)
        started_ns = time.monotonic_ns()
        completed = run_command([str(script_path)], check=False, timeout=5)
        probe_window_ns = time.monotonic_ns() - started_ns
        if completed.returncode != 0:
            details = tail_text(completed.stderr or completed.stdout)
            raise RuntimeError(f"exec latency probe failed: {details}")
    return {
        "marker": marker,
        "marker_tokens": [marker],
        "started_ns": started_ns,
        "probe_window_ns": probe_window_ns,
    }


def _emit_file_open_latency_probe() -> dict[str, object]:
    marker = f"tracee-open-probe-{uuid.uuid4().hex}"
    with tempfile.NamedTemporaryFile(prefix=f"{marker}-", delete=False) as handle:
        probe_path = Path(handle.name)
        handle.write(b"tracee-probe\n")
    try:
        started_ns = time.monotonic_ns()
        with probe_path.open("rb") as handle:
            handle.read(1)
        probe_window_ns = time.monotonic_ns() - started_ns
    finally:
        probe_path.unlink(missing_ok=True)
    return {
        "marker": marker,
        "marker_tokens": [marker],
        "started_ns": started_ns,
        "probe_window_ns": probe_window_ns,
    }


def _emit_tcp_connect_latency_probe() -> dict[str, object]:
    listener = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    listener.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    listener.bind(("127.0.0.1", 0))
    listener.listen(1)
    port = int(listener.getsockname()[1])
    accepted: dict[str, object] = {"error": None}

    def accept_once() -> None:
        try:
            conn, _ = listener.accept()
            conn.close()
        except OSError as exc:
            accepted["error"] = str(exc)

    thread = threading.Thread(target=accept_once, daemon=True)
    thread.start()
    try:
        started_ns = time.monotonic_ns()
        with socket.create_connection(("127.0.0.1", port), timeout=2.0):
            pass
        probe_window_ns = time.monotonic_ns() - started_ns
    finally:
        listener.close()
        thread.join(timeout=1.0)
    if accepted["error"] is not None:
        raise RuntimeError(f"tcp connect latency probe failed: {accepted['error']}")
    return {
        "marker": str(port),
        "marker_tokens": ["127.0.0.1", str(port)],
        "started_ns": started_ns,
        "probe_window_ns": probe_window_ns,
    }


def emit_latency_probe(spec: Mapping[str, object]) -> dict[str, object]:
    probe_kind = latency_probe_kind(spec)
    if probe_kind == "file_open":
        return _emit_file_open_latency_probe()
    if probe_kind == "tcp_connect":
        return _emit_tcp_connect_latency_probe()
    return _emit_exec_latency_probe()


def measure_latency_probes(
    workload_spec: Mapping[str, object],
    *,
    collector: TraceeOutputCollector,
    probe_count: int,
    timeout_s: float,
    ci_iterations: int,
    ci_seed: int,
) -> dict[str, object]:
    event_names = latency_probe_events(workload_spec)
    probe_rows: list[dict[str, object]] = []
    for probe_index in range(max(0, int(probe_count))):
        emitted = emit_latency_probe(workload_spec)
        matched = collector.wait_for_event(
            event_names=event_names,
            marker_tokens=emitted["marker_tokens"],
            min_observed_ns=int(emitted["started_ns"]),
            timeout_s=timeout_s,
        )
        if matched is None:
            raise RuntimeError(
                f"Tracee latency probe was not detected for workload {workload_spec.get('name')}: "
                f"tokens={emitted['marker_tokens']}, events={event_names}"
            )
        latency_ms = max(0.0, (int(matched["observed_monotonic_ns"]) - int(emitted["started_ns"])) / 1_000_000.0)
        probe_rows.append(
            {
                "index": probe_index,
                "event_name": matched["event_name"],
                "marker": emitted["marker"],
                "marker_tokens": emitted["marker_tokens"],
                "latency_ms": latency_ms,
                "probe_window_ms": float(emitted["probe_window_ns"]) / 1_000_000.0,
            }
        )
    return {
        "probe_count": len(probe_rows),
        "probe_timeout_s": timeout_s,
        "event_names": event_names,
        "probes": probe_rows,
        "summary": summarize_latency_values(
            [row["latency_ms"] for row in probe_rows],
            ci_iterations=ci_iterations,
            ci_seed=ci_seed,
        ),
    }


def workload_primary_event_total(event_counts: Mapping[str, object], workload_spec: Mapping[str, object]) -> int:
    return sum(int(event_counts.get(event_name, 0) or 0) for event_name in primary_events_for_workload(workload_spec))


def verify_phase_measurement(record: Mapping[str, object], *, require_tracee_activity: bool) -> None:
    if not require_tracee_activity:
        return
    if int(record.get("primary_events_total", 0) or 0) <= 0:
        raise RuntimeError(f"{record.get('name')} produced zero primary Tracee events")
    drops = record.get("drop_counters") or {}
    if int(drops.get("lost_event_count", 0) or 0) > 0 or int(drops.get("lost_write_count", 0) or 0) > 0:
        raise RuntimeError(f"{record.get('name')} lost Tracee events: {drops}")
    bpf_summary = (record.get("bpf") or {}).get("summary") or {}
    if int(bpf_summary.get("total_events", 0) or 0) <= 0:
        raise RuntimeError(f"{record.get('name')} produced zero selected-program BPF runtime events: {bpf_summary}")


def measure_workload(
    workload_spec: Mapping[str, object],
    duration_s: int,
    prog_ids: list[int],
    *,
    cycle_index: int,
    phase_name: str,
    control_throughput: float | int | None,
    latency_probe: Mapping[str, object] | None,
    prog_fds: dict[int, int] | None,
    agent_pid: int | None,
    collector: TraceeOutputCollector | None,
) -> dict[str, object]:
    before_bpf = sample_bpf_stats(prog_ids, prog_fds=prog_fds)
    before_tracee = collector.snapshot() if collector is not None else None
    cpu_holder: dict[int, dict[str, float]] = {}
    system_cpu_holder: dict[str, float] = {}
    threads: list[threading.Thread] = []

    if agent_pid is not None:
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

    workload_result = run_workload(workload_spec, duration_s)

    for thread in threads:
        thread.join()

    after_bpf = sample_bpf_stats(prog_ids, prog_fds=prog_fds)
    after_tracee = collector.snapshot() if collector is not None else None
    bpf_delta = compute_delta(before_bpf, after_bpf)

    if before_tracee is not None and after_tracee is not None:
        before_counts = Counter(before_tracee.get("event_counts") or {})
        after_counts = Counter(after_tracee.get("event_counts") or {})
        event_counts = {
            event_name: int(after_counts.get(event_name, 0) - before_counts.get(event_name, 0))
            for event_name in sorted(set(before_counts) | set(after_counts))
        }
        before_stats = before_tracee.get("latest_stats") or {}
        after_stats = after_tracee.get("latest_stats") or {}
        drop_counters = {
            field: int(after_stats.get(field, 0)) - int(before_stats.get(field, 0))
            for field in ("event_count", "lost_event_count", "lost_write_count")
        }
        total_events = int(after_tracee.get("total_events", 0)) - int(before_tracee.get("total_events", 0))
    else:
        event_counts = {}
        drop_counters = {}
        total_events = None

    agent_cpu = cpu_holder.get(agent_pid or -1) if agent_pid is not None else None
    agent_cpu_total = None
    if agent_cpu is not None:
        agent_cpu_total = float(agent_cpu["user_pct"]) + float(agent_cpu["sys_pct"])

    primary_event_names = primary_events_for_workload(workload_spec)
    primary_events_total = (
        workload_primary_event_total(event_counts, workload_spec)
        if collector is not None
        else None
    )
    primary_events_per_sec = (
        (float(primary_events_total) / workload_result.duration_s)
        if primary_events_total is not None and workload_result.duration_s > 0
        else None
    )
    overhead_pct = 0.0 if phase_name == "control" else application_overhead_pct(control_throughput, workload_result.ops_per_sec)
    return {
        "cycle_index": cycle_index,
        "phase": phase_name,
        "name": str(workload_spec.get("name", workload_spec.get("kind", "unknown"))),
        "kind": str(workload_spec.get("kind", "")),
        "metric": str(workload_spec.get("metric", "ops/s")),
        "command_template": str(workload_spec.get("command", "")),
        "primary_event_names": primary_event_names,
        "control_app_throughput": control_throughput,
        "application_overhead_pct": overhead_pct,
        "app_throughput": workload_result.ops_per_sec,
        "ops_total": workload_result.ops_total,
        "ops_per_sec": workload_result.ops_per_sec,
        "duration_s": workload_result.duration_s,
        "events_total": total_events,
        "events_per_sec": (
            (float(total_events) / workload_result.duration_s)
            if total_events is not None and workload_result.duration_s > 0
            else None
        ),
        "primary_events_total": primary_events_total,
        "primary_events_per_sec": primary_events_per_sec,
        "events_per_op": (
            (float(primary_events_total) / float(workload_result.ops_total))
            if primary_events_total is not None and workload_result.ops_total > 0
            else None
        ),
        "event_counts": event_counts,
        "drop_counters": drop_counters,
        "latency_probe": None if latency_probe is None else dict(latency_probe),
        "latency_ms": None if latency_probe is None else dict(latency_probe.get("summary") or {}),
        "agent_cpu": {
            "user_pct": None if agent_cpu is None else agent_cpu["user_pct"],
            "sys_pct": None if agent_cpu is None else agent_cpu["sys_pct"],
            "total_pct": agent_cpu_total,
        },
        "system_cpu": system_cpu_holder,
        "bpf": bpf_delta,
        "stdout_tail": workload_result.stdout,
        "stderr_tail": workload_result.stderr,
}


def summarize_phase(
    workloads: Sequence[Mapping[str, object]],
    *,
    ci_iterations: int,
    ci_seed: int,
) -> dict[str, object]:
    return {
        "app_throughput": summarize_numeric_distribution(
            [record.get("app_throughput") for record in workloads],
            ci_iterations=ci_iterations,
            ci_seed=ci_seed,
        ),
        "events_per_sec": summarize_numeric_distribution(
            [record.get("events_per_sec") for record in workloads],
            ci_iterations=ci_iterations,
            ci_seed=ci_seed + 1,
        ),
        "primary_events_per_sec": summarize_numeric_distribution(
            [record.get("primary_events_per_sec") for record in workloads],
            ci_iterations=ci_iterations,
            ci_seed=ci_seed + 2,
        ),
        "application_overhead_pct": summarize_numeric_distribution(
            [record.get("application_overhead_pct") for record in workloads],
            ci_iterations=ci_iterations,
            ci_seed=ci_seed + 3,
        ),
        "agent_cpu_total_pct": summarize_numeric_distribution(
            [
                ((record.get("agent_cpu") or {}).get("total_pct") if isinstance(record.get("agent_cpu"), Mapping) else None)
                for record in workloads
            ],
            ci_iterations=ci_iterations,
            ci_seed=ci_seed + 4,
        ),
        "system_cpu_busy_pct": summarize_numeric_distribution(
            [
                ((record.get("system_cpu") or {}).get("busy_pct") if isinstance(record.get("system_cpu"), Mapping) else None)
                for record in workloads
            ],
            ci_iterations=ci_iterations,
            ci_seed=ci_seed + 5,
        ),
        "bpf_avg_ns_per_run": summarize_numeric_distribution(
            [
                ((record.get("bpf") or {}).get("summary", {}).get("avg_ns_per_run"))
                for record in workloads
            ],
            ci_iterations=ci_iterations,
            ci_seed=ci_seed + 6,
        ),
        "detection_latency_ms_p99": summarize_numeric_distribution(
            [
                ((record.get("latency_ms") or {}).get("p99"))
                for record in workloads
            ],
            ci_iterations=ci_iterations,
            ci_seed=ci_seed + 7,
        ),
    }


def phase_records(phase: Mapping[str, object]) -> list[Mapping[str, object]]:
    samples = phase.get("samples")
    if isinstance(samples, list):
        return [record for record in samples if isinstance(record, Mapping)]
    workloads = phase.get("workloads")
    if isinstance(workloads, list):
        return [record for record in workloads if isinstance(record, Mapping)]
    return []


def summarize_workload_samples(
    samples: Sequence[Mapping[str, object]],
    *,
    ci_iterations: int,
    ci_seed: int,
) -> list[dict[str, object]]:
    groups: dict[str, list[Mapping[str, object]]] = {}
    for sample in samples:
        groups.setdefault(str(sample.get("name") or "unknown"), []).append(sample)

    rows: list[dict[str, object]] = []
    for index, name in enumerate(sorted(groups)):
        records = groups[name]
        rows.append(
            {
                "name": name,
                "kind": str(records[0].get("kind", "")),
                "metric": str(records[0].get("metric", "ops/s")),
                "sample_count": len(records),
                "primary_event_names": list(records[0].get("primary_event_names") or []),
                "app_throughput": summarize_numeric_distribution(
                    [record.get("app_throughput") for record in records],
                    ci_iterations=ci_iterations,
                    ci_seed=ci_seed + (index * 20),
                ),
                "events_per_sec": summarize_numeric_distribution(
                    [record.get("events_per_sec") for record in records],
                    ci_iterations=ci_iterations,
                    ci_seed=ci_seed + (index * 20) + 1,
                ),
                "primary_events_per_sec": summarize_numeric_distribution(
                    [record.get("primary_events_per_sec") for record in records],
                    ci_iterations=ci_iterations,
                    ci_seed=ci_seed + (index * 20) + 2,
                ),
                "application_overhead_pct": summarize_numeric_distribution(
                    [record.get("application_overhead_pct") for record in records],
                    ci_iterations=ci_iterations,
                    ci_seed=ci_seed + (index * 20) + 3,
                ),
                "detection_latency_ms_mean": summarize_numeric_distribution(
                    [((record.get("latency_ms") or {}).get("mean")) for record in records],
                    ci_iterations=ci_iterations,
                    ci_seed=ci_seed + (index * 20) + 4,
                ),
                "detection_latency_ms_p99": summarize_numeric_distribution(
                    [((record.get("latency_ms") or {}).get("p99")) for record in records],
                    ci_iterations=ci_iterations,
                    ci_seed=ci_seed + (index * 20) + 5,
                ),
                "agent_cpu_total_pct": summarize_numeric_distribution(
                    [((record.get("agent_cpu") or {}).get("total_pct")) for record in records],
                    ci_iterations=ci_iterations,
                    ci_seed=ci_seed + (index * 20) + 6,
                ),
                "system_cpu_busy_pct": summarize_numeric_distribution(
                    [((record.get("system_cpu") or {}).get("busy_pct")) for record in records],
                    ci_iterations=ci_iterations,
                    ci_seed=ci_seed + (index * 20) + 7,
                ),
                "bpf_avg_ns_per_run": summarize_numeric_distribution(
                    [((record.get("bpf") or {}).get("summary", {}).get("avg_ns_per_run")) for record in records],
                    ci_iterations=ci_iterations,
                    ci_seed=ci_seed + (index * 20) + 8,
                ),
                "lost_event_count": summarize_numeric_distribution(
                    [((record.get("drop_counters") or {}).get("lost_event_count")) for record in records],
                    ci_iterations=ci_iterations,
                    ci_seed=ci_seed + (index * 20) + 9,
                ),
                "correctness": {
                    "samples": len(records),
                    "all_zero_drops": all(
                        int(((record.get("drop_counters") or {}).get("lost_event_count", 0) or 0)) == 0
                        and int(((record.get("drop_counters") or {}).get("lost_write_count", 0) or 0)) == 0
                        for record in records
                    ),
                    "all_latency_probes_detected": all(
                        record.get("phase") == "control"
                        or int(((record.get("latency_probe") or {}).get("probe_count", 0) or 0)) > 0
                        for record in records
                    ),
                },
            }
        )
    return rows


def attach_control_phase_metrics(
    phase: Mapping[str, object],
    control_records: Sequence[Mapping[str, object]],
    *,
    ci_iterations: int,
    ci_seed: int,
) -> dict[str, object]:
    phase_copy = dict(phase)
    records = [dict(record) for record in (phase.get("workloads") or []) if isinstance(record, Mapping)]
    if str(phase.get("phase", "")) == "control":
        phase_copy["workloads"] = records
        phase_copy["summary"] = summarize_phase(records, ci_iterations=ci_iterations, ci_seed=ci_seed)
        return phase_copy
    control_sequence = [record for record in control_records if isinstance(record, Mapping)]
    control_by_name: dict[str, Mapping[str, object]] = {}
    for record in control_sequence:
        for key in (record.get("name"), record.get("kind")):
            if key is None:
                continue
            control_by_name[str(key)] = record
    for index, record in enumerate(records):
        control_record = control_by_name.get(str(record.get("name") or record.get("kind") or ""))
        if control_record is None and index < len(control_sequence):
            control_record = control_sequence[index]
        control_throughput = None if control_record is None else control_record.get("app_throughput")
        record["control_app_throughput"] = control_throughput
        record["application_overhead_pct"] = application_overhead_pct(control_throughput, record.get("app_throughput"))
    phase_copy["workloads"] = records
    phase_copy["summary"] = summarize_phase(records, ci_iterations=ci_iterations, ci_seed=ci_seed)
    return phase_copy


def aggregate_phase_samples(
    phase_name: str,
    samples: Sequence[Mapping[str, object]],
    *,
    ci_iterations: int,
    ci_seed: int,
) -> dict[str, object]:
    return {
        "phase": phase_name,
        "samples": [dict(sample) for sample in samples],
        "workloads": summarize_workload_samples(samples, ci_iterations=ci_iterations, ci_seed=ci_seed),
        "summary": summarize_phase(samples, ci_iterations=ci_iterations, ci_seed=ci_seed + 1000),
    }


def aggregate_programs(phase: Mapping[str, object]) -> dict[str, dict[str, object]]:
    aggregated: dict[str, dict[str, object]] = {}
    for workload in phase_records(phase):
        programs = ((workload.get("bpf") or {}).get("programs") or {})
        for prog_id, record in programs.items():
            key = str(prog_id)
            target = aggregated.setdefault(
                key,
                {
                    "id": int(record.get("id", prog_id)),
                    "name": str(record.get("name", f"id-{prog_id}")),
                    "run_cnt_delta": 0,
                    "run_time_ns_delta": 0,
                },
            )
            target["run_cnt_delta"] += int(record.get("run_cnt_delta", 0) or 0)
            target["run_time_ns_delta"] += int(record.get("run_time_ns_delta", 0) or 0)
    for record in aggregated.values():
        run_cnt = int(record["run_cnt_delta"])
        run_time = int(record["run_time_ns_delta"])
        record["avg_ns_per_run"] = (run_time / run_cnt) if run_cnt > 0 else None
    return aggregated


def summarize_program_activity(
    phase: Mapping[str, object],
    prog_ids: Sequence[int],
) -> dict[str, object]:
    aggregated = aggregate_programs(phase)
    rows: list[dict[str, object]] = []
    total_run_cnt = 0
    total_run_time_ns = 0
    for prog_id in [int(value) for value in prog_ids if int(value) > 0]:
        record = aggregated.get(str(prog_id), {})
        run_cnt = int(record.get("run_cnt_delta", 0) or 0)
        run_time_ns = int(record.get("run_time_ns_delta", 0) or 0)
        total_run_cnt += run_cnt
        total_run_time_ns += run_time_ns
        rows.append(
            {
                "id": prog_id,
                "name": str(record.get("name") or f"id-{prog_id}"),
                "run_cnt_delta": run_cnt,
                "run_time_ns_delta": run_time_ns,
                "avg_ns_per_run": (run_time_ns / run_cnt) if run_cnt > 0 else None,
            }
        )
    return {
        "programs": rows,
        "total_run_cnt": total_run_cnt,
        "total_run_time_ns": total_run_time_ns,
        "avg_ns_per_run": (total_run_time_ns / total_run_cnt) if total_run_cnt > 0 else None,
    }


def _phase_samples_by_workload_and_cycle(phase: Mapping[str, object]) -> dict[str, dict[int, Mapping[str, object]]]:
    grouped: dict[str, dict[int, Mapping[str, object]]] = {}
    for sample in phase_records(phase):
        grouped.setdefault(str(sample.get("name") or "unknown"), {})[int(sample.get("cycle_index", -1) or -1)] = sample
    return grouped


def compare_phases(
    baseline: Mapping[str, object],
    post: Mapping[str, object] | None,
    *,
    control: Mapping[str, object] | None = None,
    ci_iterations: int = DEFAULT_BOOTSTRAP_ITERATIONS,
    ci_seed: int = DEFAULT_BOOTSTRAP_SEED,
) -> dict[str, object]:
    if not post:
        return {"comparable": False, "reason": "rejit did not apply successfully"}

    baseline_by_name = _phase_samples_by_workload_and_cycle(baseline)
    post_by_name = _phase_samples_by_workload_and_cycle(post)
    control_by_name = _phase_samples_by_workload_and_cycle(control or {})
    workload_rows: list[dict[str, object]] = []
    for index, name in enumerate(sorted(set(baseline_by_name) & set(post_by_name))):
        common_cycles = sorted(set(baseline_by_name[name]) & set(post_by_name[name]))
        if not common_cycles:
            continue
        before_samples = [baseline_by_name[name][cycle] for cycle in common_cycles]
        after_samples = [post_by_name[name][cycle] for cycle in common_cycles]
        control_samples = [control_by_name.get(name, {}).get(cycle) for cycle in common_cycles]
        workload_rows.append(
            {
                "name": name,
                "pairs": len(common_cycles),
                "cycles": common_cycles,
                "control_app_throughput": summarize_numeric_distribution(
                    [None if sample is None else sample.get("app_throughput") for sample in control_samples],
                    ci_iterations=ci_iterations,
                    ci_seed=ci_seed + (index * 50),
                ),
                "app_throughput": paired_metric_report(
                    [sample.get("app_throughput") for sample in before_samples],
                    [sample.get("app_throughput") for sample in after_samples],
                    ci_iterations=ci_iterations,
                    ci_seed=ci_seed + (index * 50) + 1,
                ),
                "primary_events_per_sec": paired_metric_report(
                    [sample.get("primary_events_per_sec") for sample in before_samples],
                    [sample.get("primary_events_per_sec") for sample in after_samples],
                    ci_iterations=ci_iterations,
                    ci_seed=ci_seed + (index * 50) + 2,
                ),
                "detection_latency_ms_p99": paired_metric_report(
                    [((sample.get("latency_ms") or {}).get("p99")) for sample in before_samples],
                    [((sample.get("latency_ms") or {}).get("p99")) for sample in after_samples],
                    ci_iterations=ci_iterations,
                    ci_seed=ci_seed + (index * 50) + 3,
                ),
                "application_overhead_pct": paired_metric_report(
                    [sample.get("application_overhead_pct") for sample in before_samples],
                    [sample.get("application_overhead_pct") for sample in after_samples],
                    ci_iterations=ci_iterations,
                    ci_seed=ci_seed + (index * 50) + 4,
                ),
                "agent_cpu_total_pct": paired_metric_report(
                    [((sample.get("agent_cpu") or {}).get("total_pct")) for sample in before_samples],
                    [((sample.get("agent_cpu") or {}).get("total_pct")) for sample in after_samples],
                    ci_iterations=ci_iterations,
                    ci_seed=ci_seed + (index * 50) + 5,
                ),
                "bpf_avg_ns_per_run": paired_metric_report(
                    [((sample.get("bpf") or {}).get("summary", {}).get("avg_ns_per_run")) for sample in before_samples],
                    [((sample.get("bpf") or {}).get("summary", {}).get("avg_ns_per_run")) for sample in after_samples],
                    ci_iterations=ci_iterations,
                    ci_seed=ci_seed + (index * 50) + 6,
                ),
                "lost_event_count": paired_metric_report(
                    [((sample.get("drop_counters") or {}).get("lost_event_count")) for sample in before_samples],
                    [((sample.get("drop_counters") or {}).get("lost_event_count")) for sample in after_samples],
                    ci_iterations=ci_iterations,
                    ci_seed=ci_seed + (index * 50) + 7,
                ),
            }
        )

    baseline_programs = aggregate_programs(baseline)
    post_programs = aggregate_programs(post)
    program_rows: list[dict[str, object]] = []
    for prog_id in sorted(set(baseline_programs) | set(post_programs), key=int):
        before = baseline_programs.get(prog_id, {})
        after = post_programs.get(prog_id, {})
        program_rows.append(
            {
                "id": int(prog_id),
                "name": str(after.get("name") or before.get("name") or f"id-{prog_id}"),
                "baseline_avg_ns_per_run": before.get("avg_ns_per_run"),
                "post_avg_ns_per_run": after.get("avg_ns_per_run"),
                "delta_pct": percent_delta(before.get("avg_ns_per_run"), after.get("avg_ns_per_run")),
            }
        )

    return {
        "comparable": True,
        "workloads": workload_rows,
        "programs": program_rows,
    }


def append_preflight_markdown(lines: list[str], preflight: Mapping[str, object]) -> None:
    lines.extend(["## Preflight", ""])
    activity = preflight.get("program_activity") if isinstance(preflight.get("program_activity"), Mapping) else {}
    for workload in phase_records(preflight):
        details = [
            f"primary_events/s={workload.get('primary_events_per_sec')}",
            f"bpf_avg_ns={((workload.get('bpf') or {}).get('summary', {}).get('avg_ns_per_run'))}",
        ]
        target_activity = activity.get("target_programs") if isinstance(activity, Mapping) else None
        if isinstance(target_activity, Mapping):
            details.append(f"target_runs={target_activity.get('total_run_cnt')}")
        apply_activity = activity.get("apply_programs") if isinstance(activity, Mapping) else None
        if isinstance(apply_activity, Mapping) and target_activity != apply_activity:
            details.append(f"apply_runs={apply_activity.get('total_run_cnt')}")
        lines.append(f"- {workload['name']}: " + ", ".join(details))
    lines.append("")


def _summary_mean(summary: Mapping[str, object] | None) -> object:
    return None if summary is None else summary.get("mean")


def _summary_ci(summary: Mapping[str, object] | None) -> str:
    if summary is None:
        return "n/a"
    ci = summary.get("mean_ci95")
    if not isinstance(ci, Mapping):
        return "n/a"
    return f"[{ci.get('low')}, {ci.get('high')}]"


def _paired_delta_mean(report: Mapping[str, object] | None) -> object:
    if report is None:
        return None
    delta = report.get("pct_delta")
    if not isinstance(delta, Mapping):
        return None
    return delta.get("mean")


def build_markdown(payload: Mapping[str, object]) -> str:
    preflight = payload.get("preflight")
    lines = [
        "# Tracee Real End-to-End Benchmark",
        "",
        f"- Generated: {payload['generated_at']}",
        f"- Mode: `{payload['mode']}`",
        f"- Duration per workload: `{payload['duration_s']}s`",
        f"- Warmup per workload: `{payload.get('warmup_duration_s')}s`",
        f"- Paired cycles: `{payload.get('sample_count')}`",
        f"- Latency probes per phase: `{payload.get('latency_probe_count')}`",
        f"- Smoke: `{payload['smoke']}`",
        f"- Tracee binary: `{payload.get('tracee_binary') or 'unavailable'}`",
        "",
        "## Setup",
        "",
        f"- Setup return code: `{payload['setup']['returncode']}`",
        f"- Setup tracee binary: `{payload['setup'].get('tracee_binary') or 'missing'}`",
        "",
    ]
    status = str(payload.get("status") or "")
    if status != "ok":
        result_reason = payload.get("error_message") or "unknown"
        lines.extend(
            [
                "## Result",
                "",
                "- Status: `ERROR`",
                f"- Reason: `{result_reason}`",
            ]
        )
        if isinstance(preflight, Mapping):
            lines.append("")
            append_preflight_markdown(lines, preflight)
        limitations = payload.get("limitations") or []
        if limitations:
            lines.extend(["", "## Limitations", ""])
            for limitation in limitations:
                lines.append(f"- {limitation}")
        lines.append("")
        return "\n".join(lines)

    if isinstance(preflight, Mapping):
        append_preflight_markdown(lines, preflight)

    control = payload.get("control")
    if isinstance(control, Mapping):
        lines.extend(["## Control", ""])
        for workload in control.get("workloads") or []:
            lines.append(
                f"- {workload['name']}: app_mean={_summary_mean(workload.get('app_throughput'))} {workload['metric']}, "
                f"app_ci95={_summary_ci(workload.get('app_throughput'))}"
            )
        lines.append("")

    lines.extend(["## Baseline", ""])
    baseline = payload["baseline"]
    for workload in baseline.get("workloads") or []:
        lines.append(
            f"- {workload['name']}: app_mean={_summary_mean(workload.get('app_throughput'))} {workload['metric']}, "
            f"primary_events_mean={_summary_mean(workload.get('primary_events_per_sec'))}/s, "
            f"latency_p99_mean={_summary_mean(workload.get('detection_latency_ms_p99'))} ms, "
            f"overhead_mean={_summary_mean(workload.get('application_overhead_pct'))}%, "
            f"bpf_avg_ns_mean={_summary_mean(workload.get('bpf_avg_ns_per_run'))}"
        )
    lines.append("")
    post = payload.get("post_rejit")
    if post:
        lines.extend(["## Post-ReJIT", ""])
        for workload in post.get("workloads") or []:
            lines.append(
                f"- {workload['name']}: app_mean={_summary_mean(workload.get('app_throughput'))} {workload['metric']}, "
                f"primary_events_mean={_summary_mean(workload.get('primary_events_per_sec'))}/s, "
                f"latency_p99_mean={_summary_mean(workload.get('detection_latency_ms_p99'))} ms, "
                f"overhead_mean={_summary_mean(workload.get('application_overhead_pct'))}%, "
                f"bpf_avg_ns_mean={_summary_mean(workload.get('bpf_avg_ns_per_run'))}"
            )
        lines.append("")
    comparison = payload.get("comparison") or {}
    lines.extend(["## Comparison", ""])
    if comparison.get("comparable"):
        for workload in comparison.get("workloads", []):
            lines.append(
                f"- {workload['name']}: "
                f"app_delta_mean={_paired_delta_mean(workload.get('app_throughput'))}%, "
                f"event_delta_mean={_paired_delta_mean(workload.get('primary_events_per_sec'))}%, "
                f"overhead_delta_mean={_paired_delta_mean(workload.get('application_overhead_pct'))}%, "
                f"latency_p99_delta_mean={_paired_delta_mean(workload.get('detection_latency_ms_p99'))}%, "
                f"app_p={workload.get('app_throughput', {}).get('p_value')}, "
                f"overhead_p={workload.get('application_overhead_pct', {}).get('p_value')}"
            )
    else:
        lines.append("- Comparable: `False`")
        lines.append(f"- Reason: `{comparison.get('reason', 'unknown')}`")
    limitations = payload.get("limitations") or []
    if limitations:
        lines.extend(["", "## Limitations", ""])
        for limitation in limitations:
            lines.append(f"- {limitation}")
    lines.append("")
    return "\n".join(lines)


def run_phase(
    workloads: Sequence[Mapping[str, object]],
    duration_s: int,
    prog_ids: list[int],
    *,
    cycle_index: int,
    phase_name: str,
    warmup_duration_s: int | float,
    latency_probe_count: int,
    latency_probe_timeout_s: float,
    ci_iterations: int,
    ci_seed: int,
    prog_fds: dict[int, int] | None,
    agent_pid: int | None,
    collector: TraceeOutputCollector | None,
    control_records: Sequence[Mapping[str, object]] | None = None,
    require_tracee_activity: bool = False,
) -> dict[str, object]:
    del control_records
    records: list[dict[str, object]] = []
    for index, workload_spec in enumerate(workloads):
        warmup = warmup_workload(workload_spec, warmup_duration_s)
        latency_probe = None
        if collector is not None and phase_name != "control" and latency_probe_count > 0:
            latency_probe = measure_latency_probes(
                workload_spec,
                collector=collector,
                probe_count=latency_probe_count,
                timeout_s=latency_probe_timeout_s,
                ci_iterations=ci_iterations,
                ci_seed=ci_seed + (index * 10),
            )
        record = measure_workload(
            workload_spec,
            duration_s,
            prog_ids,
            cycle_index=cycle_index,
            phase_name=phase_name,
            control_throughput=None,
            latency_probe=latency_probe,
            prog_fds=prog_fds,
            agent_pid=agent_pid,
            collector=collector,
        )
        record["warmup"] = warmup
        verify_phase_measurement(record, require_tracee_activity=require_tracee_activity and phase_name != "control")
        records.append(record)
    return {
        "phase": phase_name,
        "cycle_index": cycle_index,
        "workloads": records,
        "summary": summarize_phase(records, ci_iterations=ci_iterations, ci_seed=ci_seed + 1000),
    }


def error_payload(
    *,
    config: Mapping[str, object],
    duration_s: int,
    tracee_binary: str | None,
    setup_result: Mapping[str, object],
    smoke: bool,
    error_message: str,
    limitations: Sequence[str],
    preflight: Mapping[str, object] | None = None,
) -> dict[str, object]:
    return {
        "generated_at": datetime.now(timezone.utc).isoformat(),
        "status": "error",
        "mode": "error",
        "error_message": error_message,
        "smoke": smoke,
        "duration_s": duration_s,
        "tracee_binary": tracee_binary,
        "tracee_programs": [],
        "setup": dict(setup_result),
        "host": host_metadata(),
        "config": dict(config),
        "preflight": None if preflight is None else dict(preflight),
        "control": None,
        "baseline": None,
        "paired_cycles": [],
        "scan_results": {},
        "rejit_result": None,
        "post_rejit": None,
        "comparison": {"comparable": False, "reason": error_message},
        "limitations": list(limitations),
        "map_capture": None,
    }


def run_tracee_case(args: argparse.Namespace) -> dict[str, object]:
    config = load_config(Path(args.config).resolve())
    duration_s = int(args.duration or config.get("measurement_duration_s") or 20)
    if args.smoke and not args.duration:
        duration_s = int(config.get("smoke_duration_s") or 8)
    sample_count_value = config.get("smoke_sample_count") if args.smoke else config.get("sample_count")
    sample_count = int(sample_count_value or (DEFAULT_SMOKE_SAMPLE_COUNT if args.smoke else DEFAULT_SAMPLE_COUNT))
    preflight_duration_s = int(config.get("preflight_duration_s") or 0)
    warmup_value = config.get("smoke_warmup_duration_s") if args.smoke else config.get("warmup_duration_s")
    warmup_duration_s = float(warmup_value or (DEFAULT_SMOKE_WARMUP_DURATION_S if args.smoke else DEFAULT_WARMUP_DURATION_S))
    latency_probe_value = config.get("smoke_latency_probe_count") if args.smoke else config.get("latency_probe_count")
    latency_probe_count = int(
        latency_probe_value or (DEFAULT_SMOKE_LATENCY_PROBE_COUNT if args.smoke else DEFAULT_LATENCY_PROBE_COUNT)
    )
    latency_probe_timeout_s = float(config.get("latency_probe_timeout_s") or DEFAULT_LATENCY_PROBE_TIMEOUT_S)
    statistics_config = config.get("statistics") if isinstance(config.get("statistics"), Mapping) else {}
    ci_iterations = int((statistics_config or {}).get("bootstrap_iterations") or DEFAULT_BOOTSTRAP_ITERATIONS)
    ci_seed = int((statistics_config or {}).get("bootstrap_seed") or DEFAULT_BOOTSTRAP_SEED)
    require_program_activity = bool(config.get("require_program_activity", False))

    daemon_binary = Path(args.daemon).resolve()
    ensure_artifacts(daemon_binary)

    setup_result = {
        "returncode": 0,
        "tracee_binary": None,
        "stdout_tail": "",
        "stderr_tail": "",
    }
    tracee_binary = resolve_tracee_binary(args.tracee_binary, setup_result)
    if tracee_binary is None and not args.skip_setup:
        setup_result = run_setup_script(Path(args.setup_script).resolve())
        tracee_binary = resolve_tracee_binary(args.tracee_binary, setup_result)
    elif tracee_binary is not None:
        setup_result["tracee_binary"] = tracee_binary
        setup_result["stdout_tail"] = "Tracee setup skipped: using an already available binary."

    limitations: list[str] = []
    if setup_result["returncode"] != 0:
        limitations.append("Setup script returned non-zero; only the real Tracee binary path was attempted.")
    if tracee_binary is None:
        return error_payload(
            config=config,
            duration_s=duration_s,
            tracee_binary=None,
            setup_result=setup_result,
            smoke=bool(args.smoke),
            error_message="Tracee binary is unavailable in this environment; manual .bpf.o fallback is forbidden.",
            limitations=limitations,
        )
    if require_program_activity and preflight_duration_s <= 0:
        limitations.append("require_program_activity requires preflight_duration_s > 0.")
        return error_payload(
            config=config,
            duration_s=duration_s,
            tracee_binary=tracee_binary,
            setup_result=setup_result,
            smoke=bool(args.smoke),
            error_message="require_program_activity requires preflight_duration_s > 0",
            limitations=limitations,
        )

    workloads = list(config.get("workloads") or [])
    if not workloads:
        return error_payload(
            config=config,
            duration_s=duration_s,
            tracee_binary=tracee_binary,
            setup_result=setup_result,
            smoke=bool(args.smoke),
            error_message="Tracee config contains no workloads",
            limitations=limitations,
        )
    events = list(config.get("events") or [])
    commands = build_tracee_commands(tracee_binary, events, args.tracee_extra_arg or [])
    preflight: dict[str, object] | None = None
    runner_binary = Path(args.runner).resolve()

    try:
        map_capture: dict[str, object] | None = None
        cycle_results: list[dict[str, object]] = []
        tracee_programs: list[dict[str, object]] = []
        selected_programs: list[dict[str, object]] = []
        apply_programs: list[dict[str, object]] = []
        with enable_bpf_stats():
            for cycle_index in range(sample_count):
                cycle_seed = ci_seed + (cycle_index * 5000)
                control_phase = run_phase(
                    workloads,
                    duration_s,
                    [],
                    cycle_index=cycle_index,
                    phase_name="control",
                    warmup_duration_s=warmup_duration_s,
                    latency_probe_count=0,
                    latency_probe_timeout_s=latency_probe_timeout_s,
                    ci_iterations=ci_iterations,
                    ci_seed=cycle_seed,
                    prog_fds=None,
                    agent_pid=None,
                    collector=None,
                )
                control_records = tuple(dict(record) for record in (control_phase.get("workloads") or []))
                if not control_records:
                    raise RuntimeError("control phase produced no workload measurements")

                def setup() -> dict[str, object]:
                    return {}

                def start(_: object) -> CaseLifecycleState:
                    runner = TraceeRunner(
                        tracee_binary=tracee_binary,
                        events=events,
                        extra_args=args.tracee_extra_arg or [],
                        load_timeout_s=int(args.load_timeout),
                    )
                    runner.start()
                    cycle_selected_programs = select_tracee_programs(runner.programs, config)
                    prog_ids = [int(program["id"]) for program in cycle_selected_programs]
                    if config.get("apply_programs"):
                        cycle_apply_programs = select_tracee_programs(
                            runner.programs,
                            config,
                            config_key="apply_programs",
                            allow_all_when_unset=False,
                        )
                        apply_prog_ids = [int(program["id"]) for program in cycle_apply_programs]
                    else:
                        cycle_apply_programs = [dict(program) for program in cycle_selected_programs]
                        apply_prog_ids = list(prog_ids)
                    return CaseLifecycleState(
                        runtime=runner,
                        target_prog_ids=prog_ids,
                        apply_prog_ids=apply_prog_ids,
                        scan_kwargs={"prog_fds": runner.program_fds},
                        artifacts={
                            "tracee_programs": runner.programs,
                            "selected_tracee_programs": cycle_selected_programs,
                            "apply_tracee_programs": cycle_apply_programs,
                        },
                    )

                def before_baseline(_: object, lifecycle: CaseLifecycleState) -> LifecycleAbort | None:
                    nonlocal preflight
                    if preflight is not None or preflight_duration_s <= 0:
                        return None
                    runner = lifecycle.runtime
                    assert isinstance(runner, TraceeRunner)
                    preflight_prog_ids = sorted(set(lifecycle.target_prog_ids) | set(lifecycle.apply_prog_ids))
                    preflight = run_phase(
                        list(workloads),
                        preflight_duration_s,
                        preflight_prog_ids,
                        cycle_index=cycle_index,
                        phase_name="preflight",
                        warmup_duration_s=0,
                        latency_probe_count=0,
                        latency_probe_timeout_s=latency_probe_timeout_s,
                        ci_iterations=ci_iterations,
                        ci_seed=cycle_seed + 250,
                        prog_fds=runner.program_fds,
                        agent_pid=runner.pid,
                        collector=runner.collector,
                    )
                    preflight["program_activity"] = {
                        "target_programs": summarize_program_activity(preflight, lifecycle.target_prog_ids),
                        "apply_programs": summarize_program_activity(preflight, lifecycle.apply_prog_ids),
                    }
                    lifecycle.artifacts["preflight"] = preflight
                    if not require_program_activity:
                        return None

                    target_run_cnt = int(
                        ((preflight.get("program_activity") or {}).get("target_programs") or {}).get("total_run_cnt", 0)
                        or 0
                    )
                    apply_run_cnt = int(
                        ((preflight.get("program_activity") or {}).get("apply_programs") or {}).get("total_run_cnt", 0)
                        or 0
                    )
                    if target_run_cnt <= 0:
                        limitations.append(
                            "Configured Tracee events/workload did not execute the selected target programs during preflight."
                        )
                        return LifecycleAbort(
                            status="error",
                            reason="preflight observed zero target-program executions; target workload did not exercise the selected programs",
                            artifacts={"preflight": preflight},
                        )
                    if config.get("apply_programs") and apply_run_cnt <= 0:
                        limitations.append(
                            "Configured Tracee events/workload did not execute the configured apply programs during preflight."
                        )
                        return LifecycleAbort(
                            status="error",
                            reason="preflight observed zero apply-program executions; configured apply programs were not exercised",
                            artifacts={"preflight": preflight},
                        )
                    return None

                def workload(_: object, lifecycle: CaseLifecycleState, phase_name: str) -> dict[str, object]:
                    runner = lifecycle.runtime
                    assert isinstance(runner, TraceeRunner)
                    phase_result = run_phase(
                        workloads,
                        duration_s,
                        lifecycle.target_prog_ids,
                        cycle_index=cycle_index,
                        phase_name=phase_name,
                        warmup_duration_s=warmup_duration_s,
                        latency_probe_count=latency_probe_count,
                        latency_probe_timeout_s=latency_probe_timeout_s,
                        ci_iterations=ci_iterations,
                        ci_seed=cycle_seed + (500 if phase_name == "post_rejit" else 0),
                        prog_fds=runner.program_fds,
                        agent_pid=runner.pid,
                        collector=runner.collector,
                        control_records=control_records,
                        require_tracee_activity=True,
                    )
                    return attach_control_phase_metrics(
                        phase_result,
                        control_records,
                        ci_iterations=ci_iterations,
                        ci_seed=cycle_seed + (1500 if phase_name == "post_rejit" else 1000),
                    )

                def after_baseline(_: object, lifecycle: CaseLifecycleState, baseline: Mapping[str, object]) -> dict[str, object] | None:
                    del baseline
                    nonlocal map_capture
                    if not args.capture_maps or map_capture is not None:
                        return None
                    cycle_apply_programs = lifecycle.artifacts["apply_tracee_programs"]
                    assert isinstance(cycle_apply_programs, list)
                    capture_plan = build_map_capture_specs(
                        cycle_apply_programs,
                        repo_name="tracee",
                        object_paths=sorted((ROOT_DIR / "corpus" / "build" / "tracee").glob("*.bpf.o")),
                        runner_binary=runner_binary,
                    )
                    map_capture = {
                        "cycle_index": cycle_index,
                        "discovery": {
                            key: value
                            for key, value in capture_plan.items()
                            if key != "program_specs"
                        },
                    }
                    map_capture["result"] = capture_map_state(
                        captured_from="e2e/tracee",
                        program_specs=capture_plan["program_specs"],
                        optimize_results={},
                    )
                    return {"map_capture": map_capture}

                def stop(_: object, lifecycle: CaseLifecycleState) -> None:
                    runner = lifecycle.runtime
                    assert isinstance(runner, TraceeRunner)
                    runner.stop()

                def cleanup(_: object) -> None:
                    return None

                lifecycle_result = run_case_lifecycle(
                    daemon_binary=daemon_binary,
                    setup=setup,
                    start=start,
                    workload=workload,
                    stop=stop,
                    cleanup=cleanup,
                    before_baseline=before_baseline,
                    after_baseline=after_baseline,
                    enabled_passes=benchmark_rejit_enabled_passes(),
                )

                if lifecycle_result.abort is not None:
                    return error_payload(
                        config=config,
                        duration_s=duration_s,
                        tracee_binary=tracee_binary,
                        setup_result=setup_result,
                        smoke=bool(args.smoke),
                        error_message=lifecycle_result.abort.reason,
                        limitations=limitations,
                        preflight=preflight,
                    )

                if lifecycle_result.state is None or lifecycle_result.baseline is None:
                    raise RuntimeError(f"Tracee lifecycle cycle {cycle_index} completed without a baseline phase")
                if not lifecycle_result.rejit_result or not lifecycle_result.rejit_result.get("applied"):
                    raise RuntimeError(f"Tracee reJIT did not apply in cycle {cycle_index}: {lifecycle_result.rejit_result}")
                if lifecycle_result.post_rejit is None:
                    raise RuntimeError(f"Tracee post-ReJIT phase is missing in cycle {cycle_index}")

                cycle_scan_results = lifecycle_result.scan_results
                cycle_baseline = lifecycle_result.baseline
                cycle_post_rejit = lifecycle_result.post_rejit
                cycle_comparison = compare_phases(
                    cycle_baseline,
                    cycle_post_rejit,
                    control=control_phase,
                    ci_iterations=ci_iterations,
                    ci_seed=cycle_seed + 1000,
                )
                cycle_results.append(
                    {
                        "cycle_index": cycle_index,
                        "control": control_phase,
                        "baseline": cycle_baseline,
                        "scan_results": {str(key): value for key, value in cycle_scan_results.items()},
                        "rejit_result": lifecycle_result.rejit_result,
                        "post_rejit": cycle_post_rejit,
                        "comparison": cycle_comparison,
                    }
                )

                if not tracee_programs:
                    tracee_programs = list(lifecycle_result.artifacts.get("tracee_programs") or [])
                if not selected_programs:
                    selected_programs = list(lifecycle_result.artifacts.get("selected_tracee_programs") or [])
                if not apply_programs:
                    apply_programs = list(lifecycle_result.artifacts.get("apply_tracee_programs") or [])
    except Exception as exc:
        return error_payload(
            config=config,
            duration_s=duration_s,
            tracee_binary=tracee_binary,
            setup_result=setup_result,
            smoke=bool(args.smoke),
            error_message=f"Tracee case could not run: {exc}",
            limitations=limitations,
            preflight=preflight,
        )

    control = aggregate_phase_samples(
        "control",
        [sample for cycle in cycle_results for sample in phase_records(cycle["control"])],
        ci_iterations=ci_iterations,
        ci_seed=ci_seed + 20000,
    )
    baseline = aggregate_phase_samples(
        "baseline",
        [sample for cycle in cycle_results for sample in phase_records(cycle["baseline"])],
        ci_iterations=ci_iterations,
        ci_seed=ci_seed + 25000,
    )
    post_rejit = aggregate_phase_samples(
        "post_rejit",
        [sample for cycle in cycle_results for sample in phase_records(cycle["post_rejit"])],
        ci_iterations=ci_iterations,
        ci_seed=ci_seed + 30000,
    )
    comparison = compare_phases(
        baseline,
        post_rejit,
        control=control,
        ci_iterations=ci_iterations,
        ci_seed=ci_seed + 35000,
    )

    payload = {
        "generated_at": datetime.now(timezone.utc).isoformat(),
        "status": "ok",
        "mode": "tracee_daemon_same_image_paired_with_control",
        "smoke": bool(args.smoke),
        "duration_s": duration_s,
        "sample_count": sample_count,
        "warmup_duration_s": warmup_duration_s,
        "latency_probe_count": latency_probe_count,
        "latency_probe_timeout_s": latency_probe_timeout_s,
        "tracee_binary": tracee_binary,
        "tracee_launch_command": commands,
        "tracee_programs": tracee_programs,
        "selected_tracee_programs": selected_programs,
        "apply_tracee_programs": apply_programs,
        "setup": setup_result,
        "host": host_metadata(),
        "config": dict(config),
        "statistics": {
            "bootstrap_iterations": ci_iterations,
            "bootstrap_seed": ci_seed,
            "significance_test": "exact_paired_permutation_on_signed_deltas",
        },
        "preflight": preflight,
        "control": control,
        "baseline": baseline,
        "paired_cycles": cycle_results,
        "scan_results": {str(cycle["cycle_index"]): cycle["scan_results"] for cycle in cycle_results},
        "rejit_result": {str(cycle["cycle_index"]): cycle["rejit_result"] for cycle in cycle_results},
        "post_rejit": post_rejit,
        "comparison": comparison,
        "limitations": limitations,
        "map_capture": map_capture,
    }
    return payload


def build_case_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(description="Run the Tracee real end-to-end benchmark.")
    parser.add_argument("--config", default=str(DEFAULT_CONFIG))
    parser.add_argument("--setup-script", default=str(DEFAULT_SETUP_SCRIPT))
    parser.add_argument("--output-json", default=str(DEFAULT_OUTPUT_JSON))
    parser.add_argument("--output-md", default=str(DEFAULT_OUTPUT_MD))
    parser.add_argument("--tracee-binary")
    parser.add_argument("--daemon", default=str(DEFAULT_DAEMON))
    parser.add_argument("--runner", default=str(ROOT_DIR / "runner" / "build" / "micro_exec"))
    parser.add_argument("--duration", type=int)
    parser.add_argument("--smoke", action="store_true")
    parser.add_argument("--load-timeout", type=int, default=20)
    parser.add_argument("--tracee-extra-arg", action="append", default=[])
    parser.add_argument("--capture-maps", action="store_true")
    parser.add_argument("--skip-setup", action="store_true")
    return parser


def main(argv: Sequence[str] | None = None) -> int:
    parser = build_case_parser()
    args = parser.parse_args(argv)
    payload = run_tracee_case(args)
    if args.output_json == str(DEFAULT_OUTPUT_JSON) and args.smoke:
        output_json = smoke_output_path(RESULTS_DIR, "tracee")
    else:
        output_json = Path(args.output_json).resolve()
    persist_results(payload, output_json, Path(args.output_md).resolve(), build_markdown)
    print(json.dumps(payload, indent=2, sort_keys=True))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
