from __future__ import annotations

import json
import os
import re
import socket
import subprocess
import tempfile
import threading
import time
import urllib.parse
import urllib.request
from dataclasses import asdict, dataclass
from http.server import BaseHTTPRequestHandler, ThreadingHTTPServer
from pathlib import Path
from typing import Sequence

from . import run_command, tail_text, which


@dataclass(frozen=True, slots=True)
class WorkloadResult:
    ops_total: float
    ops_per_sec: float | None
    duration_s: float
    stdout: str
    stderr: str

    def to_dict(self) -> dict[str, object]:
        return asdict(self)


class _SilentHandler(BaseHTTPRequestHandler):
    def do_GET(self) -> None:  # noqa: N802
        payload = b"tracee-benchmark\n"
        self.send_response(200)
        self.send_header("Content-Type", "text/plain")
        self.send_header("Content-Length", str(len(payload)))
        self.end_headers()
        try:
            self.wfile.write(payload)
        except (BrokenPipeError, ConnectionResetError, ConnectionAbortedError, socket.timeout):
            # Workload clients may disconnect immediately after headers; this is
            # normal during short-lived probe traffic and should not spam logs.
            return

    def log_message(self, format: str, *args: object) -> None:
        del format, args


class LocalHttpServer:
    def __init__(self) -> None:
        self.server = ThreadingHTTPServer(("127.0.0.1", 0), _SilentHandler)
        self.thread = threading.Thread(target=self.server.serve_forever, daemon=True)

    @property
    def url(self) -> str:
        host, port = self.server.server_address
        return f"http://{host}:{port}/"

    def __enter__(self) -> "LocalHttpServer":
        self.thread.start()
        return self

    def __exit__(self, exc_type, exc, tb) -> None:
        self.server.shutdown()
        self.thread.join(timeout=2.0)
        self.server.server_close()


def _finish_result(ops_total: float, duration_s: float, stdout: str, stderr: str) -> WorkloadResult:
    return WorkloadResult(
        ops_total=float(ops_total),
        ops_per_sec=(float(ops_total) / duration_s) if duration_s > 0 else None,
        duration_s=duration_s,
        stdout=tail_text(stdout, max_lines=40, max_chars=8000),
        stderr=tail_text(stderr, max_lines=40, max_chars=8000),
    )


def _parse_stress_ng_bogo_ops(text: str, *, stressor: str | None = None) -> float | None:
    for line in text.splitlines():
        if "stress-ng:" not in line:
            continue
        if stressor and f" {stressor} " not in f" {line} ":
            continue
        values = re.findall(r"[-+]?\d+(?:\.\d+)?", line)
        if values:
            try:
                return float(values[0])
            except ValueError:
                continue
    return None


def run_rapid_exec_storm(
    duration_s: int | float | None = None,
    *,
    iterations: int | None = None,
    command: Sequence[str] | None = None,
    command_path: str = "/bin/true",
) -> WorkloadResult:
    duration_limit, iteration_limit = _normalize_workload_limits(duration_s, iterations)
    start = time.monotonic()
    ops_total = 0
    exec_command = list(command) if command else [command_path]
    while _work_remaining(start, duration_limit, ops_total, iteration_limit):
        completed = run_command(exec_command, check=False, timeout=5)
        if completed.returncode != 0:
            details = tail_text(completed.stderr or completed.stdout)
            raise RuntimeError(f"rapid exec workload failed: {details}")
        ops_total += 1
    elapsed = time.monotonic() - start
    return _finish_result(float(ops_total), elapsed, "", "")


def run_user_exec_loop(
    duration_s: int | float | None = None,
    *,
    iterations: int | None = None,
    uid: int = 65534,
    gid: int = 65534,
    command_path: str = "/bin/true",
) -> WorkloadResult:
    command: list[str] = [command_path]
    if os.geteuid() == 0:
        setpriv = which("setpriv")
        if setpriv is not None:
            command = [
                setpriv,
                "--reuid",
                str(uid),
                "--regid",
                str(gid),
                "--clear-groups",
                command_path,
            ]
    return run_rapid_exec_storm(
        duration_s,
        iterations=iterations,
        command=command,
        command_path=command_path,
    )


