from __future__ import annotations

import os
import re
import shutil
import socket
import subprocess
import tempfile
import threading
import time
import urllib.error
import urllib.request
from pathlib import Path

from .. import ROOT_DIR, run_command, tail_text, which
from ..benchmark_net import (
    BENCHMARK_IFACE,
    BENCHMARK_IFACE_CIDR,
    BENCHMARK_NETNS,
    BENCHMARK_PEER_IFACE,
    BENCHMARK_PEER_IFACE_CIDR,
    is_benchmark_interface,
)
from ..agent import stop_agent
from .process_support import NativeProcessRunner, ProcessOutputCollector


def _runtime_tmp_root() -> Path:
    override = os.environ.get("BPFREJIT_ETCD_RUNTIME_TMPDIR", "").strip()
    if override:
        candidate = Path(override).expanduser()
        try:
            candidate.mkdir(parents=True, exist_ok=True)
        except OSError:
            pass
        else:
            if os.access(candidate, os.W_OK | os.X_OK):
                return candidate
    for candidate in (Path("/var/tmp"), Path("/tmp")):
        try:
            candidate.mkdir(parents=True, exist_ok=True)
        except OSError:
            continue
        if os.access(candidate, os.W_OK | os.X_OK):
            return candidate
    raise RuntimeError("no writable local temporary directory is available for etcd-backed runners")


def runner_hostname() -> str:
    return socket.gethostname().strip() or "localhost"


def anchored_iface_regex(interface: str) -> str:
    normalized = str(interface or "").strip()
    if not normalized:
        raise RuntimeError("interface name is required for anchored_iface_regex")
    return rf"^{re.escape(normalized)}$"


def is_synthetic_benchmark_interface(interface: str | None) -> bool:
    return is_benchmark_interface(interface)


def _link_exists(name: str) -> bool:
    try:
        run_command(["ip", "-o", "link", "show", "dev", name], timeout=10)
    except Exception:
        return False
    return True


def _delete_link_if_exists(name: str) -> None:
    if not _link_exists(name):
        return
    try:
        run_command(["ip", "link", "delete", "dev", name], timeout=10)
    except Exception:
        pass


def _netns_exists(name: str) -> bool:
    try:
        completed = run_command(["ip", "netns", "list"], timeout=10)
    except Exception:
        return False
    return any(line.split(maxsplit=1)[0].strip() == name for line in completed.stdout.splitlines())


def _link_exists_in_netns(namespace: str, name: str) -> bool:
    if not _netns_exists(namespace):
        return False
    try:
        run_command(["ip", "-n", namespace, "-o", "link", "show", "dev", name], timeout=10)
    except Exception:
        return False
    return True


def ensure_benchmark_interface() -> str:
    iface_exists = _link_exists(BENCHMARK_IFACE)
    peer_exists_in_root = _link_exists(BENCHMARK_PEER_IFACE)
    peer_exists_in_netns = _link_exists_in_netns(BENCHMARK_NETNS, BENCHMARK_PEER_IFACE)
    if not iface_exists and peer_exists_in_netns:
        run_command(
            ["ip", "-n", BENCHMARK_NETNS, "link", "delete", "dev", BENCHMARK_PEER_IFACE],
            check=False,
            timeout=10,
        )
        peer_exists_in_netns = False
    if iface_exists and not peer_exists_in_netns:
        _delete_link_if_exists(BENCHMARK_IFACE)
        iface_exists = False
        peer_exists_in_root = False
        peer_exists_in_netns = False
    if not _netns_exists(BENCHMARK_NETNS):
        run_command(["ip", "netns", "add", BENCHMARK_NETNS], timeout=10)
    if not iface_exists:
        run_command(
            [
                "ip",
                "link",
                "add",
                "dev",
                BENCHMARK_IFACE,
                "type",
                "veth",
                "peer",
                "name",
                BENCHMARK_PEER_IFACE,
            ],
            timeout=10,
        )
        peer_exists_in_root = True
    if peer_exists_in_root:
        run_command(["ip", "link", "set", "dev", BENCHMARK_PEER_IFACE, "netns", BENCHMARK_NETNS], timeout=10)
    if not _link_exists_in_netns(BENCHMARK_NETNS, BENCHMARK_PEER_IFACE):
        raise RuntimeError(
            f"benchmark peer interface {BENCHMARK_PEER_IFACE} is unavailable in namespace {BENCHMARK_NETNS}"
        )
    run_command(["ip", "addr", "replace", BENCHMARK_IFACE_CIDR, "dev", BENCHMARK_IFACE], timeout=10)
    run_command(["ip", "link", "set", "dev", BENCHMARK_IFACE, "up"], timeout=10)
    run_command(
        ["ip", "-n", BENCHMARK_NETNS, "addr", "replace", BENCHMARK_PEER_IFACE_CIDR, "dev", BENCHMARK_PEER_IFACE],
        timeout=10,
    )
    run_command(["ip", "-n", BENCHMARK_NETNS, "link", "set", "dev", "lo", "up"], timeout=10)
    run_command(["ip", "-n", BENCHMARK_NETNS, "link", "set", "dev", BENCHMARK_PEER_IFACE, "up"], timeout=10)
    return BENCHMARK_IFACE


