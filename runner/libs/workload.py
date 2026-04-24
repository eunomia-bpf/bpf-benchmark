from __future__ import annotations

import ctypes
import ctypes.util
import errno
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
from typing import Callable, Sequence

from . import run_command, tail_text, which
from .kernel_modules import kernel_module_is_builtin, load_kernel_module, repo_kernel_modules_root

LOOPBACK_LISTEN_BACKLOG = 128
LOOPBACK_CONNECT_TIMEOUT_S = 2.0
AT_FDCWD = -100
AT_EMPTY_PATH = 0x1000
_OPENAT2_SYSCALL_NR = {
    "x86_64": 437,
    "aarch64": 437,
    "arm64": 437,
}
_TRACEE_MODULE_LOAD_CANDIDATES = (
    "vcan",
    "dummy",
    "binfmt_misc",
    "configfs",
)
_CGROUP_ROOT = Path("/sys/fs/cgroup")


class _OpenHow(ctypes.Structure):
    _fields_ = [
        ("flags", ctypes.c_uint64),
        ("mode", ctypes.c_uint64),
        ("resolve", ctypes.c_uint64),
    ]


_LIBC = ctypes.CDLL(ctypes.util.find_library("c") or None, use_errno=True)
_LIBC.open.argtypes = [ctypes.c_char_p, ctypes.c_int, ctypes.c_int]
_LIBC.open.restype = ctypes.c_int
_LIBC.openat.argtypes = [ctypes.c_int, ctypes.c_char_p, ctypes.c_int, ctypes.c_int]
_LIBC.openat.restype = ctypes.c_int
_LIBC.execveat.argtypes = [
    ctypes.c_int,
    ctypes.c_char_p,
    ctypes.POINTER(ctypes.c_char_p),
    ctypes.POINTER(ctypes.c_char_p),
    ctypes.c_int,
]
_LIBC.execveat.restype = ctypes.c_int
_LIBC.accept4.argtypes = [ctypes.c_int, ctypes.c_void_p, ctypes.c_void_p, ctypes.c_int]
_LIBC.accept4.restype = ctypes.c_int
_LIBC.syscall.restype = ctypes.c_long


def _raise_ctypes_oserror(prefix: str) -> None:
    err = ctypes.get_errno()
    if err <= 0:
        err = errno.EIO
    raise OSError(err, f"{prefix}: {os.strerror(err)}")


def _notes_text(notes: Sequence[str]) -> str:
    return "\n".join(str(note) for note in notes if str(note).strip())


def _close_quietly(fd: int | None) -> None:
    if fd is None or int(fd) < 0:
        return
    try:
        os.close(int(fd))
    except OSError:
        return


def _libc_open(path: Path | str, flags: int, mode: int = 0) -> int:
    fd = _LIBC.open(os.fsencode(os.fspath(path)), int(flags), int(mode))
    if fd < 0:
        _raise_ctypes_oserror(f"open({path})")
    return int(fd)


def _libc_openat(dirfd: int, path: str, flags: int, mode: int = 0) -> int:
    fd = _LIBC.openat(int(dirfd), os.fsencode(path), int(flags), int(mode))
    if fd < 0:
        _raise_ctypes_oserror(f"openat({path})")
    return int(fd)


def _libc_openat2(dirfd: int, path: str, flags: int, mode: int = 0, resolve: int = 0) -> int:
    syscall_nr = _OPENAT2_SYSCALL_NR.get(os.uname().machine.lower())
    if syscall_nr is None:
        raise RuntimeError(f"openat2 is unsupported on architecture {os.uname().machine!r}")
    how = _OpenHow(flags=int(flags), mode=int(mode), resolve=int(resolve))
    fd = _LIBC.syscall(
        int(syscall_nr),
        int(dirfd),
        os.fsencode(path),
        ctypes.byref(how),
        ctypes.sizeof(how),
    )
    if fd < 0:
        _raise_ctypes_oserror(f"openat2({path})")
    return int(fd)


def _build_exec_argv(program: str) -> ctypes.Array[ctypes.c_char_p]:
    argv = (ctypes.c_char_p * 2)()
    argv[0] = os.fsencode(program)
    argv[1] = None
    return argv


def _build_envp() -> ctypes.Array[ctypes.c_char_p]:
    if hasattr(os, "environb"):
        entries = [key + b"=" + value for key, value in os.environb.items()]
    else:
        entries = [f"{key}={value}".encode() for key, value in os.environ.items()]
    envp = (ctypes.c_char_p * (len(entries) + 1))()
    for index, entry in enumerate(entries):
        envp[index] = entry
    envp[len(entries)] = None
    return envp


