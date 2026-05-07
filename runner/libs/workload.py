from __future__ import annotations

import os
import re
import select
import shlex
import socket
import subprocess
import sys
import tempfile
import threading
import time
from dataclasses import dataclass
from http.server import BaseHTTPRequestHandler, ThreadingHTTPServer
from contextlib import contextmanager
from pathlib import Path
from typing import Iterator, Mapping, Sequence

from . import run_command, tail_text, which
from .benchmark_net import BENCHMARK_IFACE, BENCHMARK_NETNS, BENCHMARK_PEER_IFACE_IP

_CILIUM_ENDPOINT_NAMESPACES = ("bpfbench-cepa", "bpfbench-cepb")
_CILIUM_ENDPOINT_IFACE = "eth0"


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
    """Raw workload run record. Framework never parses tool output.

    All metric extraction (ops_per_sec, latency percentiles, error rates,
    bytes_total, etc.) happens offline in `analysis/` from `stdout`.

    Fields are observed externally (return code, wallclock duration, exact
    command) or stored verbatim (stdout, stderr). `config` records non-output
    metadata such as the workload name, namespace, network device, or netem
    settings — values determined before the run, not derived from the run.
    `components` carries sub-runs of composite workloads, each itself a raw
    `WorkloadResult`.
    """

    workload_name: str
    command: tuple[str, ...]
    returncode: int
    duration_s: float
    stdout: str
    stderr: str
    config: Mapping[str, object] | None = None
    components: tuple["WorkloadResult", ...] | None = None

    def to_dict(self) -> dict[str, object]:
        payload: dict[str, object] = {
            "workload_name": self.workload_name,
            "command": list(self.command),
            "returncode": int(self.returncode),
            "duration_s": float(self.duration_s),
            "stdout": self.stdout,
            "stderr": self.stderr,
        }
        if self.config:
            payload["config"] = dict(self.config)
        if self.components:
            payload["components"] = [c.to_dict() for c in self.components]
        return payload


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
_NAMESPACED_UDP_SERVER_SCRIPT = """
import socket
import sys

host = sys.argv[1]
port = int(sys.argv[2])
sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
sock.bind((host, port))
print("READY", flush=True)
while True:
    sock.recvfrom(65535)
"""
_UDP_CLIENT_SCRIPT = """
import socket
import sys
import time

host = sys.argv[1]
port = int(sys.argv[2])
duration = float(sys.argv[3])
deadline = time.monotonic() + duration
sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
payload = b"bpfbench-cilium-udp" * 4
sent = 0
while time.monotonic() < deadline:
    try:
        sock.sendto(payload, (host, port))
        sent += 1
    except OSError:
        pass
print(sent)
"""


@dataclass(frozen=True)
class _CiliumEndpoint:
    namespace: str
    ipv4: str
    gateway: str


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


