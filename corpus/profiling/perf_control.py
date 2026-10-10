from __future__ import annotations

import errno
import os
import select
import signal
import subprocess
import time
from dataclasses import dataclass
from pathlib import Path
from typing import IO, Sequence


@dataclass
class PerfCollector:
    """A fail-fast perf process controlled through perf's FIFO protocol."""

    command: Sequence[str]
    control_fifo: Path
    ack_fifo: Path
    stderr_path: Path
    use_sudo_for_signals: bool = False
    process: subprocess.Popen[bytes] | None = None
    control_fd: int | None = None
    ack_fd: int | None = None
    stderr_file: IO[bytes] | None = None
    enabled: bool = False

    def start(self, timeout_s: float = 20.0) -> None:
        for fifo in (self.control_fifo, self.ack_fifo):
            if fifo.exists():
                raise RuntimeError(f"refusing to replace existing perf FIFO: {fifo}")
            os.mkfifo(fifo, 0o600)
        self.ack_fd = os.open(self.ack_fifo, os.O_RDONLY | os.O_NONBLOCK)
        self.stderr_file = self.stderr_path.open("wb")
        self.process = subprocess.Popen(
            [str(part) for part in self.command],
            stdout=subprocess.DEVNULL,
            stderr=self.stderr_file,
            start_new_session=True,
        )
        deadline = time.monotonic() + timeout_s
        while time.monotonic() < deadline:
            if self.process.poll() is not None:
                raise RuntimeError(
                    f"perf exited during startup with status {self.process.returncode}; "
                    f"see {self.stderr_path}"
                )
            try:
                self.control_fd = os.open(
                    self.control_fifo, os.O_WRONLY | os.O_NONBLOCK
                )
                break
            except OSError as exc:
                if exc.errno != errno.ENXIO:
                    raise
                time.sleep(0.05)
        if self.control_fd is None:
            raise RuntimeError("timed out opening perf control FIFO")
        self._send("disable", timeout_s=timeout_s)

    def _send(self, command: str, *, timeout_s: float = 10.0) -> None:
        if self.process is None or self.control_fd is None or self.ack_fd is None:
            raise RuntimeError("perf collector is not initialized")
        if self.process.poll() is not None:
            raise RuntimeError(
                f"perf exited with status {self.process.returncode}; see {self.stderr_path}"
            )
        os.write(self.control_fd, f"{command}\n".encode())
        deadline = time.monotonic() + timeout_s
        response = bytearray()
        while time.monotonic() < deadline:
            if self.process.poll() is not None:
                raise RuntimeError(
                    f"perf exited waiting for {command!r} acknowledgement with "
                    f"status {self.process.returncode}; see {self.stderr_path}"
                )
            readable, _, _ = select.select([self.ack_fd], [], [], 0.2)
            if not readable:
                continue
            chunk = os.read(self.ack_fd, 4096)
            if not chunk:
                time.sleep(0.02)
                continue
            response.extend(chunk)
            if b"\n" not in response:
                continue
            first_line = bytes(response).split(b"\n", 1)[0].strip()
            if first_line != b"ack":
                raise RuntimeError(
                    f"unexpected perf response for {command!r}: {first_line!r}"
                )
            return
        raise RuntimeError(f"timed out waiting for perf {command!r} acknowledgement")

    def enable(self) -> None:
        if self.enabled:
            raise RuntimeError("perf collector is already enabled")
        self._send("enable")
        self.enabled = True

    def disable(self) -> None:
        if not self.enabled:
            raise RuntimeError("perf collector is not enabled")
        self._send("disable")
        self.enabled = False

    def finish(self) -> None:
        if self.enabled:
            self.disable()
        self._stop()
        self._close()

    def abort(self) -> None:
        if self.process is not None and self.process.poll() is None:
            self._stop(check_status=False)
        self._close()

    def _stop(self, *, check_status: bool = True) -> None:
        if self.process is None:
            return
        if self.process.poll() is None:
            self._signal_group(signal.SIGINT)
            try:
                self.process.wait(timeout=30)
            except subprocess.TimeoutExpired:
                self._signal_group(signal.SIGTERM)
                try:
                    self.process.wait(timeout=10)
                except subprocess.TimeoutExpired:
                    self._signal_group(signal.SIGKILL)
                    self.process.wait(timeout=10)
        if check_status and self.process.returncode not in (0, 130, -signal.SIGINT):
            raise RuntimeError(
                f"perf exited with status {self.process.returncode}; see {self.stderr_path}"
            )

    def _signal_group(self, signum: signal.Signals) -> None:
        assert self.process is not None
        if self.use_sudo_for_signals:
            subprocess.run(
                [
                    "sudo",
                    "-n",
                    "kill",
                    "-s",
                    signum.name.removeprefix("SIG"),
                    "--",
                    f"-{self.process.pid}",
                ],
                check=True,
                stdout=subprocess.DEVNULL,
                stderr=subprocess.DEVNULL,
            )
        else:
            os.killpg(self.process.pid, signum)

    def _close(self) -> None:
        for field in ("control_fd", "ack_fd"):
            fd = getattr(self, field)
            if fd is not None:
                os.close(fd)
                setattr(self, field, None)
        if self.stderr_file is not None:
            self.stderr_file.close()
            self.stderr_file = None
        for fifo in (self.control_fifo, self.ack_fifo):
            try:
                fifo.unlink()
            except FileNotFoundError:
                pass