def _wait_successful_child(pid: int, description: str) -> None:
    _, status = os.waitpid(int(pid), 0)
    exit_code = os.waitstatus_to_exitcode(status)
    if exit_code != 0:
        raise RuntimeError(f"{description} failed with exit code {exit_code}")


def _run_execveat_once(path: str) -> None:
    pid = os.fork()
    if pid == 0:
        argv = _build_exec_argv(path)
        envp = _build_envp()
        _LIBC.execveat(AT_FDCWD, os.fsencode(path), argv, envp, 0)
        err = ctypes.get_errno()
        os._exit(err if 0 < err < 256 else 127)
    _wait_successful_child(pid, f"execveat({path})")


def _run_failed_execveat_once(path: str) -> None:
    pid = os.fork()
    if pid == 0:
        argv = _build_exec_argv(path)
        envp = _build_envp()
        _LIBC.execveat(AT_FDCWD, os.fsencode(path), argv, envp, 0)
        err = ctypes.get_errno()
        os._exit(0 if err == errno.ENOENT else (err if 0 < err < 256 else 127))
    _wait_successful_child(pid, f"failed execveat({path})")


def _accept4_roundtrip() -> None:
    listener = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    listener.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    listener.bind(("127.0.0.1", 0))
    listener.listen(1)
    port = int(listener.getsockname()[1])
    accepted_fd = -1
    thread_error: list[str] = []
    deadline = time.monotonic() + LOOPBACK_CONNECT_TIMEOUT_S

    def client() -> None:
        try:
            with socket.create_connection(("127.0.0.1", port), timeout=LOOPBACK_CONNECT_TIMEOUT_S):
                pass
        except OSError as exc:
            thread_error.append(str(exc))

    thread = threading.Thread(target=client, daemon=True)
    thread.start()
    try:
        # listener.settimeout() flips the fd to nonblocking, so explicit retry
        # here keeps the accept4 syscall while avoiding transient EAGAIN races.
        listener.setblocking(False)
        while True:
            accepted_fd = _LIBC.accept4(listener.fileno(), None, None, int(getattr(socket, "SOCK_CLOEXEC", 0)))
            if accepted_fd >= 0:
                break
            err = ctypes.get_errno()
            if err == errno.EINTR:
                continue
            if err in (errno.EAGAIN, errno.EWOULDBLOCK):
                if thread_error:
                    raise RuntimeError(f"accept4 client failed: {thread_error[-1]}")
                if time.monotonic() >= deadline:
                    raise RuntimeError("accept4 timed out waiting for loopback client")
                time.sleep(0.01)
                continue
            raise OSError(err, f"accept4: {os.strerror(err)}")
    finally:
        _close_quietly(accepted_fd)
        listener.close()
        thread.join(timeout=2.0)
    if thread_error:
        raise RuntimeError(f"accept4 client failed: {thread_error[-1]}")


def _exercise_dup_family(path: Path) -> None:
    source_fd = os.open(path, os.O_RDWR | os.O_CREAT | os.O_TRUNC, 0o600)
    duplicated_fd = -1
    try:
        os.write(source_fd, b"dup-test")
        duplicated_fd = os.dup2(source_fd, source_fd + 64)
    finally:
        _close_quietly(duplicated_fd)
        _close_quietly(source_fd)


def _exercise_socketpair_once() -> None:
    left, right = socket.socketpair()
    try:
        left.sendall(b"edge")
        right.recv(4)
    finally:
        left.close()
        right.close()


def _exercise_cgroup_mkdir_rmdir_once() -> str | None:
    if not _CGROUP_ROOT.is_dir():
        return f"cgroup root is unavailable: {_CGROUP_ROOT}"
    path = _CGROUP_ROOT / f"bpf-benchmark-tracee-edge-{os.getpid()}-{time.monotonic_ns()}"
    try:
        path.mkdir()
        path.rmdir()
    except OSError as exc:
        return f"cgroup mkdir/rmdir failed: {exc}"
    return None


