from __future__ import annotations

import json
import os
import re
import select
import shlex
import signal
import socket
import subprocess
import sys
import tempfile
import threading
import time
from dataclasses import asdict, dataclass
from http.server import BaseHTTPRequestHandler, ThreadingHTTPServer
from contextlib import contextmanager
from pathlib import Path
from typing import Iterator, Mapping, Sequence

from . import run_command, tail_text, which
from .benchmark_net import BENCHMARK_IFACE, BENCHMARK_NETNS, BENCHMARK_PEER_IFACE_IP


def resolve_workload_tool(name: str) -> str:
    tool_dir = os.environ.get("BPFREJIT_WORKLOAD_TOOL_BIN_DIR", "").strip()
    if tool_dir:
        candidate = Path(tool_dir) / name
        if candidate.is_file() and os.access(candidate, os.X_OK):
            return str(candidate)
        raise RuntimeError(f"{name} is required in workload tool artifact dir: {candidate}")
    resolved = which(name)
    if resolved is not None:
        return resolved
    raise RuntimeError(f"{name} is required for this workload")


@dataclass(frozen=True)
class WorkloadResult:
    ops_total: float
    ops_per_sec: float | None
    duration_s: float
    stdout: str
    stderr: str

    def to_dict(self) -> dict[str, object]:
        return asdict(self)


class _SilentHandler(BaseHTTPRequestHandler):
    protocol_version = "HTTP/1.1"

    def do_GET(self) -> None:  # noqa: N802
        payload = b"tracee-benchmark\n"
        self.send_response(200)
        self.send_header("Content-Type", "text/plain")
        self.send_header("Content-Length", str(len(payload)))
        self.end_headers()
        try:
            self.wfile.write(payload)
        except (BrokenPipeError, ConnectionResetError, ConnectionAbortedError, socket.timeout):
            return

    def log_message(self, format: str, *args: object) -> None:
        del format, args


class _ThreadingHTTPServerV6(ThreadingHTTPServer):
    address_family = socket.AF_INET6


class LocalHttpServer:
    def __init__(self, host: str = "127.0.0.1") -> None:
        self.host = str(host)
        self.family = socket.AF_INET6 if ":" in self.host else socket.AF_INET
        server_class = _ThreadingHTTPServerV6 if self.family == socket.AF_INET6 else ThreadingHTTPServer
        bind_address: tuple[object, ...] = (self.host, 0, 0, 0) if self.family == socket.AF_INET6 else (self.host, 0)
        self.server = server_class(bind_address, _SilentHandler)
        self.thread = threading.Thread(target=self.server.serve_forever, daemon=True)

    @property
    def url(self) -> str:
        if self.family == socket.AF_INET6:
            host, port, _flowinfo, _scopeid = self.server.server_address
            return f"http://[{host}]:{port}/"
        host, port = self.server.server_address
        return f"http://{host}:{port}/"

    def __enter__(self) -> "LocalHttpServer":
        self.thread.start()
        return self

    def __exit__(self, exc_type, exc, tb) -> None:
        self.server.shutdown()
        self.thread.join(timeout=2.0)
        self.server.server_close()


_NAMESPACED_HTTP_SERVER_SCRIPT = """
from http.server import BaseHTTPRequestHandler, ThreadingHTTPServer
import socket
import sys

class SilentHandler(BaseHTTPRequestHandler):
    protocol_version = "HTTP/1.1"

    def do_GET(self):
        payload = b"tracee-benchmark\\n"
        self.send_response(200)
        self.send_header("Content-Type", "text/plain")
        self.send_header("Content-Length", str(len(payload)))
        self.end_headers()
        try:
            self.wfile.write(payload)
        except (BrokenPipeError, ConnectionResetError, ConnectionAbortedError, socket.timeout):
            return

    def log_message(self, format, *args):
        del format, args

host = sys.argv[1]
port = int(sys.argv[2])
if ":" in host:
    class Server(ThreadingHTTPServer):
        address_family = socket.AF_INET6
    bind_address = (host, port, 0, 0)
else:
    Server = ThreadingHTTPServer
    bind_address = (host, port)
server = Server(bind_address, SilentHandler)
print("READY", flush=True)
server.serve_forever()
"""
_NAMESPACED_HTTP_READY_MARKER = "READY"


