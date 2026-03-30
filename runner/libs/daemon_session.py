from __future__ import annotations

from dataclasses import dataclass, field
from pathlib import Path
from typing import Sequence

from .kinsn import capture_daemon_kinsn_discovery, prepare_kinsn_modules
from .rejit import (
    _start_daemon_server,
    _stop_daemon_server,
    apply_daemon_rejit,
    scan_programs as scan_live_programs,
)


@dataclass(slots=True)
class DaemonSession:
    daemon_binary: Path
    proc: object
    socket_path: Path
    socket_dir: str
    stdout_path: Path
    stderr_path: Path
    kinsn_metadata: dict[str, object] = field(default_factory=dict)
    _closed: bool = False

    @classmethod
    def start(cls, daemon_binary: Path | str, *, load_kinsn: bool = False) -> "DaemonSession":
        binary = Path(daemon_binary).resolve()
        kinsn_metadata: dict[str, object] = {}
        if load_kinsn:
            kinsn_metadata = prepare_kinsn_modules()
        proc, socket_path, socket_dir, stdout_path, stderr_path = _start_daemon_server(binary)
        try:
            if load_kinsn:
                kinsn_metadata = dict(kinsn_metadata)
                kinsn_metadata["daemon_binary"] = str(binary)
                kinsn_metadata["daemon_kinsn_discovery"] = capture_daemon_kinsn_discovery(
                    stdout_path,
                    stderr_path,
                )
                kinsn_metadata["status"] = "ready"
        except Exception:
            _stop_daemon_server(proc, socket_path, socket_dir)
            raise
        return cls(
            daemon_binary=binary,
            proc=proc,
            socket_path=socket_path,
            socket_dir=socket_dir,
            stdout_path=stdout_path,
            stderr_path=stderr_path,
            kinsn_metadata=kinsn_metadata,
        )

    def __enter__(self) -> "DaemonSession":
        return self

    def __exit__(self, exc_type: object, exc: object, tb: object) -> None:
        del exc_type, exc, tb
        self.close()

    def close(self) -> None:
        if self._closed:
            return
        self._closed = True
        _stop_daemon_server(self.proc, self.socket_path, self.socket_dir)

    def scan_programs(
        self,
        prog_ids: Sequence[int],
        *,
        prog_fds: dict[int, int] | None = None,
        timeout_seconds: int = 60,
    ) -> dict[int, dict[str, object]]:
        return scan_live_programs(
            [int(prog_id) for prog_id in prog_ids if int(prog_id) > 0],
            self.daemon_binary,
            prog_fds=prog_fds,
            timeout_seconds=timeout_seconds,
            daemon_socket_path=self.socket_path,
            daemon_proc=self.proc,
            daemon_stdout_path=self.stdout_path,
            daemon_stderr_path=self.stderr_path,
        )

    def apply_rejit(
        self,
        prog_ids: Sequence[int],
        *,
        enabled_passes: Sequence[str] | None = None,
    ) -> dict[str, object]:
        return apply_daemon_rejit(
            [int(prog_id) for prog_id in prog_ids if int(prog_id) > 0],
            enabled_passes=enabled_passes,
            daemon_socket_path=self.socket_path,
            daemon_proc=self.proc,
            daemon_stdout_path=self.stdout_path,
            daemon_stderr_path=self.stderr_path,
        )
