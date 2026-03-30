from __future__ import annotations

from pathlib import Path

from .. import ROOT_DIR
from .process_support import NativeProcessRunner


class LoxilbRunner(NativeProcessRunner):
    def _default_binary_candidates(self) -> tuple[Path, ...]:
        return (
            ROOT_DIR / "corpus" / "build" / "loxilb" / "bin" / "loxilb",
            ROOT_DIR / "runner" / "repos" / "loxilb" / "bin" / "loxilb",
            Path("/usr/bin/loxilb"),
        )


__all__ = ["LoxilbRunner"]