def _ensure_tracee_module_load_prereqs() -> tuple[str, Path]:
    modprobe_binary = which("modprobe")
    if modprobe_binary is None:
        raise RuntimeError("modprobe is required for tracee_module_load_loop")
    repo_root = repo_kernel_modules_root()
    release_dir = repo_root / "lib" / "modules" / os.uname().release
    if not release_dir.is_dir():
        raise RuntimeError(
            "tracee_module_load_loop requires repo kernel modules for this release: "
            f"{release_dir}"
        )
    return modprobe_binary, repo_root


def _module_candidate_exists(module_name: str) -> bool:
    release_dir = repo_kernel_modules_root() / "lib" / "modules" / os.uname().release
    return any(release_dir.rglob(f"{module_name}.ko"))


def _module_is_loaded(module_name: str) -> bool:
    return Path("/sys/module").joinpath(str(module_name)).is_dir()


def _wait_for_module_state(module_name: str, *, present: bool, timeout_s: float = 5.0) -> None:
    deadline = time.monotonic() + max(0.1, float(timeout_s))
    while time.monotonic() < deadline:
        if _module_is_loaded(module_name) == bool(present):
            return
        time.sleep(0.05)
    state = "present" if present else "absent"
    raise RuntimeError(f"module {module_name} did not become {state}")


def _run_module_load_cycle() -> str:
    modprobe_binary, repo_root = _ensure_tracee_module_load_prereqs()
    errors: list[str] = []
    for module_name in _TRACEE_MODULE_LOAD_CANDIDATES:
        try:
            if kernel_module_is_builtin(module_name):
                continue
        except RuntimeError as exc:
            errors.append(str(exc))
            break
        if not _module_candidate_exists(module_name):
            continue
        if _module_is_loaded(module_name):
            continue
        load_kernel_module(module_name, timeout=20)
        try:
            _wait_for_module_state(module_name, present=True, timeout_s=5.0)
            unload = run_command(
                [modprobe_binary, "-d", str(repo_root), "-r", module_name],
                check=False,
                timeout=20,
            )
            if unload.returncode != 0:
                raise RuntimeError(tail_text(unload.stderr or unload.stdout))
            _wait_for_module_state(module_name, present=False, timeout_s=5.0)
            return module_name
        except Exception as exc:
            errors.append(f"{module_name}: {exc}")
            if _module_is_loaded(module_name):
                run_command([modprobe_binary, "-d", str(repo_root), "-r", module_name], check=False, timeout=20)
    if errors:
        raise RuntimeError("no module load cycle succeeded: " + "; ".join(errors))
    raise RuntimeError("no eligible module candidates were found for tracee_module_load_loop")


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
        command = [setpriv, "--reuid", str(uid), "--regid", str(gid), "--clear-groups", command_path]
    return run_rapid_exec_storm(duration_s, iterations=iterations, command=command, command_path=command_path)


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
    with tempfile.TemporaryDirectory(prefix="tracee-fio-", dir=str(_disk_backed_tmp_root())) as tempdir:
        data_path = Path(tempdir) / "fio.bin"
        cmd = [fio_binary, "--name=tracee-e2e", f"--filename={data_path}", "--rw=randwrite", "--bs=4k", "--size=64M",
               f"--runtime={max(1, int(duration_s))}", "--time_based=1", "--ioengine=sync",
               "--create_on_open=1", "--fsync=1", "--end_fsync=1", "--invalidate=1", "--output-format=json"]
        start = time.monotonic()
        c = run_command(cmd, check=False, timeout=float(duration_s) + 60)
        elapsed = time.monotonic() - start
        if c.returncode != 0:
            raise RuntimeError(f"fio file_io workload failed: {tail_text(c.stderr or c.stdout)}")
        payload = json.loads(c.stdout)
        jobs = payload.get("jobs")
        if not isinstance(jobs, list) or not jobs or not isinstance(jobs[0], dict):
            raise RuntimeError(f"fio file_io workload returned no job stats: {tail_text(c.stdout or json.dumps(payload))}")
        job = jobs[0]
        read_stats, write_stats = job.get("read"), job.get("write")
        if not isinstance(read_stats, dict) or not isinstance(write_stats, dict):
            raise RuntimeError(f"fio file_io workload returned malformed read/write stats: {tail_text(c.stdout or json.dumps(payload))}")
        ops_total = float(read_stats.get("total_ios", 0) or 0) + float(write_stats.get("total_ios", 0) or 0)
        if ops_total <= 0:
            raise RuntimeError(f"fio file_io workload did not report total_ios metrics: {tail_text(c.stdout or json.dumps(payload))}")
        return _finish_result(ops_total, elapsed, c.stdout or "", c.stderr or "")