def run_exec_storm(duration_s: int | float, rate: int) -> WorkloadResult:
    stress_ng = which("stress-ng")
    if stress_ng is None:
        raise RuntimeError("stress-ng is required for the exec_storm workload")
    run_cwd: Path | None = None
    command: list[str] = [
        stress_ng,
        "--exec",
        str(max(1, int(rate))),
        "--exec-method",
        "execve",
        "--temp-path",
        "/tmp",
        "--timeout",
        f"{max(1, int(duration_s))}s",
        "--metrics-brief",
    ]
    if os.geteuid() == 0:
        setpriv = which("setpriv")
        if setpriv is None:
            raise RuntimeError("setpriv is required for the exec_storm workload when running as root")
        command = [
            setpriv,
            "--reuid",
            "65534",
            "--regid",
            "65534",
            "--clear-groups",
            *command,
        ]
        run_cwd = Path("/tmp")
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
    ops_total = _parse_stress_ng_bogo_ops(combined, stressor="exec")
    if ops_total is None:
        ops_total = max(1.0, elapsed * max(1, int(rate)))
    return _finish_result(ops_total, elapsed, completed.stdout or "", completed.stderr or "")


def run_file_io(duration_s: int | float) -> WorkloadResult:
    fio_binary = which("fio")
    if fio_binary is None:
        raise RuntimeError("fio is required for the file_io workload")
    with tempfile.TemporaryDirectory(prefix="tracee-fio-") as tempdir:
        data_path = Path(tempdir) / "fio.bin"
        command = [
            fio_binary,
            "--name=tracee-e2e",
            f"--filename={data_path}",
            "--rw=randread",
            "--bs=4k",
            "--size=100M",
            f"--runtime={max(1, int(duration_s))}",
            "--time_based=1",
            "--ioengine=sync",
            "--direct=0",
            "--output-format=json",
        ]
        start = time.monotonic()
        completed = run_command(command, check=False, timeout=float(duration_s) + 60)
        elapsed = time.monotonic() - start
        if completed.returncode != 0:
            details = tail_text(completed.stderr or completed.stdout)
            raise RuntimeError(f"fio file_io workload failed: {details}")
        payload = json.loads(completed.stdout)
        job = (payload.get("jobs") or [{}])[0]
        read_stats = job.get("read") or {}
        write_stats = job.get("write") or {}
        ops_total = float(read_stats.get("total_ios", 0) or 0) + float(write_stats.get("total_ios", 0) or 0)
        if ops_total <= 0:
            ops_total = (float(read_stats.get("iops", 0) or 0) + float(write_stats.get("iops", 0) or 0)) * elapsed
        return _finish_result(ops_total, elapsed, completed.stdout or "", completed.stderr or "")


def run_python_http_loop(duration_s: int | float, url: str) -> WorkloadResult:
    parsed = urllib.parse.urlsplit(url)
    if parsed.scheme not in {"http", "https"}:
        raise RuntimeError(f"unsupported URL scheme for python http workload: {url}")
    deadline = time.monotonic() + float(duration_s)
    ops_total = 0.0
    while time.monotonic() < deadline:
        with urllib.request.urlopen(url, timeout=2.0) as response:
            response.read(1)
        ops_total += 1.0
    elapsed = max(0.0, float(duration_s))
    return _finish_result(ops_total, elapsed, "", "")


def _prepare_read_file(path: Path, size_mb: int = 64) -> None:
    if path.exists() and path.stat().st_size >= size_mb * 1024 * 1024:
        return
    chunk = b"\0" * (1024 * 1024)
    with path.open("wb") as handle:
        for _ in range(max(1, int(size_mb))):
            handle.write(chunk)


def _normalize_workload_limits(
    duration_s: int | float | None,
    iterations: int | None,
) -> tuple[float | None, int | None]:
    duration_limit: float | None = None
    if duration_s is not None:
        duration_limit = max(0.0, float(duration_s))

    iteration_limit: int | None = None
    if iterations is not None:
        iteration_limit = max(1, int(iterations))

    if duration_limit is None and iteration_limit is None:
        raise ValueError("either duration_s or iterations is required")
    return duration_limit, iteration_limit


def _work_remaining(
    started_at: float,
    duration_limit: float | None,
    completed: int,
    iteration_limit: int | None,
) -> bool:
    if iteration_limit is not None and completed >= iteration_limit:
        return False
    if duration_limit is not None and (time.monotonic() - started_at) >= duration_limit:
        return False
    return True


def run_rapid_open_storm(
    duration_s: int | float | None = None,
    *,
    iterations: int | None = None,
    file_count: int = 128,
) -> WorkloadResult:
    duration_limit, iteration_limit = _normalize_workload_limits(duration_s, iterations)
    with tempfile.TemporaryDirectory(prefix="tetragon-open-storm-") as tempdir:
        directory = Path(tempdir)
        files = [directory / f"open-{index}.dat" for index in range(max(1, int(file_count)))]
        for path in files:
            path.write_bytes(b"x")

        start = time.monotonic()
        ops_total = 0
        while _work_remaining(start, duration_limit, ops_total, iteration_limit):
            path = files[ops_total % len(files)]
            with path.open("rb"):
                pass
            ops_total += 1
        elapsed = time.monotonic() - start
    return _finish_result(float(ops_total), elapsed, "", "")


