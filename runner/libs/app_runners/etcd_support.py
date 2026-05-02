from __future__ import annotations

import os
import shutil
import socket
import subprocess
import tempfile
import threading
import time
import urllib.error
import urllib.request
from pathlib import Path

from .. import ROOT_DIR, tail_text, which
from ..agent import stop_agent
from .process_support import ProcessOutputCollector


def _runtime_tmp_root() -> Path:
    for candidate in (Path("/var/tmp"), Path("/tmp")):
        try:
            candidate.mkdir(parents=True, exist_ok=True)
        except OSError:
            continue
        if os.access(candidate, os.W_OK | os.X_OK):
            return candidate
    raise RuntimeError("no writable local temporary directory is available for etcd-backed runners")


def _reserve_local_port() -> int:
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as sock:
        sock.bind(("127.0.0.1", 0))
        sock.listen(1)
        return int(sock.getsockname()[1])


class LocalEtcdSession:
    @staticmethod
    def create_runtime_dir(prefix: str) -> Path:
        return Path(tempfile.mkdtemp(prefix=str(prefix), dir=str(_runtime_tmp_root()))).resolve()

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