def _wait_for_stdout_marker(
    process: subprocess.Popen[str],
    *,
    marker: str,
    deadline: float,
    description: str,
) -> None:
    stdout_lines: list[str] = []
    while time.monotonic() < deadline:
        if process.stdout is not None:
            readable, _, _ = select.select([process.stdout], [], [], 0)
            if readable:
                line = process.stdout.readline()
                if line:
                    stdout_lines.append(line)
                    if line.strip() == marker:
                        return
        if process.poll() is not None:
            stdout = "".join(stdout_lines)
            if process.stdout is not None:
                stdout += process.stdout.read()
            stderr = "" if process.stderr is None else process.stderr.read()
            raise RuntimeError(
                f"{description} exited before becoming ready: "
                f"{tail_text(stderr or stdout, max_lines=20, max_chars=4000)}"
            )
        time.sleep(0.05)
    raise TimeoutError(f"{description} did not print {marker!r}")


class NamespacedHttpServer:
    def __init__(self, namespace: str, host: str, port: int = 18080) -> None:
        self.namespace = str(namespace).strip()
        self.host = str(host).strip()
        self.port = int(port)
        self.process: subprocess.Popen[str] | None = None

    @property
    def url(self) -> str:
        if ":" in self.host:
            return f"http://[{self.host}]:{self.port}/"
        return f"http://{self.host}:{self.port}/"

    def __enter__(self) -> "NamespacedHttpServer":
        ip_binary = which("ip")
        if ip_binary is None:
            raise RuntimeError("ip is required for interface-bound network workloads")
        python_binary = sys.executable or which("python3")
        if not python_binary:
            raise RuntimeError("python3 is required for interface-bound network workloads")
        self.process = subprocess.Popen(
            [
                ip_binary,
                "netns",
                "exec",
                self.namespace,
                python_binary,
                "-u",
                "-c",
                _NAMESPACED_HTTP_SERVER_SCRIPT,
                self.host,
                str(self.port),
            ],
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            text=True,
            bufsize=1,
        )
        deadline = time.monotonic() + 5.0
        try:
            _wait_for_stdout_marker(
                self.process,
                marker=_NAMESPACED_HTTP_READY_MARKER,
                deadline=deadline,
                description="interface-bound HTTP server",
            )
        except TimeoutError as exc:
            self.__exit__(None, None, None)
            raise RuntimeError(
                f"interface-bound HTTP server in namespace {self.namespace} did not report ready at {self.url}"
            ) from exc
        except RuntimeError:
            self.__exit__(None, None, None)
            raise
        return self

    def __exit__(self, exc_type, exc, tb) -> None:
        del exc_type, exc, tb
        if self.process is None:
            return
        process = self.process
        self.process = None
        if process.poll() is None:
            process.terminate()
            try:
                process.wait(timeout=5)
            except subprocess.TimeoutExpired:
                process.kill()
                process.wait(timeout=5)
        if process.stdout is not None:
            process.stdout.close()
        if process.stderr is not None:
            process.stderr.close()


def _finish_result(ops_total: float, duration_s: float, stdout: str, stderr: str) -> WorkloadResult:
    return WorkloadResult(
        ops_total=float(ops_total),
        ops_per_sec=(float(ops_total) / duration_s) if duration_s > 0 else None,
        duration_s=duration_s,
        stdout=tail_text(stdout, max_lines=40, max_chars=8000),
        stderr=tail_text(stderr, max_lines=40, max_chars=8000),
    )


def _merge_workload_results(results: Sequence[WorkloadResult]) -> WorkloadResult:
    total_duration = sum(r.duration_s for r in results)
    total_ops = sum(r.ops_total for r in results)
    stdout = "\n".join(r.stdout for r in results if r.stdout)
    stderr = "\n".join(r.stderr for r in results if r.stderr)
    return WorkloadResult(ops_total=total_ops, ops_per_sec=(total_ops / total_duration) if total_duration > 0 else None,
                          duration_s=total_duration, stdout=tail_text(stdout, max_lines=80, max_chars=12000),
                          stderr=tail_text(stderr, max_lines=80, max_chars=12000))