def run_open_storm(
    duration_s: int | float | None = None,
    *,
    iterations: int | None = None,
    file_count: int = 128,
) -> WorkloadResult:
    return run_rapid_open_storm(duration_s, iterations=iterations, file_count=file_count)


def run_rapid_connect_storm(
    duration_s: int | float | None = None,
    *,
    iterations: int | None = None,
) -> WorkloadResult:
    duration_limit, iteration_limit = _normalize_workload_limits(duration_s, iterations)
    ready = threading.Event()
    stop = threading.Event()
    errors: list[str] = []
    port_holder: list[int] = []

    def server() -> None:
        try:
            with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as listener:
                listener.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
                listener.bind(("127.0.0.1", 0))
                listener.listen()
                listener.settimeout(0.25)
                port_holder.append(int(listener.getsockname()[1]))
                ready.set()
                while not stop.is_set():
                    try:
                        conn, _ = listener.accept()
                    except (socket.timeout, TimeoutError):
                        continue
                    with conn:
                        pass
        except Exception as exc:
            errors.append(str(exc))
            ready.set()

    thread = threading.Thread(target=server, daemon=True)
    thread.start()
    if not ready.wait(timeout=2.0):
        stop.set()
        thread.join(timeout=1.0)
        raise RuntimeError("loopback listener did not become ready")
    if errors:
        stop.set()
        thread.join(timeout=1.0)
        raise RuntimeError(f"loopback listener failed: {errors[-1]}")
    if not port_holder:
        stop.set()
        thread.join(timeout=1.0)
        raise RuntimeError("loopback listener failed to publish a port")

    port = port_holder[0]
    start = time.monotonic()
    ops_total = 0
    transient_failures = 0
    try:
        while _work_remaining(start, duration_limit, ops_total, iteration_limit):
            try:
                with socket.create_connection(("127.0.0.1", port), timeout=1.0):
                    pass
                ops_total += 1
            except (TimeoutError, OSError):
                transient_failures += 1
                time.sleep(0.001)
    finally:
        stop.set()
        thread.join(timeout=1.0)

    if errors:
        raise RuntimeError(f"loopback listener failed: {errors[-1]}")
    if ops_total <= 0 and transient_failures > 0:
        raise RuntimeError(f"loopback connects failed repeatedly ({transient_failures} transient failures)")
    elapsed = time.monotonic() - start
    stderr = "" if transient_failures <= 0 else f"transient_connect_failures={transient_failures}"
    return _finish_result(float(ops_total), elapsed, "", stderr)


def run_connect_storm(
    duration_s: int | float | None = None,
    *,
    iterations: int | None = None,
) -> WorkloadResult:
    return run_rapid_connect_storm(duration_s, iterations=iterations)


def run_rapid_bind_storm(
    duration_s: int | float | None = None,
    *,
    iterations: int | None = None,
) -> WorkloadResult:
    duration_limit, iteration_limit = _normalize_workload_limits(duration_s, iterations)
    start = time.monotonic()
    ops_total = 0
    while _work_remaining(start, duration_limit, ops_total, iteration_limit):
        with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as client:
            client.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
            client.bind(("127.0.0.1", 0))
        ops_total += 1
    elapsed = time.monotonic() - start
    return _finish_result(float(ops_total), elapsed, "", "")


def run_bind_storm(
    duration_s: int | float | None = None,
    *,
    iterations: int | None = None,
) -> WorkloadResult:
    return run_rapid_bind_storm(duration_s, iterations=iterations)


def run_file_open_load(duration_s: int | float) -> WorkloadResult:
    stress_ng = which("stress-ng")
    if stress_ng is None:
        raise RuntimeError("stress-ng is required for the file_open workload")
    command = [
        stress_ng,
        "--open",
        "4",
        "--timeout",
        f"{max(1, int(duration_s))}s",
        "--metrics-brief",
    ]
    start = time.monotonic()
    completed = run_command(command, check=False, timeout=float(duration_s) + 30)
    elapsed = time.monotonic() - start
    if completed.returncode != 0:
        details = tail_text(completed.stderr or completed.stdout)
        raise RuntimeError(f"file_open workload failed: {details}")
    combined = (completed.stdout or "") + "\n" + (completed.stderr or "")
    ops_total = _parse_stress_ng_bogo_ops(combined, stressor="open")
    if ops_total is None:
        ops_total = max(1.0, elapsed)
    return _finish_result(ops_total, elapsed, completed.stdout or "", completed.stderr or "")