def detect_primary_interface(*, prefer_benchmark: bool = False) -> str:
    if prefer_benchmark:
        return ensure_benchmark_interface()
    try:
        completed = run_command(["ip", "-o", "route", "show", "default"], timeout=10)
        for line in completed.stdout.splitlines():
            tokens = line.split()
            if "dev" not in tokens:
                continue
            index = tokens.index("dev") + 1
            if index >= len(tokens):
                continue
            candidate = tokens[index].strip()
            if candidate and candidate != "lo":
                return candidate
    except Exception:
        pass
    completed = run_command(["ip", "-o", "link", "show"], timeout=10)
    for line in completed.stdout.splitlines():
        _, _, remainder = line.partition(": ")
        name = remainder.split("@", 1)[0].split(":", 1)[0].strip()
        if name and name != "lo":
            return name
    return ensure_benchmark_interface()


def _reserve_local_port() -> int:
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as sock:
        sock.bind(("127.0.0.1", 0))
        sock.listen(1)
        return int(sock.getsockname()[1])


class LocalEtcdSession:
    def __init__(
        self,
        *,
        work_dir: Path,
        name: str,
        startup_timeout_s: int = 20,
    ) -> None:
        self.work_dir = Path(work_dir).resolve()
        self.name = str(name).strip() or "runner"
        self.startup_timeout_s = int(startup_timeout_s)
        self.data_dir = self.work_dir / "data"
        self.process: subprocess.Popen[str] | None = None
        self.collector = ProcessOutputCollector()
        self.stdout_thread: threading.Thread | None = None
        self.stderr_thread: threading.Thread | None = None
        self.client_url = ""
        self.peer_url = ""
        self.command_used: list[str] = []

    def start(self) -> "LocalEtcdSession":
        binary = which("etcd")
        if binary is None:
            raise RuntimeError("etcd is required to run Cilium/Calico without Kubernetes")
        shutil.rmtree(self.work_dir, ignore_errors=True)
        self.data_dir.mkdir(parents=True, exist_ok=True)
        client_port = _reserve_local_port()
        peer_port = _reserve_local_port()
        self.client_url = f"http://127.0.0.1:{client_port}"
        self.peer_url = f"http://127.0.0.1:{peer_port}"
        command = [
            binary,
            "--name", self.name,
            "--data-dir", str(self.data_dir),
            "--listen-client-urls", self.client_url,
            "--advertise-client-urls", self.client_url,
            "--listen-peer-urls", self.peer_url,
            "--initial-advertise-peer-urls", self.peer_url,
            "--initial-cluster", f"{self.name}={self.peer_url}",
            "--initial-cluster-state", "new",
        ]
        self.command_used = list(command)
        self.process = subprocess.Popen(
            command,
            cwd=ROOT_DIR,
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            text=True,
            bufsize=1,
        )
        assert self.process.stdout is not None
        assert self.process.stderr is not None
        self.stdout_thread = threading.Thread(
            target=self.collector.consume_stdout,
            args=(self.process.stdout,),
            daemon=True,
        )
        self.stderr_thread = threading.Thread(
            target=self.collector.consume_stderr,
            args=(self.process.stderr,),
            daemon=True,
        )
        self.stdout_thread.start()
        self.stderr_thread.start()
        deadline = time.monotonic() + max(1, self.startup_timeout_s)
        while time.monotonic() < deadline:
            if self.process.poll() is not None:
                returncode = self.process.returncode
                details = self._tail_details()
                self.close()
                raise RuntimeError(
                    f"local etcd exited with code {returncode} before becoming healthy"
                    + (f": {details}" if details else "")
                )
            if self._healthy():
                return self
            time.sleep(0.2)
        details = self._tail_details()
        self.close()
        raise RuntimeError(
            f"local etcd did not become healthy within {self.startup_timeout_s}s"
            + (f": {details}" if details else "")
        )

    def _healthy(self) -> bool:
        if not self.client_url:
            return False
        try:
            with urllib.request.urlopen(f"{self.client_url}/health", timeout=1.0) as response:
                payload = response.read().decode("utf-8", errors="replace").lower()
        except (OSError, urllib.error.URLError):
            return False
        return '"health":"true"' in payload or '"health":true' in payload

    def snapshot(self) -> dict[str, object]:
        return self.collector.snapshot()

    def close(self) -> None:
        if self.process is not None:
            stop_agent(self.process, timeout=8)
            self.process = None
        if self.stdout_thread is not None:
            self.stdout_thread.join(timeout=2.0)
            self.stdout_thread = None
        if self.stderr_thread is not None:
            self.stderr_thread.join(timeout=2.0)
            self.stderr_thread = None
        shutil.rmtree(self.work_dir, ignore_errors=True)

    def _tail_details(self) -> str:
        snapshot = self.snapshot()
        combined = "\n".join(
            list(snapshot.get("stderr_tail") or []) + list(snapshot.get("stdout_tail") or [])
        )
        return tail_text(combined, max_lines=40, max_chars=8000)