_FLOAT_PATTERN = r"[-+]?(?:\d+(?:\.\d*)?|\.\d+)(?:[eE][-+]?\d+)?"
_STRESS_NG_METRIC_RE = re.compile(rf"stress-ng:\s+metrc:\s+\[\d+\]\s+(\S+)\s+({_FLOAT_PATTERN})\b")
_STRESS_NG_CPU_STRESSORS = ("cpu",)
_STRESS_NG_FILESYSTEM_STRESSORS = (
    "access",
    "chdir",
    "chmod",
    "chown",
    "dentry",
    "dir",
    "dirmany",
    "fallocate",
    "file-ioctl",
    "filename",
    "flock",
    "fpunch",
    "fstat",
    "getdent",
    "hdd",
    "inotify",
    "open",
    "rename",
    "touch",
    "utime",
    "link",
    "symlink",
    "mknod",
    "fcntl",
)
_STRESS_NG_IO_STRESSORS = (
    "aio",
    "aiol",
    "hdd",
    "io",
    "iomix",
    "io-uring",
    "sync-file",
)
_STRESS_NG_NETWORK_STRESSORS = (
    "epoll",
    "netdev",
    "sctp",
    "sock",
    "sockdiag",
    "sockfd",
    "sockpair",
    "sockmany",
    "udp",
    "udp-flood",
)
_STRESS_NG_OS_STRESSORS = (
    "cap",
    "eventfd",
    "get",
    "prctl",
    "set",
    "dup",
    "kill",
    "sigfd",
    "signal",
    "pty",
    "itimer",
    "timerfd",
)
_STRESS_NG_PROCESS_STRESSORS = (
    "clone",
    "exec",
    "fork",
    "vfork",
)
_STRESS_NG_SCHEDULER_STRESSORS = (
    "futex",
    "sem",
    "sem-sysv",
    "switch",
    "yield",
)
_STRESS_NG_MEMORY_STRESSORS = (
    "mmap",
    "mprotect",
    "mremap",
    "madvise",
)
_STRESS_NG_WORKLOAD_STRESSORS: Mapping[str, tuple[str, ...]] = {
    "stress_ng_cpu": _STRESS_NG_CPU_STRESSORS,
    "stress_ng_filesystem": _STRESS_NG_FILESYSTEM_STRESSORS,
    "stress_ng_os": _STRESS_NG_OS_STRESSORS,
    "stress_ng_process": _STRESS_NG_PROCESS_STRESSORS,
    "stress_ng_scheduler": _STRESS_NG_SCHEDULER_STRESSORS,
    "stress_ng_os_io_network": (
        *_STRESS_NG_OS_STRESSORS,
        *_STRESS_NG_IO_STRESSORS,
        *_STRESS_NG_NETWORK_STRESSORS,
        *_STRESS_NG_MEMORY_STRESSORS,
    ),
}

_STRESS_NG_STRESSOR_ARGS: Mapping[str, tuple[str, ...]] = {
    "fallocate": ("--fallocate-bytes", "128M"),
    "fpunch": ("--fpunch-bytes", "32M"),
    "hdd": ("--hdd-bytes", "128M"),
    "iomix": ("--iomix-bytes", "128M"),
    "mmap": ("--mmap-bytes", "16M"),
    "mremap": ("--mremap-bytes", "16M"),
    "open": ("--open-max", "1024"),
    "syscall": ("--syscall-method", "fast75"),
}
_STRESS_NG_NETWORK_PORT_STRESSORS = {
    "epoll": 100,
    "sctp": 200,
    "sock": 300,
    "sockfd": 400,
}


def _stress_ng_dynamic_stressor_args(stressors: Sequence[str]) -> list[str]:
    selected = {str(stressor).strip() for stressor in stressors if str(stressor).strip()}
    if not (selected & set(_STRESS_NG_NETWORK_PORT_STRESSORS)):
        return []
    base_port = 20000 + (os.getpid() % 30000)
    args: list[str] = []
    for stressor, offset in _STRESS_NG_NETWORK_PORT_STRESSORS.items():
        if stressor in selected:
            args.extend([f"--{stressor}-port", str(base_port + offset)])
    return args


def _stress_ng_metric_rows(text: str) -> list[tuple[str, float]]:
    rows: list[tuple[str, float]] = []
    for line in text.splitlines():
        if "stress-ng: metrc:" not in line:
            continue
        match = _STRESS_NG_METRIC_RE.search(line)
        if not match:
            continue
        matched_stressor, bogo_ops = match.groups()
        try:
            rows.append((matched_stressor, float(bogo_ops)))
        except ValueError:
            continue
    return rows


