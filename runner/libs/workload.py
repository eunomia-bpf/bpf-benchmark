from __future__ import annotations

import json
import os
import re
import socket
import stat
import subprocess
import tempfile
import threading
import time
from dataclasses import asdict, dataclass
from http.server import BaseHTTPRequestHandler, ThreadingHTTPServer
from pathlib import Path
from typing import Sequence

from . import run_command, tail_text, which
from .kernel_modules import load_kernel_module

LOOPBACK_LISTEN_BACKLOG = 128
LOOPBACK_CONNECT_TIMEOUT_S = 2.0


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


class _ThreadingHTTPServerV6(ThreadingHTTPServer):
    address_family = socket.AF_INET6


class LocalHttpServer:
    def __init__(self, host: str = "127.0.0.1") -> None:
        self.host = str(host)
        self.family = socket.AF_INET6 if ":" in self.host else socket.AF_INET
        server_class = _ThreadingHTTPServerV6 if self.family == socket.AF_INET6 else ThreadingHTTPServer
        bind_address: tuple[object, ...]
        if self.family == socket.AF_INET6:
            bind_address = (self.host, 0, 0, 0)
        else:
            bind_address = (self.host, 0)
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


def _finish_result(ops_total: float, duration_s: float, stdout: str, stderr: str) -> WorkloadResult:
    return WorkloadResult(
        ops_total=float(ops_total),
        ops_per_sec=(float(ops_total) / duration_s) if duration_s > 0 else None,
        duration_s=duration_s,
        stdout=tail_text(stdout, max_lines=40, max_chars=8000),
        stderr=tail_text(stderr, max_lines=40, max_chars=8000),
    )


def _merge_workload_results(results: Sequence[WorkloadResult]) -> WorkloadResult:
    total_duration = sum(result.duration_s for result in results)
    total_ops = sum(result.ops_total for result in results)
    stdout = "\n".join(result.stdout for result in results if result.stdout)
    stderr = "\n".join(result.stderr for result in results if result.stderr)
    return WorkloadResult(
        ops_total=total_ops,
        ops_per_sec=(total_ops / total_duration) if total_duration > 0 else None,
        duration_s=total_duration,
        stdout=tail_text(stdout, max_lines=80, max_chars=12000),
        stderr=tail_text(stderr, max_lines=80, max_chars=12000),
    )


def parse_stress_ng_bogo_ops(text: str, *, stressor: str | None = None) -> float | None:
    for line in text.splitlines():
        if "stress-ng: metrc:" not in line:
            continue
        match = re.search(r"stress-ng:\s+metrc:\s+\[\d+\]\s+(\S+)\s+([-+]?\d+(?:\.\d+)?)", line)
        if not match:
            continue
        matched_stressor, bogo_ops = match.groups()
        if stressor and matched_stressor != stressor:
            continue
        try:
            return float(bogo_ops)
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
        if setpriv is None:
            raise RuntimeError("setpriv is required for the exec_loop workload when running as root")
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
    temp_root = _disk_backed_tmp_root()
    run_cwd: Path | None = None
    stress_ng_args: list[str] = [
        "--exec",
        str(max(1, int(rate))),
        "--exec-method",
        "execve",
        "--temp-path",
        str(temp_root),
        "--timeout",
        f"{max(1, int(duration_s))}s",
        "--metrics-brief",
    ]
    command: list[str] = [stress_ng, *stress_ng_args]
    if os.geteuid() == 0:
        setpriv = which("setpriv")
        if setpriv is None:
            raise RuntimeError("setpriv is required for the exec_storm workload when running as root")
        temp_root = _shared_unprivileged_tmp_root()
        stress_ng_args[5] = str(temp_root)
        command = [
            setpriv,
            "--reuid",
            "65534",
            "--regid",
            "65534",
            "--clear-groups",
            stress_ng,
            *stress_ng_args,
        ]
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
    with tempfile.TemporaryDirectory(prefix="tracee-fio-", dir=str(_disk_backed_tmp_root())) as tempdir:
        data_path = Path(tempdir) / "fio.bin"
        command = [
            fio_binary,
            "--name=tracee-e2e",
            f"--filename={data_path}",
            # Mixed randrw on a freshly created file can issue an initial read
            # against yet-unwritten offsets and fail under virtme's rw overlay.
            # Random writes still exercise the block layer and biosnoop probes
            # without tripping that guest-specific EIO path.
            "--rw=randwrite",
            "--bs=4k",
            "--size=64M",
            f"--runtime={max(1, int(duration_s))}",
            "--time_based=1",
            "--ioengine=sync",
            # virtme rw overlays commonly reject O_DIRECT with EIO. Keep the
            # workload buffered, invalidate cache, and fsync each iteration so
            # biosnoop-style block I/O still happens in the guest.
            "--create_on_open=1",
            "--fsync=1",
            "--end_fsync=1",
            "--invalidate=1",
            "--output-format=json",
        ]
        start = time.monotonic()
        completed = run_command(command, check=False, timeout=float(duration_s) + 60)
        elapsed = time.monotonic() - start
        if completed.returncode != 0:
            details = tail_text(completed.stderr or completed.stdout)
            raise RuntimeError(f"fio file_io workload failed: {details}")
        payload = json.loads(completed.stdout)
        jobs = payload.get("jobs")
        if not isinstance(jobs, list) or not jobs or not isinstance(jobs[0], dict):
            details = tail_text(completed.stdout or json.dumps(payload))
            raise RuntimeError(f"fio file_io workload returned no job stats: {details}")
        job = jobs[0]
        read_stats = job.get("read")
        write_stats = job.get("write")
        if not isinstance(read_stats, dict) or not isinstance(write_stats, dict):
            details = tail_text(completed.stdout or json.dumps(payload))
            raise RuntimeError(f"fio file_io workload returned malformed read/write stats: {details}")
        ops_total = float(read_stats.get("total_ios", 0) or 0) + float(write_stats.get("total_ios", 0) or 0)
        if ops_total <= 0:
            details = tail_text(completed.stdout or json.dumps(payload))
            raise RuntimeError(f"fio file_io workload did not report total_ios metrics: {details}")
        return _finish_result(ops_total, elapsed, completed.stdout or "", completed.stderr or "")