class EtcdBackedNativeRunner(NativeProcessRunner):
    def __init__(self, *, etcd_startup_timeout_s: int = 20, **kwargs: object) -> None:
        super().__init__(**kwargs)
        self.etcd_startup_timeout_s = int(etcd_startup_timeout_s)
        self.etcd_session: LocalEtcdSession | None = None
        self.runtime_dir: Path | None = None

    def _prepare_runtime(self) -> None:
        self.runtime_dir = Path(
            tempfile.mkdtemp(prefix=f"{type(self).__name__.lower()}_", dir=str(_runtime_tmp_root()))
        ).resolve()

    def _after_runtime_prepared(self) -> None:
        return None

    def _after_etcd_started(self) -> None:
        return None

    def _etcd_name(self) -> str:
        return type(self).__name__.replace("Runner", "").lower() or "runner"

    def start(self) -> list[int]:
        if self.etcd_session is not None:
            raise RuntimeError(f"{type(self).__name__} is already running")
        self._prepare_runtime()
        try:
            self._after_runtime_prepared()
            assert self.runtime_dir is not None
            session = LocalEtcdSession(
                work_dir=self.runtime_dir / "etcd",
                name=self._etcd_name(),
                startup_timeout_s=self.etcd_startup_timeout_s,
            )
            self.etcd_session = session.start()
            self._after_etcd_started()
            return super().start()
        except Exception:
            self.stop()
            raise

    def stop(self) -> None:
        super().stop()
        if self.etcd_session is not None:
            self.etcd_session.close()
            self.etcd_session = None
        if self.runtime_dir is not None:
            shutil.rmtree(self.runtime_dir, ignore_errors=True)
            self.runtime_dir = None


__all__ = [
    "EtcdBackedNativeRunner",
    "LocalEtcdSession",
    "anchored_iface_regex",
    "ensure_benchmark_interface",
    "detect_primary_interface",
    "is_synthetic_benchmark_interface",
    "runner_hostname",
]