def run_dd_read_load(duration_s: int | float) -> WorkloadResult:
    dd_binary = which("dd") or "dd"
    with tempfile.TemporaryDirectory(prefix="tracee-dd-read-") as tempdir:
        data_path = Path(tempdir) / "read-target.bin"
        _prepare_read_file(data_path, size_mb=64)
        block_size = "4k"
        block_count = 4096
        start = time.monotonic()
        deadline = start + float(duration_s)
        stderr_lines: list[str] = []
        ops_total = 0.0
        while time.monotonic() < deadline:
            completed = run_command(
                [
                    dd_binary,
                    f"if={data_path}",
                    "of=/dev/null",
                    f"bs={block_size}",
                    f"count={block_count}",
                    "iflag=fullblock",
                    "status=none",
                ],
                check=False,
                timeout=30,
            )
            if completed.returncode != 0:
                details = tail_text(completed.stderr or completed.stdout)
                raise RuntimeError(f"dd read load failed: {details}")
            stderr_lines.append(completed.stderr or "")
            ops_total += float(block_count)
        elapsed = time.monotonic() - start
        return _finish_result(ops_total, elapsed, "", "\n".join(stderr_lines))


def run_network_load(duration_s: int | float) -> WorkloadResult:
    wrk_binary = which("wrk")
    if wrk_binary is None:
        raise RuntimeError("wrk is required for the network workload")
    with LocalHttpServer() as server:
        command = [
            wrk_binary,
            "-t2",
            "-c10",
            f"-d{max(1, int(duration_s))}s",
            server.url,
        ]
        start = time.monotonic()
        completed = run_command(command, check=False, timeout=float(duration_s) + 30)
        elapsed = time.monotonic() - start
        if completed.returncode != 0:
            details = tail_text(completed.stderr or completed.stdout)
            raise RuntimeError(f"network wrk load failed: {details}")
        requests_per_sec = None
        total_requests = None
        for line in completed.stdout.splitlines():
            line = line.strip()
            req_match = re.search(r"Requests/sec:\s+([0-9.]+)", line)
            if req_match:
                requests_per_sec = float(req_match.group(1))
            total_match = re.search(r"([0-9]+)\s+requests in", line)
            if total_match:
                total_requests = float(total_match.group(1))
        if total_requests is None and requests_per_sec is not None:
            total_requests = requests_per_sec * elapsed
        return _finish_result(total_requests or 0.0, elapsed, completed.stdout or "", completed.stderr or "")


def run_tcp_connect_load(duration_s: int | float) -> WorkloadResult:
    curl_binary = which("curl")
    if curl_binary is None:
        raise RuntimeError("curl is required for TCP connect load")
    with LocalHttpServer() as server:
        start = time.monotonic()
        deadline = start + float(duration_s)
        ops_total = 0.0
        stderr_lines: list[str] = []
        while time.monotonic() < deadline:
            completed = run_command(
                [curl_binary, "-fsS", "-o", "/dev/null", "--http1.1", "--max-time", "2", server.url],
                check=False,
                timeout=5,
            )
            if completed.returncode != 0:
                details = tail_text(completed.stderr or completed.stdout)
                raise RuntimeError(f"tcp connect load failed: {details}")
            stderr_lines.append(completed.stderr or "")
            ops_total += 1.0
        elapsed = time.monotonic() - start
        return _finish_result(ops_total, elapsed, "", "\n".join(stderr_lines))


def run_scheduler_load(duration_s: int | float) -> WorkloadResult:
    hackbench = which("hackbench")
    if hackbench is None:
        raise RuntimeError("hackbench is required for the scheduler workload")
    start = time.monotonic()
    deadline = start + float(duration_s)
    completed_runs = 0.0
    stdout_lines: list[str] = []
    stderr_lines: list[str] = []
    while time.monotonic() < deadline:
        completed = run_command(
            [hackbench, "--pipe", "--groups", "8", "--fds", "16", "--loops", "10"],
            check=False,
            timeout=max(30, int(duration_s) + 10),
        )
        if completed.returncode != 0:
            details = tail_text(completed.stderr or completed.stdout)
            raise RuntimeError(f"scheduler hackbench failed: {details}")
        stdout_lines.append(completed.stdout or "")
        stderr_lines.append(completed.stderr or "")
        completed_runs += 1.0
    elapsed = time.monotonic() - start
    return _finish_result(completed_runs, elapsed, "\n".join(stdout_lines), "\n".join(stderr_lines))