def _disk_backed_tmp_root() -> Path:
    seen: set[Path] = set()
    candidates = [Path(os.environ.get(n, "").strip()) for n in ("BPFREJIT_RUNTIME_TMPDIR", "TMPDIR", "TMP", "TEMP") if os.environ.get(n, "").strip()]
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


def _ensure_null_blk_device_node(path: Path) -> Path:
    sysfs_dev = Path("/sys/block/nullb0/dev")
    deadline = time.monotonic() + 2.0
    while time.monotonic() < deadline:
        if sysfs_dev.is_file():
            break
        time.sleep(0.1)
    if not sysfs_dev.is_file():
        return _wait_for_block_device(path)
    try:
        mode = path.stat().st_mode
        if stat.S_ISBLK(mode):
            return path
        path.unlink()
    except FileNotFoundError:
        pass
    major_text, minor_text = sysfs_dev.read_text(encoding="utf-8").strip().split(":", 1)
    os.mknod(path, stat.S_IFBLK | 0o660, os.makedev(int(major_text), int(minor_text)))
    return _wait_for_block_device(path)


def _normalize_workload_limits(duration_s: int | float | None, iterations: int | None) -> tuple[float | None, int | None]:
    duration_limit = None if duration_s is None else max(0.0, float(duration_s))
    iteration_limit = None if iterations is None else max(1, int(iterations))
    if duration_limit is None and iteration_limit is None:
        raise ValueError("either duration_s or iterations is required")
    return duration_limit, iteration_limit


def _work_remaining(started_at: float, duration_limit: float | None, completed: int, iteration_limit: int | None) -> bool:
    if iteration_limit is not None and completed >= iteration_limit: return False
    if duration_limit is not None and (time.monotonic() - started_at) >= duration_limit: return False
    return True


def run_rapid_open_storm(duration_s: int | float | None = None, *, iterations: int | None = None, file_count: int = 128) -> WorkloadResult:
    duration_limit, iteration_limit = _normalize_workload_limits(duration_s, iterations)
    with tempfile.TemporaryDirectory(prefix="loopback-open-storm-", dir=str(_disk_backed_tmp_root())) as tempdir:
        directory = Path(tempdir)
        files = [directory / f"open-{i}.dat" for i in range(max(1, int(file_count)))]
        for path in files: path.write_bytes(b"x")
        start = time.monotonic()
        ops_total = 0
        while _work_remaining(start, duration_limit, ops_total, iteration_limit):
            with files[ops_total % len(files)].open("rb"): pass
            ops_total += 1
        elapsed = time.monotonic() - start
    return _finish_result(float(ops_total), elapsed, "", "")


run_open_storm = run_rapid_open_storm


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
    def _abort(msg: str) -> None:
        stop.set(); thread.join(timeout=1.0); raise RuntimeError(msg)
    if not ready.wait(timeout=2.0): _abort("loopback listener did not become ready")
    if errors: _abort(f"loopback listener failed: {errors[-1]}")
    if not port_holder: _abort("loopback listener failed to publish a port")
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
    if transient_failures and ops_total <= 0:
        raise RuntimeError(
            f"loopback connects failed {len(transient_failures)} time(s): {transient_failures[-1]}"
        )
    if ops_total <= 0:
        raise RuntimeError("loopback connect workload completed without any successful operations")
    elapsed = time.monotonic() - start
    stderr = ""
    if transient_failures:
        stderr = f"loopback_connect_transient_failures={len(transient_failures)} last={transient_failures[-1]}"
    return _finish_result(float(ops_total), elapsed, "", stderr)


run_connect_storm = run_rapid_connect_storm


def run_rapid_bind_storm(duration_s: int | float | None = None, *, iterations: int | None = None) -> WorkloadResult:
    duration_limit, iteration_limit = _normalize_workload_limits(duration_s, iterations)
    start = time.monotonic(); ops_total = 0
    while _work_remaining(start, duration_limit, ops_total, iteration_limit):
        family = socket.AF_INET if (ops_total % 2) == 0 else socket.AF_INET6
        with socket.socket(family, socket.SOCK_STREAM) as client:
            client.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
            client.bind(("::1", 0, 0, 0) if family == socket.AF_INET6 else ("127.0.0.1", 0))
        ops_total += 1
    return _finish_result(float(ops_total), time.monotonic() - start, "", "")