def _disk_backed_tmp_root() -> Path:
    seen: set[Path] = set()
    candidates: list[Path] = []
    for name in ("BPFREJIT_RUNTIME_TMPDIR", "TMPDIR", "TMP", "TEMP"):
        value = os.environ.get(name, "").strip()
        if value:
            candidates.append(Path(value))
    candidates.extend((Path("/var/tmp"), Path("/tmp")))
    for candidate in candidates:
        resolved = candidate.expanduser()
        if resolved in seen:
            continue
        seen.add(resolved)
        try:
            resolved.mkdir(parents=True, exist_ok=True)
        except OSError:
            continue
        if os.access(resolved, os.W_OK | os.X_OK):
            return resolved
    raise RuntimeError("no writable disk-backed temporary directory is available")


def _shared_unprivileged_tmp_root() -> Path:
    for candidate in (Path("/dev/shm"), Path("/tmp"), Path("/var/tmp")):
        try:
            candidate.mkdir(parents=True, exist_ok=True)
        except OSError:
            continue
        if not os.access(candidate, os.W_OK | os.X_OK):
            continue
        runtime_root = candidate / "bpf-benchmark"
        try:
            runtime_root.mkdir(parents=True, exist_ok=True)
            runtime_root.chmod(0o1777)
        except OSError:
            continue
        if os.access(runtime_root, os.W_OK | os.X_OK):
            return runtime_root
    raise RuntimeError("no writable shared temporary directory is available for exec_storm")


def _load_kernel_module(module_name: str, *module_args: str) -> None:
    load_kernel_module(module_name, *module_args, timeout=10)


