from __future__ import annotations

import os
import platform
import json
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
from .benchmark_net import (
    BENCHMARK_IFACE,
    BENCHMARK_IFACE_CIDR,
    BENCHMARK_NETNS,
    BENCHMARK_PEER_IFACE,
    BENCHMARK_PEER_IFACE_IP,
)
from .kernel_modules import kernel_module_is_builtin, load_kernel_module

_PKTGEN_THREAD = "/proc/net/pktgen/kpktgend_0"
_PKTGEN_CTRL = "/proc/net/pktgen/pgctrl"
_PKTGEN_CLONE_SKB = 1000

_CILIUM_ENDPOINT_NAMESPACES = ("bpfbench-cepa", "bpfbench-cepb")
_CILIUM_ENDPOINT_HOST_IFACES = ("lxcbench0", "lxcbench1")
_CILIUM_ENDPOINT_IFACE = "eth0"
_CILIUM_PLAIN_ENDPOINT_IPV4S = ("10.244.0.10", "10.244.0.11")
_CILIUM_PLAIN_ENDPOINT_GATEWAYS = ("10.244.0.1", "10.244.0.2")


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

    Tool output is stored verbatim. Any metric extraction from stdout happens
    outside the benchmark framework.

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


class _BenchmarkThreadingHTTPServer(ThreadingHTTPServer):
    daemon_threads = True
    block_on_close = False

    def handle_error(self, request: object, client_address: object) -> None:
        exc = sys.exc_info()[1]
        if isinstance(exc, (BrokenPipeError, ConnectionResetError, ConnectionAbortedError, socket.timeout)):
            return
        super().handle_error(request, client_address)


class _ThreadingHTTPServerV6(_BenchmarkThreadingHTTPServer):
    address_family = socket.AF_INET6


class LocalHttpServer:
    def __init__(self, host: str = "127.0.0.1") -> None:
        self.host = str(host)
        self.family = socket.AF_INET6 if ":" in self.host else socket.AF_INET
        server_class = _ThreadingHTTPServerV6 if self.family == socket.AF_INET6 else _BenchmarkThreadingHTTPServer
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

class BenchmarkThreadingHTTPServer(ThreadingHTTPServer):
    daemon_threads = True
    block_on_close = False

    def handle_error(self, request, client_address):
        exc = sys.exc_info()[1]
        if isinstance(exc, (BrokenPipeError, ConnectionResetError, ConnectionAbortedError, socket.timeout)):
            return
        super().handle_error(request, client_address)


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
    class Server(BenchmarkThreadingHTTPServer):
        address_family = socket.AF_INET6
    bind_address = (host, port, 0, 0)
else:
    Server = BenchmarkThreadingHTTPServer
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


def _ensure_kernel_module_loaded(module_name: str) -> None:
    normalized = module_name.replace("-", "_")
    if (Path("/sys/module") / normalized).exists():
        return
    if kernel_module_is_builtin(module_name):
        return
    load_kernel_module(module_name)
    if (Path("/sys/module") / normalized).exists():
        return
    if kernel_module_is_builtin(module_name):
        return
    raise RuntimeError(f"kernel module {module_name} still is not resident after modprobe")


def _shell_write(path: str, line: str) -> None:
    run_command(["sh", "-c", f"printf '%s\\n' {shlex.quote(line)} > {shlex.quote(path)}"])


def _read_text(path: str) -> str:
    return run_command(["cat", path]).stdout or ""


def _link_mac(name: str, *, namespace: str | None = None) -> str:
    command = ["ip", "-j"]
    if namespace is not None:
        command += ["-n", namespace]
    command += ["link", "show", "dev", name]
    payload = json.loads(run_command(command).stdout)
    if not isinstance(payload, list) or not payload or not isinstance(payload[0], dict):
        raise RuntimeError(f"could not read link metadata for {name}")
    address = str(payload[0].get("address") or "").strip()
    if not address:
        raise RuntimeError(f"link {name} has no MAC address")
    return address


def _link_exists(name: str) -> bool:
    return run_command(["ip", "link", "show", "dev", name], check=False).returncode == 0


def _delete_link_if_exists(name: str) -> None:
    if _link_exists(name):
        run_command(["ip", "link", "delete", "dev", name], check=False)


def _delete_netns_if_exists(namespace: str) -> None:
    if _netns_exists(namespace):
        run_command(["ip", "netns", "delete", namespace], check=False)