run_bind_storm = run_rapid_bind_storm


def run_file_open_load(duration_s: int | float) -> WorkloadResult:
    return run_rapid_open_storm(duration_s, file_count=256)


def run_block_io_load(duration_s: int | float) -> WorkloadResult:
    dd_binary = which("dd")
    if dd_binary is None:
        raise RuntimeError("dd is required for the block_io workload")
    block_size, block_count = "4k", 4096
    _load_kernel_module("null_blk", "nr_devices=1", "queue_mode=2")
    device_path = _ensure_null_blk_device_node(Path("/dev/nullb0"))
    start = time.monotonic()
    deadline = start + float(duration_s)
    stderr_lines: list[str] = []
    ops_total = 0.0
    while time.monotonic() < deadline:
        wc = run_command([dd_binary, "if=/dev/zero", f"of={device_path}", f"bs={block_size}", f"count={block_count}", "oflag=direct", "conv=fsync", "status=none"], check=False, timeout=30)
        if wc.returncode != 0:
            raise RuntimeError(f"block_io write failed: {tail_text(wc.stderr or wc.stdout)}")
        rc = run_command([dd_binary, f"if={device_path}", "of=/dev/null", f"bs={block_size}", f"count={block_count}", "iflag=fullblock,direct", "status=none"], check=False, timeout=30)
        if rc.returncode != 0:
            raise RuntimeError(f"block_io read failed: {tail_text(rc.stderr or rc.stdout)}")
        stderr_lines += [wc.stderr or "", rc.stderr or ""]
        ops_total += float(block_count * 2)
    elapsed = time.monotonic() - start
    return _finish_result(ops_total, elapsed, "", "\n".join(stderr_lines))


def run_tracee_default_load(duration_s: int | float) -> WorkloadResult:
    t = max(0.3, float(duration_s))
    exec_s = max(0.1, t * 0.4)
    open_s = max(0.1, t * 0.3)
    return _merge_workload_results([run_user_exec_loop(exec_s), run_open_storm(open_s),
                                    run_connect_storm(max(0.1, t - exec_s - open_s))])


def run_tetragon_exec_connect_mix_workload(
    duration_s: int | float,
    *,
    exec_runner: Callable[[int | float], WorkloadResult] | None = None,
) -> WorkloadResult:
    total = max(0.3, float(duration_s))
    exec_s = max(0.1, total * 0.6)
    connect_s = max(0.1, total - exec_s)
    chosen_exec_runner = run_exec_storm if exec_runner is None else exec_runner
    return _merge_workload_results(
        [
            chosen_exec_runner(exec_s),
            run_connect_storm(connect_s),
        ]
    )


def run_tracee_system_edge_mix_workload(duration_s: int | float) -> WorkloadResult:
    with tempfile.TemporaryDirectory(prefix="tracee-edge-", dir=str(_disk_backed_tmp_root())) as tempdir:
        root = Path(tempdir)
        dup_path = root / "dup-edge.bin"
        notes: list[str] = []
        start = time.monotonic()
        deadline = start + max(0.2, float(duration_s))
        ops_total = 0.0
        cgroup_exercised = False
        missing_path = str(root / "definitely-missing-execveat")
        while time.monotonic() < deadline:
            _run_execveat_once("/bin/true")
            _run_failed_execveat_once(missing_path)
            _exercise_dup_family(dup_path)
            _exercise_socketpair_once()
            _accept4_roundtrip()
            if not cgroup_exercised:
                cgroup_result = _exercise_cgroup_mkdir_rmdir_once()
                if cgroup_result:
                    raise RuntimeError(cgroup_result)
                cgroup_exercised = True
            ops_total += 1.0
        return _finish_result(ops_total, time.monotonic() - start, "", _notes_text(notes))


def run_tracee_module_load_loop_workload(duration_s: int | float) -> WorkloadResult:
    _ensure_tracee_module_load_prereqs()
    start = time.monotonic()
    deadline = start + max(0.2, float(duration_s))
    ops_total = 0.0
    notes: list[str] = []
    selected_module = ""
    while time.monotonic() < deadline:
        module_name = _run_module_load_cycle()
        if module_name and not selected_module:
            selected_module = module_name
            notes.append(f"module_load_candidate={module_name}")
        ops_total += 1.0
    return _finish_result(ops_total, time.monotonic() - start, "", _notes_text(notes))


