from __future__ import annotations

from pathlib import Path

from .. import ROOT_DIR
from .process_support import NativeProcessRunner


_BINARY_BY_APP = {
    "bind-iface": ROOT_DIR / "corpus" / "build" / "systemd" / "bin" / "systemd",
    "restrict-fs": ROOT_DIR / "corpus" / "build" / "systemd" / "bin" / "systemd",
    "restrict-ifaces": ROOT_DIR / "corpus" / "build" / "systemd" / "bin" / "systemd",
    "socket-bind": ROOT_DIR / "corpus" / "build" / "systemd" / "bin" / "systemd",
    "sysctl-monitor": ROOT_DIR / "corpus" / "build" / "systemd" / "bin" / "systemd-networkd",
    "userns-restrict": ROOT_DIR / "corpus" / "build" / "systemd" / "bin" / "systemd-nsresourced",
}


def systemd_binary_for_app(app: str | None) -> Path:
    normalized = str(app or "").strip()
    if not normalized:
        return ROOT_DIR / "corpus" / "build" / "systemd" / "bin" / "systemd"
    return _BINARY_BY_APP.get(normalized, ROOT_DIR / "corpus" / "build" / "systemd" / "bin" / "systemd")


class SystemdRunner(NativeProcessRunner):
    def __init__(self, *, app: str, **kwargs: object) -> None:
        self.app = str(app).strip()
        if not self.app:
            raise RuntimeError("SystemdRunner requires an app name")
        super().__init__(**kwargs)

    def _default_binary_candidates(self) -> tuple[Path, ...]:
        return (systemd_binary_for_app(self.app),)


__all__ = ["SystemdRunner", "systemd_binary_for_app"]