def parse_stress_ng_bogo_ops(text: str, *, stressor: str | None = None) -> float | None:
    for matched_stressor, bogo_ops in _stress_ng_metric_rows(text):
        if stressor and matched_stressor != stressor:
            continue
        return bogo_ops
    return None



def run_stress_ng_class_load(duration_s: int | float, stressors: Sequence[str], *, workload_name: str) -> WorkloadResult:
    stress_ng = which("stress-ng")
    if stress_ng is None:
        raise RuntimeError(f"stress-ng is required for the {workload_name} workload")
    normalized_stressors = tuple(str(stressor).strip() for stressor in stressors if str(stressor).strip())
    if not normalized_stressors:
        raise RuntimeError(f"{workload_name} workload requires at least one stress-ng stressor")
    seconds = max(1, int(round(float(duration_s))))
    temp_root = _disk_backed_tmp_root()
    command: list[str] = [stress_ng]
    # Use 4 workers per stressor so each rare-syscall stressor still gets
    # enough kernel time within a 1s smoke / 5s authoritative workload to
    # fire BPF hooks in heavy multi-policy agents (tetragon/tracee).
    for stressor in normalized_stressors:
        command += [f"--{stressor}", "4"]
        command += list(_STRESS_NG_STRESSOR_ARGS.get(stressor, ()))
    command += _stress_ng_dynamic_stressor_args(normalized_stressors)
    command += ["--timeout", f"{seconds}s", "--metrics-brief", "--temp-path", str(temp_root)]
    start = time.monotonic()
    try:
        completed = run_command(
            command,
            check=False,
            cwd=temp_root,
            timeout=max(float(seconds) + 30, float(seconds) * 4),
        )
    except subprocess.TimeoutExpired as exc:
        raise RuntimeError(f"{workload_name} workload timed out") from exc
    elapsed = time.monotonic() - start
    if completed.returncode != 0:
        raise RuntimeError(
            f"{workload_name} workload failed: "
            f"{tail_text(completed.stderr or completed.stdout)}"
        )
    combined = (completed.stdout or "") + "\n" + (completed.stderr or "")
    ops_total = sum(bogo_ops for _, bogo_ops in _stress_ng_metric_rows(combined))
    if ops_total <= 0:
        raise RuntimeError(
            f"{workload_name} workload did not report bogo-ops metrics: "
            f"{tail_text(combined)}"
        )
    return _finish_result(ops_total, elapsed, completed.stdout or "", completed.stderr or "")


def run_file_io(duration_s: int | float) -> WorkloadResult:
    fio_binary = which("fio")
    if fio_binary is None:
        raise RuntimeError("fio is required for the file_io workload")
    seconds = max(1, int(round(float(duration_s))))
    with tempfile.TemporaryDirectory(prefix="fio-randrw-", dir=str(_disk_backed_tmp_root())) as tempdir:
        cmd = [
            fio_binary,
            "--name=bench",
            "--rw=randrw",
            "--bs=4k",
            "--size=64M",
            "--numjobs=4",
            f"--runtime={seconds}",
            "--time_based",
            "--ioengine=sync",
            "--output-format=json",
        ]
        start = time.monotonic()
        c = run_command(cmd, check=False, cwd=Path(tempdir), timeout=float(seconds) + 60)
        elapsed = time.monotonic() - start
        if c.returncode != 0:
            raise RuntimeError(f"fio file_io workload failed: {tail_text(c.stderr or c.stdout)}")
        payload = json.loads(c.stdout)
        jobs = payload.get("jobs")
        if not isinstance(jobs, list) or not jobs:
            raise RuntimeError(f"fio file_io workload returned no job stats: {tail_text(c.stdout or json.dumps(payload))}")
        ops_total = 0.0
        for job in jobs:
            if not isinstance(job, dict):
                raise RuntimeError(f"fio file_io workload returned malformed job stats: {tail_text(c.stdout or json.dumps(payload))}")
            read_stats, write_stats = job.get("read"), job.get("write")
            if not isinstance(read_stats, dict) or not isinstance(write_stats, dict):
                raise RuntimeError(f"fio file_io workload returned malformed read/write stats: {tail_text(c.stdout or json.dumps(payload))}")
            ops_total += float(read_stats.get("total_ios", 0) or 0) + float(write_stats.get("total_ios", 0) or 0)
        if ops_total <= 0:
            raise RuntimeError(f"fio file_io workload did not report total_ios metrics: {tail_text(c.stdout or json.dumps(payload))}")
        return _finish_result(ops_total, elapsed, c.stdout or "", c.stderr or "")