def run_tracee_io_vector_mix_workload(duration_s: int | float) -> WorkloadResult:
    with tempfile.TemporaryDirectory(prefix="tracee-iov-", dir=str(_disk_backed_tmp_root())) as tempdir:
        path = Path(tempdir) / "iov.dat"
        fd = os.open(path, os.O_CREAT | os.O_RDWR | os.O_TRUNC, 0o600)
        start = time.monotonic()
        deadline = start + max(0.2, float(duration_s))
        ops_total = 0.0
        try:
            while time.monotonic() < deadline:
                os.ftruncate(fd, 0)
                os.lseek(fd, 0, os.SEEK_SET)
                os.write(fd, b"tracee-write")
                os.writev(fd, [b"-", b"writev"])
                os.pwritev(fd, [b"pread", b"v2"], 0)
                os.lseek(fd, 0, os.SEEK_SET)
                os.read(fd, 6)
                os.readv(fd, [bytearray(8), bytearray(8)])
                os.preadv(fd, [bytearray(4), bytearray(4)], 0)
                ops_total += 1.0
        finally:
            os.close(fd)
        return _finish_result(ops_total, time.monotonic() - start, "", "")


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
    try:
        _load_kernel_module("sch_netem")
    except RuntimeError as exc:
        raise RuntimeError(f"sch_netem is required for the tcp_retransmit workload: {exc}") from exc
    effective_duration = max(8.0, float(duration_s))
    cycle_duration = 2.0

    def clear_qdisc() -> str:
        completed = run_command([tc_binary, "qdisc", "del", "dev", "lo", "root"], check=False, timeout=10)
        details = tail_text(completed.stderr or completed.stdout)
        if completed.returncode == 0:
            return ""
        if "No such file" in details or "Cannot delete qdisc" in details:
            return ""
        return details

    def forced_retransmit_cycle(seconds: float) -> tuple[bool, str]:
        ready = threading.Event()
        accepted = threading.Event()
        send_gate = threading.Event()
        errors: list[str] = []
        port_holder: list[int] = []

        def server() -> None:
            payload = b"x" * 65536
            try:
                with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as listener:
                    listener.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
                    listener.bind(("127.0.0.1", 0))
                    listener.listen(1)
                    listener.settimeout(1.0)
                    port_holder.append(int(listener.getsockname()[1]))
                    ready.set()
                    conn, _ = listener.accept()
                    with conn:
                        conn.settimeout(0.25)
                        accepted.set()
                        if not send_gate.wait(timeout=2.0):
                            return
                        deadline = time.monotonic() + max(0.5, float(seconds))
                        while time.monotonic() < deadline:
                            try:
                                conn.sendall(payload)
                            except (BrokenPipeError, ConnectionResetError, ConnectionAbortedError, socket.timeout, OSError):
                                break
            except Exception as exc:
                errors.append(str(exc))
                ready.set()
                accepted.set()

        thread = threading.Thread(target=server, daemon=True)
        thread.start()
        client: socket.socket | None = None
        received = 0
        try:
            if not ready.wait(timeout=2.0):
                return False, "tcp retransmit server did not become ready"
            if errors:
                return False, f"tcp retransmit server failed: {errors[-1]}"
            if not port_holder:
                return False, "tcp retransmit server failed to publish a port"
            client = socket.create_connection(("127.0.0.1", port_holder[0]), timeout=LOOPBACK_CONNECT_TIMEOUT_S)
            client.settimeout(0.1)
            if not accepted.wait(timeout=2.0):
                return False, "tcp retransmit server did not accept the client"
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
                    "100ms",
                    "loss",
                    "100%",
                    "limit",
                    "10000",
                ],
                action="qdisc replace dev lo root netem",
            )
            send_gate.set()
            drop_deadline = time.monotonic() + max(0.5, float(seconds))
            while time.monotonic() < drop_deadline:
                try:
                    chunk = client.recv(65536)
                except socket.timeout:
                    continue
                except OSError as exc:
                    errors.append(str(exc))
                    break
                if not chunk:
                    break
                received += len(chunk)
        finally:
            cleanup_error = clear_qdisc()
            if cleanup_error:
                errors.append(f"qdisc cleanup failed: {cleanup_error}")
            if client is not None:
                try:
                    client.settimeout(0.1)
                    recovery_deadline = time.monotonic() + 0.5
                    while time.monotonic() < recovery_deadline:
                        try:
                            chunk = client.recv(65536)
                        except socket.timeout:
                            continue
                        except OSError:
                            break
                        if not chunk:
                            break
                        received += len(chunk)
                finally:
                    client.close()
            send_gate.set()
            thread.join(timeout=1.0)
        return received > 0, errors[-1] if errors else ""

    clear_error = clear_qdisc()
    if clear_error:
        raise RuntimeError(f"netem qdisc cleanup before tcp retransmit workload failed: {clear_error}")

    start = time.monotonic()
    deadline = start + effective_duration
    attempts = 0
    successes = 0
    failures = 0
    cycle_errors: list[str] = []
    while time.monotonic() < deadline:
        attempts += 1
        remaining = max(0.5, deadline - time.monotonic())
        success, error = forced_retransmit_cycle(min(cycle_duration, remaining))
        if success:
            successes += 1
        else:
            failures += 1
        if error:
            cycle_errors.append(error)
    cleanup_error = clear_qdisc()
    if cleanup_error:
        raise RuntimeError(f"netem qdisc cleanup after tcp retransmit workload failed: {cleanup_error}")

    if attempts <= 0:
        raise RuntimeError("tcp retransmit workload did not run any retransmit cycles")
    elapsed = time.monotonic() - start
    stderr = f"failed_cycles={failures}"
    if cycle_errors:
        stderr += f"\nlast_cycle_error={cycle_errors[-1]}"
    return _finish_result(float(attempts), elapsed, f"successful_cycles={successes}", stderr)