def run_named_workload(workload_kind: str, duration_s: int | float) -> WorkloadResult:
    seconds = max(1, int(round(float(duration_s))))
    kind = str(workload_kind or "").strip()
    if kind == "exec_storm":
        return run_exec_storm(seconds, rate=2)
    if kind == "file_open_storm":
        return run_file_open_load(seconds)
    if kind in {"network", "tracee_default"}:
        return run_network_load(seconds)
    if kind == "fio":
        return run_file_io(seconds)
    if kind == "hackbench":
        return run_scheduler_load(seconds)
    if kind == "bind_storm":
        return run_bind_storm(seconds)
    if kind == "minimal_syscall":
        return run_user_exec_loop(seconds)
    if kind == "iterator_poll":
        start = time.monotonic()
        deadline = start + float(seconds)
        ops_total = 0.0
        while time.monotonic() < deadline:
            list(Path("/proc/self/task").iterdir())
            ops_total += 1.0
        elapsed = time.monotonic() - start
        return _finish_result(ops_total, elapsed, "", "")
    if kind == "mixed_system":
        return _run_mixed_workload(float(seconds))
    if kind == "security_policy_mix":
        result = run_open_storm(seconds)
        return WorkloadResult(
            ops_total=result.ops_total,
            ops_per_sec=result.ops_per_sec,
            duration_s=result.duration_s,
            stdout=result.stdout,
            stderr=result.stderr,
        )
    if kind == "system_telemetry_mix":
        return _run_mixed_workload(float(seconds))
    if kind == "oom_stress":
        stress_ng = which("stress-ng")
        if stress_ng is None:
            raise RuntimeError("stress-ng is required for the oom_stress workload")
        command = [
            stress_ng,
            "--vm",
            "1",
            "--vm-bytes",
            "75%",
            "--oomable",
            "--timeout",
            f"{seconds}s",
            "--metrics-brief",
        ]
        start = time.monotonic()
        completed = run_command(command, check=False, timeout=float(seconds) + 30)
        elapsed = time.monotonic() - start
        if completed.returncode != 0:
            details = tail_text(completed.stderr or completed.stdout)
            raise RuntimeError(f"oom_stress workload failed: {details}")
        combined = (completed.stdout or "") + "\n" + (completed.stderr or "")
        ops_total = _parse_stress_ng_bogo_ops(combined, stressor="vm") or 0.0
        return _finish_result(ops_total, elapsed, completed.stdout or "", completed.stderr or "")
    if kind == "sysctl_write":
        sysctl_binary = which("sysctl")
        if sysctl_binary is None:
            raise RuntimeError("sysctl is required for the sysctl_write workload")
        start = time.monotonic()
        deadline = start + float(seconds)
        ops_total = 0.0
        while time.monotonic() < deadline:
            completed = run_command([sysctl_binary, "-n", "kernel.pid_max"], check=False, timeout=5)
            if completed.returncode != 0:
                details = tail_text(completed.stderr or completed.stdout)
                raise RuntimeError(f"sysctl_write workload failed: {details}")
            ops_total += 1.0
        elapsed = time.monotonic() - start
        return _finish_result(ops_total, elapsed, "", "")
    if kind == "userns_unshare":
        unshare_binary = which("unshare")
        if unshare_binary is None:
            raise RuntimeError("unshare is required for the userns_unshare workload")
        start = time.monotonic()
        deadline = start + float(seconds)
        ops_total = 0.0
        while time.monotonic() < deadline:
            completed = run_command([unshare_binary, "-Ur", "/bin/true"], check=False, timeout=5)
            if completed.returncode != 0:
                details = tail_text(completed.stderr or completed.stdout)
                raise RuntimeError(f"userns_unshare workload failed: {details}")
            ops_total += 1.0
        elapsed = time.monotonic() - start
        return _finish_result(ops_total, elapsed, "", "")
    raise RuntimeError(f"unsupported workload kind: {kind}")


__all__ = [
    "WorkloadResult",
    "run_connect_storm",
    "run_dd_read_load",
    "run_exec_storm",
    "run_bind_storm",
    "run_file_open_load",
    "run_file_io",
    "run_network_load",
    "run_open_storm",
    "run_rapid_bind_storm",
    "run_rapid_connect_storm",
    "run_rapid_open_storm",
    "run_named_workload",
    "run_scheduler_load",
    "run_tcp_connect_load",
    "run_user_exec_loop",
]
