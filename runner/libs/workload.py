from __future__ import annotations

import ctypes
import ctypes.util
import errno
import json
import mmap
import os
import re
import select
import signal
import shlex
import socket
import stat
import subprocess
import sys
import tempfile
import threading
import time
from dataclasses import asdict, dataclass
from http.server import BaseHTTPRequestHandler, ThreadingHTTPServer
from pathlib import Path
from typing import Callable, Mapping, Sequence

from . import run_command, tail_text, which
from .benchmark_net import BENCHMARK_IFACE, BENCHMARK_NETNS, BENCHMARK_PEER_IFACE_IP
from .kernel_modules import kernel_module_is_builtin, load_kernel_module, repo_kernel_modules_root

LOOPBACK_LISTEN_BACKLOG = 128
LOOPBACK_CONNECT_TIMEOUT_S = 2.0
AT_FDCWD = -100
AT_EMPTY_PATH = 0x1000
PTRACE_ATTACH = 16
PTRACE_DETACH = 17
_INOTIFY_ALL_EVENTS = 0x00000FFF
_OPENAT2_SYSCALL_NR = {
    "x86_64": 437,
    "aarch64": 437,
    "arm64": 437,
}
_OPEN_SYSCALL_NR = {
    "x86_64": 2,
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


class _IOVec(ctypes.Structure):
    _fields_ = [
        ("iov_base", ctypes.c_void_p),
        ("iov_len", ctypes.c_size_t),
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
if hasattr(_LIBC, "mount"):
    _LIBC.mount.argtypes = [ctypes.c_char_p, ctypes.c_char_p, ctypes.c_char_p, ctypes.c_ulong, ctypes.c_void_p]
    _LIBC.mount.restype = ctypes.c_int
if hasattr(_LIBC, "umount2"):
    _LIBC.umount2.argtypes = [ctypes.c_char_p, ctypes.c_int]
    _LIBC.umount2.restype = ctypes.c_int
if hasattr(_LIBC, "ptrace"):
    _LIBC.ptrace.argtypes = [ctypes.c_uint, ctypes.c_uint, ctypes.c_void_p, ctypes.c_void_p]
    _LIBC.ptrace.restype = ctypes.c_long
if hasattr(_LIBC, "process_vm_writev"):
    _LIBC.process_vm_writev.argtypes = [
        ctypes.c_int,
        ctypes.POINTER(_IOVec),
        ctypes.c_ulong,
        ctypes.POINTER(_IOVec),
        ctypes.c_ulong,
        ctypes.c_ulong,
    ]
    _LIBC.process_vm_writev.restype = getattr(ctypes, "c_ssize_t", ctypes.c_long)
if hasattr(_LIBC, "inotify_init1"):
    _LIBC.inotify_init1.argtypes = [ctypes.c_int]
    _LIBC.inotify_init1.restype = ctypes.c_int
if hasattr(_LIBC, "inotify_add_watch"):
    _LIBC.inotify_add_watch.argtypes = [ctypes.c_int, ctypes.c_char_p, ctypes.c_uint32]
    _LIBC.inotify_add_watch.restype = ctypes.c_int


def _raise_ctypes_oserror(prefix: str) -> None:
    err = ctypes.get_errno()
    if err <= 0:
        err = errno.EIO
    raise OSError(err, f"{prefix}: {os.strerror(err)}")


def _notes_text(notes: Sequence[str]) -> str:
    return "\n".join(str(note) for note in notes if str(note).strip())


def _note_once(notes: list[str], note: str) -> None:
    if note not in notes:
        notes.append(note)


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


def _libc_sys_open(path: Path | str, flags: int, mode: int = 0) -> int:
    syscall_nr = _OPEN_SYSCALL_NR.get(os.uname().machine.lower())
    if syscall_nr is None:
        raise RuntimeError(f"direct open syscall is unsupported on architecture {os.uname().machine!r}")
    fd = _LIBC.syscall(int(syscall_nr), os.fsencode(os.fspath(path)), int(flags), int(mode))
    if fd < 0:
        _raise_ctypes_oserror(f"sys_open({path})")
    return int(fd)


def _libc_mount(source: str, target: Path | str, fs_type: str, flags: int = 0, data: str | None = None) -> None:
    if not hasattr(_LIBC, "mount"):
        raise RuntimeError("mount is unsupported on this libc")
    data_ptr = None if data is None else ctypes.c_char_p(os.fsencode(data))
    rc = _LIBC.mount(
        os.fsencode(source),
        os.fsencode(os.fspath(target)),
        os.fsencode(fs_type),
        ctypes.c_ulong(int(flags)),
        data_ptr,
    )
    if rc != 0:
        _raise_ctypes_oserror(f"mount({target})")


def _libc_umount2(target: Path | str, flags: int = 0) -> None:
    if not hasattr(_LIBC, "umount2"):
        raise RuntimeError("umount2 is unsupported on this libc")
    rc = _LIBC.umount2(os.fsencode(os.fspath(target)), int(flags))
    if rc != 0:
        _raise_ctypes_oserror(f"umount2({target})")


def _libc_ptrace(request: int, pid: int, addr: int = 0, data: int = 0) -> int:
    if not hasattr(_LIBC, "ptrace"):
        raise RuntimeError("ptrace is unsupported on this libc")
    rc = _LIBC.ptrace(
        int(request),
        int(pid),
        ctypes.c_void_p(int(addr)),
        ctypes.c_void_p(int(data)),
    )
    if rc < 0:
        _raise_ctypes_oserror(f"ptrace(request={request}, pid={pid})")
    return int(rc)


def _libc_process_vm_writev(pid: int, local_iov: _IOVec, remote_iov: _IOVec) -> int:
    if not hasattr(_LIBC, "process_vm_writev"):
        raise RuntimeError("process_vm_writev is unsupported on this libc")
    written = _LIBC.process_vm_writev(
        int(pid),
        ctypes.byref(local_iov),
        1,
        ctypes.byref(remote_iov),
        1,
        0,
    )
    if written < 0:
        _raise_ctypes_oserror(f"process_vm_writev(pid={pid})")
    return int(written)


def _libc_inotify_init1(flags: int) -> int:
    if not hasattr(_LIBC, "inotify_init1"):
        raise RuntimeError("inotify_init1 is unsupported on this libc")
    fd = _LIBC.inotify_init1(int(flags))
    if fd < 0:
        _raise_ctypes_oserror("inotify_init1")
    return int(fd)


def _libc_inotify_add_watch(fd: int, path: Path | str, mask: int) -> int:
    if not hasattr(_LIBC, "inotify_add_watch"):
        raise RuntimeError("inotify_add_watch is unsupported on this libc")
    wd = _LIBC.inotify_add_watch(int(fd), os.fsencode(os.fspath(path)), int(mask))
    if wd < 0:
        _raise_ctypes_oserror(f"inotify_add_watch({path})")
    return int(wd)


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
    duplicated_fd_2 = -1
    duplicated_fd_3 = -1
    try:
        os.write(source_fd, b"dup-test")
        duplicated_fd = os.dup(source_fd)
        duplicated_fd_2 = os.dup2(source_fd, source_fd + 64)
        if hasattr(os, "dup3"):
            duplicated_fd_3 = os.dup3(source_fd, source_fd + 128, os.O_CLOEXEC)
    finally:
        _close_quietly(duplicated_fd_3)
        _close_quietly(duplicated_fd_2)
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


def _exercise_cgroup_attach_task_once() -> str | None:
    if not _CGROUP_ROOT.is_dir():
        return f"cgroup root is unavailable: {_CGROUP_ROOT}"
    path = _CGROUP_ROOT / f"bpf-benchmark-tracee-edge-{os.getpid()}-{time.monotonic_ns()}"
    child = None
    try:
        path.mkdir()
        child = subprocess.Popen(
            [sys.executable or which("python3") or "python3", "-c", "import time; time.sleep(30)"],
            stdout=subprocess.DEVNULL,
            stderr=subprocess.DEVNULL,
        )
        (path / "cgroup.procs").write_text(f"{int(child.pid)}\n", encoding="utf-8")
        child.terminate()
        child.wait(timeout=5)
        path.rmdir()
    except OSError as exc:
        return f"cgroup attach-task failed: {exc}"
    except subprocess.TimeoutExpired as exc:
        return f"cgroup attach-task child did not exit cleanly: {exc}"
    finally:
        if child is not None and child.poll() is None:
            child.kill()
            try:
                child.wait(timeout=5)
            except subprocess.TimeoutExpired:
                pass
        try:
            path.rmdir()
        except OSError:
            pass
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
_STRESS_NG_STRESSOR_OPS: Mapping[str, int] = {
    "access": 1000,
    "aio": 200,
    "aiol": 200,
    "cap": 2000,
    "chdir": 50,
    "chmod": 100,
    "chown": 100,
    "clone": 100,
    "cpu": 2000,
    "dentry": 1000,
    "dir": 1000,
    "dirmany": 1000,
    "epoll": 1000,
    "eventfd": 1000,
    "fallocate": 1,
    "file-ioctl": 1000,
    "filename": 200,
    "flock": 1000,
    "fork": 200,
    "fpunch": 5,
    "fstat": 200,
    "futex": 1000,
    "get": 200,
    "getdent": 1000,
    "hdd": 128,
    "inotify": 10,
    "io": 20,
    "iomix": 128,
    "io-uring": 200,
    "netdev": 1000,
    "open": 100,
    "prctl": 1000,
    "rename": 100,
    "sctp": 200,
    "sem": 1000,
    "sem-sysv": 1000,
    "set": 1000,
    "sock": 200,
    "sockdiag": 1000,
    "sockfd": 200,
    "sockpair": 500,
    "switch": 1000,
    "sync-file": 20,
    "syscall": 64,
    "touch": 200,
    "udp-flood": 1000,
    "utime": 200,
    "vfork": 200,
    "yield": 5000,
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


def _build_stress_ng_stressor_command(
    stress_ng: str,
    stressor: str,
    *,
    seconds: int,
    temp_root: Path,
) -> list[str]:
    normalized_stressor = str(stressor).strip()
    if not normalized_stressor:
        raise RuntimeError("stress-ng stressor name must be non-empty")
    command = [stress_ng, f"--{normalized_stressor}", "1"]
    command.extend(_STRESS_NG_STRESSOR_ARGS.get(normalized_stressor, ()))
    command.extend(_stress_ng_dynamic_stressor_args((normalized_stressor,)))
    if ops_limit := _STRESS_NG_STRESSOR_OPS.get(normalized_stressor):
        command.extend([f"--{normalized_stressor}-ops", str(int(ops_limit))])
    command.extend(
        [
            "--timeout",
            f"{seconds}s",
            "--metrics-brief",
            "--temp-path",
            str(temp_root),
        ]
    )
    return command


def run_stress_ng_class_load(duration_s: int | float, stressors: Sequence[str], *, workload_name: str) -> WorkloadResult:
    stress_ng = which("stress-ng")
    if stress_ng is None:
        raise RuntimeError(f"stress-ng is required for the {workload_name} workload")
    normalized_stressors = tuple(str(stressor).strip() for stressor in stressors if str(stressor).strip())
    if not normalized_stressors:
        raise RuntimeError(f"{workload_name} workload requires at least one stress-ng stressor")
    seconds = max(1, int(round(float(duration_s))))
    temp_root = _disk_backed_tmp_root()
    stdout_chunks: list[str] = []
    stderr_chunks: list[str] = []
    ops_total = 0.0
    start = time.monotonic()
    for stressor in normalized_stressors:
        command = _build_stress_ng_stressor_command(
            stress_ng,
            stressor,
            seconds=seconds,
            temp_root=temp_root,
        )
        try:
            completed = run_command(
                command,
                check=False,
                cwd=temp_root,
                timeout=max(float(seconds) + 15, float(seconds) * 4),
            )
        except subprocess.TimeoutExpired as exc:
            raise RuntimeError(f"{workload_name} workload stressor {stressor} timed out") from exc
        stdout_chunks.append(completed.stdout or "")
        stderr_chunks.append(completed.stderr or "")
        if completed.returncode != 0:
            raise RuntimeError(
                f"{workload_name} workload stressor {stressor} failed: "
                f"{tail_text(completed.stderr or completed.stdout)}"
            )
        combined = (completed.stdout or "") + "\n" + (completed.stderr or "")
        stressor_ops = parse_stress_ng_bogo_ops(combined, stressor=stressor)
        if stressor_ops is None:
            raise RuntimeError(
                f"{workload_name} workload stressor {stressor} did not report bogo-ops metrics: "
                f"{tail_text(combined)}"
            )
        ops_total += float(stressor_ops)
    elapsed = time.monotonic() - start
    return _finish_result(ops_total, elapsed, "\n".join(stdout_chunks), "\n".join(stderr_chunks))


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


def _udp_loopback_roundtrip_once(family: int) -> None:
    bind_addr = ("::1", 0, 0, 0) if family == socket.AF_INET6 else ("127.0.0.1", 0)
    with socket.socket(family, socket.SOCK_DGRAM) as server, socket.socket(family, socket.SOCK_DGRAM) as client:
        server.settimeout(LOOPBACK_CONNECT_TIMEOUT_S)
        client.settimeout(LOOPBACK_CONNECT_TIMEOUT_S)
        server.bind(bind_addr)
        if family == socket.AF_INET6 and hasattr(socket, "IPV6_V6ONLY"):
            server.setsockopt(socket.IPPROTO_IPV6, socket.IPV6_V6ONLY, 1)
            client.setsockopt(socket.IPPROTO_IPV6, socket.IPV6_V6ONLY, 1)
        payload = b"tetragon-udp-payload"
        reply = b"ack:" + payload[:8]
        client.sendto(payload, server.getsockname())
        data, peer = server.recvfrom(256)
        if data != payload:
            raise RuntimeError("UDP loopback server received an unexpected payload")
        server.sendto(reply, peer)
        echoed, _ = client.recvfrom(256)
        if echoed != reply:
            raise RuntimeError("UDP loopback client received an unexpected reply")


def _tcp_payload_roundtrip_once() -> None:
    payload = b"tetragon-tcp-payload"
    ready = threading.Event()
    errors: list[str] = []
    port_holder: list[int] = []

    def server() -> None:
        try:
            with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as listener:
                listener.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
                listener.bind(("127.0.0.1", 0))
                listener.listen(1)
                port_holder.append(int(listener.getsockname()[1]))
                ready.set()
                conn, _ = listener.accept()
                with conn:
                    conn.settimeout(LOOPBACK_CONNECT_TIMEOUT_S)
                    data = conn.recv(256)
                    if data != payload:
                        raise RuntimeError("TCP payload server received an unexpected payload")
                    conn.sendall(b"ack:" + data[:8])
        except Exception as exc:
            errors.append(str(exc))
            ready.set()

    thread = threading.Thread(target=server, daemon=True)
    thread.start()
    if not ready.wait(timeout=2.0):
        raise RuntimeError("TCP payload server did not become ready")
    if not port_holder:
        raise RuntimeError(errors[-1] if errors else "TCP payload server did not publish a port")
    with socket.create_connection(("127.0.0.1", port_holder[0]), timeout=LOOPBACK_CONNECT_TIMEOUT_S) as client:
        client.settimeout(LOOPBACK_CONNECT_TIMEOUT_S)
        client.sendall(payload)
        response = client.recv(256)
        if response != b"ack:" + payload[:8]:
            raise RuntimeError("TCP payload client received an unexpected reply")
    thread.join(timeout=2.0)
    if errors:
        raise RuntimeError(errors[-1])


def _exercise_fs_metadata_once(
    root: Path,
    *,
    follow_symlink: bool,
    use_inotify: bool,
) -> None:
    watch_fd = -1
    follow_target = root / f"follow-target-{time.monotonic_ns()}.txt"
    follow_link = root / f"follow-link-{time.monotonic_ns()}"
    metadata_target = root / f"metadata-target-{time.monotonic_ns()}.txt"
    renamed_target = root / f"metadata-renamed-{time.monotonic_ns()}.txt"
    fifo_path = root / f"metadata-fifo-{time.monotonic_ns()}"
    try:
        if use_inotify:
            watch_fd = _libc_inotify_init1(os.O_CLOEXEC | os.O_NONBLOCK)
            _libc_inotify_add_watch(watch_fd, root, _INOTIFY_ALL_EVENTS)
        follow_target.write_bytes(b"follow-me")
        metadata_target.write_bytes(b"metadata")
        if follow_symlink:
            follow_link.symlink_to(follow_target.name)
            with follow_link.open("rb") as handle:
                handle.read()
        os.rename(metadata_target, renamed_target)
        os.chmod(renamed_target, 0o640)
        now_ns = time.time_ns()
        os.utime(renamed_target, ns=(now_ns, now_ns))
        os.mknod(fifo_path, stat.S_IFIFO | 0o600)
        if watch_fd >= 0:
            try:
                os.read(watch_fd, 4096)
            except BlockingIOError:
                pass
    finally:
        _close_quietly(watch_fd)
        for path in (follow_link, follow_target, renamed_target, metadata_target, fifo_path):
            try:
                path.unlink()
            except FileNotFoundError:
                pass


def _exercise_mmap_truncate_once(root: Path) -> None:
    path = root / f"mmap-truncate-{time.monotonic_ns()}.bin"
    fd = os.open(path, os.O_CREAT | os.O_RDWR | os.O_TRUNC, 0o600)
    try:
        os.write(fd, b"x" * 8192)
        os.lseek(fd, 0, os.SEEK_SET)
        mapping = mmap.mmap(fd, 8192, access=mmap.ACCESS_WRITE)
        try:
            payload = b"mmap-truncate!!"
            mapping[: len(payload)] = payload
            mapping.flush()
            os.truncate(path, 4096)
        finally:
            mapping.close()
    finally:
        os.close(fd)
        try:
            path.unlink()
        except FileNotFoundError:
            pass


def _exercise_pty_write_once() -> None:
    master_fd, slave_fd = os.openpty()
    try:
        os.write(slave_fd, b"pty-write\n")
        os.read(master_fd, 128)
    finally:
        _close_quietly(slave_fd)
        _close_quietly(master_fd)


def _exercise_mount_roundtrip_once(root: Path) -> None:
    mountpoint = root / f"mount-{time.monotonic_ns()}"
    mountpoint.mkdir()
    mounted = False
    try:
        _libc_mount("tmpfs", mountpoint, "tmpfs", data="size=64k")
        mounted = True
        (mountpoint / "mounted.txt").write_text("tmpfs\n", encoding="utf-8")
    finally:
        if mounted:
            _libc_umount2(mountpoint)
        mountpoint.rmdir()


def _exercise_signal_delivery_once() -> None:
    sleep_binary = which("sleep")
    if sleep_binary is None:
        raise RuntimeError("sleep is required for the signal delivery workload")
    child = subprocess.Popen(
        [sleep_binary, "30"],
        stdout=subprocess.DEVNULL,
        stderr=subprocess.DEVNULL,
    )
    try:
        time.sleep(0.05)
        child.send_signal(signal.SIGUSR1)
        child.wait(timeout=5)
        if child.returncode in (0, None):
            raise RuntimeError("sleep child ignored SIGUSR1")
    finally:
        if child.poll() is None:
            child.kill()
            child.wait(timeout=5)


def _exercise_bpf_self_observe_once() -> None:
    bpftrace_binary = which("bpftrace")
    if bpftrace_binary is None:
        raise RuntimeError("bpftrace is required for the Tetragon BPF self-observation workload")
    completed = run_command(
        [
            bpftrace_binary,
            "-q",
            "-e",
            "kprobe:fd_install { @cnt = count(); exit(); }",
            "-c",
            "cat /etc/hosts >/dev/null",
        ],
        check=False,
        timeout=20,
    )
    if completed.returncode != 0:
        raise RuntimeError(tail_text(completed.stderr or completed.stdout))


def _exercise_ptrace_and_process_vm_writev_once() -> None:
    payload = b"tracee-process-vm-write"
    pipe_read, pipe_write = os.pipe()
    ack_read, ack_write = os.pipe()
    pid = os.fork()
    if pid == 0:
        _close_quietly(pipe_read)
        _close_quietly(ack_write)
        try:
            buffer = ctypes.create_string_buffer(len(payload))
            os.write(pipe_write, f"{ctypes.addressof(buffer)}\n".encode("utf-8"))
            os.read(ack_read, 1)
            os._exit(0 if bytes(buffer.raw[: len(payload)]) == payload else 2)
        except Exception:
            os._exit(3)

    _close_quietly(pipe_write)
    _close_quietly(ack_read)
    attached = False
    child_reaped = False
    try:
        address_text = os.read(pipe_read, 64).decode("utf-8").strip()
        if not address_text:
            raise RuntimeError("ptrace/process_vm_writev child did not publish a remote buffer address")
        remote_address = int(address_text)
        _libc_ptrace(PTRACE_ATTACH, pid)
        attached = True
        _, status = os.waitpid(pid, 0)
        if not os.WIFSTOPPED(status):
            raise RuntimeError("ptrace attach target did not stop as expected")
        local_buffer = ctypes.create_string_buffer(payload)
        local_iov = _IOVec(ctypes.cast(local_buffer, ctypes.c_void_p), len(payload))
        remote_iov = _IOVec(ctypes.c_void_p(remote_address), len(payload))
        written = _libc_process_vm_writev(pid, local_iov, remote_iov)
        if written != len(payload):
            raise RuntimeError(f"process_vm_writev wrote {written} bytes, expected {len(payload)}")
        _libc_ptrace(PTRACE_DETACH, pid)
        attached = False
        os.write(ack_write, b"1")
        _wait_successful_child(pid, "process_vm_writev child")
        child_reaped = True
    finally:
        if not child_reaped:
            if attached:
                try:
                    _libc_ptrace(PTRACE_DETACH, pid)
                except Exception:
                    pass
            try:
                os.kill(pid, 9)
            except OSError:
                pass
            try:
                os.waitpid(pid, 0)
            except OSError:
                pass
        _close_quietly(pipe_read)
        _close_quietly(ack_write)


def _run_best_effort_activity(
    label: str,
    notes: list[str],
    activity: Callable[[], None],
) -> bool:
    try:
        activity()
        return True
    except Exception as exc:
        _note_once(notes, f"{label}_unavailable={exc}")
        return False


def _run_optional_segment(
    label: str,
    duration_s: float,
    runner: Callable[[int | float], WorkloadResult],
) -> WorkloadResult:
    try:
        return runner(duration_s)
    except Exception as exc:
        return _finish_result(0.0, 0.0, "", f"{label} unavailable: {exc}")


def run_tetragon_socket_event_mix_workload(duration_s: int | float) -> WorkloadResult:
    start = time.monotonic()
    deadline = start + max(0.2, float(duration_s))
    ops_total = 0.0
    notes: list[str] = []
    udp_ipv4_available = True
    ipv6_available = socket.has_ipv6
    tcp_payload_available = True
    while time.monotonic() < deadline:
        if udp_ipv4_available:
            udp_ipv4_available = _run_best_effort_activity(
                "udp_ipv4_loopback",
                notes,
                lambda: _udp_loopback_roundtrip_once(socket.AF_INET),
            )
        if ipv6_available:
            ipv6_available = _run_best_effort_activity(
                "udp_ipv6_loopback",
                notes,
                lambda: _udp_loopback_roundtrip_once(socket.AF_INET6),
            )
        if tcp_payload_available:
            tcp_payload_available = _run_best_effort_activity(
                "tcp_payload_loopback",
                notes,
                _tcp_payload_roundtrip_once,
            )
        ops_total += 1.0
    return _finish_result(ops_total, time.monotonic() - start, "", _notes_text(notes))


def run_tetragon_fs_event_mix_workload(duration_s: int | float) -> WorkloadResult:
    with tempfile.TemporaryDirectory(prefix="tetragon-fs-", dir=str(_disk_backed_tmp_root())) as tempdir:
        root = Path(tempdir)
        etc_tempdir: tempfile.TemporaryDirectory[str] | None = None
        notes: list[str] = []
        etc_root: Path | None = None
        try:
            etc_tempdir = tempfile.TemporaryDirectory(prefix="tetragon-fs-", dir="/etc")
            etc_root = Path(etc_tempdir.name)
        except Exception as exc:
            _note_once(notes, f"etc_fs_root_unavailable={exc}")
        start = time.monotonic()
        deadline = start + max(0.2, float(duration_s))
        ops_total = 0.0
        fs_metadata_available = True
        mmap_truncate_available = True
        pty_available = True
        etc_fs_metadata_available = etc_root is not None
        etc_mmap_truncate_available = etc_root is not None
        try:
            while time.monotonic() < deadline:
                if fs_metadata_available:
                    fs_metadata_available = _run_best_effort_activity(
                        "tetragon_fs_metadata",
                        notes,
                        lambda: _exercise_fs_metadata_once(root, follow_symlink=True, use_inotify=False),
                    )
                if mmap_truncate_available:
                    mmap_truncate_available = _run_best_effort_activity(
                        "tetragon_mmap_truncate",
                        notes,
                        lambda: _exercise_mmap_truncate_once(root),
                    )
                if pty_available:
                    pty_available = _run_best_effort_activity(
                        "tetragon_pty_write",
                        notes,
                        _exercise_pty_write_once,
                    )
                if etc_root is not None and etc_fs_metadata_available:
                    etc_fs_metadata_available = _run_best_effort_activity(
                        "tetragon_etc_fs_metadata",
                        notes,
                        lambda: _exercise_fs_metadata_once(etc_root, follow_symlink=True, use_inotify=False),
                    )
                if etc_root is not None and etc_mmap_truncate_available:
                    etc_mmap_truncate_available = _run_best_effort_activity(
                        "tetragon_etc_mmap_truncate",
                        notes,
                        lambda: _exercise_mmap_truncate_once(etc_root),
                    )
                ops_total += 1.0
        finally:
            if etc_tempdir is not None:
                etc_tempdir.cleanup()
        return _finish_result(ops_total, time.monotonic() - start, "", _notes_text(notes))


def run_tetragon_host_event_mix_workload(duration_s: int | float) -> WorkloadResult:
    with tempfile.TemporaryDirectory(prefix="tetragon-host-", dir=str(_disk_backed_tmp_root())) as tempdir:
        root = Path(tempdir)
        start = time.monotonic()
        deadline = start + max(0.2, float(duration_s))
        ops_total = 0.0
        notes: list[str] = []
        mount_available = True
        module_attempted = False
        signal_available = True
        bpf_self_observe_attempted = False
        while time.monotonic() < deadline:
            if mount_available:
                mount_available = _run_best_effort_activity(
                    "mount",
                    notes,
                    lambda: _exercise_mount_roundtrip_once(root),
                )
            if not module_attempted:
                module_attempted = True
                try:
                    notes.append(f"module_load_candidate={_run_module_load_cycle()}")
                except Exception as exc:
                    _note_once(notes, f"module_load_unavailable={exc}")
            if signal_available:
                signal_available = _run_best_effort_activity(
                    "signal_delivery",
                    notes,
                    _exercise_signal_delivery_once,
                )
            if not bpf_self_observe_attempted:
                bpf_self_observe_attempted = True
                _run_best_effort_activity(
                    "bpf_self_observe",
                    notes,
                    _exercise_bpf_self_observe_once,
                )
            ops_total += 1.0
        return _finish_result(ops_total, time.monotonic() - start, "", _notes_text(notes))


def run_tracee_syscall_edge_mix_workload(duration_s: int | float) -> WorkloadResult:
    with tempfile.TemporaryDirectory(prefix="tracee-edge-", dir=str(_disk_backed_tmp_root())) as tempdir:
        root = Path(tempdir)
        dup_path = root / "dup-edge.bin"
        start = time.monotonic()
        deadline = start + max(0.2, float(duration_s))
        ops_total = 0.0
        notes: list[str] = []
        cgroup_exercised = False
        cgroup_available = True
        ptrace_available = True
        missing_path = str(root / "definitely-missing-execveat")
        while time.monotonic() < deadline:
            _run_execveat_once("/bin/true")
            _run_failed_execveat_once(missing_path)
            _exercise_dup_family(dup_path)
            _exercise_socketpair_once()
            _accept4_roundtrip()
            if ptrace_available:
                try:
                    _exercise_ptrace_and_process_vm_writev_once()
                except Exception as exc:
                    notes.append(f"ptrace_process_vm_writev_unavailable={exc}")
                    ptrace_available = False
            _exercise_fs_metadata_once(root, follow_symlink=True, use_inotify=True)
            if not cgroup_exercised and cgroup_available:
                cgroup_result = _exercise_cgroup_attach_task_once()
                if cgroup_result:
                    notes.append(f"cgroup_attach_task_unavailable={cgroup_result}")
                    cgroup_available = False
                else:
                    cgroup_exercised = True
            ops_total += 1.0
        return _finish_result(ops_total, time.monotonic() - start, "", _notes_text(notes))


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
    total = max(0.6, float(duration_s))
    stress_exec_s = max(0.1, total * 0.20)
    rapid_exec_s = max(0.1, total * 0.15)
    socket_s = max(0.1, total * 0.20)
    fs_s = max(0.1, total * 0.20)
    host_s = max(0.1, total - stress_exec_s - rapid_exec_s - socket_s - fs_s)
    chosen_exec_runner = run_exec_storm if exec_runner is None else exec_runner
    return _merge_workload_results(
        [
            chosen_exec_runner(stress_exec_s),
            _run_optional_segment(
                "tetragon_rapid_exec",
                rapid_exec_s,
                lambda seconds: run_rapid_exec_storm(seconds, command_path="/bin/true"),
            ),
            _run_optional_segment("tetragon_socket_event_mix", socket_s, run_tetragon_socket_event_mix_workload),
            _run_optional_segment("tetragon_fs_event_mix", fs_s, run_tetragon_fs_event_mix_workload),
            _run_optional_segment("tetragon_host_event_mix", host_s, run_tetragon_host_event_mix_workload),
        ]
    )


def run_tracee_system_edge_mix_workload(duration_s: int | float) -> WorkloadResult:
    total = max(0.6, float(duration_s))
    syscall_s = max(0.2, total * 0.45)
    iov_s = max(0.2, total * 0.30)
    module_s = max(0.2, total - syscall_s - iov_s)
    return _merge_workload_results(
        [
            run_tracee_syscall_edge_mix_workload(syscall_s),
            run_tracee_io_vector_mix_workload(iov_s),
            _run_optional_segment("tracee_module_load_loop", module_s, run_tracee_module_load_loop_workload),
        ]
    )


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
                    _note_once(notes, f"{name}_burner_start_failed={exc}")
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
                    _note_once(
                        notes,
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
                    _note_once(
                        notes,
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
        direct_open_supported = True
        try:
            while time.monotonic() < deadline:
                fd_sys_open = -1
                fd_open = _libc_open(target, os.O_RDONLY | os.O_CLOEXEC)
                fd_openat = _libc_openat(dirfd, target.name, os.O_RDONLY | os.O_CLOEXEC)
                fd_openat2 = -1
                try:
                    if direct_open_supported:
                        try:
                            fd_sys_open = _libc_sys_open(target, os.O_RDONLY | os.O_CLOEXEC)
                        except RuntimeError as exc:
                            _note_once(notes, f"direct_open_unavailable={exc}")
                            direct_open_supported = False
                    try:
                        fd_openat2 = _libc_openat2(dirfd, target.name, os.O_RDONLY | os.O_CLOEXEC)
                    except OSError as exc:
                        raise RuntimeError(f"open_family_storm requires openat2: {exc}") from exc
                    ops_total += 1.0
                finally:
                    _close_quietly(fd_sys_open)
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
    ip_binary = which("ip")
    if ip_binary is None:
        raise RuntimeError("ip is required for interface-bound network workloads")
    return [ip_binary, "netns", "exec", BENCHMARK_NETNS, *command]


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
    network_device: str | None = None,
) -> WorkloadResult:
    seconds = max(1, int(round(float(duration_s))))
    kind = str(kind or "").strip()
    if kind == "mixed":
        return run_mixed_workload(float(duration_s))
    if kind in _STRESS_NG_WORKLOAD_STRESSORS:
        return run_stress_ng_class_load(
            float(duration_s),
            _STRESS_NG_WORKLOAD_STRESSORS[kind],
            workload_name=kind,
        )
    if kind == "tcp_connect":
        return run_tcp_connect_load(seconds, network_device=network_device)
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
            return run_tcp_connect_load(seconds, network_device=network_device)
        return run_network_load(seconds, network_device=network_device)
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
    if kind in {"fio", "fio_randrw"}:
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