def _disk_backed_tmp_root() -> Path:
    seen: set[Path] = set()
    candidates = [Path(os.environ.get(n, "").strip()) for n in ("TMPDIR", "TMP", "TEMP") if os.environ.get(n, "").strip()]
    candidates += [Path("/var/tmp"), Path("/tmp")]
    for candidate in candidates:
        resolved = candidate.expanduser()
        if resolved in seen: continue
        seen.add(resolved)
        try: resolved.mkdir(parents=True, exist_ok=True)
        except OSError: continue
        if os.access(resolved, os.W_OK | os.X_OK): return resolved
    raise RuntimeError("no writable disk-backed temporary directory is available")


def _network_http_server(network_device: str | None = None) -> LocalHttpServer | NamespacedHttpServer:
    normalized_device = str(network_device or "").strip()
    if not normalized_device:
        return LocalHttpServer()
    if normalized_device != BENCHMARK_IFACE:
        raise RuntimeError(
            f"interface-bound network workload only supports benchmark interface {BENCHMARK_IFACE}; "
            f"got {normalized_device}"
        )
    # Re-create the bpfbench veth/netns if a previous app teardown left them
    # missing or partially configured (e.g. cilium teardown deletes the veth).
    # Lazy import to avoid runner→workload cycle at import time.
    from .app_runners.cilium import _ensure_benchmark_interface
    _ensure_benchmark_interface()
    return NamespacedHttpServer(BENCHMARK_NETNS, BENCHMARK_PEER_IFACE_IP)


def _network_client_command(command: list[str], network_device: str | None = None) -> list[str]:
    normalized_device = str(network_device or "").strip()
    if not normalized_device:
        return command
    if normalized_device != BENCHMARK_IFACE:
        raise RuntimeError(
            f"interface-bound network workload only supports benchmark interface {BENCHMARK_IFACE}; "
            f"got {normalized_device}"
        )
    # Run the client in the root network namespace so traffic crosses the bpfbench0
    # veth and hits TC BPF programs attached there (cilium datapath).
    # The HTTP server stays inside bpfbenchns (see _network_http_server), so packets
    # travel: root-ns client → bpfbench0 → bpfbench1/bpfbenchns → server.
    return list(command)


def _render_command(command: Sequence[str]) -> str:
    return " ".join(shlex.quote(str(part)) for part in command)


@contextmanager
def _netem_qdisc(device: str, *, loss_pct: float, delay_ms: int) -> Iterator[None]:
    tc = which("tc")
    if tc is None:
        raise RuntimeError("tc binary required for netem-based workloads (install iproute2)")
    add = [tc, "qdisc", "add", "dev", device, "root", "netem",
           "loss", f"{loss_pct}%", "delay", f"{delay_ms}ms"]
    delete = [tc, "qdisc", "del", "dev", device, "root"]
    if run_command(add, check=False, timeout=10).returncode != 0:
        run_command(delete, check=False, timeout=10)
        if run_command(add, check=False, timeout=10).returncode != 0:
            raise RuntimeError(f"failed to install netem qdisc on {device}")
    try:
        yield
    finally:
        run_command(delete, check=False, timeout=10)


