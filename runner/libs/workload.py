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
from pathlib import Path
from typing import Mapping, Sequence

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
    "udp-flood",
)
_STRESS_NG_OS_STRESSORS = (
    "cap",
    "eventfd",
    "get",
    "prctl",
    "set",
)
_STRESS_NG_SCHEDULER_STRESSORS = (
    "clone",
    "fork",
    "futex",
    "sem",
    "sem-sysv",
    "switch",
    "vfork",
    "yield",
)
_STRESS_NG_WORKLOAD_STRESSORS: Mapping[str, tuple[str, ...]] = {
    "stress_ng_cpu": _STRESS_NG_CPU_STRESSORS,
    "stress_ng_filesystem": _STRESS_NG_FILESYSTEM_STRESSORS,
    "stress_ng_io": _STRESS_NG_IO_STRESSORS,
    "stress_ng_network": _STRESS_NG_NETWORK_STRESSORS,
    "stress_ng_os": _STRESS_NG_OS_STRESSORS,
    "stress_ng_process": _STRESS_NG_SCHEDULER_STRESSORS,
    "stress_ng_scheduler": _STRESS_NG_SCHEDULER_STRESSORS,
    "stress_ng_os_io_network": (
        *_STRESS_NG_OS_STRESSORS,
        *_STRESS_NG_IO_STRESSORS,
        *_STRESS_NG_NETWORK_STRESSORS,
    ),
}

