from __future__ import annotations

from pathlib import Path

from .. import ROOT_DIR
from .process_support import NativeProcessRunner


class TubularRunner(NativeProcessRunner):
    def _default_binary_candidates(self) -> tuple[Path, ...]:
        return (
            ROOT_DIR / "corpus" / "build" / "tubular" / "bin" / "tubectl",
            ROOT_DIR / "runner" / "repos" / "tubular" / "bin" / "tubectl",
        )

    def _command(self, binary: Path) -> list[str]:
        return [str(binary), "load", *self.loader_args]


__all__ = ["TubularRunner"]