def _wait_for_block_device(path: Path, *, timeout_s: float = 2.0) -> Path:
    deadline = time.monotonic() + timeout_s
    while time.monotonic() < deadline:
        try:
            mode = path.stat().st_mode
        except FileNotFoundError:
            time.sleep(0.1)
            continue
        if stat.S_ISBLK(mode):
            return path
        time.sleep(0.1)
    raise RuntimeError(f"block device did not appear: {path}")


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
    with tempfile.TemporaryDirectory(
        prefix="loopback-open-storm-",
        dir=str(_disk_backed_tmp_root()),
    ) as tempdir:
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
                listener.listen(LOOPBACK_LISTEN_BACKLOG)
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
    transient_failures: list[str] = []
    try:
        while _work_remaining(start, duration_limit, ops_total, iteration_limit):
            try:
                with socket.create_connection(("127.0.0.1", port), timeout=LOOPBACK_CONNECT_TIMEOUT_S):
                    pass
                ops_total += 1
            except (TimeoutError, OSError) as exc:
                transient_failures.append(str(exc))
                time.sleep(0.001)
    finally:
        stop.set()
        thread.join(timeout=1.0)

    if errors:
        raise RuntimeError(f"loopback listener failed: {errors[-1]}")
    if transient_failures:
        raise RuntimeError(
            f"loopback connects failed {len(transient_failures)} time(s): {transient_failures[-1]}"
        )
    if ops_total <= 0:
        raise RuntimeError("loopback connect workload completed without any successful operations")
    elapsed = time.monotonic() - start
    return _finish_result(float(ops_total), elapsed, "", "")


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
        family = socket.AF_INET if (ops_total % 2) == 0 else socket.AF_INET6
        with socket.socket(family, socket.SOCK_STREAM) as client:
            client.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
            if family == socket.AF_INET6:
                client.bind(("::1", 0, 0, 0))
            else:
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
    # stress-ng --open is prone to destabilizing virtme guest sessions under
    # heavy tracing. A simple bounded open loop still fires the same VFS open
    # probes without depending on stress-ng's worker model.
    return run_rapid_open_storm(duration_s, file_count=256)


def run_block_io_load(duration_s: int | float) -> WorkloadResult:
    dd_binary = which("dd")
    if dd_binary is None:
        raise RuntimeError("dd is required for the block_io workload")
    block_size = "4k"
    block_count = 4096
    _load_kernel_module("null_blk", "nr_devices=1", "queue_mode=2")
    device_path = _wait_for_block_device(Path("/dev/nullb0"))

    start = time.monotonic()
    deadline = start + float(duration_s)
    stderr_lines: list[str] = []
    ops_total = 0.0
    while time.monotonic() < deadline:
        write_completed = run_command(
            [
                dd_binary,
                "if=/dev/zero",
                f"of={device_path}",
                f"bs={block_size}",
                f"count={block_count}",
                "oflag=direct",
                "conv=fsync",
                "status=none",
            ],
            check=False,
            timeout=30,
        )
        if write_completed.returncode != 0:
            details = tail_text(write_completed.stderr or write_completed.stdout)
            raise RuntimeError(f"block_io write failed: {details}")
        read_completed = run_command(
            [
                dd_binary,
                f"if={device_path}",
                "of=/dev/null",
                f"bs={block_size}",
                f"count={block_count}",
                "iflag=fullblock,direct",
                "status=none",
            ],
            check=False,
            timeout=30,
        )
        if read_completed.returncode != 0:
            details = tail_text(read_completed.stderr or read_completed.stdout)
            raise RuntimeError(f"block_io read failed: {details}")
        stderr_lines.append(write_completed.stderr or "")
        stderr_lines.append(read_completed.stderr or "")
        ops_total += float(block_count * 2)
    elapsed = time.monotonic() - start
    return _finish_result(ops_total, elapsed, "", "\n".join(stderr_lines))


def run_tracee_default_load(duration_s: int | float) -> WorkloadResult:
    total_duration = max(0.3, float(duration_s))
    exec_seconds = max(0.1, total_duration * 0.4)
    open_seconds = max(0.1, total_duration * 0.3)
    connect_seconds = max(0.1, total_duration - exec_seconds - open_seconds)
    return _merge_workload_results(
        [
            run_user_exec_loop(exec_seconds),
            run_open_storm(open_seconds),
            run_connect_storm(connect_seconds),
        ]
    )


def _run_tc_qdisc(command: Sequence[str], *, action: str) -> subprocess.CompletedProcess[str]:
    completed = run_command(list(command), check=False, timeout=10)
    if completed.returncode != 0:
        details = tail_text(completed.stderr or completed.stdout)
        raise RuntimeError(f"tc {action} failed: {details}")
    return completed


