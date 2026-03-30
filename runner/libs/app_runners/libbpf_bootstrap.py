from __future__ import annotations

from pathlib import Path

from .. import ROOT_DIR
from .process_support import NativeProcessRunner


DEFAULT_BINARY_ROOT = ROOT_DIR / "corpus" / "build" / "libbpf-bootstrap" / "bin"


class LibbpfBootstrapRunner(NativeProcessRunner):
    def __init__(self, *, app: str, **kwargs: object) -> None:
        self.app = str(app).strip()
        if not self.app:
            raise RuntimeError("LibbpfBootstrapRunner requires an app name")
        super().__init__(**kwargs)

    def _default_binary_candidates(self) -> tuple[Path, ...]:
        return (DEFAULT_BINARY_ROOT / self.app,)


__all__ = ["LibbpfBootstrapRunner"]