_STRESS_NG_STRESSOR_ARGS: Mapping[str, tuple[str, ...]] = {
    "fallocate": ("--fallocate-bytes", "128M"),
    "fpunch": ("--fpunch-bytes", "32M"),
    "hdd": ("--hdd-bytes", "128M"),
    "iomix": ("--iomix-bytes", "128M"),
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
    for stressor in normalized_stressors:
        command += [f"--{stressor}", "1"]
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


def run_exec_storm(duration_s: int | float, rate: int) -> WorkloadResult:
    stress_ng = which("stress-ng")
    if stress_ng is None:
        raise RuntimeError("stress-ng is required for the exec_storm workload")
    temp_root = _disk_backed_tmp_root()
    run_cwd: Path | None = None
    stress_ng_args = ["--exec", str(max(1, int(rate))), "--exec-method", "execve",
                      "--temp-path", str(temp_root), "--timeout", f"{max(1, int(duration_s))}s", "--metrics-brief"]
    command: list[str] = [stress_ng, *stress_ng_args]
    if os.geteuid() == 0:
        setpriv = which("setpriv")
        if setpriv is None:
            raise RuntimeError("setpriv is required for the exec_storm workload when running as root")
        temp_root = _shared_unprivileged_tmp_root()
        stress_ng_args[5] = str(temp_root)
        command = [setpriv, "--reuid", "65534", "--regid", "65534", "--clear-groups", stress_ng, *stress_ng_args]
        run_cwd = temp_root
    start = time.monotonic()
    try:
        completed = run_command(
            command,
            check=False,
            cwd=run_cwd,
            timeout=max(float(duration_s) + 30, float(duration_s) * 12),
        )
    except subprocess.TimeoutExpired:
        raise RuntimeError("stress-ng exec workload timed out")
    elapsed = time.monotonic() - start
    if completed.returncode != 0:
        details = tail_text(completed.stderr or completed.stdout)
        raise RuntimeError(f"stress-ng exec workload failed: {details}")
    combined = (completed.stdout or "") + "\n" + (completed.stderr or "")
    ops_total = parse_stress_ng_bogo_ops(combined, stressor="exec")
    if ops_total is None:
        details = tail_text(combined)
        raise RuntimeError(f"stress-ng exec workload did not report bogo-ops metrics: {details}")
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


def _shared_unprivileged_tmp_root() -> Path:
    for candidate in (Path("/dev/shm"), Path("/tmp"), Path("/var/tmp")):
        try: candidate.mkdir(parents=True, exist_ok=True)
        except OSError: continue
        if not os.access(candidate, os.W_OK | os.X_OK): continue
        runtime_root = candidate / "bpf-benchmark"
        try: runtime_root.mkdir(parents=True, exist_ok=True); runtime_root.chmod(0o1777)
        except OSError: continue
        if os.access(runtime_root, os.W_OK | os.X_OK): return runtime_root
    raise RuntimeError("no writable shared temporary directory is available for exec_storm")


def _build_shell_cpu_burn_command(duration_s: float) -> tuple[list[str] | None, list[str]]:
    bash_binary = which("bash")
    if bash_binary is None:
        return None, ["shell_burner_unavailable"]
    duration_us = max(1, int(round(duration_s * 1_000_000.0)))
    return (
        [
            bash_binary,
            "-lc",
            (
                "if [ -n \"${EPOCHREALTIME:-}\" ]; then "
                f"end_us=$((10#${{EPOCHREALTIME/./}} + {duration_us})); "
                "while (( 10#${EPOCHREALTIME/./} < end_us )); do :; done; "
                "else "
                f"end_ns=$(( $(date +%s%N) + {duration_us * 1000} )); "
                "while [ \"$(date +%s%N)\" -lt \"$end_ns\" ]; do :; done; "
                "fi"
            ),
        ],
        ["shell_burner=bash"],
    )


def _build_native_cpu_burn_command(root: Path, duration_s: float) -> tuple[list[str] | None, str | None]:
    cc_binary = which("cc") or which("gcc") or which("clang")
    if cc_binary is None:
        return None, "native_burner_unavailable"
    source = root / "cpu_burn.c"
    binary = root / "cpu-burn-native"
    source.write_text(
        """
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv) {
    const double duration_s = (argc > 1) ? atof(argv[1]) : 1.0;
    struct timespec start;
    if (clock_gettime(CLOCK_MONOTONIC, &start) != 0) {
        return 2;
    }
    const unsigned long long start_ns =
        ((unsigned long long)start.tv_sec * 1000000000ULL) + (unsigned long long)start.tv_nsec;
    const unsigned long long duration_ns =
        (unsigned long long)(duration_s * 1000000000.0);
    unsigned long long value = 1;
    for (;;) {
        struct timespec now;
        if (clock_gettime(CLOCK_MONOTONIC, &now) != 0) {
            return 3;
        }
        const unsigned long long now_ns =
            ((unsigned long long)now.tv_sec * 1000000000ULL) + (unsigned long long)now.tv_nsec;
        if ((now_ns - start_ns) >= duration_ns) {
            break;
        }
        value = value * 1664525ULL + 1013904223ULL;
    }
    if (value == 0) {
        fprintf(stderr, "%llu\\n", value);
    }
    return 0;
}
        """.strip()
        + "\n",
        encoding="utf-8",
    )
    build = run_command(
        [
            cc_binary,
            "-O2",
            "-fno-omit-frame-pointer",
            "-std=c11",
            "-D_POSIX_C_SOURCE=200809L",
            "-o",
            str(binary),
            str(source),
        ],
        check=False,
        timeout=30,
    )
    if build.returncode != 0:
        return None, f"native_burner_build_failed={tail_text(build.stderr or build.stdout)}"
    return [str(binary), f"{duration_s:.3f}"], None


def _build_go_cpu_burn_command(root: Path, duration_s: float) -> tuple[list[str] | None, str | None]:
    go_binary = which("go")
    if go_binary is None:
        return None, "go_burner_unavailable"
    source = root / "cpu_burn.go"
    binary = root / "cpu-burn-go"
    source.write_text(
        """
package main

import (
    "context"
    "os"
    "runtime/pprof"
    "strconv"
    "time"
)

func main() {
    durationS, err := strconv.ParseFloat(os.Args[1], 64)
    if err != nil {
        panic(err)
    }
    labels := pprof.Labels("workload", "otel-profiler", "language", "go")
    pprof.Do(context.Background(), labels, func(context.Context) {
        deadline := time.Now().Add(time.Duration(durationS * float64(time.Second)))
        value := uint64(1)
        for time.Now().Before(deadline) {
            value = value*1664525 + 1013904223
        }
        if value == 0 {
            os.Stderr.WriteString("0")
        }
    })
}
        """.strip()
        + "\n",
        encoding="utf-8",
    )
    build = run_command(
        [go_binary, "build", "-o", str(binary), str(source)],
        check=False,
        timeout=60,
    )
    if build.returncode != 0:
        return None, f"go_burner_build_failed={tail_text(build.stderr or build.stdout)}"
    return [str(binary), f"{duration_s:.3f}"], None


def run_otel_profiler_cpu_mix_workload(duration_s: int | float) -> WorkloadResult:
    effective_duration = max(1.0, float(duration_s))
    python_binary = sys.executable or which("python3")
    if not python_binary:
        raise RuntimeError("python3 is required for the otel profiler CPU mix workload")
    with tempfile.TemporaryDirectory(prefix="otel-profiler-workload-", dir=str(_disk_backed_tmp_root())) as tempdir:
        root = Path(tempdir)
        commands: list[tuple[str, list[str]]] = []
        notes: list[str] = []
        shell_command, shell_notes = _build_shell_cpu_burn_command(effective_duration)
        notes.extend(shell_notes)
        if shell_command is not None:
            commands.append(("shell", shell_command))
        native_command, native_note = _build_native_cpu_burn_command(root, effective_duration)
        if native_note:
            notes.append(native_note)
        if native_command is not None:
            commands.append(("native", native_command))
        go_command, go_note = _build_go_cpu_burn_command(root, effective_duration)
        if go_note:
            notes.append(go_note)
        if go_command is not None:
            commands.append(("go", go_command))
        commands.append(
            (
                "python",
                [
                    python_binary,
                    "-c",
                    (
                        "import time\n"
                        "deadline = time.monotonic() + float(__import__('sys').argv[1])\n"
                        "value = 1\n"
                        "while time.monotonic() < deadline:\n"
                        "    value = (value * 1664525 + 1013904223) & 0xFFFFFFFF\n"
                        "print(value if value == -1 else '', end='')\n"
                    ),
                    f"{effective_duration:.3f}",
                ],
            )
        )
        if node_binary := (which("node") or which("nodejs")):
            commands.append(
                (
                    "node",
                    [
                        node_binary,
                        "-e",
                        (
                            "const deadline = Date.now() + Math.ceil(Number(process.argv[1]) * 1000);"
                            " let value = 1;"
                            " while (Date.now() < deadline) { value = (value * 1664525 + 1013904223) >>> 0; }"
                            " if (value === 0xffffffff) console.error(value);"
                        ),
                        f"{effective_duration:.3f}",
                    ],
                )
            )
        else:
            notes.append("node_burner_unavailable")
        if java_binary := which("java"):
            java_source = root / "CpuBurn.java"
            java_source.write_text(
                """
public final class CpuBurn {
    public static void main(String[] args) {
        final long durationNs = (long) (Double.parseDouble(args[0]) * 1_000_000_000L);
        final long start = System.nanoTime();
        long value = 1L;
        while ((System.nanoTime() - start) < durationNs) {
            value = value * 1664525L + 1013904223L;
        }
        if (value == Long.MIN_VALUE) {
            System.err.println(value);
        }
    }
}
                """.strip()
                + "\n",
                encoding="utf-8",
            )
            commands.append(("java", [java_binary, str(java_source), f"{effective_duration:.3f}"]))
        else:
            notes.append("java_burner_unavailable")
        if ruby_binary := which("ruby"):
            commands.append(
                (
                    "ruby",
                    [
                        ruby_binary,
                        "-e",
                        (
                            "deadline = Process.clock_gettime(Process::CLOCK_MONOTONIC) + ARGV[0].to_f;"
                            " value = 1;"
                            " while Process.clock_gettime(Process::CLOCK_MONOTONIC) < deadline do"
                            " value = (value * 1664525 + 1013904223) & 0xffffffff;"
                            " end;"
                            " warn(value) if value == -1"
                        ),
                        f"{effective_duration:.3f}",
                    ],
                )
            )
        else:
            notes.append("ruby_burner_unavailable")
        if perl_binary := which("perl"):
            commands.append(
                (
                    "perl",
                    [
                        perl_binary,
                        "-e",
                        (
                            "use Time::HiRes qw(clock_gettime CLOCK_MONOTONIC);"
                            " my $deadline = clock_gettime(CLOCK_MONOTONIC) + $ARGV[0];"
                            " my $value = 1;"
                            " while (clock_gettime(CLOCK_MONOTONIC) < $deadline) {"
                            "   $value = ($value * 1664525 + 1013904223) & 0xffffffff;"
                            " }"
                            " print q{} if $value == -1;"
                        ),
                        f"{effective_duration:.3f}",
                    ],
                )
            )
        else:
            notes.append("perl_burner_unavailable")

        processes: list[tuple[str, subprocess.Popen[str]]] = []
        started_burners: list[str] = []
        start = time.monotonic()
        deadline = start + effective_duration
        try:
            for name, command in commands:
                try:
                    processes.append(
                        (
                            name,
                            subprocess.Popen(
                                command,
                                stdout=subprocess.PIPE,
                                stderr=subprocess.PIPE,
                                text=True,
                            ),
                        )
                    )
                    started_burners.append(name)
                except OSError as exc:
                    notes.append(f"{name}_burner_start_failed={exc}")
            if not processes:
                raise RuntimeError("no otel profiler CPU burners could be started")
            while time.monotonic() < deadline and processes:
                now = time.monotonic()
                still_running: list[tuple[str, subprocess.Popen[str]]] = []
                for name, process in processes:
                    if process.poll() is None or (now + 0.1) >= deadline:
                        still_running.append((name, process))
                        continue
                    stdout_text, stderr_text = process.communicate()
                    notes.append(
                        f"{name}_burner_exited_early={process.returncode}:{tail_text(stderr_text or stdout_text)}",
                    )
                processes = still_running
                if not processes:
                    raise RuntimeError("all otel profiler CPU burners exited before the sampling window ended")
                time.sleep(0.05)
            stdout_parts: list[str] = []
            stderr_parts: list[str] = []
            successful_burners: list[str] = []
            for name, process in processes:
                remaining_timeout = max(5.0, effective_duration)
                stdout_text, stderr_text = process.communicate(timeout=remaining_timeout)
                if process.returncode != 0:
                    notes.append(
                        f"{name}_burner_failed={process.returncode}:{tail_text(stderr_text or stdout_text)}",
                    )
                    continue
                successful_burners.append(name)
                if stdout_text.strip():
                    stdout_parts.append(stdout_text)
                if stderr_text.strip():
                    stderr_parts.append(f"{name}: {stderr_text}")
            if not successful_burners:
                raise RuntimeError("all otel profiler CPU burners failed before completing")
        finally:
            for _name, process in processes:
                if process.poll() is None:
                    process.terminate()
                    try:
                        process.wait(timeout=5)
                    except subprocess.TimeoutExpired:
                        process.kill()
                        process.wait(timeout=5)
        started = " ".join(started_burners)
        stdout = "\n".join(part for part in [f"started_burners={started}", *stdout_parts] if part)
        stderr = "\n".join(part for part in [*notes, *stderr_parts] if part)
        return _finish_result(float(len(successful_burners)), time.monotonic() - start, stdout, stderr)


def _network_http_server(network_device: str | None = None) -> LocalHttpServer | NamespacedHttpServer:
    normalized_device = str(network_device or "").strip()
    if not normalized_device:
        return LocalHttpServer()
    if normalized_device != BENCHMARK_IFACE:
        raise RuntimeError(
            f"interface-bound network workload only supports benchmark interface {BENCHMARK_IFACE}; "
            f"got {normalized_device}"
        )
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


def run_network_load(duration_s: int | float, *, network_device: str | None = None) -> WorkloadResult:
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
    curl_binary = which("curl")
    if curl_binary is None:
        raise RuntimeError("curl is required for TCP connect load")
    normalized_device = str(network_device or "").strip()
    if normalized_device:
        with _network_http_server(normalized_device) as server:
            start = time.monotonic(); deadline = start + float(duration_s)
            ops_total = 0.0; stderr_lines: list[str] = []
            while time.monotonic() < deadline:
                command = _network_client_command(
                    [curl_binary, "-fsS", "-g", "-o", "/dev/null", "--http1.1", "--max-time", "2", server.url],
                    normalized_device,
                )
                c = run_command(command, check=False, timeout=5)
                if c.returncode != 0:
                    raise RuntimeError(
                        f"tcp connect load failed via {_render_command(command)}: {tail_text(c.stderr or c.stdout)}"
                    )
                stderr_lines.append(c.stderr or ""); ops_total += 1.0
            elapsed = time.monotonic() - start
            return _finish_result(ops_total, elapsed, "", "\n".join(stderr_lines))
    with LocalHttpServer("127.0.0.1") as server_v4, LocalHttpServer("::1") as server_v6:
        urls = (server_v4.url, server_v6.url)
        start = time.monotonic(); deadline = start + float(duration_s)
        ops_total = 0.0; stderr_lines: list[str] = []
        while time.monotonic() < deadline:
            c = run_command([curl_binary, "-fsS", "-g", "-o", "/dev/null", "--http1.1", "--max-time", "2", urls[int(ops_total) % len(urls)]], check=False, timeout=5)
            if c.returncode != 0:
                raise RuntimeError(f"tcp connect load failed: {tail_text(c.stderr or c.stdout)}")
            stderr_lines.append(c.stderr or ""); ops_total += 1.0
        elapsed = time.monotonic() - start
        return _finish_result(ops_total, elapsed, "", "\n".join(stderr_lines))


def run_scheduler_load(duration_s: int | float) -> WorkloadResult:
    hackbench = resolve_workload_tool("hackbench")
    start = time.monotonic()
    deadline = start + float(duration_s)
    completed_runs = 0.0
    stdout_lines: list[str] = []
    stderr_lines: list[str] = []
    while time.monotonic() < deadline:
        c = run_command([hackbench, "--pipe", "--groups", "8", "--fds", "16", "--loops", "10"], check=False, timeout=max(30, int(duration_s) + 10))
        if c.returncode != 0:
            raise RuntimeError(f"scheduler hackbench failed: {tail_text(c.stderr or c.stdout)}")
        stdout_lines.append(c.stdout or ""); stderr_lines.append(c.stderr or "")
        completed_runs += 1.0
    elapsed = time.monotonic() - start
    return _finish_result(completed_runs, elapsed, "\n".join(stdout_lines), "\n".join(stderr_lines))


def run_named_workload(
    kind: str,
    duration_s: int | float,
    *,
    network_as_tcp_connect: bool = False,
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
    if kind == "scheduler":
        return run_scheduler_load(seconds)
    if kind == "exec_storm":
        return run_exec_storm(seconds, rate=2)
    if kind == "network":
        if network_as_tcp_connect:
            return run_tcp_connect_load(seconds, network_device=network_device)
        return run_network_load(seconds, network_device=network_device)
    if kind in {"fio", "fio_randrw"}:
        return run_file_io(seconds)
    if kind == "hackbench":
        return run_scheduler_load(seconds)
    if kind == "oom_stress":
        stress_ng = which("stress-ng")
        if stress_ng is None:
            raise RuntimeError("stress-ng is required for the oom_stress workload")
        command = [stress_ng, "--vm", "1", "--vm-bytes", "75%", "--oomable", "--timeout", f"{seconds}s", "--metrics-brief"]
        start = time.monotonic()
        completed = run_command(command, check=False, timeout=float(seconds) + 30)
        elapsed = time.monotonic() - start
        if completed.returncode != 0:
            raise RuntimeError(f"oom_stress workload failed: {tail_text(completed.stderr or completed.stdout)}")
        combined = (completed.stdout or "") + "\n" + (completed.stderr or "")
        if (ops_total := parse_stress_ng_bogo_ops(combined, stressor="vm")) is None:
            raise RuntimeError(f"oom_stress workload did not report bogo-ops metrics: {tail_text(combined)}")
        return _finish_result(ops_total, elapsed, completed.stdout or "", completed.stderr or "")
    raise RuntimeError(f"unsupported workload kind: {kind}")