def run_open_family_storm_workload(duration_s: int | float) -> WorkloadResult:
    with tempfile.TemporaryDirectory(prefix="open-family-", dir=str(_disk_backed_tmp_root())) as tempdir:
        root = Path(tempdir)
        target = root / "storm.dat"
        target.write_bytes(b"open-family\n")
        dirfd = os.open(root, os.O_RDONLY | getattr(os, "O_DIRECTORY", 0))
        start = time.monotonic()
        deadline = start + max(0.2, float(duration_s))
        ops_total = 0.0
        notes: list[str] = []
        try:
            while time.monotonic() < deadline:
                fd_open = _libc_open(target, os.O_RDONLY | os.O_CLOEXEC)
                fd_openat = _libc_openat(dirfd, target.name, os.O_RDONLY | os.O_CLOEXEC)
                fd_openat2 = -1
                try:
                    try:
                        fd_openat2 = _libc_openat2(dirfd, target.name, os.O_RDONLY | os.O_CLOEXEC)
                    except OSError as exc:
                        raise RuntimeError(f"open_family_storm requires openat2: {exc}") from exc
                    ops_total += 1.0
                finally:
                    _close_quietly(fd_open)
                    _close_quietly(fd_openat)
                    _close_quietly(fd_openat2)
        finally:
            os.close(dirfd)
        return _finish_result(ops_total, time.monotonic() - start, "", _notes_text(notes))


def run_vfs_create_write_fsync_load(duration_s: int | float) -> WorkloadResult:
    with tempfile.TemporaryDirectory(prefix="tracee-vfs-", dir=str(_disk_backed_tmp_root())) as tempdir:
        root = Path(tempdir); payload = b"x" * (64 * 1024)
        start = time.monotonic(); deadline = start + float(duration_s); ops_total = 0.0
        while time.monotonic() < deadline:
            path = root / f"vfs-op-{int(ops_total)}.dat"
            with path.open("wb") as h: h.write(payload); h.flush(); os.fsync(h.fileno())
            with path.open("rb") as h:
                while h.read(len(payload)): pass
            path.unlink(); ops_total += 1.0
        return _finish_result(ops_total, time.monotonic() - start, "", "")


def run_vfs_create_fsync_exact_workload(duration_s: int | float) -> WorkloadResult:
    with tempfile.TemporaryDirectory(prefix="tracee-vfs-exact-", dir=str(_disk_backed_tmp_root())) as tempdir:
        root = Path(tempdir)
        payload = b"x" * (64 * 1024)
        start = time.monotonic()
        deadline = start + max(0.2, float(duration_s))
        ops_total = 0.0
        while time.monotonic() < deadline:
            path = root / f"exact-{int(ops_total)}.dat"
            fd = os.open(path, os.O_CREAT | os.O_EXCL | os.O_RDWR, 0o600)
            try:
                os.write(fd, payload)
                os.fsync(fd)
                os.lseek(fd, 0, os.SEEK_SET)
                while os.read(fd, len(payload)):
                    pass
            finally:
                os.close(fd)
            path.unlink()
            ops_total += 1.0
        return _finish_result(ops_total, time.monotonic() - start, "", "")