def run_network_lossy_multi_load(
    duration_s: int | float,
    *,
    network_device: str | None = None,
) -> WorkloadResult:
    """Network load with 20% packet loss + concurrent ICMP probes.

    Exercises ICMP plus HTTP traffic so multi-protocol datapath programs
    (e.g. cilium) receive packets across more program slots than plain HTTP
    load.

    Parameters chosen to maximise event volume for low-frequency BPF hooks
    while staying within standard netem stress-test parameter ranges:
    - 20% loss / 50 ms delay: aggressive but bounded; matches the upper end
      of typical netem WAN emulation profiles in networking literature.
    - wrk -t4 -c50: 200 concurrent flows -> ~10K connect events/s under loss.
    """
    if not network_device:
        raise RuntimeError("network_lossy_multi requires network_device")
    wrk_binary = resolve_workload_tool("wrk")
    ping_binary = which("ping")
    seconds = max(1, int(round(float(duration_s))))
    with _netem_qdisc(network_device, loss_pct=20.0, delay_ms=50):
        with _network_http_server(network_device) as server:
            ping_proc = None
            if ping_binary is not None:
                ping_cmd = _network_client_command(
                    [ping_binary, "-i", "0.01", "-q", "-w", str(seconds), BENCHMARK_PEER_IFACE_IP],
                    network_device,
                )
                ping_proc = subprocess.Popen(
                    ping_cmd, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL,
                )
            try:
                start = time.monotonic()
                command = _network_client_command(
                    [wrk_binary, "-t4", "-c50", f"-d{seconds}s", server.url],
                    network_device,
                )
                c = run_command(command, check=False, timeout=float(duration_s) + 30)
                elapsed = time.monotonic() - start
                if c.returncode != 0:
                    raise RuntimeError(
                        f"network_lossy_multi wrk load failed via {_render_command(command)}: "
                        f"{tail_text(c.stderr or c.stdout)}"
                    )
                total_requests = next(
                    (float(m.group(1))
                     for line in c.stdout.splitlines()
                     if (m := re.search(r"([0-9]+)\s+requests in", line.strip()))),
                    None,
                )
                if total_requests is None:
                    raise RuntimeError(
                        f"network_lossy_multi wrk did not report requests metric: "
                        f"{tail_text(c.stdout or c.stderr)}"
                    )
                return _finish_result(total_requests, elapsed, c.stdout or "", c.stderr or "")
            finally:
                if ping_proc is not None:
                    ping_proc.terminate()
                    try:
                        ping_proc.wait(timeout=2)
                    except subprocess.TimeoutExpired:
                        ping_proc.kill()
                        ping_proc.wait(timeout=2)


def run_xdp_traffic_load(duration_s: int | float, *, network_device: str | None = None) -> WorkloadResult:
    """Lightweight HTTP keep-alive load for XDP packet-forwarding programs.

    XDP runs at network device ingress before any qdisc; the goal is steady
    packet flow through the iface, not connect-rate or netem. wrk -t2 -c10
    sustains ~30K-100K HTTP requests/sec via 10 keep-alive connections, which
    yields enough packets for katran's XDP load balancer measurement without
    saturating the link.
    """
    wrk_binary = resolve_workload_tool("wrk")
    with _network_http_server(network_device) as server:
        start = time.monotonic()
        command = _network_client_command(
            [wrk_binary, "-t2", "-c10", f"-d{max(1, int(duration_s))}s", server.url],
            network_device,
        )
        c = run_command(command, check=False, timeout=float(duration_s) + 30)
        elapsed = time.monotonic() - start
        if c.returncode != 0:
            raise RuntimeError(
                f"network wrk load failed via {_render_command(command)}: {tail_text(c.stderr or c.stdout)}"
            )
        total_requests = next((float(m.group(1)) for line in c.stdout.splitlines() if (m := re.search(r"([0-9]+)\s+requests in", line.strip()))), None)
        if total_requests is None:
            raise RuntimeError(f"network wrk load did not report total request metrics: {tail_text(c.stdout or c.stderr)}")
        return _finish_result(total_requests, elapsed, c.stdout or "", c.stderr or "")


def run_tcp_connect_load(duration_s: int | float, *, network_device: str | None = None) -> WorkloadResult:
    """TCP connect-rate workload using wrk with Connection: close.

    Each HTTP request forces a fresh TCP handshake (no keep-alive), which is
    the standard way SIGCOMM/USENIX papers measure TCP connect throughput.
    """
    wrk_binary = resolve_workload_tool("wrk")
    seconds = max(1, int(round(float(duration_s))))
    wrk_args = [wrk_binary, "-t2", "-c10", f"-d{seconds}s",
                "-H", "Connection: close"]
    normalized_device = str(network_device or "").strip()
    if normalized_device:
        with _network_http_server(normalized_device) as server:
            command = _network_client_command([*wrk_args, server.url], normalized_device)
            start = time.monotonic()
            c = run_command(command, check=False, timeout=float(duration_s) + 30)
            elapsed = time.monotonic() - start
            if c.returncode != 0:
                raise RuntimeError(
                    f"tcp connect load failed via {_render_command(command)}: "
                    f"{tail_text(c.stderr or c.stdout)}"
                )
            total = next(
                (float(m.group(1)) for line in c.stdout.splitlines()
                 if (m := re.search(r"([0-9]+)\s+requests in", line.strip()))),
                None,
            )
            if total is None:
                raise RuntimeError(
                    f"tcp connect load did not report requests metric: "
                    f"{tail_text(c.stdout or c.stderr)}"
                )
            return _finish_result(total, elapsed, c.stdout or "", c.stderr or "")
    with LocalHttpServer("127.0.0.1") as server:
        command = [*wrk_args, server.url]
        start = time.monotonic()
        c = run_command(command, check=False, timeout=float(duration_s) + 30)
        elapsed = time.monotonic() - start
        if c.returncode != 0:
            raise RuntimeError(f"tcp connect load failed: {tail_text(c.stderr or c.stdout)}")
        total = next(
            (float(m.group(1)) for line in c.stdout.splitlines()
             if (m := re.search(r"([0-9]+)\s+requests in", line.strip()))),
            None,
        )
        if total is None:
            raise RuntimeError(
                f"tcp connect load did not report requests metric: "
                f"{tail_text(c.stdout or c.stderr)}"
            )
        return _finish_result(total, elapsed, c.stdout or "", c.stderr or "")