def run_tcp_retransmit_load(duration_s: int | float) -> WorkloadResult:
    tc_binary = which("tc")
    if tc_binary is None:
        raise RuntimeError("tc is required for the tcp_retransmit workload")
    _load_kernel_module("sch_netem")
    # Short corpus smoke runs need a denser retransmit pattern than the default
    # loopback path naturally produces, otherwise the tracing program can stay
    # attached but never accumulate a measurable baseline delta.
    effective_duration = max(8.0, float(duration_s))
    transfer_target_bytes = 16 * 1024

    ready = threading.Event()
    stop = threading.Event()
    errors: list[str] = []
    port_holder: list[int] = []

    def server() -> None:
        payload = b"x" * 65536
        try:
            with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as listener:
                listener.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
                listener.bind(("127.0.0.1", 0))
                listener.listen(LOOPBACK_LISTEN_BACKLOG)
                listener.settimeout(0.25)
                port_holder.append(int(listener.getsockname()[1]))
                ready.set()
                while not stop.is_set():
                    try:
                        conn, _ = listener.accept()
                    except (socket.timeout, TimeoutError):
                        continue
                    with conn:
                        conn.settimeout(1.0)
                        try:
                            for _ in range(128):
                                if stop.is_set():
                                    break
                                conn.sendall(payload)
                        except (BrokenPipeError, ConnectionResetError, ConnectionAbortedError, socket.timeout, OSError):
                            continue
        except Exception as exc:
            errors.append(str(exc))
            ready.set()

    thread = threading.Thread(target=server, daemon=True)
    thread.start()
    if not ready.wait(timeout=2.0):
        stop.set()
        thread.join(timeout=1.0)
        raise RuntimeError("tcp retransmit server did not become ready")
    if errors:
        stop.set()
        thread.join(timeout=1.0)
        raise RuntimeError(f"tcp retransmit server failed: {errors[-1]}")
    if not port_holder:
        stop.set()
        thread.join(timeout=1.0)
        raise RuntimeError("tcp retransmit server failed to publish a port")

    _run_tc_qdisc(
        [
            tc_binary,
            "qdisc",
            "replace",
            "dev",
            "lo",
            "root",
            "netem",
            "delay",
            "80ms",
            "loss",
            "12%",
        ],
        action="qdisc replace dev lo root netem",
    )

    port = port_holder[0]
    start = time.monotonic()
    deadline = start + effective_duration
    attempts = 0
    successes = 0
    failures = 0
    try:
        while time.monotonic() < deadline:
            attempts += 1
            received = 0
            try:
                with socket.create_connection(("127.0.0.1", port), timeout=1.0) as client:
                    client.settimeout(1.0)
                    while received < transfer_target_bytes and time.monotonic() < deadline:
                        try:
                            chunk = client.recv(65536)
                        except socket.timeout:
                            if received > 0:
                                break
                            raise
                        if not chunk:
                            break
                        received += len(chunk)
                if received > 0:
                    successes += 1
                else:
                    failures += 1
            except (TimeoutError, OSError):
                failures += 1
    finally:
        cleanup_error: RuntimeError | None = None
        try:
            _run_tc_qdisc([tc_binary, "qdisc", "del", "dev", "lo", "root"], action="qdisc del dev lo root")
        except RuntimeError as exc:
            cleanup_error = exc
        stop.set()
        thread.join(timeout=1.0)
        if cleanup_error is not None:
            raise cleanup_error

    if errors:
        raise RuntimeError(f"tcp retransmit server failed: {errors[-1]}")
    if successes <= 0:
        raise RuntimeError(f"tcp retransmit workload produced no successful transfers; attempts={attempts}, failures={failures}")
    elapsed = time.monotonic() - start
    return _finish_result(
        float(attempts),
        elapsed,
        f"successful_transfers={successes}",
        f"failed_transfers={failures}",
    )


def run_vfs_create_write_fsync_load(duration_s: int | float) -> WorkloadResult:
    with tempfile.TemporaryDirectory(prefix="tracee-vfs-", dir=str(_disk_backed_tmp_root())) as tempdir:
        root = Path(tempdir)
        payload = b"x" * (64 * 1024)
        start = time.monotonic()
        deadline = start + float(duration_s)
        ops_total = 0.0
        while time.monotonic() < deadline:
            path = root / f"vfs-op-{int(ops_total)}.dat"
            with path.open("wb") as handle:
                handle.write(payload)
                handle.flush()
                os.fsync(handle.fileno())
            with path.open("rb") as handle:
                while handle.read(len(payload)):
                    pass
            path.unlink()
            ops_total += 1.0
        elapsed = time.monotonic() - start
        return _finish_result(ops_total, elapsed, "", "")