def run_network_load(duration_s: int | float) -> WorkloadResult:
    wrk_binary = resolve_workload_tool("wrk")
    with LocalHttpServer() as server:
        start = time.monotonic()
        c = run_command([wrk_binary, "-t2", "-c10", f"-d{max(1, int(duration_s))}s", server.url], check=False, timeout=float(duration_s) + 30)
        elapsed = time.monotonic() - start
        if c.returncode != 0:
            raise RuntimeError(f"network wrk load failed: {tail_text(c.stderr or c.stdout)}")
        total_requests = next((float(m.group(1)) for line in c.stdout.splitlines() if (m := re.search(r"([0-9]+)\s+requests in", line.strip()))), None)
        if total_requests is None:
            raise RuntimeError(f"network wrk load did not report total request metrics: {tail_text(c.stdout or c.stderr)}")
        return _finish_result(total_requests, elapsed, c.stdout or "", c.stderr or "")


def run_tcp_connect_load(duration_s: int | float) -> WorkloadResult:
    curl_binary = which("curl")
    if curl_binary is None:
        raise RuntimeError("curl is required for TCP connect load")
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
    kind: str,
    duration_s: int | float,
    *,
    network_as_tcp_connect: bool = False,
) -> WorkloadResult:
    seconds = max(1, int(round(float(duration_s))))
    kind = str(kind or "").strip()
    if kind == "mixed":
        return run_mixed_workload(float(duration_s))
    if kind == "tcp_connect":
        return run_tcp_connect_load(seconds)
    if kind == "tetragon_exec_connect_mix":
        return run_tetragon_exec_connect_mix_workload(float(duration_s))
    if kind == "scheduler":
        return run_scheduler_load(seconds)
    if kind == "exec_storm":
        return run_exec_storm(seconds, rate=2)
    if kind == "exec_loop":
        return run_user_exec_loop(seconds)
    if kind in {"file_open", "file_open_storm"}:
        return run_file_open_load(seconds)
    if kind == "open_family_storm":
        return run_open_family_storm_workload(float(duration_s))
    if kind in {"network", "tracee_default"}:
        if kind == "tracee_default":
            return run_tracee_default_load(float(duration_s))
        if network_as_tcp_connect:
            return run_tcp_connect_load(seconds)
        return run_network_load(seconds)
    if kind == "tracee_system_edge_mix":
        return run_tracee_system_edge_mix_workload(float(duration_s))
    if kind == "tracee_module_load_loop":
        return run_tracee_module_load_loop_workload(float(duration_s))
    if kind == "tracee_io_vector_mix":
        return run_tracee_io_vector_mix_workload(float(duration_s))
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
    if kind == "vfs_create_fsync_exact":
        return run_vfs_create_fsync_exact_workload(float(duration_s))
    if kind == "iterator_poll":
        start = time.monotonic(); deadline = start + float(seconds); ops_total = 0.0
        while time.monotonic() < deadline:
            list(Path("/proc/self/task").iterdir()); ops_total += 1.0
        return _finish_result(ops_total, time.monotonic() - start, "", "")
    if kind == "security_policy_mix":
        return run_open_storm(seconds)
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
    def _simple_poll_loop(cmd: list[str], fail_msg: str) -> WorkloadResult:
        start = time.monotonic(); deadline = start + float(seconds); ops_total = 0.0
        while time.monotonic() < deadline:
            c = run_command(cmd, check=False, timeout=5)
            if c.returncode != 0: raise RuntimeError(f"{fail_msg}: {tail_text(c.stderr or c.stdout)}")
            ops_total += 1.0
        return _finish_result(ops_total, time.monotonic() - start, "", "")
    if kind == "sysctl_write":
        if (sysctl_binary := which("sysctl")) is None:
            raise RuntimeError("sysctl is required for the sysctl_write workload")
        return _simple_poll_loop([sysctl_binary, "-n", "kernel.pid_max"], "sysctl_write workload failed")
    if kind == "userns_unshare":
        if (unshare_binary := which("unshare")) is None:
            raise RuntimeError("unshare is required for the userns_unshare workload")
        return _simple_poll_loop([unshare_binary, "-Ur", "/bin/true"], "userns_unshare workload failed")
    raise RuntimeError(f"unsupported workload kind: {kind}")
