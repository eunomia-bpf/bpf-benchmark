from __future__ import annotations

from pathlib import Path

from .. import ROOT_DIR
from .process_support import NativeProcessRunner


class CorootNodeAgentRunner(NativeProcessRunner):
    def _default_binary_candidates(self) -> tuple[Path, ...]:
        return (
            ROOT_DIR / "corpus" / "build" / "coroot-node-agent" / "bin" / "coroot-node-agent",
            ROOT_DIR / "runner" / "repos" / "coroot-node-agent" / "bin" / "coroot-node-agent",
            Path("/usr/bin/coroot-node-agent"),
        )


__all__ = ["CorootNodeAgentRunner"]