def run_network_load(duration_s: int | float) -> WorkloadResult:
    wrk_binary = resolve_workload_tool("wrk")
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
        total_requests = None
        for line in completed.stdout.splitlines():
            line = line.strip()
            total_match = re.search(r"([0-9]+)\s+requests in", line)
            if total_match:
                total_requests = float(total_match.group(1))
        if total_requests is None:
            details = tail_text(completed.stdout or completed.stderr)
            raise RuntimeError(f"network wrk load did not report total request metrics: {details}")
        return _finish_result(total_requests, elapsed, completed.stdout or "", completed.stderr or "")


def run_tcp_connect_load(duration_s: int | float) -> WorkloadResult:
    curl_binary = which("curl")
    if curl_binary is None:
        raise RuntimeError("curl is required for TCP connect load")
    with LocalHttpServer("127.0.0.1") as server_v4, LocalHttpServer("::1") as server_v6:
        urls = (server_v4.url, server_v6.url)
        start = time.monotonic()
        deadline = start + float(duration_s)
        ops_total = 0.0
        stderr_lines: list[str] = []
        while time.monotonic() < deadline:
            url = urls[int(ops_total) % len(urls)]
            completed = run_command(
                [curl_binary, "-fsS", "-g", "-o", "/dev/null", "--http1.1", "--max-time", "2", url],
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
    hackbench = resolve_workload_tool("hackbench")
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


def run_mixed_workload(duration_s: float) -> WorkloadResult:
    segments = (
        (run_user_exec_loop, 0.25),
        (run_file_open_load, 0.20),
        (run_block_io_load, 0.20),
        (run_tcp_connect_load, 0.20),
        (run_bind_storm, 0.10),
        (run_scheduler_load, 0.05),
    )
    remaining = max(1.0, float(duration_s))
    results: list[WorkloadResult] = []
    for index, (runner, share) in enumerate(segments, start=1):
        if index == len(segments):
            slice_seconds = max(1.0, remaining)
        else:
            slice_seconds = max(1.0, round(float(duration_s) * share))
            remaining -= slice_seconds
        results.append(runner(slice_seconds))
    return _merge_workload_results(results)


def run_named_workload(
    workload_kind: str,
    duration_s: int | float,
    *,
    network_as_tcp_connect: bool = False,
) -> WorkloadResult:
    seconds = max(1, int(round(float(duration_s))))
    kind = str(workload_kind or "").strip()
    if kind == "mixed":
        return run_mixed_workload(float(duration_s))
    if kind == "tcp_connect":
        return run_tcp_connect_load(seconds)
    if kind == "scheduler":
        return run_scheduler_load(seconds)
    if kind == "exec_storm":
        return run_exec_storm(seconds, rate=2)
    if kind in {"exec_loop", "minimal_syscall"}:
        return run_user_exec_loop(seconds)
    if kind in {"file_open", "file_open_storm"}:
        return run_file_open_load(seconds)
    if kind in {"network", "tracee_default"}:
        if kind == "tracee_default":
            return run_tracee_default_load(float(duration_s))
        if network_as_tcp_connect:
            return run_tcp_connect_load(seconds)
        return run_network_load(seconds)
    if kind == "block_io":
        return run_block_io_load(float(duration_s))
    if kind == "tcp_retransmit":
        return run_tcp_retransmit_load(float(duration_s))
    if kind == "fio":
        return run_file_io(seconds)
    if kind == "hackbench":
        return run_scheduler_load(seconds)
    if kind == "bind_storm":
        return run_bind_storm(seconds)
    if kind == "vfs_create_write_fsync":
        return run_vfs_create_write_fsync_load(seconds)
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
        return run_mixed_workload(float(seconds))
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
        return run_mixed_workload(float(seconds))
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
        ops_total = parse_stress_ng_bogo_ops(combined, stressor="vm")
        if ops_total is None:
            details = tail_text(combined)
            raise RuntimeError(f"oom_stress workload did not report bogo-ops metrics: {details}")
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
    "parse_stress_ng_bogo_ops",
    "run_block_io_load",
    "run_connect_storm",
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
    "run_tcp_retransmit_load",
    "run_tcp_connect_load",
    "run_tracee_default_load",
    "run_vfs_create_write_fsync_load",
    "run_user_exec_loop",
    "run_mixed_workload",
]
