from __future__ import annotations

from pathlib import Path

from .. import ROOT_DIR
from .process_support import NativeProcessRunner


_BINARY_BY_OBJECT = {
    "bind-iface.bpf.o": ROOT_DIR / "corpus" / "build" / "systemd" / "bin" / "systemd",
    "restrict-fs.bpf.o": ROOT_DIR / "corpus" / "build" / "systemd" / "bin" / "systemd",
    "socket-bind.bpf.o": ROOT_DIR / "corpus" / "build" / "systemd" / "bin" / "systemd",
    "sysctl-monitor.bpf.o": ROOT_DIR / "corpus" / "build" / "systemd" / "bin" / "systemd-networkd",
    "userns-restrict.bpf.o": ROOT_DIR / "corpus" / "build" / "systemd" / "bin" / "systemd-nsresourced",
}


def systemd_binary_for_object(object_path: Path | str | None) -> Path:
    if object_path is None:
        return ROOT_DIR / "corpus" / "build" / "systemd" / "bin" / "systemd"
    candidate = Path(object_path)
    return _BINARY_BY_OBJECT.get(candidate.name, ROOT_DIR / "corpus" / "build" / "systemd" / "bin" / "systemd")


class SystemdRunner(NativeProcessRunner):
    def _default_binary_candidates(self) -> tuple[Path, ...]:
        return (systemd_binary_for_object(self.object_path),)


__all__ = ["SystemdRunner", "systemd_binary_for_object"]