@dataclass(frozen=True)
class _CiliumEndpoint:
    namespace: str
    host_if: str
    ipv4: str
    gateway: str


def _wait_for_stdout_marker(
    process: subprocess.Popen[str],
    *,
    marker: str,
    description: str,
) -> None:
    stdout_lines: list[str] = []
    while True:
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
        try:
            _wait_for_stdout_marker(
                self.process,
                marker=_NAMESPACED_HTTP_READY_MARKER,
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
        try:
            _wait_for_stdout_marker(
                self.process,
                marker=_NAMESPACED_HTTP_READY_MARKER,
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

# `fcntl` is intentionally not in the filesystem set: current kernels can
# reject stress-ng's mandatory-lock subtests, tripping exit 2 even though the
# surrounding file-system workload is otherwise healthy.
#
# Stressors that must be dropped on AL2023 ARM64 (t4g.small) because their
# workers fail intermittently, tripping stress-ng exit 2 and zeroing the
# whole workload. x86 keeps SCTP: kernel has it compiled in and it exercises
# relevant BPF paths.
#   sctp: kernel SCTP=m, autoload flaky.
# Keys are `platform.machine()` values.
_STRESS_NG_DROP_STRESSORS_BY_ARCH: Mapping[str, frozenset[str]] = {
    "aarch64": frozenset({"sctp"}),
}


def _stressors_for_current_arch(stressors: Sequence[str]) -> tuple[str, ...]:
    drop = _STRESS_NG_DROP_STRESSORS_BY_ARCH.get(platform.machine(), frozenset())
    if not drop:
        return tuple(stressors)
    return tuple(s for s in stressors if s not in drop)
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
_STRESS_NG_BCC_HOOK_STRESSORS = (
    # Hot BCC hook families with high BPF/user-work ratio: syscall/capability
    # paths plus socket fd churn. Full BCC tool coverage is checked
    # by stats-on diagnostics; low-ratio block/vfs/file-IO stressors would make
    # the app-level performance workload mostly measure storage/user work.
    "syscall",
    "cap",
    "set",
    "sockfd",
)
_STRESS_NG_TETRAGON_POLICY_STRESSORS = (
    # Matches the bundled Tetragon policies that showed high event cost in
    # 60s no-eBPF/eBPF-no-state tuning: datagram/socket tracking, eventfd,
    # and file mmap permission hooks.
    "eventfd",
    "mmap",
    "udp",
    "sock",
    "sockfd",
    "sockpair",
)
_STRESS_NG_TRACEE_SYSCALL_STRESSORS = (
    # Tracee's all-events mode is dominated by syscall/raw tracepoint/LSM
    # paths. Use cheap syscall generators to maximize event density.
    "cap",
    "set",
    "sigfd",
    "eventfd",
    "kill",
    "futex",
    "prctl",
)
_STRESS_NG_WORKLOAD_STRESSORS: Mapping[str, tuple[str, ...]] = {
    "stress_ng_cpu": _STRESS_NG_CPU_STRESSORS,
    "stress_ng_filesystem": _STRESS_NG_FILESYSTEM_STRESSORS,
    "stress_ng_os": _STRESS_NG_OS_STRESSORS,
    "stress_ng_process": _STRESS_NG_PROCESS_STRESSORS,
    "stress_ng_scheduler": _STRESS_NG_SCHEDULER_STRESSORS,
    "stress_ng_bcc_hook_hot": _STRESS_NG_BCC_HOOK_STRESSORS,
    "stress_ng_tetragon_policy_hot": _STRESS_NG_TETRAGON_POLICY_STRESSORS,
    "stress_ng_tracee_syscall_hot": _STRESS_NG_TRACEE_SYSCALL_STRESSORS,
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
_STRESS_NG_DEFAULT_WORKERS = 1
_STRESS_NG_STRESSOR_WORKERS: Mapping[str, int] = {
    # stress-ng's SCTP worker shares --sctp-port across workers. With four
    # workers one process can fail intermittently while the other three pass.
    "sctp": 1,
}
_STRESS_NG_NETWORK_PORT_STRESSORS = {
    "epoll": 100,
    "sctp": 200,
    "sock": 300,
    "sockfd": 400,
}
_STRESS_NG_PORT_BASE_MIN = 12000
_STRESS_NG_PORT_BASE_SPAN = 49152
_STRESS_NG_PORT_BASE_STRIDE = 512
_stress_ng_port_base_lock = threading.Lock()
_stress_ng_port_base_counter = 0


def _stress_ng_next_port_base() -> int:
    global _stress_ng_port_base_counter

    with _stress_ng_port_base_lock:
        counter = _stress_ng_port_base_counter
        _stress_ng_port_base_counter += 1
    return _STRESS_NG_PORT_BASE_MIN + (
        (os.getpid() + counter * _STRESS_NG_PORT_BASE_STRIDE) % _STRESS_NG_PORT_BASE_SPAN
    )


def _stress_ng_dynamic_stressor_args(stressors: Sequence[str]) -> list[str]:
    selected = {str(stressor).strip() for stressor in stressors if str(stressor).strip()}
    if not (selected & set(_STRESS_NG_NETWORK_PORT_STRESSORS)):
        return []
    base_port = _stress_ng_next_port_base()
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
        workers = _STRESS_NG_STRESSOR_WORKERS.get(stressor, _STRESS_NG_DEFAULT_WORKERS)
        command += [f"--{stressor}", str(workers)]
        command += list(_STRESS_NG_STRESSOR_ARGS.get(stressor, ()))
    command += _stress_ng_dynamic_stressor_args(normalized_stressors)
    command += ["--timeout", f"{seconds}s", "--metrics-brief", "--temp-path", str(temp_root)]
    start = time.monotonic()
    completed = run_command(command, check=False, cwd=temp_root)
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
        c = run_command(cmd, check=False, cwd=Path(tempdir))
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
    completed = run_command(["ip", "netns", "list"], check=False)
    if completed.returncode != 0:
        return False
    return any(line.split(maxsplit=1)[0].strip() == namespace for line in completed.stdout.splitlines())


def _namespace_ipv4(namespace: str, iface: str) -> str | None:
    completed = run_command(["ip", "-n", namespace, "-4", "-o", "addr", "show", "dev", iface], check=False)
    if completed.returncode != 0:
        return None
    match = re.search(r"\binet\s+([0-9.]+)/", completed.stdout)
    return None if match is None else match.group(1)


def _namespace_default_gateway(namespace: str) -> str | None:
    completed = run_command(["ip", "-n", namespace, "-4", "route", "show", "default"], check=False)
    if completed.returncode != 0:
        return None
    match = re.search(r"\bvia\s+([0-9.]+)\b", completed.stdout)
    return None if match is None else match.group(1)


def _cilium_endpoint_topology() -> tuple[_CiliumEndpoint, _CiliumEndpoint] | None:
    endpoints: list[_CiliumEndpoint] = []
    for namespace, host_if in zip(_CILIUM_ENDPOINT_NAMESPACES, _CILIUM_ENDPOINT_HOST_IFACES, strict=True):
        if not _netns_exists(namespace):
            return None
        if not _link_exists(host_if):
            return None
        ipv4 = _namespace_ipv4(namespace, _CILIUM_ENDPOINT_IFACE)
        gateway = _namespace_default_gateway(namespace)
        if not ipv4 or not gateway:
            return None
        endpoints.append(_CiliumEndpoint(namespace=namespace, host_if=host_if, ipv4=ipv4, gateway=gateway))
    return endpoints[0], endpoints[1]


def _cleanup_plain_cilium_endpoint_topology() -> None:
    for host_if in _CILIUM_ENDPOINT_HOST_IFACES:
        _delete_link_if_exists(host_if)
    for namespace in _CILIUM_ENDPOINT_NAMESPACES:
        _delete_netns_if_exists(namespace)


def _setup_plain_cilium_endpoint_topology() -> tuple[_CiliumEndpoint, _CiliumEndpoint]:
    _cleanup_plain_cilium_endpoint_topology()
    run_command(["sysctl", "-qw", "net.ipv4.ip_forward=1"])
    endpoints: list[_CiliumEndpoint] = []
    for namespace, host_if, ipv4, gateway in zip(
        _CILIUM_ENDPOINT_NAMESPACES,
        _CILIUM_ENDPOINT_HOST_IFACES,
        _CILIUM_PLAIN_ENDPOINT_IPV4S,
        _CILIUM_PLAIN_ENDPOINT_GATEWAYS,
        strict=True,
    ):
        peer = f"{host_if}p"
        run_command(["ip", "netns", "add", namespace])
        run_command(["ip", "link", "add", "dev", host_if, "type", "veth", "peer", "name", peer])
        run_command(["ip", "link", "set", "dev", peer, "netns", namespace])
        run_command(["ip", "addr", "replace", f"{gateway}/32", "dev", host_if])
        run_command(["ip", "link", "set", "dev", host_if, "up"])
        run_command(["sysctl", "-qw", f"net.ipv4.conf.{host_if}.rp_filter=0"])
        run_command(["ip", "-n", namespace, "link", "set", "dev", peer, "name", _CILIUM_ENDPOINT_IFACE])
        run_command(["ip", "-n", namespace, "link", "set", "dev", "lo", "up"])
        run_command(["ip", "-n", namespace, "link", "set", "dev", _CILIUM_ENDPOINT_IFACE, "up"])
        run_command(["ip", "-n", namespace, "addr", "replace", f"{ipv4}/32", "dev", _CILIUM_ENDPOINT_IFACE])
        run_command(["ip", "-n", namespace, "route", "replace", f"{gateway}/32", "dev", _CILIUM_ENDPOINT_IFACE, "scope", "link"])
        run_command(["ip", "-n", namespace, "route", "replace", "default", "via", gateway, "dev", _CILIUM_ENDPOINT_IFACE])
        run_command(["ip", "route", "replace", f"{ipv4}/32", "dev", host_if])
        endpoints.append(_CiliumEndpoint(namespace=namespace, host_if=host_if, ipv4=ipv4, gateway=gateway))
    return endpoints[0], endpoints[1]


@contextmanager
def _cilium_endpoint_pktgen_topology() -> Iterator[tuple[_CiliumEndpoint, _CiliumEndpoint]]:
    existing = _cilium_endpoint_topology()
    if existing is not None:
        yield existing
        return
    endpoints = _setup_plain_cilium_endpoint_topology()
    try:
        yield endpoints
    finally:
        _cleanup_plain_cilium_endpoint_topology()


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
    command = [
        wrk_binary,
        f"-t{int(threads)}",
        f"-c{int(connections)}",
        f"-d{int(seconds)}s",
        url,
    ]
    if namespace:
        command = _namespaced_client_command(namespace, command)
    start = time.monotonic()
    completed = run_command(command, check=False)
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
    completed = run_command(command, check=False)
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


def _netns_shell_write(namespace: str, path: str, line: str) -> None:
    run_command(
        ["ip", "netns", "exec", namespace, "sh", "-c", f"printf '%s\\n' {shlex.quote(line)} > {shlex.quote(path)}"]
    )


def _netns_read_text(namespace: str, path: str) -> str:
    return run_command(["ip", "netns", "exec", namespace, "cat", path]).stdout or ""


def _run_namespaced_pktgen_udp(
    duration_s: int | float,
    *,
    namespace: str,
    iface: str,
    src_ip: str,
    dst_ip: str,
    src_mac: str,
    dst_mac: str,
    dst_port: int,
    workload_name: str,
    clone_skb: int = _PKTGEN_CLONE_SKB,
    thread_index: int = 0,
) -> WorkloadResult:
    _ensure_kernel_module_loaded("pktgen")
    seconds = max(1, int(round(float(duration_s))))
    device_path = f"/proc/net/pktgen/{iface}"
    thread_path = f"/proc/net/pktgen/kpktgend_{int(thread_index)}"
    _netns_shell_write(namespace, _PKTGEN_CTRL, "reset")
    _netns_shell_write(namespace, thread_path, "rem_device_all")
    _netns_shell_write(namespace, thread_path, f"add_device {iface}")
    for command in (
        "flag !SHARED",
        f"clone_skb {int(clone_skb)}",
        "burst 1",
        "count 0",
        "delay 0",
        "xmit_mode start_xmit",
        "pkt_size 64",
        f"src_min {src_ip}",
        f"src_max {src_ip}",
        f"dst {dst_ip}",
        f"dst_max {dst_ip}",
        f"src_mac {src_mac}",
        f"dst_mac {dst_mac}",
        "udp_src_min 1",
        "udp_src_max 65535",
        f"udp_dst_min {int(dst_port)}",
        f"udp_dst_max {int(dst_port)}",
        "flows 65535",
        "flowlen 1",
        "clear_counters",
    ):
        _netns_shell_write(namespace, device_path, command)
    start_command = [
        "ip",
        "netns",
        "exec",
        namespace,
        "sh",
        "-c",
        f"printf '%s\\n' start > {shlex.quote(_PKTGEN_CTRL)}",
    ]
    start = time.monotonic()
    process = subprocess.Popen(start_command, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
    try:
        time.sleep(seconds)
        _netns_shell_write(namespace, _PKTGEN_CTRL, "stop")
        stdout, stderr = process.communicate()
    except BaseException:
        if process.poll() is None:
            try:
                _netns_shell_write(namespace, _PKTGEN_CTRL, "stop")
            finally:
                process.kill()
        raise
    elapsed = time.monotonic() - start
    if process.returncode != 0:
        raise RuntimeError(f"{workload_name} failed: {tail_text(stderr or stdout)}")
    device_state = _netns_read_text(namespace, device_path)
    return _record_run(
        workload_name=workload_name,
        command=start_command,
        returncode=int(process.returncode or 0),
        duration_s=elapsed,
        stdout=device_state,
        stderr=stderr or "",
        config={
            "tool": "kernel_pktgen",
            "namespace": namespace,
            "iface": iface,
            "src_ip": src_ip,
            "dst_ip": dst_ip,
            "dst_port": int(dst_port),
            "pkt_size": 64,
            "flows": 65535,
            "clone_skb": int(clone_skb),
        },
    )


def run_cilium_endpoint_pktgen_load(
    duration_s: int | float,
    *,
    network_device: str | None = None,
) -> WorkloadResult:
    if network_device and str(network_device).strip() != BENCHMARK_IFACE:
        raise RuntimeError(f"cilium_endpoint_pktgen requires benchmark interface {BENCHMARK_IFACE}")
    with _cilium_endpoint_pktgen_topology() as (endpoint_a, endpoint_b):
        directions = (
            (endpoint_a, endpoint_b, "cilium_endpoint_pktgen_forward"),
        )
        results: list[WorkloadResult | None] = [None] * len(directions)
        errors: list[BaseException] = []

        def run_direction(index: int, src: _CiliumEndpoint, dst: _CiliumEndpoint, name: str) -> None:
            try:
                results[index] = _run_namespaced_pktgen_udp(
                    duration_s,
                    namespace=src.namespace,
                    iface=_CILIUM_ENDPOINT_IFACE,
                    src_ip=src.ipv4,
                    dst_ip=dst.ipv4,
                    src_mac=_link_mac(_CILIUM_ENDPOINT_IFACE, namespace=src.namespace),
                    dst_mac=_link_mac(src.host_if),
                    dst_port=18081,
                    workload_name=name,
                    clone_skb=0,
                    thread_index=index,
                )
            except BaseException as exc:
                errors.append(exc)

        threads = [
            threading.Thread(target=run_direction, args=(index, src, dst, name))
            for index, (src, dst, name) in enumerate(directions)
        ]
        for thread in threads:
            thread.start()
        for thread in threads:
            thread.join()
        if errors:
            raise RuntimeError("; ".join(str(error) for error in errors))
        components = tuple(result for result in results if result is not None)
        if len(components) != len(directions):
            raise RuntimeError("cilium endpoint pktgen did not produce every direction result")
    return _composite(
        workload_name="cilium_endpoint_pktgen",
        components=components,
        duration_s=max(component.duration_s for component in components),
        config={"path": "single-direction-endpoint-to-endpoint"},
    )


def run_network_pktgen_udp_load(
    duration_s: int | float,
    *,
    network_device: str | None = None,
) -> WorkloadResult:
    """Kernel pktgen UDP flood through the benchmark veth.

    This is the high packet-rate Cilium workload. It avoids wrk/HTTP/netem
    latency so the measured throughput is dominated by packets traversing the
    Cilium TC/XDP datapath rather than userspace request handling.
    """
    if str(network_device or "").strip() != BENCHMARK_IFACE:
        raise RuntimeError(f"network_pktgen_udp requires benchmark interface {BENCHMARK_IFACE}")
    from .app_runners.cilium import _ensure_benchmark_interface

    _ensure_benchmark_interface()
    _ensure_kernel_module_loaded("pktgen")
    seconds = max(1, int(round(float(duration_s))))
    src_ip = BENCHMARK_IFACE_CIDR.split("/", 1)[0]
    src_mac = _link_mac(BENCHMARK_IFACE)
    dst_mac = _link_mac(BENCHMARK_PEER_IFACE, namespace=BENCHMARK_NETNS)
    device_path = f"/proc/net/pktgen/{BENCHMARK_IFACE}"
    _shell_write(_PKTGEN_CTRL, "reset")
    _shell_write(_PKTGEN_THREAD, "rem_device_all")
    _shell_write(_PKTGEN_THREAD, f"add_device {BENCHMARK_IFACE}")
    for command in (
        "flag !SHARED",
        f"clone_skb {_PKTGEN_CLONE_SKB}",
        "burst 1",
        "count 0",
        "delay 0",
        "xmit_mode start_xmit",
        "pkt_size 64",
        f"src_min {src_ip}",
        f"src_max {src_ip}",
        f"dst {BENCHMARK_PEER_IFACE_IP}",
        f"dst_max {BENCHMARK_PEER_IFACE_IP}",
        f"src_mac {src_mac}",
        f"dst_mac {dst_mac}",
        "udp_src_min 1",
        "udp_src_max 65535",
        "udp_dst_min 18081",
        "udp_dst_max 18081",
        "flows 65535",
        "flowlen 1",
        "clear_counters",
    ):
        _shell_write(device_path, command)
    start_command = ["sh", "-c", f"printf '%s\\n' start > {shlex.quote(_PKTGEN_CTRL)}"]
    start = time.monotonic()
    process = subprocess.Popen(start_command, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
    try:
        time.sleep(seconds)
        _shell_write(_PKTGEN_CTRL, "stop")
        stdout, stderr = process.communicate()
    except BaseException:
        if process.poll() is None:
            try:
                _shell_write(_PKTGEN_CTRL, "stop")
            finally:
                process.kill()
        raise
    elapsed = time.monotonic() - start
    if process.returncode != 0:
        raise RuntimeError(f"network pktgen workload failed: {tail_text(stderr or stdout)}")
    device_state = _read_text(device_path)
    return _record_run(
        workload_name="network_pktgen_udp",
        command=start_command,
        returncode=int(process.returncode or 0),
        duration_s=elapsed,
        stdout=device_state,
        stderr=stderr or "",
        config={
            "tool": "kernel_pktgen",
            "iface": BENCHMARK_IFACE,
            "src_ip": src_ip,
            "dst_ip": BENCHMARK_PEER_IFACE_IP,
            "dst_port": 18081,
            "pkt_size": 64,
            "flows": 65535,
            "clone_skb": _PKTGEN_CLONE_SKB,
        },
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
    if run_command(add, check=False).returncode != 0:
        run_command(delete, check=False)
        if run_command(add, check=False).returncode != 0:
            raise RuntimeError(f"failed to install netem qdisc on {device}")
    try:
        yield
    finally:
        run_command(delete, check=False)


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
                c = run_command(command, check=False)
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
        c = run_command(command, check=False)
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
            c = run_command(command, check=False)
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
        c = run_command(command, check=False)
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


_OTEL_INTERP_PY = """\
import sys, time
worker = int(sys.argv[2])
x = worker + 1
n = 0
t0 = time.monotonic()
deadline = t0 + float(sys.argv[1])
while time.monotonic() < deadline:
    x = ((x * 1103515245) + 12345) & 0xffffffff
    n += 1
sys.stderr.write(f"python3 int_loop ops={n} elapsed_s={time.monotonic()-t0:.6f} worker={worker} sink={x}\\n")
"""
_OTEL_INTERP_RB = """\
worker = ARGV.fetch(1).to_i
x = worker + 1
n = 0
t0 = Process.clock_gettime(Process::CLOCK_MONOTONIC)
deadline = t0 + ARGV.fetch(0).to_f
while Process.clock_gettime(Process::CLOCK_MONOTONIC) < deadline
  x = ((x * 1103515245) + 12345) & 0xffffffff
  n += 1
end
elapsed = Process.clock_gettime(Process::CLOCK_MONOTONIC) - t0
STDERR.puts "ruby int_loop ops=#{n} elapsed_s=#{format("%.6f", elapsed)} worker=#{worker} sink=#{x}"
"""
_OTEL_INTERP_NODE = """\
const worker = Number(process.argv[2]);
let x = worker + 1;
let n = 0;
const t0 = process.hrtime.bigint();
const deadline = t0 + BigInt(Math.round(Number(process.argv[1]) * 1e9));
while (process.hrtime.bigint() < deadline) {
  x = (((x * 1103515245) + 12345) >>> 0);
  n++;
}
const dt = Number(process.hrtime.bigint() - t0) / 1e9;
process.stderr.write(`nodejs int_loop ops=${n} elapsed_s=${dt.toFixed(6)} worker=${worker} sink=${x}\\n`);
"""
_OTEL_INTERP_PERL = """\
use Time::HiRes qw(clock_gettime CLOCK_MONOTONIC);
my $worker = int($ARGV[1]);
my $x = $worker + 1;
my $n = 0;
my $t0 = clock_gettime(CLOCK_MONOTONIC);
my $deadline = $t0 + $ARGV[0];
while (clock_gettime(CLOCK_MONOTONIC) < $deadline) {
  $x = (($x * 1103515245) + 12345) & 0xffffffff;
  $n++;
}
my $dt = clock_gettime(CLOCK_MONOTONIC) - $t0;
printf STDERR ("perl int_loop ops=%d elapsed_s=%.6f worker=%d sink=%d\\n", $n, $dt, $worker, $x);
"""
_OTEL_INTERP_PHP = """\
$worker = (int)$argv[2];
$x = $worker + 1;
$n = 0;
$t0 = hrtime(true);
$deadline = $t0 + (int)((float)$argv[1] * 1e9);
while (hrtime(true) < $deadline) {
  $x = (($x * 1103515245) + 12345) & 0xffffffff;
  $n++;
}
$dt = (hrtime(true) - $t0) / 1e9;
fwrite(STDERR, sprintf("php int_loop ops=%d elapsed_s=%.6f worker=%d sink=%d\\n", $n, $dt, $worker, $x));
"""

# (tool, run_args) per language. Each script reads duration_s from argv[1]
# and worker index from argv[2]. The bounded integer loops keep the hot path
# in interpreter/JIT frames instead of spending most cycles in hashing C
# extensions, making OTEL profiler overhead visible in workload throughput.
# (perf_unwind_<lang> run_cnt stays 0 due to BPF tail-call prologue bypass;
# see the tail-call accounting caveat in CLAUDE.md.)
_OTEL_INTERP_LOOPS: tuple[tuple[str, tuple[str, ...]], ...] = (
    ("python3", ("-u", "-c", _OTEL_INTERP_PY)),
    ("ruby",    ("-e", _OTEL_INTERP_RB)),
    ("nodejs",  ("-e", _OTEL_INTERP_NODE)),
    ("perl",    ("-e", _OTEL_INTERP_PERL)),
    ("php",     ("-r", _OTEL_INTERP_PHP)),
)
_OTEL_INTERP_WORKERS_PER_LANGUAGE = 1


def run_otel_mixed_workload(duration_s: int | float) -> WorkloadResult:
    """Mixed workload for OTEL profiler: interpreter integer loops + stress-ng cpu.

    Concurrent processes for the measurement window:
      - Python/Ruby/Node.js/Perl/PHP each run bounded integer loops; these
        drive perf samples into interpreter/JIT PC ranges so the per-language
        perf_unwind_<lang> BPF programs are dispatched.
      - stress-ng `--cpu` exercises native CPU-bound code so perf samples
        also land in non-interpreter native stack frames, exercising
        perf_unwind_native and the Go-binary path.

    The composite WorkloadResult holds one component per concurrent process
    (language workers + stress-ng), each with raw stdout/stderr. Interpreting
    language ops/sec or stress-ng bogo-ops is external to the framework.

    Note: BPF tail-called programs (perf_unwind_<lang>) skip the prologue
    and stay at run_cnt=0; coverage of these programs is established via
    profiler-side telemetry, not the framework's per-program run_cnt_delta.
    See CLAUDE.md "Tail-call accounting caveat".
    """
    seconds = max(1, int(round(float(duration_s))))
    stress_ng = which("stress-ng")
    if stress_ng is None:
        raise RuntimeError("otel_mixed_workload requires stress-ng in PATH")
    temp_root = _disk_backed_tmp_root()
    procs: list[tuple[str, int | None, list[str], "subprocess.Popen[bytes]"]] = []
    start = time.monotonic()
    # Language interpreter loops first.
    for tool, args in _OTEL_INTERP_LOOPS:
        binary = which(tool)
        if binary is None:
            for _, _, _, proc in procs:
                if proc.poll() is None:
                    proc.kill()
            raise RuntimeError(f"otel_mixed_workload requires {tool} in PATH")
        for worker in range(_OTEL_INTERP_WORKERS_PER_LANGUAGE):
            cmd = [binary, *list(args), str(seconds), str(worker)]
            procs.append((tool, worker, cmd, subprocess.Popen(
                cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE, stdin=subprocess.DEVNULL,
            )))
    # Concurrent native stress (cpu class). Use --cpu 1 so the language
    # workers still get CPU time on small VMs; stress-ng itself emits
    # --metrics-brief lines on stdout for offline ops counting.
    stress_cmd = [stress_ng, "--cpu", "1", "--timeout", f"{seconds}s",
                  "--metrics-brief", "--temp-path", str(temp_root)]
    procs.append(("stress-ng", None, stress_cmd, subprocess.Popen(
        stress_cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE,
        stdin=subprocess.DEVNULL, cwd=str(temp_root),
    )))
    components: list[WorkloadResult] = []
    for tool, worker, cmd, proc in procs:
        try:
            out, err = proc.communicate()
        except BaseException:
            for _, _, _, pending in procs:
                if pending.poll() is None:
                    pending.kill()
            raise
        elapsed = time.monotonic() - start
        if proc.returncode != 0:
            raise RuntimeError(
                f"otel_mixed_workload {tool} failed (rc={proc.returncode}): "
                f"{tail_text(err.decode('utf-8','replace') or out.decode('utf-8','replace'))}"
            )
        config: dict[str, object] = {"tool": tool}
        if tool != "stress-ng":
            assert worker is not None
            config.update({
                "language": tool,
                "loop": "integer_lcg",
                "worker_index": worker,
                "workers_per_language": _OTEL_INTERP_WORKERS_PER_LANGUAGE,
            })
        else:
            config.update({"stressors": ["cpu"]})
        components.append(_record_run(
            workload_name=("otel_stress_ng_cpu" if tool == "stress-ng"
                           else f"otel_{tool}_int_loop_{worker}"),
            command=cmd, returncode=proc.returncode,
            duration_s=elapsed,
            stdout=out.decode("utf-8", "replace"),
            stderr=err.decode("utf-8", "replace"),
            config=config,
        ))
    return _composite(
        workload_name="otel_mixed_workload",
        components=components,
        duration_s=time.monotonic() - start,
    )


def run_noop(duration_s: int | float) -> WorkloadResult:
    """Sleep workload for apps whose runner-managed background processes are
    the actual measurement load (e.g. otelcol-ebpf-profiler with language
    interpreter idlers spawned in `start()`).

    The runner does no in-process work during measurement; perf samples
    accumulate against the long-running background interpreters that the
    runner already controls.
    """
    seconds = max(1, int(round(float(duration_s))))
    cmd = ["sleep", str(seconds)]
    start = time.monotonic()
    completed = run_command(cmd, check=False)
    elapsed = time.monotonic() - start
    return _record_run(
        workload_name="noop",
        command=cmd,
        returncode=completed.returncode,
        duration_s=elapsed,
        stdout=completed.stdout or "",
        stderr=completed.stderr or "",
        config={"tool": "sleep"},
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
            _stressors_for_current_arch(_STRESS_NG_WORKLOAD_STRESSORS[kind]),
            workload_name=kind,
        )
    if kind == "tcp_connect":
        return run_tcp_connect_load(seconds, network_device=network_device)
    if kind == "xdp_traffic":
        return run_xdp_traffic_load(seconds, network_device=network_device)
    if kind == "network_lossy_multi":
        return run_network_lossy_multi_load(seconds, network_device=network_device)
    if kind == "cilium_endpoint_pktgen":
        return run_cilium_endpoint_pktgen_load(seconds, network_device=network_device)
    if kind == "network_pktgen_udp":
        return run_network_pktgen_udp_load(seconds, network_device=network_device)
    if kind in {"fio", "fio_randrw"}:
        return run_file_io(seconds)
    if kind == "noop":
        return run_noop(seconds)
    if kind == "otel_mixed_workload":
        return run_otel_mixed_workload(seconds)
    raise RuntimeError(f"unsupported workload kind: {kind}")