_MULTI_RUNTIME_PROBES: tuple[tuple[str, tuple[str, ...]], ...] = (
    ("python3", ("-c", "x = 0\nwhile True:\n    x += 1")),
    ("ruby", ("-e", "x = 0; loop { x += 1 }")),
    ("node", ("-e", "let x=0; while(true){x++;}")),
    ("perl", ("-e", "my $x=0; while(1){$x++;}")),
    ("php", ("-r", "$x=0; while(true){$x++;}")),
)


def _spawn_runtime_idlers() -> list[subprocess.Popen[str]]:
    procs: list[subprocess.Popen[str]] = []
    for tool, args in _MULTI_RUNTIME_PROBES:
        binary = which(tool)
        if binary is None:
            continue
        try:
            proc = subprocess.Popen(
                [binary, *args],
                stdout=subprocess.DEVNULL,
                stderr=subprocess.DEVNULL,
                stdin=subprocess.DEVNULL,
            )
        except OSError:
            continue
        procs.append(proc)
    return procs


def _kill_runtime_idlers(procs: Sequence[subprocess.Popen[str]]) -> None:
    for proc in procs:
        if proc.poll() is None:
            proc.terminate()
    for proc in procs:
        try:
            proc.wait(timeout=2)
        except subprocess.TimeoutExpired:
            proc.kill()
            try:
                proc.wait(timeout=2)
            except subprocess.TimeoutExpired:
                pass


def run_multi_runtime_cpu_load(duration_s: int | float) -> WorkloadResult:
    """CPU workload with concurrent multi-language idle loops.

    Spawns long-running interpreter processes (python/ruby/node/perl/php) so
    eBPF profilers (e.g. otelcol-ebpf-profiler) sample stack frames for each
    runtime's unwinder, then runs stress-ng --cpu to drive native unwinder
    coverage. Interpreters that are not installed are silently skipped so the
    workload still runs on hosts with a partial language toolchain.
    """
    procs = _spawn_runtime_idlers()
    try:
        return run_stress_ng_class_load(
            float(duration_s),
            _STRESS_NG_CPU_STRESSORS,
            workload_name="multi_runtime_cpu",
        )
    finally:
        _kill_runtime_idlers(procs)


def run_named_workload(
    kind: str,
    duration_s: int | float,
    *,
    network_device: str | None = None,
) -> WorkloadResult:
    seconds = max(1, int(round(float(duration_s))))
    kind = str(kind or "").strip()
    if kind in _STRESS_NG_WORKLOAD_STRESSORS:
        return run_stress_ng_class_load(
            float(duration_s),
            _STRESS_NG_WORKLOAD_STRESSORS[kind],
            workload_name=kind,
        )
    if kind == "multi_runtime_cpu":
        return run_multi_runtime_cpu_load(seconds)
    if kind == "tcp_connect":
        return run_tcp_connect_load(seconds, network_device=network_device)
    if kind == "xdp_traffic":
        return run_xdp_traffic_load(seconds, network_device=network_device)
    if kind == "network_lossy_multi":
        return run_network_lossy_multi_load(seconds, network_device=network_device)
    if kind in {"fio", "fio_randrw"}:
        return run_file_io(seconds)
    raise RuntimeError(f"unsupported workload kind: {kind}")