class NamespacedUdpServer:
    def __init__(self, namespace: str, host: str, port: int = 18081) -> None:
        self.namespace = str(namespace).strip()
        self.host = str(host).strip()
        self.port = int(port)
        self.process: subprocess.Popen[str] | None = None

    def __enter__(self) -> "NamespacedUdpServer":
        ip_binary = which("ip")
        if ip_binary is None:
            raise RuntimeError("ip is required for namespace UDP workloads")
        python_binary = sys.executable or which("python3")
        if not python_binary:
            raise RuntimeError("python3 is required for namespace UDP workloads")
        self.process = subprocess.Popen(
            [
                ip_binary,
                "netns",
                "exec",
                self.namespace,
                python_binary,
                "-u",
                "-c",
                _NAMESPACED_UDP_SERVER_SCRIPT,
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
                description="namespace UDP server",
            )
        except TimeoutError as exc:
            self.__exit__(None, None, None)
            raise RuntimeError(f"namespace UDP server in {self.namespace} did not report ready at {self.host}:{self.port}") from exc
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


def _record_run(
    *,
    workload_name: str,
    command: Sequence[str],
    returncode: int,
    duration_s: float,
    stdout: str,
    stderr: str,
    config: Mapping[str, object] | None = None,
) -> WorkloadResult:
    # Cap raw output at 8 MiB per stream. Most tools emit a few KB; katran's
    # per-request latency dump can reach a few MB at SAMPLES=3, and stress-ng
    # can be verbose. Below 8 MiB tail_text is essentially a passthrough.
    return WorkloadResult(
        workload_name=workload_name,
        command=tuple(str(part) for part in command),
        returncode=int(returncode),
        duration_s=float(duration_s),
        stdout=tail_text(stdout, max_lines=200000, max_chars=8388608),
        stderr=tail_text(stderr, max_lines=200000, max_chars=8388608),
        config=None if config is None else dict(config),
    )


def _composite(
    *,
    workload_name: str,
    components: Sequence[WorkloadResult],
    duration_s: float,
    config: Mapping[str, object] | None = None,
) -> WorkloadResult:
    return WorkloadResult(
        workload_name=workload_name,
        command=(),
        returncode=0 if all(c.returncode == 0 for c in components) else 1,
        duration_s=float(duration_s),
        stdout="",
        stderr="",
        config=None if config is None else dict(config),
        components=tuple(components),
    )


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
    # Process / scheduler / ptrace stressors covering exec, fork, clone,
    # ptrace, futex, sem syscalls. These exist in stress-ng standard set
    # but were not in the OS-IO-network stress group; including them lets
    # the standard workload exercise execve/execveat (security_bprm_check,
    # syscall__execve_*), sched_process_fork (tracepoint_*), and ptrace
    # (trace_ret_ptrace) probes that were previously dormant.
    "exec",
    "fork",
    "vfork",
    "clone",
    "ptrace",
    "futex",
    "sem",
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
        *_STRESS_NG_FILESYSTEM_STRESSORS,
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
    return _record_run(
        workload_name=workload_name,
        command=command,
        returncode=completed.returncode,
        duration_s=elapsed,
        stdout=completed.stdout or "",
        stderr=completed.stderr or "",
        config={"tool": "stress-ng", "stressors": list(normalized_stressors)},
    )


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
        return _record_run(
            workload_name="file_io",
            command=cmd,
            returncode=c.returncode,
            duration_s=elapsed,
            stdout=c.stdout or "",
            stderr=c.stderr or "",
            config={"tool": "fio"},
        )


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


def _namespaced_client_command(namespace: str, command: Sequence[str]) -> list[str]:
    ip_binary = which("ip")
    if ip_binary is None:
        raise RuntimeError("ip is required for namespaced network workloads")
    return [ip_binary, "netns", "exec", str(namespace), *[str(part) for part in command]]


def _netns_exists(namespace: str) -> bool:
    completed = run_command(["ip", "netns", "list"], check=False, timeout=10)
    if completed.returncode != 0:
        return False
    return any(line.split(maxsplit=1)[0].strip() == namespace for line in completed.stdout.splitlines())


def _namespace_ipv4(namespace: str, iface: str) -> str | None:
    completed = run_command(["ip", "-n", namespace, "-4", "-o", "addr", "show", "dev", iface], check=False, timeout=10)
    if completed.returncode != 0:
        return None
    match = re.search(r"\binet\s+([0-9.]+)/", completed.stdout)
    return None if match is None else match.group(1)


def _namespace_default_gateway(namespace: str) -> str | None:
    completed = run_command(["ip", "-n", namespace, "-4", "route", "show", "default"], check=False, timeout=10)
    if completed.returncode != 0:
        return None
    match = re.search(r"\bvia\s+([0-9.]+)\b", completed.stdout)
    return None if match is None else match.group(1)


def _cilium_endpoint_topology() -> tuple[_CiliumEndpoint, _CiliumEndpoint] | None:
    endpoints: list[_CiliumEndpoint] = []
    for namespace in _CILIUM_ENDPOINT_NAMESPACES:
        if not _netns_exists(namespace):
            return None
        ipv4 = _namespace_ipv4(namespace, _CILIUM_ENDPOINT_IFACE)
        gateway = _namespace_default_gateway(namespace)
        if not ipv4 or not gateway:
            return None
        endpoints.append(_CiliumEndpoint(namespace=namespace, ipv4=ipv4, gateway=gateway))
    return endpoints[0], endpoints[1]


def _run_wrk_http_load(
    wrk_binary: str,
    url: str,
    seconds: int,
    *,
    namespace: str | None = None,
    threads: int = 2,
    connections: int = 8,
    workload_name: str,
) -> WorkloadResult:
    command = [wrk_binary, f"-t{int(threads)}", f"-c{int(connections)}", f"-d{int(seconds)}s", url]
    if namespace:
        command = _namespaced_client_command(namespace, command)
    start = time.monotonic()
    completed = run_command(command, check=False, timeout=float(seconds) + 30)
    elapsed = time.monotonic() - start
    if completed.returncode != 0:
        raise RuntimeError(
            f"{workload_name} wrk load failed via {_render_command(command)}: "
            f"{tail_text(completed.stderr or completed.stdout)}"
        )
    return _record_run(
        workload_name=workload_name,
        command=command,
        returncode=completed.returncode,
        duration_s=elapsed,
        stdout=completed.stdout or "",
        stderr=completed.stderr or "",
        config={"tool": "wrk", "url": url, "namespace": namespace,
                "threads": int(threads), "connections": int(connections)},
    )


def _start_ping(target: str, seconds: int, *, namespace: str | None = None) -> subprocess.Popen[object] | None:
    ping_binary = which("ping")
    if ping_binary is None:
        return None
    command: list[str] = [ping_binary, "-i", "0.01", "-q", "-w", str(seconds), target]
    if namespace:
        command = _namespaced_client_command(namespace, command)
    return subprocess.Popen(command, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)


def _stop_background_process(process: subprocess.Popen[object] | None) -> None:
    if process is None:
        return
    if process.poll() is None:
        process.terminate()
        try:
            process.wait(timeout=2)
        except subprocess.TimeoutExpired:
            process.kill()
            process.wait(timeout=2)


def _run_udp_burst(host: str, port: int, seconds: int, *, namespace: str | None = None) -> WorkloadResult:
    python_binary = sys.executable or which("python3")
    if not python_binary:
        raise RuntimeError("python3 is required for UDP workloads")
    command: list[str] = [python_binary, "-u", "-c", _UDP_CLIENT_SCRIPT, host, str(port), str(seconds)]
    if namespace:
        command = _namespaced_client_command(namespace, command)
    start = time.monotonic()
    completed = run_command(command, check=False, timeout=float(seconds) + 10)
    elapsed = time.monotonic() - start
    if completed.returncode != 0:
        raise RuntimeError(f"UDP workload failed via {_render_command(command)}: {tail_text(completed.stderr or completed.stdout)}")
    return _record_run(
        workload_name="udp_burst",
        command=command,
        returncode=completed.returncode,
        duration_s=elapsed,
        stdout=completed.stdout or "",
        stderr=completed.stderr or "",
        config={"tool": "python-udp-client", "target_host": host,
                "target_port": int(port), "namespace": namespace},
    )


def _run_cilium_endpoint_matrix(seconds: int, *, wrk_binary: str) -> WorkloadResult | None:
    topology = _cilium_endpoint_topology()
    if topology is None:
        return None
    seconds = 1
    endpoint_a, endpoint_b = topology
    results: list[WorkloadResult] = []
    with (
        NamespacedHttpServer(endpoint_a.namespace, endpoint_a.ipv4) as server_a,
        NamespacedHttpServer(endpoint_b.namespace, endpoint_b.ipv4) as server_b,
        NamespacedHttpServer(BENCHMARK_NETNS, BENCHMARK_PEER_IFACE_IP) as external_server,
        LocalHttpServer(endpoint_a.gateway) as host_server,
    ):
        ping_proc = _start_ping(endpoint_a.ipv4, seconds)
        try:
            results.append(
                _run_wrk_http_load(
                    wrk_binary,
                    server_a.url,
                    seconds,
                    threads=2,
                    connections=20,
                    workload_name="cilium host-to-endpoint",
                )
            )
        finally:
            _stop_background_process(ping_proc)

        ping_proc = _start_ping(endpoint_a.gateway, seconds, namespace=endpoint_a.namespace)
        try:
            results.append(
                _run_wrk_http_load(
                    wrk_binary,
                    host_server.url,
                    seconds,
                    namespace=endpoint_a.namespace,
                    threads=2,
                    connections=20,
                    workload_name="cilium endpoint-to-host",
                )
            )
        finally:
            _stop_background_process(ping_proc)

        ping_proc = _start_ping(endpoint_b.ipv4, seconds, namespace=endpoint_a.namespace)
        try:
            results.append(
                _run_wrk_http_load(
                    wrk_binary,
                    server_b.url,
                    seconds,
                    namespace=endpoint_a.namespace,
                    threads=2,
                    connections=20,
                    workload_name="cilium endpoint-to-endpoint",
                )
            )
            results.append(
                _run_wrk_http_load(
                    wrk_binary,
                    server_a.url,
                    seconds,
                    namespace=endpoint_b.namespace,
                    threads=2,
                    connections=20,
                    workload_name="cilium reverse-endpoint-to-endpoint",
                )
            )
        finally:
            _stop_background_process(ping_proc)

        results.append(
            _run_wrk_http_load(
                wrk_binary,
                external_server.url,
                seconds,
                namespace=endpoint_a.namespace,
                threads=2,
                connections=20,
                workload_name="cilium endpoint-to-external",
            )
        )
        results.append(
            _run_wrk_http_load(
                wrk_binary,
                server_a.url,
                seconds,
                namespace=BENCHMARK_NETNS,
                threads=2,
                connections=20,
                workload_name="cilium external-to-endpoint",
            )
        )

        with NamespacedUdpServer(endpoint_b.namespace, endpoint_b.ipv4) as udp_server:
            results.append(_run_udp_burst(endpoint_b.ipv4, udp_server.port, seconds, namespace=endpoint_a.namespace))
        with NamespacedUdpServer(endpoint_a.namespace, endpoint_a.ipv4) as udp_server:
            results.append(_run_udp_burst(endpoint_a.ipv4, udp_server.port, seconds, namespace=BENCHMARK_NETNS))
        with NamespacedUdpServer(BENCHMARK_NETNS, BENCHMARK_PEER_IFACE_IP) as udp_server:
            results.append(_run_udp_burst(BENCHMARK_PEER_IFACE_IP, udp_server.port, seconds, namespace=endpoint_a.namespace))
    total_duration = sum(r.duration_s for r in results)
    return _composite(
        workload_name="cilium_endpoint_matrix",
        components=results,
        duration_s=total_duration,
    )


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
    results: list[WorkloadResult] = []
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
                results.append(_record_run(
                    workload_name="network_lossy_multi_wrk",
                    command=command,
                    returncode=c.returncode,
                    duration_s=elapsed,
                    stdout=c.stdout or "",
                    stderr=c.stderr or "",
                    config={"tool": "wrk", "url": server.url},
                ))
            finally:
                _stop_background_process(ping_proc)
    endpoint_result = _run_cilium_endpoint_matrix(seconds, wrk_binary=wrk_binary)
    if endpoint_result is not None:
        results.append(endpoint_result)
    return _composite(
        workload_name="network_lossy_multi",
        components=results,
        duration_s=sum(r.duration_s for r in results),
        config={"network_device": network_device,
                "netem": {"loss_pct": 20.0, "delay_ms": 50}},
    )


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
        return _record_run(
            workload_name="xdp_traffic",
            command=command,
            returncode=c.returncode,
            duration_s=elapsed,
            stdout=c.stdout or "",
            stderr=c.stderr or "",
            config={"tool": "wrk", "url": server.url},
        )


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
            return _record_run(
                workload_name="tcp_connect",
                command=command,
                returncode=c.returncode,
                duration_s=elapsed,
                stdout=c.stdout or "",
                stderr=c.stderr or "",
                config={"tool": "wrk", "url": server.url},
            )
    with LocalHttpServer("127.0.0.1") as server:
        command = [*wrk_args, server.url]
        start = time.monotonic()
        c = run_command(command, check=False, timeout=float(duration_s) + 30)
        elapsed = time.monotonic() - start
        if c.returncode != 0:
            raise RuntimeError(f"tcp connect load failed: {tail_text(c.stderr or c.stdout)}")
        return _record_run(
            workload_name="tcp_connect",
            command=command,
            returncode=c.returncode,
            duration_s=elapsed,
            stdout=c.stdout or "",
            stderr=c.stderr or "",
            config={"tool": "wrk", "url": server.url},
        )


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
    if kind == "tcp_connect":
        return run_tcp_connect_load(seconds, network_device=network_device)
    if kind == "xdp_traffic":
        return run_xdp_traffic_load(seconds, network_device=network_device)
    if kind == "network_lossy_multi":
        return run_network_lossy_multi_load(seconds, network_device=network_device)
    if kind in {"fio", "fio_randrw"}:
        return run_file_io(seconds)
    raise RuntimeError(f"unsupported workload kind: {kind}")
