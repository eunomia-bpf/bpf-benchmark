from __future__ import annotations

from pathlib import Path

from .. import ROOT_DIR
from .process_support import NativeProcessRunner


class CalicoRunner(NativeProcessRunner):
    def _default_binary_candidates(self) -> tuple[Path, ...]:
        return (
            ROOT_DIR / "corpus" / "build" / "calico" / "bin" / "calico-node",
            ROOT_DIR / "runner" / "repos" / "calico" / "bin" / "calico-node",
            Path("/usr/bin/calico-node"),
        )


__all__ = ["CalicoRunner"]
